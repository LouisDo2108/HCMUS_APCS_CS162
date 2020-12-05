#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

int main()
{
	Node* head1 = nullptr, *head2 = nullptr;
	ifstream fi;
	ofstream fo;
	initLinkedlist(fi, head1, head2);
	two_into_one(fo, head1, head2);
	delLinkedlist(head1);
	delLinkedlist(head2);
	return 0;
}