#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	int n;
	cout << "Input the chess size: n x n: ";
	cin >> n;

	bool* column = new bool[n];
	int* queens = new int[n];
	for (int i = 0; i < n; ++i)
	{
		queens[i] = -1;
		column[i] = false;
	}

	bool* ld = new bool[(2 * n) - 1], * rd = new bool[(2 * n) - 1];
	for (int i = 0; i < (2 * n - 1); ++i)
	{
		ld[i] = false;
		rd[i] = false;
	}

	if (n == 2)
		queens[0] = 0;
	else if (n == 3)
	{
		queens[0] = 1;
		queens[2] = 0;
	}
	else
		solveNQueen(queens, column, ld, rd, 0, n);

	delete[] column;
	delete[] ld;
	delete[] rd;
	delete[] queens;
	return 0;
}