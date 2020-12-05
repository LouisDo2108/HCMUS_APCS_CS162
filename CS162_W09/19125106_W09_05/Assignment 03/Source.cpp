#include "Header.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void copy(string source, string destination)
{
	ifstream fi;
	ofstream fo;

	int i = 0, len = source.length(), index;
	while (source[len - i] != '\\' && i < len) ++i;

	index = i;

	for (i = len - index; i < len; ++i)
		destination += source[i];

	fi.open(source, ios::binary);
	fo.open(destination, ios::binary);
	if(!fi.is_open() && !fo.is_open())
		cout << "Can't open the source file" << endl;
	else
	{
		char temp[1001];
		while (!fi.eof())
		{
			fi.read(temp, 1000);
			fo.write(temp, fi.gcount());
		}
		cout << "Copy successfully!" << endl;
	}
	fi.close();
	fo.close();

	return;
}
