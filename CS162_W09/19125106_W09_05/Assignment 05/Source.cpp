#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

void merge(string source, string destination)
{
	ifstream fi;
	ofstream fo;

	string path = source, partfilepath, name = "", mergedname;
	int i = 0, len = source.length();
	for (const auto& entry : fs::directory_iterator(path))
	{
		partfilepath = entry.path().u8string();
		break;
	}
	for (i = len; i < partfilepath.length(); ++i)
	{
		if (partfilepath[i] == '.' && partfilepath[i + 1] == 'p')
			break;
		else name += partfilepath[i];
	}

	destination += name;

	fo.open(destination, ios::binary|ios::ate|ios::app);
	if (!fo.is_open())
		cout << "Can't open the output file" << endl;
	else
	{
		for (const auto& entry : fs::directory_iterator(path))
		{
			partfilepath = entry.path().u8string();

			fi.open(partfilepath, ios::binary | ios::ate);
			int size = (int)fi.tellg();
			char* temp = new char[size + 1];
			fi.seekg(0, ios::beg);
			fi.read(temp, size);
			fo.write(temp, fi.gcount());
			fi.close();
		}
		cout << "Merged successfully!" << endl;
	}
	fo.close();
	return;
}