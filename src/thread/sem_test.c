#include "common.h"

#define SEM_PATH "/var/run/sem_test"

#define THREAD_NUM 1

extern char* __progname;

int sem_init(int init_value, int);
int sem_p(int sem_id, int value);
int sem_v(int sem_id, int value);
int sem_del(int sem_id);
int get_sem_cnt(int sem_id);


static void writepid(void)
{
    FILE* out = NULL;
    char name[1024];
    (void) snprintf(name, sizeof(name), "/var/run/%s.pid", __progname);
    out = fopen(name, "w");
    if (out)
    {
        (void) fprintf(out, "%d", getpid());
        (void) fclose(out);
    }
}

static void removepid(void)
{
    char name[1024];
    (void) snprintf(name, sizeof(name), "/var/run/%s.pid", __progname);
    (void) remove(name);
}


int sem_init(int set, int init_value)
{
	int sem_id;
	key_t key;

	char name[1024];
	snprintf(name, sizeof(name), "/var/run/%s.pid", __progname);
	if (access(name, R_OK) != 0 ) {
		printf("%s not exist!\n", name);
	}
	key = ftok(name, 1024);
	if (key < 0) {
		perror("ftok fail\n");
		return -1;
	}
	//printf("key %u\n", key);
	sem_id = semget(key, 1, 0660|IPC_CREAT);
	if (sem_id < 0) {
		perror("semget fail!\n");
		return -1;
	}
	get_sem_cnt(sem_id);
	if (set) {
		union semun arg;
		arg.val = init_value;
		if (semctl(sem_id, /* semnum */0, SETVAL, arg)) {
			perror("semctl fail!");
			return -1;
		}
	}
	return sem_id;
}
int sem_p(int sem_id, int value)
{
	struct sembuf buf;
	buf.sem_num = 0;
	buf.sem_op -= value;
	buf.sem_flg = SEM_UNDO;

	if (semop(sem_id, &buf, 1) < 0) {
		perror("semop P fail\n");
		return -1;
	}
	printf("sem P - %u\n", value);
	return 0;
}
int sem_v(int sem_id, int value)
{
	struct sembuf buf;
	buf.sem_num = 0;
	buf.sem_op = +value;
	buf.sem_flg = SEM_UNDO;

	if (semop(sem_id, &buf, 1) < 0) {
		perror("semop P fail\n");
		return -1;
	}
	printf("sem V + %u\n", value);
	return 0;
}
int sem_del(int sem_id)
{
	union semun sem_union;
	if (semctl(sem_id, 0, IPC_RMID, sem_union)) {
		perror("semctl del fail\n");
		return -1;
	}
	return 0;
}

void show_sem_info(int sem_id)
{
	#if 0
	union semun arg, dummy;
	struct semid_ds ds;

	arg.buf = &ds;
	if (semctl(sem_id, 0, IPC_STAT, arg)) {
		perror("semctl IPC_STAT fail\n");
		return;
	}
	//printf("sem changed: %s\n", ctime(&ds.sem_ctime));
	//printf("sem last op: %s\n", ctime(&ds.sem_otime));
	printf("sem number: %u\n", ds.sem_nsems);

	int j;

	/*  */
	printf("sem # value # sempid # semcnt\n");
	for (j = 0; j < ds.sem_nsems; j++) {
		printf("%3d %3d %3d %3d\n", j, arg.array[j], 
			semctl(sem_id, j, GETPID, dummy),
			semctl(sem_id, j, GETNCNT, dummy));

	}
	#endif
	
}
int get_sem_cnt(int sem_id)
{
	union semun arg;
	int count;
	count = semctl(sem_id, 0, GETVAL, arg);
	printf("pid %u semdid %u  count %u\n", getpid(), sem_id, count);
	return count;
}

int s_sem_id;
pthread_mutex_t thread_cnt_lock = PTHREAD_MUTEX_INITIALIZER;



void child_process_do()
{
	int i;
	
	//printf("child process %u %s begin\n", getpid(), __progname);
	//int sem_id = sem_init(1, 0);
	//show_sem_info(sem_id);
	writepid();

	show_sem_info(s_sem_id);
	sem_v(s_sem_id, THREAD_NUM);
	get_sem_cnt(s_sem_id);
	//show_sem_info(sem_id);
	//sem_del(sem_id);
	printf("child process %u done\n", getpid());
}


void* parent_thread_do(void* arg)
{

	printf("thread %u wait semid %u\n", pthread_self(), s_sem_id);
	//show_sem_info(s_sem_id);
	pthread_mutex_lock(&thread_cnt_lock);
	get_sem_cnt(s_sem_id);
	sem_p(s_sem_id, 1);
	pthread_mutex_unlock(&thread_cnt_lock);
	printf("thread %u done\n", pthread_self());
	//sem_del(s_sem_id);
	return NULL;
}
void parent_process_do()
{
	pthread_t tid[THREAD_NUM];
	int ret, i;
	int child_status;

	printf("parent process %u %s begin\n", getpid(), __progname);
	writepid();

	//s_sem_id = sem_init(0, 0);
	assert(s_sem_id);
	for (i = 0; i < THREAD_NUM; i++) {
		ret = pthread_create(&tid[i], NULL, parent_thread_do, NULL);
		if (ret < 0) {
			perror("thread create fail\n");
			return;
		}
	}
	for (i = 0; i < THREAD_NUM; i++) {
		pthread_join(tid[i], NULL);
	}
	printf("pthread join\n");
	atexit(removepid);

	//waitpid(-1, &child_status, 0);
}
#if 0
/*
 * fork子进程，通过信号量让子进程先执行，父进程后执行
 */
int main()
{

	pid_t pid;
	int child_status;
	s_sem_id = sem_init(1, 0);
	pid = fork();
	if (pid < 0) {
		perror("fork fail\n");
		exit(1);
	}
	//umask (0027);
	if (pid == 0) {
		child_process_do();
	} else {//父进程创建多线程等待子进程同步
		parent_process_do();
	}
	waitpid(-1, &child_status, 0);
	return 0;
}
#endif
int main(int argc, char** argv)
{
	printf("argc %u\n", argc);
	
	int sem_id = sem_init(0, 0);
	if (argc == 3) {
		sem_p(sem_id, 1);
		
	} else  if (argc == 2) {
		sem_v(sem_id, 1);
		get_sem_cnt(sem_id);
	} else {
		printf("unkown\n");
	}

	return 0;
}
