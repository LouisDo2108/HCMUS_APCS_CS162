#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	int* arr, n;
	cout << "Enter the number of elements in the array: ";
	cin >> n;
	arr = new int[n];
	cout << "Please input the array:" << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << "a[" << i << "]: ";
		cin >> arr[i];
	}
	cout << "The mode is: ";
	cout << findMode(arr, n);
	delete [] arr;
}