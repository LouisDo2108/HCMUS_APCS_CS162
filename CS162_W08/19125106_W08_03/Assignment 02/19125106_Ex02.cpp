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
	Node* cur = head;
	remove_duplicate_x(head, head, head->next, head);
	output(fo, head);
	delLinkedlist(head);
	return 0;
}