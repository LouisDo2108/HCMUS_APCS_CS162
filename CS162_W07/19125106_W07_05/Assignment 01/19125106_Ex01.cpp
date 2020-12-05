#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	int n, k;
	cout << "1.Fibonacci, enter a natural number: ";
	cin >> n;
	int* fibo = new int[n]();
	cout << Fibonacci(n, fibo) << endl;

	cout << "2. x(n), y(n), enter n: ";
	cin >> n;
	int* dpx = new int[n], * dpy = new int[n];
	for (int i = 0; i < n; ++i)
	{
		dpx[i] = -1;
		dpy[i] = -1;
	}
	cout << "x(" << n << ") = " << x(n) << endl;
	cout << "y(" << n << ") = " << y(n) << endl;
	cout << "xprime(" << n << ") = " << xprime(n, dpx, dpy) << endl;
	cout << "yprime(" << n << ") = " << yprime(n, dpx, dpy) << endl;

	cout << "3.x(n), enter n: ";
	cin >> n;
	int* dpX = new int[n + 1]();
	cout << "x(" << n << ") = " << X(n, dpX) << endl;

	cout << "4.C(n, k), enter n and k where 1 < k < n respectively: " << endl;
	cout << "n = ";
	cin >> n;
	cout << "k = ";
	cin >> k;
	cout << "C(" << n << ", " << k << ") = " << Cnk(n, k) << endl;

	cout << "5.To Binary, enter x: ";
	cin >> n;
	cout << n << " in bin = "; 
	toBinary(n);

	cout << "\n6. sumOfDigits, enter x: ";
	cin >> n;
	cout << "The sum of digits of " << n << " is " << sumOfDigits(n);
	
	delete[] dpX;
	delete[] dpy;
	delete[] dpx;
	delete[] fibo;
	return 0;
}