#include <iostream>
#include <fstream>
#include <algorithm>
#include "Header.h"

using namespace std;

void input_date(ifstream& f, char name[], Date date[], int& n)
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
			f >> date[i].year;
			f >> date[i].month;
			f >> date[i].date;
		}
		f.close();
	}
}

bool compare(const Date& d1, const Date& d2)
{
	if (d1.year < d2.year)
		return true;
	if (d1.year == d2.year && d1.month < d2.month)
		return true;
	if (d1.year == d2.year && d1.month < d2.month && d1.date < d2.date)
		return true;
	
	return false;
}

void date_sort(Date date[], int& n)
{
	sort(date, date + n, compare);
	return;
}
void output_date(ofstream& f, char name[], Date date[], int& n)
{
	f.open(name);

	if (!f.is_open())
	{
		cout << "Can not open the text file." << endl;
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			f << date[i].year << " ";
			f << date[i].month << " ";
			f << date[i].date << endl;
		}
		f.close();
	}
}