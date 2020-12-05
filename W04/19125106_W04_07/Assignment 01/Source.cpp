#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

void remove_all_x(ofstream& f, Node*& head, int& x)
{
	if (head == nullptr)
		return;
	cout << "Enter the value x to remove all of them: ";
	cin >> x;
	Node* current = head, *del;
	bool check = false;

	if (current->data == x)
		check = true;
	else
	{
		while (current->next != nullptr)
		{
			if (current->next->data == x)
			{
				check = true;
				break;
			}
			else current = current->next;
		}
	}

	f.open("output.txt");
	if (!f.is_open())
	{
		cout << "Can't open the file" << endl;
		return;
	}
	else
	{
		if (check)
		{
			while (current != nullptr && current == head && current->data == x)
			{
				del = current;
				head = current->next;
				delete del;
				current = head;
			}
			while (current != nullptr && current->next != nullptr)
			{
				if (current->next->data == x)
				{
					del = current->next;
					current->next = del->next;
					delete del;
				}
				else
					current = current->next;
			}
		}
		current = head;
		while (current != nullptr)
		{
			f << current->data << " ";
			current = current->next;
		}
		f << 0;
	}
	f.close();
	return;
}

void initLinkedlist(ifstream& f, Node*& head)
{
	f.open("input.txt");
	if (!f.is_open())
		cout << "Can't open the file!" << endl;
	else
	{
		int data = INT_MIN;
		Node* current = head;
		f >> data;
		while (data != 0)
		{
			if (head == nullptr)
			{
				head = new Node;
				head->data = data;
				current = head;
			}
			else
			{
				current->next = new Node;
				current = current->next;
				current->data = data;
			}
			f >> data;
		}
	}
	f.close();
	return;
}

void delLinkedlist(Node*& head)
{
	Node* current = head, *del;
	
	while (current != nullptr)
	{
		del = current;
		current = current->next;
		delete del;
	}
	return;
}