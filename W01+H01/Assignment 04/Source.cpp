#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

void input_circles(ifstream& f, char name[], Circles circles[], int& n)
{
	f.open(name);

	if (!f.is_open())
	{
		cout << "Can not open the text file." << endl;
	}
	else
	{
		f >> n;

		for (int i = 0; i < n; ++i)
		{
			f >> circles[i].x;
			f >> circles[i].y;
			f >> circles[i].r;
		}

		f.close();
	}
}
double sum_area(Circles circles[], int& n)
{
	double temp_result, sum = 0;
	const double pi = 3.14;
	for (int i = 0; i < n; ++i)
	{
		temp_result = pi * circles[i].r * circles[i].r;
		sum += temp_result;
	}
	
	return sum;
}
void output_sum_area(ofstream& f, char name[], double result)
{
	f.open(name);

	if (!f.is_open())
	{
		cout << "Can not open the text file." << endl;
	}
	else
	{
		f << result;
		f.close();
	}
	return;
}