#include <iostream>
#include "Header.h"

int main()
{
	Stack A, B, C;
	int n;
	cout << "Enter the number of disks: ";
	cin >> n;
	init(A, n);
	displayAll(A, B, C);
	tower(n, A, C, B, A, B, C);
	removeAll(A, B, C);
	return 0;
}