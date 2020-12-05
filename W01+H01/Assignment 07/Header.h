#pragma once
#include <iostream>
#include <fstream>

using namespace std;

#ifndef _Header_H_
#define _Header_H_

struct Students
{
	int id;
	char fullname[100];
	double gpa;
};

void input_students(ifstream& f, char name[], Students student[], int& n);
int find_max_gpa(Students student[], int& n);
void output_students(ofstream& f, char name[], Students student);

#endif