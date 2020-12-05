#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	int repeat = 0, num = 0, k = 0;
	bool breakfast = true;
	char id[4];
	Node* head;
	init(head);
	while (repeat == 0)
	{
		inputRoom(head);
		cout << "Enter 0 to input another room or else to exit: ";
		cin.ignore(100, '\n');
		cin >> repeat;
		cin.ignore(100, '\n');
	}
	displayAll(head);
	cout << "Delete a room! Enter the room ID: " << endl;
	cin.ignore(100, '\n');
	cin.get(id, 4, '\n');
	deleteRoom(head, id);
	cout << "Search rooms!" << endl;
	cout << "Number of people: ";
	cin >> num;
	cout << "Have breakfast? ";
	cin.getline(id, 4);
	if (strcmp(id, "Yes") == 0 || strcmp(id, "yes") == 0)
		breakfast = true;
	else
		breakfast = false;
	searchRoom(head, num, breakfast);
	cout << "Remove all rooms whose number of people greater than k, enter k: ";
	cin >> k;
	removeRoomK(head, k);
	removeAll(head);
	return 0;
}