#include <iostream>
#include "Header.h"

using namespace std;

bool isPalindrome(int l, int r, char* s)
{
	if (l >= r)
		return true;
	if (s[l] != *(s + r))
		return false;
	isPalindrome(l + 1, r - 1, s);
}