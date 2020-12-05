#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include "Header.h"

using namespace std;

void input_oxy(ifstream& f, Oxy oxy[], char name[], int& n)
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
			f >> oxy[i].x;
			f >> oxy[i].y;
		}

		f.close();
	}
	return;
}

void sort_oxy(Oxy oxy[], double result[], int& n)
{
	double temp_result;
	for (int i = 0; i < n; ++i)
	{
		temp_result = sqrt(pow(oxy[i].x, 2) + pow(oxy[i].y, 2));
		result[i] = temp_result;
	}

	sort(result, result + n);
	return;
}

void output_oxy(ofstream& f, char name[], double result[], int& n)
{
	f.open(name);

	if (!f.is_open())
	{
		cout << "Can not open the text file." << endl;
	}
	else
	{
		for (int i = n - 1; i >= 0; --i)
			f << result[i] << endl;

		f.close();
	}
	return;
}