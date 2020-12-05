#include <iostream>
#include "Header.h"

using namespace std;

void output(int* arr, int n, int size)
{
	if (n >= size)
		return;
	cout << *(arr + n) << " ";
	output(arr, n + 1, size);
}
void output_reversed(int* arr, int n, int size)
{
	if (n >= size)
		return;
	output_reversed(arr, n + 1, size);
	cout << *(arr + n) << " ";
}

int sum_positive(int* arr, int n, int size)
{
	if (n >= size)
		return 0;
	if (arr[n] < 0) return sum_positive(arr, n + 1, size);
	else return arr[n] + sum_positive(arr, n + 1, size);
}
int count_distinct(int* arr, int n, int size, int* distinct)
{
	if (n >= size)
	{
		int result = 0;
		for (int j = 0; j < size; ++j)
		{
			if (distinct[j] != INT_MIN)
				++result;
		}
		return result;
	}
	
	bool is_distinct = true;
	for (int i = 0; i < size; ++i)
	{
		if (distinct[i] == arr[n])
		{
			is_distinct = false;
			break;
		}
	}
	if (is_distinct)
		distinct[n] = arr[n];
	return count_distinct(arr, n + 1, size, distinct);
}
bool check_odd(int* arr, int n, int size)
{
	if (n >= size)
		return true;
	if (arr[n] % 2 == 0)
		return false;
	else return check_odd(arr, n + 1, size);
}

int max(int a, int b)
{
	if (a > b)
		return a;
	else return b;
}

int max_value(int* arr, int n, int size)
{
	if (n >= size)
		return 0;
	return max(arr[n], max_value(arr, n + 1, size));
}