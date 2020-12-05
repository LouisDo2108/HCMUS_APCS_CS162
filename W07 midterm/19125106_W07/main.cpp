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
		cin >> repeat;
		cin.ignore(1);
	}
	displayAll(head);

	cout << "Delete a room! Enter the room ID: " << endl;
	cin.getline(id, 4);
	deleteRoom(head, id);

	cout << "Search rooms!" << endl;
	cout << "Number of people: ";
	cin >> num;
	cout << "Have breakfast? ";
	cin.ignore(1);
	cin.getline(id, 4);
	if (strcmp(id, "Yes") == 0 || strcmp(id, "yes") == 0)
		breakfast = true;
	else
		breakfast = false;
	searchRoom(head, num, breakfast);

	cout << "\nRemove all rooms whose number of people greater than k, enter k: ";
	cin >> k;

	removeRoomK(head, k);
	displayAll(head);
	removeAll(head);
	return 0;
}