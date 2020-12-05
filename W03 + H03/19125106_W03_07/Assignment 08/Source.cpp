#include <iostream>
#include "Header.h"

using namespace std;

void login(int**& labs, int& currentID, int& currentLab, int& currentStation, int& lab, int*& station)
{
	while (1)
	{
		int l, s;
		cout << "Enter the id (From 10000 to 99999): ";
		cin >> currentID;
		if (search(labs, lab, station, l, s, currentID))
		{
			cout << "This id has already logged in!" << endl;
		}
		else if (currentID < 10000 || currentID > 99999)
		{
			cout << "Invalid ID!" << endl;
		}
		else
			break;
	}
	while (1)
	{
		while (currentLab == 0 || currentLab > lab)
		{
			cout << "Enter the lab: ";
			cin >> currentLab;
			if (currentLab > lab)
				cout << "Invalid lab! Currently there are " << lab << " labs." << endl;
		}
		while (currentStation == 0 || currentStation > station[currentLab - 1])
		{
			cout << "Enter the station: ";
			cin >> currentStation;
			if (currentStation > station[currentLab - 1])
				cout << "Invalid station! Currently there are " << station[currentLab - 1] << " stations in lab " << currentLab << endl;
		}
		if (labs[currentLab - 1][currentStation - 1] != 0)
		{
			cout << "The current station is not available." << endl;
			currentLab = 0;
			currentStation = 0;
		}
		else
		{
			labs[currentLab - 1][currentStation - 1] = currentID;
			cout << currentID << " login successfully!" << endl;
			return;
		}
	}
}

void logout(int**& labs, int& lab, int*& station)
{
	int l, s, id;
	cout << "Enter the id to log out: ";
	cin >> id;
	if (search(labs, lab, station, l, s, id))
	{
		labs[l - 1][s - 1] = 0;
		cout << "Successfully log out id: " << id << endl;
	}
	else
	{
		cout << "None!" << endl;
	}
	return;
}

void createLabs(int**& labs, int& lab, int*& station)
{
	cout << "Enter the total labs count: ";
	cin >> lab;
	labs = new int* [lab];
	station = new int[lab];
	
	cout << "For each lab, enter the count of stations!" << endl;

	for (int i = 0; i < lab; ++i)
	{
		cout << "Lab " << i + 1 << ": ";
		cin >> station[i];
		labs[i] = new int[station[i]];
	}

	for (int i = 0; i < lab; ++i)
	{
		for (int j = 0; j < station[i]; ++j)
		{
			labs[i][j] = 0;
		}
	}

	return;
}

bool search(int**& labs, int& lab, int*& station, int& resultlab, int& resultstation, int id)
{
	for(int i = 0; i < lab; ++i)
		for(int j = 0; j < station[i]; ++j)
			if (labs[i][j] == id)
			{
				resultlab = i + 1;
				resultstation = j + 1;
				return true;
			}
	return false;
}

void display(int** labs, int lab, int* station)
{
	cout << endl;
	for (int i = 0; i < lab; ++i)
	{
		for (int j = 0; j < station[i]; ++j)
		{
			cout << labs[i][j] << " ";
			
		}
		cout << endl;
	}
}