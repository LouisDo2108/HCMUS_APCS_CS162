#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

using namespace std;

int main()
{
	int n;
	double m;
	Fraction frac[100];
	char inputfilename[10] = "input.txt";
	char outputfilename[20] = "output.txt";
	ofstream fo;
	ifstream fi;

	input_fraction(fi, frac, inputfilename, n);
	m = find_max(frac, n);
	output_fraction(fo, outputfilename, m);

	return 0;
}