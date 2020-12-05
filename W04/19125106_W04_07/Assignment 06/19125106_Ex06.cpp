#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

int main()
{
	Node* in = nullptr, *out = nullptr;
	ifstream fi;
	ofstream fo;
	initLinkedlist(fi, in);
	sum(fo, in, out);
	delLinkedlist(in);
	delLinkedlist(out);
	return 0;
}