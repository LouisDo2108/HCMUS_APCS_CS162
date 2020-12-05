#include <iostream>
#include <fstream>
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


double find_max(Fraction frac[], int& n)
{
	double m = LLONG_MIN, frac_result;
	for (int i = 0; i < n; ++i)
	{
		frac_result = frac[i].nom / frac[i].denom;
		if (frac_result > m)
			m = frac_result;
	}
	return m;
}

void output_fraction(ofstream& f, char name[], double result)
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