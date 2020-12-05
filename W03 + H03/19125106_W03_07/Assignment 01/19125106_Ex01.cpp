#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	int num = 9;
	int *ptrNum = &num;
	addOne(ptrNum);
	return 0;
}