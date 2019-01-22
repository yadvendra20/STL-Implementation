#include<iostream>
using namespace std;
template <typename T>
void swap(T *a,T *b)
{
    T tmp=*a;
    *a=*b;
    *b=tmp;
}
template <typename T>
void pivot(T *i,T *j)
{
    if(*i>*j)
        swap(i,j);
}
template <typename T>
T* partition(T *i,T *j)
{
    T *p=i;
    do {
        do {
            ++i;
        } while(*i<*p);
        do {
            --j;
        } while(*j>*p);
        if(i<j)
            swap(i,j);
    } while(i<j);
    swap(j,p);
    return j;
}
template <typename T>
void qsort(T *i,T *j)
{
    T *p=NULL;
    if(i<j)
    {
        pivot(i,j);
        p=partition(i,j);
        qsort(i,p-1);
        qsort(p+1,j);
    }
}
template <typename T>
void sort(T *st,T *en)
{
    T *i=st,*j=en-1;
    qsort(i,j);
}
template<typename T>
bool bsearch(T *i,T *j,T sv)
{
    if(i>j)
        return false;
    T *mid;
    mid=i+(j-i)/2;
    if(*mid==sv)
        return true;
    if(sv<*mid)
        j=mid-1;
    else
        i=mid+1;
    return bsearch(i,j,sv);
}
template <typename T>
bool binary_search(T *st,T *en,T sv)
{
    T *i=st,*j=en-1;
    if(bsearch(i,j,sv))
        return true;
    return false;
}
template <typename T>
void reverse(T *st,T *en)
{
    T *i=st,*j=en-1;
    T tmp;
    for(;i<j;i++,j--)
    {
        tmp=*i;
        *i=*j;
        *j=tmp;
    }
}
template <typename T>
T* max_element(T *st,T *en)
{
    T *mx=st,*i=st;
    i++;
    for(;i!=en;i++)
    {
        if(*i>*mx)
            mx=i;
    }
    return mx;
}
template <typename T>
T* min_element(T *st,T *en)
{
    T *mn=st,*i=st;
    i++;
    for(;i!=en;i++)
    {
        if(*i<*mn)
            mn=i;
    }
    return mn;
}
template <typename T>
T accumulate(T *st,T *en,T insum)
{
    T *i=st;
    for(;i!=en;i++)
        insum+=*i;
    return insum;
}
template <typename T>
int count(T *st,T *en,T el)
{
    T *i=st;
    int cnt=0;
    for(;i!=en;i++)
    {
        if(*i==el)
            cnt++;
    }
    return cnt;
}
template <typename T>
T* find(T *st,T *en,T el)
{
    T *i=st;
    for(;i!=en;i++)
    {
        if(*i==el)
            break;
    }
    return i;
}
template <typename T>
int distance(T *st,T *pos)
{
    return pos-st;
}
template <typename T>
bool next_permutation(T *st,T *en)
{
    if (st == en)
                return false;

        T* i = st;
        ++i;
        if (i == en)
                return false;

        i = en;
        --i;

        while (true)
        {
                T* j = i;
                --i;

                if (*i < *j)
                {
                        T* k = en;

                        while (!(*i < *--k))
                                ;

                        iter_swap(i, k);
                        reverse(j, en);
                        return true;
                }

                if (i == st)
                {
                        reverse(st, en);
                        return false;
                }
        }
}
