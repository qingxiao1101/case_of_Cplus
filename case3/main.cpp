#include <iostream>
#include <string>
#include <vector>
#include "intset.h"

using namespace std;


int main()
{
	Intset test;
	int array1[4] = {7,2,3,4};
	int array2[5] = {2,3,9,5,6};
	test.set_A(array1,4);
	test.set_B(array2,5);
	test.AB_and();
	test.AB_or();
	return 0;
}






