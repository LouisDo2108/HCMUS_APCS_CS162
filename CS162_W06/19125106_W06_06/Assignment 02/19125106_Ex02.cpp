#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	Stack s;
	init(s, 10);

	cout << "size: " << size(s) << endl;

	for (int i = 1; i <= 11; ++i)
		push(s, i);

	displayAll(s);
	
	cout << "\nPop: ";
	for (int i = 0; i < 5; ++i)
		cout << pop(s) << " ";
	cout << endl;

	displayAll(s);
	empty(s);

	if (isEmpty(s))
		cout << "\nStack is empty" << endl;
	else cout << "\nStack is not empty" << endl;

	return 0;
}