#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

int main()
{
	ifstream f;
	int n;
	char* canswers, *sanswers;
	read_correct_answers(f, canswers, n);
	read_student_answers(f, sanswers, n);
	output_result(canswers, sanswers, n);
	delete[] canswers;
	delete[] sanswers;
	return 0;
}