#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	if (argc >= 2)
	{
		string source = argv[2], destination = argv[4];
		merge(source, destination);
	}
	else cout << "Wrong arguments" << endl;
	return 0;
}