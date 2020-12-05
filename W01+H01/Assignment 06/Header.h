#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#pragma once

#ifndef Header_H_
#define Header_H_

struct Products
{
	int id, stock, price;
	char name[100];
};

void input_product(ifstream& f, Products product[], char fname[], int& n);
int calc(Products product[], int& n);
void output_money(ofstream& f, char fname[], double result);

#endif