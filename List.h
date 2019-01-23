#include<iostream>
#include<cstdlib>
#include"Algorithm.h"
#include"Vector.h"
using namespace std;
template <typename T>
class Node
{
    T data;
    Node *prev,*next;
public:
    Node()
    {
        data=0;
        next=prev=NULL;
    }
    Node(T newdata)
    {
        data=newdata;
        next=prev=NULL;
    }
    Node(Node<T> & N)
    {
        data=N.data;
        next=N.next;
        prev=N.prev;
    }
    ~Node(){}
    void setdata(T newdata)
    {
        data=newdata;
    }
    void setnext(Node<T>* newnext)
    {
        next=newnext;
    }
    void setprev(Node<T>* newprev)
    {
        prev=newprev;
    }
    T getdata(){return data;}
    Node<T>* getnext(){return next;}
    Node<T>* getprev(){return prev;}
    void setNextNull(){next=NULL;}
    void setPrevNull(){prev=NULL;}
};
template <typename T>
class Iterator
{
private:
    Node<T>* itr;
public:
    Iterator(){ itr=NULL;}
    Iterator(Node<T>* par){ itr=par;}
    T  operator*(){ return itr->getdata();}
    Iterator operator++(int){
        itr=itr->getnext();
        return *this;
    }
    Iterator operator++()
    {
        itr=itr->getnext();
        return *this;
    }
    Iterator operator--(int){
        itr=itr->getprev();
        return *this;
    }
    bool operator!=(const Iterator & k)
    {
        return itr!=k.itr;
    }
    bool operator==(const Iterator & k)
    {
        return itr==k.itr;
    }
    Node<T>* getNode(){ return itr;}
};
template <typename T>
class List : public Iterator<T>
{
    Node<T>* head;
    Node<T>* tail;
    int cnt;
public:
    List(){
        head=NULL;
        tail=NULL;
        cnt=0;
     }
    List(List<T> & ls){
        head=ls.head;
        tail=ls.tail;
        cnt=ls.cnt;
    }
    ~List(){
        delAll();
    }
    T front(){
        return head->getdata();
    }
    T back(){
        return tail->getdata();
    }
    void push_front(T);
    void push_back(T);
    Iterator<T> begin(){ return Iterator<T>(head);}
    Iterator<T> end(){ return Iterator<T>(0);}
    void display();
    void delAll();
    void pop_front();
    void pop_back();
    bool empty();
    void insert(Iterator<T> ,T);
    void erase(Iterator<T>);
    void assign(int, T);
    void assign(Iterator<T>,Iterator<T>);
    void remove(T);
    void reverse();
    int size(){return cnt;}
    void Sort();
    void clear();
};
template <typename T>
void List<T>::push_front(T newdata)
{
    Node<T>* tmp;
    tmp=new Node<T>(newdata);
    if(tail==NULL)
        tail=tmp;
    else
    {
        tmp->setnext(head);
        head->setprev(tmp);
    }
    head=tmp;
    cnt++;
    return;
}
template <typename T>
void List<T>::push_back(T newdata)
{
    Node<T>* tmp;
    tmp=new Node<T>(newdata);
    if(head==NULL)
        head=tmp;
    else
    {
        tail->setnext(tmp);
        tmp->setprev(tail);
    }
    tail=tmp;
    cnt++;
    return;
}
template <typename T>
void List<T>::display()
{
    if(head==NULL)
    {
        cout<<"\nEmpty list";
        return;
    }
    Node<T>* tr=head;
    while(tr!=NULL)
    {
        cout<<tr->getdata()<<" ";
        tr=tr->getnext();
    }
}
template <typename T>
void List<T>::delAll()
{
    Node<T>* tmp=head;
    while(head!=NULL)
    {
        head=tmp->getnext();
        delete tmp;
        tmp=head;
    }
    tail=NULL;
    cnt=0;
    return;
}
template <typename T>
void List<T>::pop_front()
{
    Node<T>* tmp=head;
    if(head==NULL)
        return ;
    else if(head==tail)
        head=tail=NULL;
    else
    {
        head=tmp->getnext();
        head->setPrevNull();
    }
    delete tmp;
    cnt--;
}
template <typename T>
void List<T>::pop_back()
{
    Node<T>* tmp=tail;
    if(tail==NULL)
        return;
    else if(head==tail)
        head=tail=NULL;
    else
    {
        tail=tmp->getprev();
        tail->setNextNull();
    }
    delete tmp;
    cnt--;
}
template <typename T>
bool List<T>::empty()
{
    return (head==NULL && tail==NULL);
}
template <typename T>
void List<T>::insert(Iterator<T> pos,T val)
{
    if(pos==NULL)
        return ;
    if(pos==begin())
    {
        push_front(val);
        return ;
    }
    Node<T>* tmp;
    tmp=new Node<T>(val);
    tmp->setnext(pos.getNode());
    Node<T>* tmp2=pos.getNode()->getprev();
    tmp->setprev(tmp2);
    tmp2->setnext(tmp);
    pos.getNode()->setprev(tmp);
    cnt++;
}
template <typename T>
void List<T>::erase(Iterator<T> pos)
{
    if(pos==NULL)
        return;
    else if(pos==head)
        pop_front();
    else if(pos==tail)
        pop_back();
    else
    {
        Node<T>* tmp=pos.getNode();
        Node<T>* pr=tmp->getprev();
        Node<T>* nx=tmp->getnext();
        pr->setnext(nx);
        nx->setprev(pr);
        delete tmp;
        cnt--;
    }
}
template <typename T>
void List<T>::assign(int nt,T newdata)
{
    int i;
    for(i=0;i<nt;i++)
        push_back(newdata);
}
template <typename T>
void List<T>::assign(Iterator<T> beg,Iterator<T> en)
{
    head=beg.getNode();
    tail=en.getNode();
}
template <typename T>
void List<T>::remove(T val)
{
    Node<T>* tr=head;
    while(tr!=NULL)
    {
        if(tr->getdata()==val)
            erase(Iterator<T>(tr));
        tr=tr->getnext();
    }
}
template <typename T>
void List<T>::reverse()
{
    Node<T>* tr=head;
    while(tr!=NULL)
    {
        Node<T>* nx=tr->getnext();
        Node<T>* tmp=tr->getprev();
        tr->setprev(tr->getnext());
        tr->setnext(tmp);
        tr=nx;
    }
    Node<T>* temp=head;
    head=tail;
    tail=temp;
}
template <typename T>
void List<T>::Sort()
{
    Node<T>* tr=head;
    Vector<T>tempV;
    while(tr!=NULL)
    {
        tempV.push_back(tr->getdata());
        tr=tr->getnext();
    }
    sort(tempV.begin(),tempV.end());
    delAll();
    int i;
    for(i=0;i<tempV.size();i++)
        push_back(tempV[i]);
}
template <typename T>
void List<T>::clear()
{
    delAll();
}
