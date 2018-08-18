#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <string.h>
#include <errno.h>

/*
    文件锁包含两种：
    1.flock()对整个文件加锁
    2.fcntl()对文件部分区域加锁

    场景：
    1. 多个进程操作同一个文件需要文件锁保护
    2. 更加通用的场景，实际并不需要文件IO，使用文件锁对其他共享资源保护
    3. daemon进程通过/var/run下写一个daemon.pid的文件，来保证单实例运行


    注意点：
    1. 文件锁和stdio库混用的问题，stdio库会对输入输出缓冲，因此避免使用，直接使用系统调用
    read/write；或者文件加锁后立即刷新IO流，释放前再立即刷新IO流；使用setbuf禁用IO缓冲，牺牲
    一些效率
    2. 关于文件锁的继承



    使用：
    #include <sys/file.h>

    int flock(int fd, int operation);
        return 0 success, -1 error

    operation取值：
    LOCK_SH fd上加共享锁
    LOCK_EX fd上加互斥锁
    LOCK_UN fd释放锁
    LOCK_NB 发起非阻塞的请求，通常|加这个标记，来非阻塞获取锁

    共享锁可以多个进程加，互斥锁只能同时有一个进程加

    
    查看系统当前的文件锁：
    cat /proc/locks


*/





#define MAX_FILE_NAME_LEN 32
/*
    Usage: ./filelock <file>  <s/x/n>
*/
int main(int argc, char** argv)
{
    if (argc != 3) {
        printf("Usage: ./filelock <file> <s/x/n>\n");
        exit(1);
    }

    char* filename;
    int lock;
    int fd, flags;
    int ret;


    if (strlen(argv[1]) > MAX_FILE_NAME_LEN) {
        printf("exceed max file len");
        exit(1);
    }
    filename = argv[1];
    if (access(filename, F_OK) < 0) {
        flags = O_CREAT|O_RDONLY;
    } else {
        flags = O_RDONLY;
    }

    fd = open(filename, flags, 0755);
    if (fd == -1) {
        perror("create file fail");
        exit(1);
    }

    lock = (argv[2][0] == 's') ? LOCK_SH :LOCK_EX;
    if (argv[2][1] == 'n') {
        lock |= LOCK_NB;
    }
    printf("argv: %s, %s\n", argv[1], argv[2]);

    printf("request lock... lock:%d\n", lock);
    ret = flock(fd, lock);
    if (ret == -1) {
        if (errno == EWOULDBLOCK) {
            printf("fail get");
            exit(0);
        } else {
            perror("flock fail");
            exit(1);

        }
    }


    printf("get lock\n");
    sleep(10);

    printf("release lock\n");
    flock(fd, LOCK_UN);

    return 0;
}



