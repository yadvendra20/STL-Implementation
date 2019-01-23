#include<iostream>
#include<cstdlib>
#include"Algorithm.h"
using namespace std;
template <typename T1>
class node
{
    T1 data;
    node *left,*right;
public:
    node()
    {
        data=0;
        left=right=NULL;
    }
    node(T1 newdata)
    {
        data=newdata;
        left=right=NULL;
    }
    ~node()
    {
        delete left;
        delete right;
    }
    void setdata(T1 newdata)
    {
        data=newdata;
    }
    void setleft(node* newleft)
    {
        left=newleft;
    }
    void setright(node* newright)
    {
        right=newright;
    }
    T1 getdata(){return data;}
    node* getleft(){return left;}
    node* getright(){return right;}
    void setleftNull(){left=NULL;}
    void setrightNull(){right=NULL;}
    void setBothNull(){
        left=NULL;
        right=NULL;
    }
};

template <typename T>
class Set
{
    node<T> *root,*curr,*prev;
    T *beg_;
    T *end_;
    int size_;
    T* setarr;
public:
    typedef T* Iterator;
    Set()
    {
        root=curr=prev=NULL;
        beg_=end_=NULL;
        size_=0;
        setarr=NULL;
    }
    Set(T*,T*); //Making of tree
    void insert(T);
    int size(){return size_;}
    bool empty(){return root==NULL;}
    bool search(T); //for search of an element in TREE
    node<T>* getroot(){return root;} //returns the root
    //void inorderAssi(T*,node<T>*); //inorder Assignment
    Iterator begin();
    Iterator end();
    void renew(T);  //making of new set vector
    void display(node<T>*); //displays the data in the tree by inorder traversal
};
template <typename T>
Set<T>::Set(T *st,T *en)
{
    beg_=st;
    end_=en;
    root=curr=prev=NULL;
    node<T> *a,*b;
    size_=0;
    setarr=NULL;
    while(beg_!=end_)
    {
        if(root==NULL)
        {
            a=new node<T>(*beg_);
            root=a;
        }
        else
        {
            b=root;
            while(1)
            {
                if(*beg_<b->getdata())
                {
                    if(b->getleft()==NULL)
                    {
                        a=new node<T>(*beg_);
                        b->setleft(a);
                        break;
                    }
                    else
                        b=b->getleft();
                }
                else if(*beg_==b->getdata())
                        ;
                else
                {
                    if(b->getright()==NULL)
                    {
                        a=new node<T>(*beg_);
                        b->setright(a);
                        break;
                    }
                    else
                        b=b->getright();
                }
            }
        }
        size_++;
        renew(*beg_);
        beg_++;
    }
}
template <typename T>
void Set<T>::insert(T newele)
{
    if(search(newele)==true)
        return;
    else
    {
        node<T> *a,*b;
        int flg=0;
        while(1)
        {
            if(root==NULL)
            {
                a=new node<T>(newele);
                root=a;
                break;
            }
            else
            {
                b=root;
                while(1)
                {
                    if(newele<b->getdata())
                    {
                        if(b->getleft()==NULL)
                        {
                            a=new node<T>(newele);
                            b->setleft(a);
                            flg=1;
                            break;
                        }
                        else
                            b=b->getleft();
                    }
                    else
                    {
                        if(newele>b->getdata())
                        {
                            if(b->getright()==NULL)
                            {
                                a=new node<T>(newele);
                                b->setright(a);
                                flg=1;
                                break;
                            }
                            else
                                b=b->getright();
                        }
                    }
                }
                if(flg==1)
                    break;
            }
        }
    }
    size_++;
    renew(newele);
}
template <typename T>
bool Set<T>::search(T sv)
{
    if(root==NULL)
        return false;
    node<T> *a=root;
    int flg=0;
    curr=prev=NULL;
    while(1)
    {
        if(sv==a->getdata())
        {
            flg=1;
            curr=a;
            break;
        }
        else if(sv<a->getdata())
        {
            if(a->getleft()==NULL)
                break;
            else
            {
                prev=a;
                a=a->getleft();
            }
        }
        else if(sv>a->getdata())
        {
            if(a->getright()==NULL)
                break;
            else
            {
                prev=a;
                a=a->getright();
            }
        }
    }
    return flg==1;
}

template <typename T>
typename Set<T>::Iterator Set<T>::begin()
{
    return setarr;
}
template <typename T>
typename Set<T>::Iterator Set<T>::end()
{
    return setarr+size_;
}
template <typename T>
void Set<T>::renew(T newele)
{
    T *newsetarr=new T[size_];
    int i;
    for(i=0;i<size_-1;i++)
        newsetarr[i]=setarr[i];
    newsetarr[i]=newele;
    if(setarr!=NULL)
        delete []setarr;
    setarr=newsetarr;
    sort(setarr,setarr+size_);
}
template <typename T>
void Set<T>::display(node<T>* rt)
{
    if(rt==NULL)
        return ;
    else
    {
        display(rt->getleft());
        cout<<rt->getdata()<<" ";
        display(rt->getright());
    }
}
