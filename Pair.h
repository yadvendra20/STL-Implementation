#include<iostream>
#include<cstdlib>
using namespace std;
template <typename T1,typename T2>
struct Pair
{
    T1 first;
    T2 second;
    Pair()
    {
        first=second=0;
    }
    Pair(T1 val1,T2 val2)
    {
        first=val1;
        second=val2;
    }
    Pair(const Pair<T1,T2> & anpr)
    {
        first=anpr.first;
        second=anpr.second;
    }
    Pair Make_pair(T1,T2);
    Pair operator=(const Pair<T1,T2> & pr)
    {
        first=pr.first;
        second=pr.second;
        return *this;
    }
    bool operator==(const Pair<T1,T2> & pr)
    {
        return (first==pr.first && second==pr.second);
    }
    bool operator!=(const Pair<T1,T2> & pr)
    {
        return !(*this==pr);
    }
    bool operator>(const Pair<T1,T2> & pr)
    {
        return (this->first > pr.first && this->second > pr.second);  //((this->first > pr.first || !(pr.first > this->first)) && this->second > pr.second);
    }
    bool operator<(const Pair<T1,T2> & pr)
    {
        return (this->first < pr.first && this->second < pr.second);  //((this->first > pr.first || !(pr.first > this->first)) && this->second > pr.second);
    }
    bool operator>=(const Pair<T1,T2> & pr)
    {
        return !(this->first < pr.first && this->second < pr.second);  //((this->first > pr.first || !(pr.first > this->first)) && this->second > pr.second);
    }
    bool operator<=(const Pair<T1,T2> & pr)
    {
        return !(this->first > pr.first && this->second > pr.second);  //((this->first > pr.first || !(pr.first > this->first)) && this->second > pr.second);
    }
    Pair Swap(Pair<T1,T2> & pr)
    {
        T1 tmp1;
        T2 tmp2;
        tmp1=first;
        first=pr.first;
        pr.first=tmp1;
        tmp2=second;
        second=pr.second;
        pr.second=tmp2;
        return *this;
    }
    void Swap(Pair<T1,T2> & ,Pair<T1,T2> & );
};
template <typename T1,typename T2>
Pair<T1,T2> Make_pair(T1 val1,T2 val2)
{
    return Pair<T1,T2>(val1,val2);
}
template <typename T1,typename T2>
void Swap(Pair<T1,T2> & pr1,Pair<T1,T2> & pr2)
{
    pr1.Swap(pr2);
}
