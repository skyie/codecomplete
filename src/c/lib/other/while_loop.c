#include "stdio.h"



int main()
{
    int a[10];
    int i;
    for (i = 1;i <= 10; i++) {
        a[i] = i;
        printf("i=%d", i);
    }

    return 0;
}
