#include <iostream>
#include "Header.h"

using namespace std;

void addOne(int* ptrNum)
{
	++*ptrNum;
	cout << *ptrNum;
	return;
}