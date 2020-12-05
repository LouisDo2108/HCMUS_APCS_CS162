#include <iostream>

using namespace std;

int x(int n);
int y(int n);

int evenCount(int *arr, int i, int count, int size)
{
    if (i >= size)
        return count;
    if (arr[i] % 2 == 0)
        ++count;
    evenCount(arr, i + 1, count, size);
}

int fibo(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

int nested(int n)
{
    if (n > 0)
        return n - 1;
    return nested(nested(n + 2));
}

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
    return 3 * x(n - 1) + 2 * y(n - 1);
}

int main()
{
    return 0;
}
