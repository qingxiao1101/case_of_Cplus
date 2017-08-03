#include <iostream>
#include <string>
#include <vector>
#include "intset.h"

using namespace std;

void Intset::set_A(int array[],int n)
{
//	vector<int>::iterator iter = A.begin();
	for(int i=0;i<n;++i)
		A.push_back(array[i]);
}
void Intset::set_B(int array[],int n)
{
	for(int i=0;i<n;++i)
		B.push_back(array[i]);
}


vector<int> Intset::AB_and(void)
{
	vector<int> v;
	vector<int>::iterator iter_A;
	vector<int>::iterator iter_B;
	for(iter_A=A.begin();iter_A!=A.end();++iter_A)
		for(iter_B=B.begin();iter_B!=B.end();++iter_B)
			if(*iter_A == *iter_B)
				v.push_back(*iter_A);
	return v;
}

vector<int> Intset::AB_or(void)
{
	
	vector<int> v(B);
	vector<int>::iterator iter_A;
	vector<int>::iterator iter_B;
	for(iter_A=A.begin();iter_A!=A.end();++iter_A)
	{
		int flag = 0,tmp;
		for(iter_B=B.begin();iter_B!=B.end();++iter_B)
			if(*iter_A == *iter_B)
				flag = 1;
			else ;
		if(flag==0)
			v.push_back(*iter_A);
	}
	return v;
}

