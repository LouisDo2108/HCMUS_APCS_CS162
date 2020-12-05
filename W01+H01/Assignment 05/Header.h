#pragma once
#include <iostream>
#include <fstream>

using namespace std;

#ifndef _Header_H_
#define _Header_H_

struct Date
{
	int year, month, date;
};

void input_date(ifstream& f, char name[], Date date[], int& n);
void date_sort(Date date[], int& n);
void output_date(ofstream& f, char name[], Date date[], int& n);

#endif