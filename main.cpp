#include<iostream>
#include"Modified_unordered_map.h"
using namespace std;
int main()
{
	unordered_map<char,int>u;
	u['A']++;
	cout<<u['A'];
}
