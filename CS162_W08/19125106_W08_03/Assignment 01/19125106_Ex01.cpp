#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

int main()
{
	Node* head = nullptr;
	ifstream fi;
	ofstream fo;
	int x;
	initLinkedlist(fi, head);
	cout << "Enter the value x to remove all from the linked list: ";
	cin >> x;
	remove_all_x(head, head, head, x);
	output(fo, head);
	delLinkedlist(head);
	return 0;
}