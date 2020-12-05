#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

int main()
{
	int n;
	double result;
	Circles circles[100];
	char inputfilename[10] = "input.txt";
	char outputfilename[20] = "output.txt";
	ifstream fi;
	ofstream fo;

	input_circles(fi, inputfilename, circles, n);
	result = sum_area(circles, n);
	output_sum_area(fo, outputfilename, result);

	return 0;
}