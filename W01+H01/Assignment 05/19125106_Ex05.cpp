#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

int main()
{
	int n;
	Date date[100];
	char inputfilename[10] = "input.txt";
	char outputfilename[20] = "output.txt";
	ifstream fi;
	ofstream fo;

	input_date(fi, inputfilename, date, n);
	date_sort(date, n);
	output_date(fo, outputfilename, date, n);

	return 0;
}