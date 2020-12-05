#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

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
void remove_duplicate_x(ofstream& f, Node*& head)
{
	f.open("output.txt");
	if (!f.is_open() || head == nullptr)
	{
		cout << "Either can't open the file or input is null." << endl;
		return;
	}
	else
	{
		if (head->next == nullptr)
			f << head->data << " ";
		else
		{
			Node* cur1 = head, *prev = cur1, * cur2 = prev->next;
			while (cur1 != nullptr && cur1->next != nullptr)
			{
				while (cur2 != nullptr)
				{
					if (cur1->data == cur2->data)
					{
						prev->next = cur2->next;
						delete cur2;
						cur2 = prev->next;
					}
					else
					{
						prev = prev->next;
						cur2 = cur2->next;
					}
				}
				if (cur1->next == nullptr)
					break;
				else
				{
					cur1 = cur1->next;
					prev = cur1;
					cur2 = prev->next;
				}
			}
			cur1 = head;
			while (cur1 != nullptr)
			{
				f << cur1->data << " ";
				cur1 = cur1->next;
			}
		}
		f << 0;
	}
	f.close();
	return;
}

void delLinkedlist(Node*& head)
{
	Node* current = head, * del;

	while (current != nullptr)
	{
		del = current;
		current = current->next;
		delete del;
	}
	return;
}