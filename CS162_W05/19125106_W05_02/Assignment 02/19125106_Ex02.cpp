#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

int main()
{
	ifstream fi;
	ofstream fo;
	Node* head1 = nullptr, * head2 = nullptr;
	initDoublyLinkedList(fi, head1, head2);
	sum(fo, head1, head2);
	deleteAll(head1);
	deleteAll(head2);
	return 0;
}