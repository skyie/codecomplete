#include <stdio.h>

#include "libtest1.h"
#include "libtest2.h"

void libtest1()
{
    libtest2();

    printf("call libtest1");

}


int sum(int a, int b)
{
    int sum = a + b;
    return sum;
}

