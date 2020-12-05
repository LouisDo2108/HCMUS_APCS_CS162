#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

int main()
{
	Node* in = nullptr, * out = nullptr;
	ifstream fi;
	ofstream fo;
	initLinkedlist(fi, in);
	sum(in, out, out, 0);
	output(fo, out);
	delLinkedlist(in);
	delLinkedlist(out);
	return 0;
}