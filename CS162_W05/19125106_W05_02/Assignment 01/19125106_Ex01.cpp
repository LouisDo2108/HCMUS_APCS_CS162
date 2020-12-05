#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

int main()
{
	Node* head = nullptr, *tail = nullptr;
	ifstream fi;
	ofstream fo;
	initCircularLinkedList(fi, head, tail);
	removeDuplicate(fo, head, tail);
	deleteAll(head, tail);
	return 0;
}