#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

using namespace std;

int main()
{
	int n, money;
	Products product[100];
	ofstream fo;
	ifstream fi;
	char inputfilename[10] = "input.txt";
	char outputfilename[20] = "output.txt";

	input_product(fi, product, inputfilename, n);
	money = calc(product, n);
	output_money(fo, outputfilename, money);

	return 0;
}