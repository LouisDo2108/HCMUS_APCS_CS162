#include <iostream>
#include <fstream>

using namespace std;
#pragma once

#ifndef _Header_H_
#define _Header_H_

struct Oxy {
	int x, y;
};

void input_oxy(ifstream& f, Oxy oxy[], char name[], int& n);
void sort_oxy(Oxy oxy[], double result [], int& n);
void output_oxy(ofstream& f, char name[], double result[], int& n);

#endif
