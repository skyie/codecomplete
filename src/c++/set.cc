#include <iostream>
#include <set>

using namespace std;

bool cmp_func(int one, int two)
{
    return one > two;
}

void test()
{

    // 创建
    int arr[] = {1,2,3,4,5};
    set<int> one(arr, arr + 5);

    set<int> two(one);

    set<int> three(two.begin(), two.end());

    set<int> four; // empty set 

    bool(*p_func)(int, int) = cmp_func();
    set<int> six

}



int main()
{


}
      