#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

typedef struct test
{
	int a;
	char name[10];

}test_t;

__thread struct test per_test;
void* pthread1_do(void* arg)
{
	printf("thread id %u\n", pthread_self());
	memset(&per_test, 0, sizeof(struct test));
	per_test.a = 1;
	strncpy(per_test.name, "thread1", sizeof(per_test.name) - 1);
	//printf("per_test a:%u, name:%s\n", per_test.a, per_test.name);
	while(1) {
		printf("per_test a:%u, name:%s\n", pthread_self(), per_test.a, per_test.name);
		sleep(20);
	}
	return NULL;
}
void* pthread2_do(void* arg)
{
	printf("thread id %u\n", pthread_self());
	memset(&per_test, 0, sizeof(struct test));
	per_test.a = 10;
	strncpy(per_test.name, "thread2", sizeof(per_test.name) - 1);
	//printf("per_test a:%u, name:%s\n", per_test.a, per_test.name);
	while(1) {
		printf("tid:%u, per_test a:%u, name:%s\n", pthread_self(), per_test.a, per_test.name);
		sleep(20);
	}
	return NULL;
}

int main()
{
	pthread_t thread_arr[2];
	int ret;

	if (pthread_create(&thread_arr[1], NULL, pthread1_do, NULL) < 0) {
		printf("create fail:%s\n", strerror(errno));
		exit(1);
	}
	if (pthread_create(&thread_arr[2], NULL, pthread2_do, NULL) < 0) {
		printf("create fail:%s\n", strerror(errno));
		exit(1);
	}
	pthread_join(thread_arr[1], NULL);
	pthread_join(thread_arr[2], NULL);
	printf("END\n");
	return 0;
}
