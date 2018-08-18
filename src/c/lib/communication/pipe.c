#include <stdio.h>


//无名管道
int create_pipe()
{
    int fd[2];
    int ret;

    ret = pipe(fd);
    if (ret < 0) {
        perror("create pipe fail");
        return -1;
    }
    

}



//




void test()
{



}



