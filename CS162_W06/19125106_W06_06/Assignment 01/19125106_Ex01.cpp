#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	Stack s;
	init(s, 10);

	cout << "size: " << size(s) << endl;

	for (int i = 1; i <= 10; ++i)
		push(s, i);

	for (int i = 0; i < 5; ++i)
		cout << pop(s) << endl;

	for (int i = 0; i < 10; ++i)
		cout << s.data[i] << " ";
	cout << endl;

	empty(s);

	for (int i = 0; i < 10; ++i)
		cout << s.data[i] << " ";

	if (isEmpty(s))
		cout << "\nStack is empty" << endl;
	else cout << "\nStack is not empty" << endl;

	delete [] s.data;
	return 0;
}