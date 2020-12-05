#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

int main()
{
	int n, result;
	Students student[100];
	char inputfilename[10] = "input.txt";
	char outputfilename[20] = "output.txt";
	ifstream fi;
	ofstream fo;

	input_students(fi, inputfilename, student, n);
	result = find_max_gpa(student, n);
	output_students(fo, outputfilename, student[result]);

	return 0;
}