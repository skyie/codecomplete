#include <stdio.h>



/*


    API接口：

-----------------------------------------
    打开文件
    #include <sys/stat.h>
    #include <fcntl.h>

    int open(const char *pathname, int flags, ...mode);

    flags:
        O_RDONLY  只读打开
        O_WRONLY    可写
        ORDWR       可读可写
        上面三个不能同时使用    

        同时可以|以下标记
        O_CREAT 如果文件不存在，创建文件，同时需要提供mode权限,可以用八进制表示
            0644 表示 
            4 可读 2 可写 1 可执行
        O_TRUNC
        O_CLOEXEC
        O_APPEND
        O_SYNC
        

        
-----------------------------------------------
    检查进程对指定文件是否可以进行某种操作
    int access(const char *pathname, int mode);
        return 0 sucess, -1 fail

    mode:
        R_OK 测试可读     W_OK 测试可写
        X_OK 测试可执行         F_OK   测试文件是否存在

*/
