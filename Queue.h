#include<iostream>
#include"List.h"
using namespace std;

template <typename T>
class Queue
{
    List<T>Qlst;
public:
    Queue(){}
    ~Queue(){}
    void push(T ele)
    {
        Qlst.push_back(ele);
    }
    void pop(){ Qlst.pop_front();}
    T & front()
    {
        T fr;
        T &fr_ref=fr;
        fr_ref=Qlst.front();
        return fr_ref;
    }
    T & back()
    {
        T bc;
        T &bc_ref=bc;
        bc_ref=Qlst.back();
        return bc_ref;
    }
    int size(){ return Qlst.size();}
    bool empty(){ return Qlst.empty();}
};
