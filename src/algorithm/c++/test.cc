#include <iostream>
#include "dlist.h"
#include "sorting.h"

using namespace std;


int g_arr[5] = {5,4,2,1,3};
void test_dlist()
{
    Dlist<int> dlist;
    dlist.push_back(10);
    dlist.push_back(12);
    dlist.dump();
}

void dump_arr()
{
    int i;
    int len = sizeof(g_arr) / sizeof(int);
    for (i=0;i < len;i++) {
        cout<<g_arr[i]<<" ";
    }
}


void test_heapsort()
{
    heapsort<int>(g_arr, sizeof(g_arr) / sizeof(int));
    dump_arr();
}


int main()
{
    //test_dlist();
    //test_sorting();
    test_heapsort();
    return 0;
}
