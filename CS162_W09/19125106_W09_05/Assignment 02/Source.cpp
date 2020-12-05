#include "Header.h"
#include <iostream>
#include <fstream>

using namespace std;

void inputDate()
{
	ofstream fo;
	int* date_arr;

	fo.open("input.bin");;
	if (!fo.is_open())
	{
		cout << "Can't open the input file" << endl;
	}
	else
	{
		int n, x;
		cout << "Input the number of dates: ";
		cin >> n;
		date_arr = new int[3 * n];
		for (int i = 0; i < n*3; i += 3)
		{
			while (1)
			{
				cout << "Date: ";
				cin >> x;
				if (x > 0 && x <= 31)
					break;
			}
			date_arr[i] = x;
			while (1)
			{
				cout << "Month: ";
				cin >> x;
				if (x > 0 && x <= 12)
					break;
			}
			date_arr[i + 1] = x;
			cout << "Year: ";
			cin >> date_arr[i + 2];
		}
		fo.write((char*)&n, sizeof(n));
		fo.write((char*)date_arr, n * 3 * 4);
		delete[] date_arr;
	}
	return;
}

void outputDate()
{
	ifstream fi;
	int n, *date_arr;
	fi.open("input.bin");
	if (!fi.is_open())
		cout << "Can't open the input file";
	else
	{
		fi.read((char*)&n, sizeof(n));
		date_arr = new int[3 * n];
		fi.read((char*)date_arr, n * 3 * 4);

		int year = 0, month = 0, date = 0;
		int index = 0;
		
		for (int i = 0; i < n*3; i += 3)
		{
			int d = date_arr[i];
			int m = date_arr[i + 1];
			int y = date_arr[i + 2];

			if (y > year || (y == year && m > month) || (y == year && m == month && d > date))
			{
				year = y;
				month = m;
				date = d;
				index = i;
			}
		}
		cout << date_arr[index] << "/" << date_arr[index + 1] << "/" << date_arr[index + 2] << endl;
		delete[] date_arr;
	}
	return;
}