[TOC]
# C++基本语法
1. new和malloc区别，free和delete区别

1.malloc和free是C的库函数，new,delete是C++运算符
2.new会调用构造函数，malloc不会
3.new返回指定类型指针，malloc返回void*指针
4.new会自动计算需分配的空间，malloc不行
5.new可以被重载，malloc不能




2. 指针和引用区别


3. STL容器的内部实现，时间复杂度


4. extern/static关键字


















## 模板
1. template<typename T> 和tempalte<class T>的区别?


   






## 编译错误 
1.
```
dlist.h:143:7: error: expected unqualified-id before ‘=’ token
     del_node->prev->next = del_node->next;
       ^
dlist.h:149:13: error: expected primary-expression before ‘;’ token

```

