#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main()
{
	Stack op, num, value;
	string x = "10 + 200*(3/(4-7))", p;
	cout << "This is the calculation: " << x << endl;
	polish(x, p, op);
	cout << "This is polished version: " << p << endl;
	cout << x << " = " << output(p, num, value);
	return 0;
}