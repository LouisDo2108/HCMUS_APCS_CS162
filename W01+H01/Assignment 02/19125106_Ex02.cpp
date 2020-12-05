#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

using namespace std;

int main()
{
	int n;
	double result[100];
	Fraction frac[100];
	char inputfilename[10] = "input.txt";
	char outputfilename[20] = "output.txt";
	ofstream fo;
	ifstream fi;

	input_fraction(fi, frac, inputfilename, n);
	sort_array(frac, result, n);
	output_fraction(fo, outputfilename, result, n);

	return 0;
}