#include <iostream>
#include "Header.h"

using namespace std;

void init(Node*& head)
{
	head = nullptr;
	return;
}

void displayInfo(Node* head)
{
	if (head)
	{
		cout << "rID: " << head->room.ID << endl;
		cout << "Usable area: " << head->room.UsableArea << endl;
		cout << "Furnished: ";
		if (head->room.Furnished)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		cout << "Have breakfast: ";
		if (head->room.HaveBreakFast)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return;
}

void inputRoom(Node*& head)
{
	char id[4];
	cout << "Input the room ID with 3 character: ";
	cin.get(id, 4, '\n');
	if (!head || (!head->next && strcmp(head->room.ID, id) != 0))
	{
		Node* temp = new Node;
		strcpy_s(temp->room.ID, 4, id);
		cout << "Enter the usable area of room: ";
		cin >> temp->room.UsableArea;
		cin.ignore(100, '\n');
		cout << "Is the room furnished? ";
		cin.get(id, 4, '\n');
		if (strcmp(id, "Yes") == 0 || strcmp(id, "yes") == 0)
			temp->room.Furnished = true;
		else
			temp->room.Furnished = false;
		cout << "Have breakfast? ";
		cin.ignore(100, '\n');
		cin.get(id, 4, '\n');
		if (strcmp(id, "Yes") == 0 || strcmp(id, "yes") == 0)
			temp->room.HaveBreakFast = true;
		else
			temp->room.HaveBreakFast = false;
		if (!head)
			head = temp;
		else
			head->next = temp;
	}
	else
	{
		Node* cur = head;
		while (cur && cur->next && strcmp(cur->next->room.ID, id) != 0)
			cur = cur->next;
		if (cur->next != nullptr)
		{
			cout << "Please check your rID!" << endl;
			return;
		}
		else
		{
			Node* temp = new Node;
			strcpy_s(temp->room.ID, 4, id);
			cout << "Enter the usable area of room: ";
			cin >> temp->room.UsableArea;
			cin.ignore(100, '\n');
			cout << "Is the room furnished? ";
			cin.get(id, 4, '\n');
			if (strcmp(id, "Yes") == 0 || strcmp(id, "yes") == 0)
				temp->room.Furnished = true;
			else
				temp->room.Furnished = false;
			cout << "Have breakfast? ";
			cin.ignore(100, '\n');
			cin.get(id, 4, '\n');
			if (strcmp(id, "Yes") == 0 || strcmp(id, "yes") == 0)
				temp->room.HaveBreakFast = true;
			else
				temp->room.HaveBreakFast = false;
			cur->next = temp;
		}
	}
	return;
}

void deleteRoom(Node*& head, char id[4])
{
	if (!head)
	{
		cout << "The homestay has no room" << endl;
		return;
	}

	if (head && strcmp(head->room.ID, id) == 0)
	{
		Node* del = head;
		head = head->next;
		displayInfo(del);
		delete del;
		return;
	}
	else
	{
		Node* cur = head;
		while (cur && cur->next && strcmp(cur->next->room.ID, id) != 0)
			cur = cur->next;
		if (!cur->next)
		{
			cout << "Cannot find the room with " << id << endl;
		}
		else
		{
			Node* del = cur->next;
			displayInfo(del);
			cur->next = del->next;
			delete del;
		}
	}
	return;
}

void searchRoom(Node* head, int num, bool breakfast)
{
	if (!head)
	{
		cout << "The homestay has zero room" << endl;
		return;
	}

	while (head)
	{
		if (head->room.NumOfPeople == num && head->room.HaveBreakFast == breakfast)
			displayInfo(head);
		head = head->next;
	}

	return;
}

void removeRoomK(Node*& head, int k)
{
	if (!head)
	{
		cout << "The homestay has zero room" << endl;
		return;
	}
	Node* del, * cur;
	while (head && head->room.NumOfPeople > k)
	{
		del = head;
		head = head->next;
		delete del;
	}

	cur = head;
	while (cur && cur->next)
	{
		if (cur->next->room.NumOfPeople > k)
		{
			del = cur;
			cur->next = del->next;
			delete del;
		}
		cur = cur->next;
	}
	return;
}

void removeAll(Node*& head)
{
	if (!head)
		return;
	else
	{
		Node* cur = head, *del;
		while (cur)
		{
			del = cur;
			cur = cur->next;
			delete del;
		}
	}
	return;
}

void displayAll(Node* head)
{
	if (!head)
		return;
	while (head)
	{
		displayInfo(head);
		head = head->next;
	}
	return;
}