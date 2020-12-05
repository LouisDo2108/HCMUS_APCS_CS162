#include "Header.h"
#include <iostream>
#include <fstream>

using namespace std;

void save_array()
{
    ofstream fo;
    int x, n;

    cout << "Enter the array size: ";
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; ++i)
    {
        cout << "arr[" << i << "]: ";
        cin >> x;
        arr[i] = x;
    }

    fo.open("input.bin", ios::out | ios::binary);
    if (!fo.is_open())
        cout << "Can't open the input file." << endl;
    else
    {
        fo.write((char*)&n, 4);
        fo.write((char*)arr, 4 * n);
    }
    fo.close();

    delete[] arr;
    return;
}

void median()
{
    ifstream fi;
    streampos size;
    fi.open("input.bin", ios::in | ios::binary);
    if (!fi.is_open())
        cout << "Can't open the input file" << endl;
    else
    {
        int size = 0;
        fi.read((char*)&size, 4);
        fi.seekg(4, ios::beg);
        int* arr = new int[size];
        fi.read((char*)arr, size * 4);
        if (size % 2 != 0)
            cout << arr[size / 2] << endl;
        else
            cout << (arr[size / 2] + arr[size / 2 - 1]) / 2 << endl;
        delete[] arr;
    }
    fi.close();
    return;
}