#include "common.h"


/*
内存映射分两种：
1.

通过cat /proc/pid/maps查看映射情况

创建映射
#include <sys/man.h>
void* mmap(void* addr, size_t length, int prot, int flags, int fd, off_t offset);
    return address of maping on success, NULL on fail


prot:
    PROT_NONE
:无法访问
    PROT_READ：可读
    PROT_WRITE：可写
    PROT_EXEC：可执行

flags:
    MAP_PRIVATE:
    MAP_SHARED:
        私有

解放
int munmap(vooid* addr, size_t length);        

    
  
*/
int 



