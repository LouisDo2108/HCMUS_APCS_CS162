#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

int main()
{
	int loopdata = INT_MIN;
	bool check = false;
	Node* head = nullptr, *tail = nullptr;
	ifstream fi;
	ofstream fo;
	initLinkedlist(fi, head, check, tail);
	check_loop(fo, head, check);
	delLinkedlist(head, check, tail);
	return 0;
}