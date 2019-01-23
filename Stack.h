#include<iostream>
#include"List.h"
using namespace std;
template <typename T>
class Stack
{
    List<T>stlst;
public:
    
    Stack(){}
    ~Stack(){}
    bool empty();
    int size(){ return stlst.size();}
    void push(T);
    T & top(){
        T tp;
        T &ref_tp=tp;
        ref_tp=stlst.front();
        return ref_tp;
    }
    T & pop()
    {
        T tp;
        T &ref_tp=tp;
        ref_tp=stlst.front();
        stlst.pop_front();
        return ref_tp;
    }
};
template <typename T>
bool Stack<T>::empty(){ return stlst.empty();}

template <typename T>
void Stack<T>::push(T newdata)
{
    stlst.push_front(newdata);
}
