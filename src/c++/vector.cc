#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void traversal(vector<T>& vec)
{

    // 使用迭代器 iterator 访问值
    // 注意这里要加typename关键字，否则编译不通过
    typename vector<T>::iterator v = vec.begin();
    while( v != vec.end()) {
       cout << "value of v = " << *v << endl;
       v++;
    }
}


int main()
{
    // 创建一个向量存储 int
    vector<int> vec; 
    int i;

    // 显示 vec 的原始大小
    cout << "vector size = " << vec.size() << endl;

    // 推入 5 个值到向量中
    for(i = 0; i < 5; i++){
      vec.push_back(i);
    }

    // 显示 vec 扩展后的大小
    cout << "extended vector size = " << vec.size() << endl;

    // 访问向量中的 5 个值
    for(i = 0; i < 5; i++){
      cout << "value of vec [" << i << "] = " << vec[i] << endl;
    }

    traversal<int>(vec);

    // 合并两个vector
    vector<int> vec2;
    vec2.push_back(20);
    vec.insert(vec.end(), vec2.begin(), vec2.end());
    cout << "merge:" << endl;
    traversal<int>(vec);  

    return 0;
}
