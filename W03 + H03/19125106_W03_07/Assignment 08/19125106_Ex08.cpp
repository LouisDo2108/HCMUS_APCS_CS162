#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	int** labs, lab, *station, id = 0, curLab = 0, curSta = 0, choice = 0, resultlab, resultstation;
	createLabs(labs, lab, station);
	display(labs, lab, station);
	while (1)
	{
		cout << "\nEnter 1: Log in" << endl;
		cout << "Enter 2: Log out" << endl;
		cout << "Enter 3: Search" << endl;
		cout << "Enter 4: Display the labs" << endl;
		cout << "Enter other to quit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			login(labs, id, curLab, curSta, lab, station);
			display(labs, lab, station);
			break;

		case 2:
			logout(labs, lab, station);
			display(labs, lab, station);
			break;
		
		case 3:
		{
			cout << "Enter the id to search: ";
			cin >> id;
			if (!search(labs, lab, station, resultlab, resultstation, id))
				cout << "None" << endl;
			else
			{
				cout << "Lab: " << resultlab << endl;
				cout << "Station: " << resultstation << endl;
			}
		}
		break;

		case 4:
			display(labs, lab, station);
			break;

		default:
		{
			display(labs, lab, station);
			for (int i = 0; i < lab; ++i)
			{
				delete[] labs[i];
			}
			delete[] station;
			delete[] labs;
			return 0;
		}
		}
		id = 0, curLab = 0, curSta = 0;
		cout << "/////////////////////////////////////////////////////////////";
	}
	return 0;
}