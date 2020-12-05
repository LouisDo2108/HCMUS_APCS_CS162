#pragma once
#include <iostream>
#include <fstream>

using namespace std;

#ifndef _Header_H_
#define _Header_H_

struct Circles
{
	int x, y;
	double r;
};

void input_circles(ifstream& f, char name[], Circles circles[], int& n);
double sum_area(Circles circles[], int& n);
void output_sum_area(ofstream&, char name[], double result);

#endif