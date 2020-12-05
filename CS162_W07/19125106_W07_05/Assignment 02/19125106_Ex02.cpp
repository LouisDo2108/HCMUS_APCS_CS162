#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	char temp[500];
	cout << "Enter a string: ";
	cin.getline(temp, 500);
	char* string = new char[strlen(temp) + 1];
	strcpy_s(string, strlen(temp) + 1, temp);
	if (isPalindrome(0, strlen(temp) - 1, string))
		cout << "It is a palindrome.";
	else
		cout << "It is NOT a palindrome.";
	return 0;
}