#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	Queue s;
	init(s, 10);
	cout << "size: " << size(s) << endl;

	for (int i = 0; i < 11; ++i)
		enqueue(s, i);

	for (int i = 0; i < 10; ++i)
		cout << s.data[i] << " ";
	cout << endl;

	if (isEmpty(s))
		cout << "Queue is emtpy" << endl;
	else
		cout << "Queue is not emtpy" << endl;

	cout << "Dequeue: ";
	for (int i = 0; i < 5; ++i)
		cout << dequeue(s) << " ";
	cout << endl;

	enqueue(s, 5);

	for (int i = 0; i < 10; ++i)
		cout << s.data[i] << " ";
	cout << endl;

	empty(s);

	if (isEmpty(s))
		cout << "Queue is emtpy" << endl;
	else
		cout << "Queue is not emtpy" << endl;

	return 0;
}