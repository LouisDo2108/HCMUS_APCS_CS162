#include "Header.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int choice = 1;
    while (choice != 0)
    {
        cout << "1. Save an array to a binary file." << endl;
        cout << "2. Loads an array, output median." << endl;
        cout << "Enter 1, 2 to run a feature or 0 to exit: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            save_array();
            break;
        case 2:
            median();
            break;
        default:
            break;
        }
    }
    return 0;
}