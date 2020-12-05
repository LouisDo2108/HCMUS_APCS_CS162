#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

int main()
{
	Node* head = nullptr;
	ifstream fi;
	ofstream fo;
	initLinkedlist(fi, head);
	remove_duplicate_x(fo, head);
	delLinkedlist(head);
	return 0;
}