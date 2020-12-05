#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

int main()
{
	Node* head = nullptr;
	ifstream fi;
	ofstream fo;
	int x = INT_MIN;
	initLinkedlist(fi, head);
	remove_all_x(fo, head, x);
	delLinkedlist(head);
	return 0;
}