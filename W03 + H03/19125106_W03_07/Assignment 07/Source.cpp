#include <iostream>
#include <fstream>
#include "Header.h"


using namespace std;

void read_correct_answers(ifstream& f, char* &canswers, int& n)
{
	f.open("CorrectAnswers.txt");
	if (!f.is_open())
	{
		cout << "Can not open the file";
	}
	else
	{
		f >> n;
		canswers = new char[n + 1];
		for (int i = 0; i < n; ++i)
			f >> *(canswers + i);
		f.close();
	}
	return;
}

void read_student_answers(ifstream& f, char* &sanswers, int& n)
{
	f.open("StudentAnswers.txt");
	if (!f.is_open())
	{
		cout << "Can not open the file";
	}
	else
	{
		f >> n;
		sanswers = new char[n + 1];
		for (int i = 0; i < n; ++i)
			f >> *(sanswers + i);
		f.close();
	}
	return;
}

void output_result(char* canswers, char* sanswers, int& n)
{
	int score = 0, count = 0, *wrong = new int[n];
	double percentage;
	for (int i = 0; i < n; ++i)
		if (*(sanswers + i) == *(canswers + i))
			++score;
		else
		{
			*(wrong + i) = 1;
			++count;
		}

	percentage = 1.0 * (n - count) / n * 100;
	cout << "The questions that student missed: ";
	for (int i = 0; i < n; ++i)
		if (*(wrong + i) == 1) cout << i + 1 << ", ";

	cout << endl;
	cout << "Total number of questions missed: " << count << endl;
	cout << "Percentage of questions answered correctly: " << percentage << "%" << endl;
	if (percentage >= 70)
		cout << "You passed!";
	else
		cout << "You failed!";

	delete [] wrong;
	return;
}