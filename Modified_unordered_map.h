#include<iostream>
#include<cstdlib>
#include"Pair.h"
using namespace std;
template <typename T1,typename T2>
class Node
{
public:
    T1 key;
    T2 value;
    Node* next;
    Node()
    {
        key=value=0;
        next=NULL;
    }
    Node(T1 newkey,T2 newvalue)
    {
        key=newkey;
        value=newvalue;
        next=NULL;
    }
    Node(Node & N)
    {
        key=N.key;
        value=N.value;
        next=N.next;
    }
    ~Node(){}
    void setnext(Node* newnext)
    {
        next=newnext;
    }
    T1 getkey(){return key;}
    T2 getvalue(){return value;}
    Node* getNext(){return next;}
    void setNextNull(){next=NULL;}
};

template <typename T1,typename T2>
class unordered_map   //HashTable
{
    T1 first;
    T2 second;
    double load_factor;
    int bucket_size;
    Node<T1,T2>** bucket_arr;
    int filled_bucket_size;
public:
    unordered_map()
    {
        load_factor=0.0;
        bucket_size=111111;
        bucket_arr=new Node<T1,T2>*[111111];
        filled_bucket_size=0;
    }
    void insert(const Pair<T1,T2> &);
    void Extend_bucket(int);
    T2& operator[](T1);
    int bucket(T1 key){ return key%bucket_size;}
    int bucket_count(){ return 111111;}
    double load(){return load_factor;}
};


template <typename T1,typename T2>
void unordered_map<T1,T2>::insert(const Pair<T1,T2> & pr)
{
    /*if(load_factor==1.0)
            Extend_bucket(2*bucket_size);*/
    Node<T1,T2>* nd=new Node<T1,T2>(pr.first,pr.second);
    first=pr.first;
    second=pr.second;
    if(bucket_arr[first%bucket_size]==NULL)
        bucket_arr[first%bucket_size]=nd;
    else
    {
        nd->setnext(bucket_arr[first%bucket_size]);
        bucket_arr[first%bucket_size]=nd;
    }
    filled_bucket_size++;
    load_factor=(double)filled_bucket_size/bucket_size;
}

template <typename T1,typename T2>
T2& unordered_map<T1,T2>::operator[](T1 key)
{
    int index;
    index=key%bucket_size;
    Node<T1,T2>* tmp=bucket_arr[index];
    int flg=0;
    while(tmp!=NULL)
    {
        if(tmp->getkey()==key)
            {
                flg=1;
                break;
            }
        tmp = tmp->next;
    }
    if(flg==1)
    return tmp->value;

    Node<T1,T2>* nd=new Node<T1,T2>(key,'\0');

    first=key;
    second='\0';
    if(bucket_arr[first%bucket_size]==NULL)
        bucket_arr[first%bucket_size]=nd;
    else
    {
        nd->setnext(bucket_arr[first%bucket_size]);
        bucket_arr[first%bucket_size]=nd;
    }
    filled_bucket_size++;
    load_factor=(double)filled_bucket_size/bucket_size;

    return nd->value;
}

/*template <typename T1,typename T2>
void unordered_map<T1,T2>::Extend_bucket(int new_size)
{
    Node<T1,T2>** newBuck_arr;
    newBuck_arr=new Node<T1,T2>*[new_size];
    int prev_size=new_size/2;
    int ind=0;
    while(ind<prev_size)
    {
        if(bucket_arr[ind]!=NULL)
        {
            Node<T1,T2>* tr=bucket_arr[ind];
            T1 new_key=tr->getkey();
            newBuck_arr[new_key%new_size]=tr;
        }
    }
    if(bucket_arr!=NULL)
        delete bucket_arr;
    bucket_arr=newBuck_arr;
    bucket_size=new_size;
    filled_bucket_size=prev_size;
    load_factor=(double)filled_bucket_size/bucket_size;
}
*/
