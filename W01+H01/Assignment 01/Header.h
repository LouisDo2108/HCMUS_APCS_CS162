#include <iostream>
#include <fstream>

using namespace std;
#pragma once

#ifndef _Header_H_
#define _Header_H_

struct Fraction
{
	double nom, denom;
};

void input_fraction(ifstream& f, Fraction frac[], char name[], int& n);
double find_max(Fraction frac[], int& n);
void output_fraction(ofstream& f, char name[], double result);

#endif