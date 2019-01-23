#include<iostream>
using namespace std;
template <typename T>
class Vector
{
private:
    T* arr;
    int size_;
    int capacity_;
public:
    typedef T* Iterator;
    Vector();
    Vector(Vector<T> &);
    Vector(T*,T*);
    Vector(int);
    ~Vector(){}
    int size();
    int capacity();
    Iterator begin();
    Iterator end();
    T& operator[](int);
    void push_back(T);
    void mkspace(int,bool);
    void pop_back();
    bool empty();
    T& front();
    T& back();
    void clear();
    void erase(Iterator);
};
template <typename T>
Vector<T>::Vector()
{
    size_=capacity_=0;
    arr=0;
}
template <typename T>
Vector<T>::Vector(int n)
{
    arr=new T[n];
    for(int i=0;i<n;i++)
        arr[i]=0;
    size_=n;
    capacity_=n;
}
template <typename T>
Vector<T>::Vector(Vector<T> &k)
{
    size_=k.size_;
    capacity_=k.capacity_;
    arr=new T[size_];
    for(int i=0;i<size_;i++)
        arr[i]=k.arr[i];
}
template <typename T>
Vector<T>::Vector(T *st,T *en)
{
    size_=capacity_=en-st;
    arr=new T[size_];
    int i=0;
    T *a=st;
    while(a!=en)
    {
        arr[i++]=*a;
        a++;
    }
}
template <typename T>
int Vector<T>::size()
{
    return size_;
}
template <typename T>
int Vector<T>::capacity()
{
    return capacity_;
}
template <typename T>
typename Vector<T>::Iterator Vector<T>::begin()
{
    return arr;
}
template <typename T>
typename Vector<T>::Iterator Vector<T>::end()
{
    return arr+size_;
}
template <typename T>
T& Vector<T>::operator[](int i)
{
    return arr[i];
}
template <typename T>
void Vector<T>::push_back(T data)
{
    if(size_==capacity_)
    {
        if(capacity_==0)
            mkspace(1,false);
        else
            mkspace(2*capacity_,true);
    }
    arr[size_]=data;
    size_++;
}
template <typename T>
void Vector<T>::mkspace(int n,bool sig)
{
    T* newarr;
    int i;
    newarr=new T[n];
    if(newarr==NULL)
        cout<<"\nMemory allocation error";
    if(sig)
    {
        for(int i=0;i<size_;i++)
            newarr[i]=arr[i];
    }
    if(arr!=NULL)
        delete []arr;
    arr=newarr;
    capacity_=n;
}
template <typename T>
void Vector<T>::pop_back()
{
    size_--;
}
template <typename T>
bool Vector<T>::empty()
{
    return size_==0;
}
template <typename T>
T& Vector<T>::front()
{
    return arr[0];
}
template <typename T>
T& Vector<T>::back()
{
    return arr[size_-1];
}
template <typename T>
void Vector<T>::clear()
{
    size_=capacity_=0;
    arr=NULL;
}
template <typename T>
void Vector<T>::erase(Iterator it)
{
    T *i=it,*j=it;
    ++i;
    for(;i!=end();++i,++j)
        *j=*i;
    size_--;
}
