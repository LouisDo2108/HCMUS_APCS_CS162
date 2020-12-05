#include <iostream>
#include "Header.h"

using namespace std;

void displayChess(int* queens, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (queens[i] != -1 && queens[i] == j)
				cout << "Q ";
			else
				cout << "x ";
		}
		cout << endl;
	}
	cout << endl;
}

bool isSafe(bool*& column, bool*& ld, bool*& rd, int r, int c, int n)
{
	if (column[c])
		return false;

	//Check left and right diagonal
	if (ld[r + c] || rd[r - c + n - 1])
		return false;
	return true;
}

void solveNQueen(int*& queens, bool*& column, bool*& ld, bool*& rd, int r, int n)
{
	if (r >= n)
		displayChess(queens, n);
	for (int i = 0; i < n; ++i)
	{
		if (isSafe(column, ld, rd, r, i, n))
		{
			ld[r + i] = true;
			rd[r - i + n - 1] = true;
			column[i] = true;
			queens[r] = i;
			solveNQueen(queens, column, ld, rd, r + 1, n);
			ld[r + i] = false;
			rd[r - i + n - 1] = false;
			column[i] = false;
			queens[r] = -1;
		}
	}
	return;
}