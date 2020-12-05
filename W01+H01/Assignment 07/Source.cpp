#include <iostream>
#include <fstream>
#include <algorithm>
#include "Header.h"

using namespace std;

void input_students(ifstream& f, char name[], Students student[], int& n)
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
			f >> student[i].id;
			f.ignore(1);
			f.getline(student[i].fullname, 100);
			f >> student[i].gpa;
		}
		f.close();
	}
}

int find_max_gpa(Students student[], int& n)
{
	int temp_max_gpa = 0, temp_id, result;
	for (int i = 0; i < n; ++i)
	{
		if (student[i].gpa > temp_max_gpa){
			temp_max_gpa = student[i].gpa;
			temp_id = student[i].id;
			result = i;
		}
		if (student[i].gpa == temp_max_gpa && student[i].id < temp_id)
		{
			temp_id = student[i].id;
			result = i;
		}
	}
	return result;
}

void output_students(ofstream& f, char name[], Students student)
{
	f.open(name);

	if (!f.is_open())
	{
		cout << "Can not open the text file." << endl;
	}
	else
	{
		f << student.id << endl;
		f << student.fullname << endl;
		f << student.gpa << endl;
		f.close();
	}
}