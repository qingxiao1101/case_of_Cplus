#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef INTSET_H
#define INTSET_H

class Intset{
	vector<int> A;
	vector<int> B;
public:
	void set_A(int array[],int n);
	void set_B(int array[],int n);
	vector<int> AB_and(void);
	vector<int> AB_or(void);
};

#endif
