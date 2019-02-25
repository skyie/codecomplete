#ifndef _DLIST_H_
#define _DLIST_H_ 

#include <iostream>
#include <assert.h>
using namespace std;
/**
 *@brief: 双向链表模板实现
 *@author skyie
 *@date 2018/04/01
 */

template<typename T>
struct Dlist_node
{
    T element;
    Dlist_node<T>* next;
    Dlist_node<T>* prev;
    Dlist_node(): element(), next(nullptr), prev(nullptr){}
    explicit Dlist_node(const T& element): element(element), next(nullptr), prev(nullptr){}
    ~Dlist_node() {
        next = nullptr;
        prev = nullptr;
    }
};


template<typename T>
class Dlist 
{
public:
    Dlist();
    ~Dlist();

    bool empty() const {return length > 0 ? true : false;}
    size_t size() const {return length;}

    T value(int pos);
    void push_front(const T& element);
    T pop_front();
    void push_back(const T& element);
    T pop_back();

    void clear();
    T erase(int pos);
    void erase(int begin, int end);

    void dump();

private:
    Dlist_node<T>* find(int pos);
    void insert_after(int pos, const T& element);
private:
    Dlist_node<T>* head;
    Dlist_node<T>* tail;
    int length;
};


template<typename T>
Dlist<T>::Dlist()
{
    head = new Dlist_node<T>();
    tail = new Dlist_node<T>();
    head->next = tail;
    tail->prev = head;
    length = 0;
}

template<typename T>
Dlist<T>::~Dlist()
{
    clear();
    delete head;
    delete tail;
}
template<typename T>
void Dlist<T>::clear()
{
    if (length != 0) {
        erase(1, length);

    }
}
template<typename T>
T Dlist<T>::value(int pos)
{
    Dlist_node<T>* node = find(pos);
    if (node == nullptr) {
        return -1;
    }
    return node->element;
}

template<typename T>
void Dlist<T>::push_front(const T& element)
{
    insert_after(0, element);
}

template<typename T>
T Dlist<T>::pop_front()
{
    Dlist_node<T>* node = find(1);
    return node->element;
}

template<typename T>
void Dlist<T>::push_back(const T& element)
{
    insert_after(length, element);

}


template<typename T>
T Dlist<T>::pop_back()
{
    Dlist_node<T>* node = find(length);
    return node->element;
}


template<typename T>
void Dlist<T>::insert_after(int pos, const T& element)
{
    if (pos < 0 || pos > length) {
        cout<< "out of bound"<<endl;
        return;
    }
    Dlist_node<T>* new_node = new Dlist_node<T>(element);
    assert(new_node);
    Dlist_node<T>* pre_node = find(pos);
    pre_node->next->prev = new_node;
    new_node->next = pre_node->next;
    new_node->prev = pre_node;
    pre_node->next = new_node;
    length++;
}

template<typename T>
Dlist_node<T>* Dlist<T>::find(int pos)
{
    if (pos < 0 || pos > length) {
        cout<< "find:out of bound"<<endl;
        return nullptr;
    }
    Dlist_node<T>* node = head;
    int i = 0;
    while (i != pos) {
        node = node->next;
        i++;
    }
    return node;
}

template<typename T>
T Dlist<T>::erase(int pos)
{
    Dlist_node<T>* del_node = find(pos);
    if (del_node == nullptr) {
        return;
    }
    T element = del_node->element;
    del_node->prev->next = del_node->next;
    del_node->next->prev = del_node->prev;
    delete del_node;
    length--;

    return element;
    //return nullptr;
}

template<typename T>
void Dlist<T>::erase(int begin, int end)
{
    Dlist_node<T>* pbegin = find(begin);
    Dlist_node<T>* pend = find(end);

    pbegin->prev->next = pend->next;
    pend->next->prev = pbegin->prev;

    Dlist_node<T>* stop = pend->next;
    while (pbegin != stop) {
        Dlist_node<T>* tmp = pbegin;
        pbegin = pbegin->next;
        delete tmp;
        length--;
    }
}

template<typename T>
void Dlist<T>::dump()
{
    Dlist_node<T>* node = head->next;
    while (node != tail) {
        cout<<node->element<<endl;
        node = node->next;
    }
        
}
#endif

