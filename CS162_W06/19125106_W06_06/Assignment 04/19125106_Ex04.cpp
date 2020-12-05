#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	Queue q;
	init(q, 10);
	cout << "size: " << q.size << endl;

	for (int i = 0; i < 11; ++i)
		enqueue(q, i);
	displayAll(q);

	if (isEmpty(q))
		cout << "Queue is emtpy" << endl;
	else
		cout << "Queue is not emtpy" << endl;

	cout << "Dequeue: ";
	for (int i = 0; i < 5; ++i)
		cout << dequeue(q) << " ";
	cout << endl;

	enqueue(q, 5);
	displayAll(q);

	empty(q);

	if (isEmpty(q))
		cout << "Queue is emtpy" << endl;
	else
		cout << "Queue is not emtpy" << endl;

	displayAll(q);
	return 0;
}