/**
 * 二分查找算法
 */

#include <iostream>

using namespace std;

class BinarySearch
{
public:
    static int binary_search(int arr[], int len, int val);          

private:
    static int _binary_search(int arr[], int start, int end, int val);   
};

/* 实现里不能加static关键字? */
int BinarySearch::_binary_search(int arr[], int start, int end, int val)
{
    if (start > end) {
        return -1;
    }
    int pos = (start + end) / 2;
    if (arr[pos] == val) {
        return pos;
    } else if (arr[pos] > val) {
        end = pos - 1;
        return _binary_search(arr, start, end, val);
    } else {
        start = pos + 1;
        return _binary_search(arr, start, end, val);
    }
}
int BinarySearch::binary_search(int arr [ ], int len, int val)
{
    int start = 0;
    int end = len - 1;
    return _binary_search(arr, start, end, val);
}







void test()
{
    int array[] = {1,2,10,20,30};
    int ret = BinarySearch::binary_search(array, sizeof(array) / sizeof(int), 20);
    cout << "find: " <<ret << endl;
    
}

int main()
{

    test();
}
