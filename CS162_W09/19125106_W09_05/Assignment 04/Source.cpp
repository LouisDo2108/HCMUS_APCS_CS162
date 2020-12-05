#include "Header.h"
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void split(string source, string destination, string mode, int x)
{
	ifstream fi;
	ofstream fo;
	string sfilename = "";
	int i = 0, len = source.length(), index;
	while (source[len - i] != '\\' && i < len) ++i;

	index = i;

	for (i = len - index; i < len; ++i)
		destination += source[i];

	i = 1;
	fi.open(source, ios::binary|ios::ate);
	if (!fi.is_open())
		cout << "Can't open the source file" << endl;
	else
	{	
		char* temp;
		if (mode == "-numpart")
		{
			const int filesize = fi.tellg();
			const int size = filesize / x;
			temp = new char[size*2 + 1];
			fi.seekg(0, ios::beg);
			while (!fi.eof())
			{
				if (i < 10)
					sfilename = destination + ".part0" + to_string(i);
				else sfilename = destination + ".part" + to_string(i);

				if (i == x)
					fi.read(temp, size + (filesize - (i - 1) * size));
				else
					fi.read(temp, size);

				fo.open(sfilename, ios::binary);
				fo.write(temp, fi.gcount());
				fo.close();
				++i;
			}
			cout << "Splited successfully!" << endl;
		}
		else
		{
			const int size = x;
			temp = new char[size + 1];
			fi.seekg(0, ios::beg);

			while (!fi.eof())
			{
				if (i < 10)
					sfilename = destination + ".part0" + to_string(i);
				else sfilename = destination + ".part" + to_string(i);

				fi.read(temp, size);
				fo.open(sfilename, ios::binary);
				fo.write(temp, fi.gcount());
				fo.close();
				++i;
			}
			cout << "Splited successfully!" << endl;
		}
		fi.close();
		delete[] temp;
	}
	return;
}