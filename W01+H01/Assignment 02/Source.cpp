#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include "Header.h"
using namespace std;

void input_fraction(ifstream& f, Fraction frac[], char name[], int& n)
{
	f.open(name);

	if (!f.is_open())
	{
		cout << "Can not open the text file." << endl;
	}
	else
	{
		f >> n;

		for (int i = 0; i < n; ++i) {
			f >> frac[i].nom;
			f >> frac[i].denom;
		}
		f.close();
	}
}

void sort_array(Fraction frac[], double result[], int& n) {
	double temp_result;
	for (int i = 0; i < n; ++i) {
		temp_result = frac[i].nom / frac[i].denom;
		result[i] = temp_result;
	}
	sort(result, result + n);
	return;
}

void output_fraction(ofstream& f, char name[], double result[], int& n)
{
	f.open(name);

	if (!f.is_open())
	{
		cout << "Can not open the text file." << endl;
	}
	else
	{
		for (int i = 0; i < n; ++i) {
			f << result[i] << endl;
		}
		f.close();
	}
	return;
}