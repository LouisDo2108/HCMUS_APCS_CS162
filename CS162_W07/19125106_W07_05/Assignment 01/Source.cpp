#include <iostream>
#include "Header.h"

using namespace std;

//1
double Fibonacci(int n, int*& fibo)
{
	if (n == 0 || n == 1)
		return 1;
	fibo[n] = Fibonacci(n - 1, fibo) + Fibonacci(n - 2, fibo);
	if (fibo[n] != 0) 
		return fibo[n];
	else 
		return Fibonacci(n - 1, fibo) + Fibonacci(n - 2, fibo);
}
//1

//2
int x(int n)
{
	if (n == 0)
		return 1;
	return x(n - 1) + y(n - 1);
}

int y(int n)
{
	if (n == 0)
		return 0;
	return 3 * x(n-1) + 2 * y(n-1);
}

int xprime(int n, int*& dpx, int*& dpy)
{
	if (n == 0)
		return 1;
	dpx[n - 1] = xprime(n - 1, dpx, dpy);
	if (dpx[n] > -1)
		return dpx[n];
	else
		return xprime(n - 1, dpx, dpy) + yprime(n - 1, dpx, dpy);
}

int yprime(int n, int*& dpx, int*& dpy)
{
	if (n == 0)
		return 0;
	dpy[n - 1] = yprime(n - 1, dpx, dpy);
	if (dpy[n] > -1)
		return dpy[n];
	else
		return 3 * xprime(n - 1, dpx, dpy) + 2 * yprime(n - 1, dpx, dpy);
}
//2

//3
int X(int n, int*& dpX)
{
	if (n == 0) return 1;
	if (dpX[n] != 0) return dpX[n];
	for (int i = n; i >= 1; --i)
		dpX[n] += i * i * X(i - 1, dpX);
	return dpX[n];
}
//3

//4
int Cnk(int n, int k)
{
	if (k == 0 || k == n)
		return 1;
	return Cnk(n - 1, k) + Cnk(n - 1, k - 1);
}
//4

//5
void toBinary(int x)
{		
	if (x == 0)
		return;
	toBinary(x / 2);
	cout << x % 2;
}
//5

//6
int sumOfDigits(int x)
{
	if (x == 0) return 0;
	return (x % 10) + sumOfDigits(x / 10);
}
//6