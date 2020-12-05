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
	list_to_num(fo, head);
	delLinkedlist(head);
	return 0;
}