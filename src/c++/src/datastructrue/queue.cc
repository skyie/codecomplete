#include <iostream>  
#include <queue>  
#include <vector>  

using namespace std;


void default_queue()
{
    queue<int> que;//默认使用deque作为底层容器  
    for (int i = 0; i < 10; ++i)  
    {  
        que.push(i*i);    
    }  
    cout << "\n队头数据:"<<que.front();  
    cout << "\n队尾数据:" << que.back();  
    cout << "\n队列大小:" << que.size();  
    cout << "\n队列que的数据:\n";  
    while (!que.empty())  
    {  
        cout << que.front() << " ";  
        que.pop();  
    }  
    cout <<endl;

}

int main()  
{  
    default_queue();
    return 0;  
}  

