#include <iostream>
#include <cstring>
#include "Header.h"

using namespace std;

bool isPalindrome(char* cstr)
{
	char* front = cstr;
	char* back = cstr + strlen(cstr) - 1;

	while (front < back)
	{
		if (*front != *back) return false;
		else
		{
			++front;
			--back;
		}
	}

	return true;
}