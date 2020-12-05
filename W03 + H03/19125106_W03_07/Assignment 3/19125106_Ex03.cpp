#include <iostream>
#include <cstring>
#include "Header.h"

using namespace std;

int main()
{
	char input[200];
	cin.getline(input, 200);
	char* cstr = new char[strlen(input) + 1];
	strcpy(cstr, input);
	cout << isPalindrome(cstr) << endl;
	delete [] cstr;
	return 0;
}