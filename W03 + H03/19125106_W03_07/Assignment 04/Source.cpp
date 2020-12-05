#include <iostream>
#include "Header.h"

using namespace std;

int findMode(int* arr, int& n)
{
	int mode = *arr, count = 1;

	for (int i = 0; i < n; ++i)
	{
		int tempmode = *(arr + i), tempcount = 1;

		for (int j = 0; j < n; ++j)
		{
			if (j == i) continue;
			if (*(arr + j) == tempmode)
				++tempcount;
		}

		if (tempcount > count)
		{
			mode = tempmode;
			count = tempcount;
		}
	}

	if (count == 1) return -1;
	else return mode;
}