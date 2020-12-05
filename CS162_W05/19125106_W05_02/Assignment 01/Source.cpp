#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

void initCircularLinkedList(ifstream& f, Node*& head, Node*& tail)
{
	f.open("input.txt");
	if (!f.is_open())
		cout << "Can't open the file";
	else
	{
		int data = INT_MIN;
		Node* current = head;
		f >> data;
		while (data != 0)
		{
			if (!head)
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
		if (current)
		{
			current->next = head;
			tail = current;
		}
		else
			cout << "Can't init tail" << endl;
	}
	f.close();
	return;
}

void removeDuplicate(ofstream& f, Node*& head, Node*& tail)
{
	f.open("output.txt");
	if (!f.is_open() || !head)
		cout << "Either can't open the file or input is null.";
	else
	{
		if (head == tail)
			f << head->data << " ";
		else
		{
			Node* cur1 = head, * prev = cur1, * cur2 = prev->next;
			while (cur1->next != head)
			{
				while (cur2 != head)
				{
					if (cur1->data == cur2->data)
					{
						prev->next = cur2->next;
						if (cur2 == tail)
						{
							tail = prev;
							tail->next = head;
						}
						delete cur2;
						cur2 = prev->next;
					}
					else
					{
						prev = prev->next;
						cur2 = cur2->next;
					}
				}					
				cur1 = cur1->next;
				prev = cur1;
				cur2 = prev->next;
			}
			Node* current = head;
			while (current->next != head)
			{
				f << current->data << " ";
				current = current->next;
			}
			f << current->data << " ";
		}
	}
	f << 0;
	f.close();
	return;
}

void deleteAll(Node*& head, Node*& tail)
{
	if (head == nullptr)
		return;
	else
	{
		Node* current = head, * del;
		while (current != nullptr && current != tail)
		{
			del = current;
			current = current->next;
			delete del;
		}
		delete current;
	}
	return;
}