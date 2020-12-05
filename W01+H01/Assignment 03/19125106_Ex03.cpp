#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

using namespace std;

int main()
{
	ofstream fo;
	ifstream fi;
	int n;
	double result[100];
	Oxy oxy[100];
	char inputfilename[10] = "input.txt";
	char outputfilename[20] = "output.txt";

	input_oxy(fi, oxy, inputfilename, n);
	sort_oxy(oxy, result, n);
	output_oxy(fo, outputfilename, result, n);

	return 0;
}