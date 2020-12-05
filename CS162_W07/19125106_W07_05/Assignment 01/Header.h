#pragma once
#ifndef _Header_H_
#define _Header_H_
#include <iostream>

using namespace std;

double Fibonacci(int n, int*& fibo);

int x(int n);
int y(int n);
int xprime(int n, int*& dpx, int*& dpy);
int yprime(int n, int*& dpx, int*& dpy);
int X(int n, int*& dpX);
int Cnk(int n, int k);
void toBinary(int x);
int sumOfDigits(int x);
#endif