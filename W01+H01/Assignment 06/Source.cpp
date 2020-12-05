#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

using namespace std;

void input_product(ifstream& f, Products product[], char fname[], int& n)
{
	f.open(fname);

	if (!f.is_open())
	{
		cout << "Can not open the text file." << endl;
	}
	else
	{
		f >> n;

		for (int i = 0; i < n; ++i) {
			f >> product[i].id;
			f.ignore(1);
			f.getline(product[i].name, 100);
			f >> product[i].stock;
			f >> product[i].price;
		}

		f.close();
	}

}

int calc(Products product[], int& n)
{
	int result = 0;
	for (int i = 0; i < n; ++i) {
		result += product[i].stock * product[i].price;
	}
	return result;
}

void output_money(ofstream& f, char fname[], double result)
{
	f.open(fname);

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