#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	int size, *arr, *distinct, x;

	cout << "Enter the array size: ";
	cin >> size;
	arr = new int[size];
	distinct = new int[size];
	for (int i = 0; i < size; ++i)
	{
		distinct[i] = INT_MIN;
		cout << "arr[" << i << "] = ";
		cin >> x;
		arr[i] = x;
	}

	cout << "Output in order: ";
	output(arr, 0, size);	
	cout << endl;

	cout << "Output in reversed order: ";
	output_reversed(arr, 0, size);
	cout << endl;

	cout << "Sum positive: ";
	cout << sum_positive(arr, 0, size) << endl;

	cout << "Count distinct values: ";
	cout << count_distinct(arr, 0, size, distinct) << endl;;

	cout << "Check only contains odd numbers: ";
	if (check_odd(arr, 0, size)) cout << "True" << endl;
	else cout << "False" << endl;

	cout << "Max value: " << max_value(arr, 0, size);

	delete[] distinct;
	delete[] arr;
	return 0;
}