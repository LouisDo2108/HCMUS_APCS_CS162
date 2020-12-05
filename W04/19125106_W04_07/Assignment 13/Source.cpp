#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

void initLinkedlist(ifstream& f, Node*& head, bool& check, Node*& originalTail)
{
	f.open("input.txt");
	if (!f.is_open())
		cout << "Can't open the file!" << endl;
	else
	{
		int data = INT_MIN;
		Node* current = head, *loop;
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
		f >> data;

		originalTail = current;
		loop = head;
		while (loop != nullptr) 
		{
			if (loop->data == data)
			{
				check = true;
				break;
			}
			else
				loop = loop->next;
		}
		if(check)
			originalTail->next = loop;
	}
	f.close();
	return;
}
void delLinkedlist(Node*& head, bool& check, Node*& originalTail)
{
	Node* current = head, * del;
	while (current != nullptr && current->next != originalTail)
	{
		del = current;
		current = current->next;
		delete del;
	}
	delete current;
	return;
}

void check_loop(ofstream& f, Node*& head, bool& check)
{
	f.open("output.txt");
	if (head == nullptr || !f.is_open())
		cout << "Either can't open the file or the input is null" << endl;
	else
	{
		if (!check)
			f << "NO";
		else
		{
			int counter = 0;
			Node* cur1 = head, *cur2 = head;
			while (cur1 != nullptr && cur2 != nullptr)
			{
				if (cur1->next == nullptr || cur2->next == nullptr)
				{
					check = false;
					break;
				}
				else if (cur1->data == cur2->data && cur1 == cur2)
				{
					++counter;
					if (counter > 1)
					{
						check = true;
						break;
					}
				}
				cur1 = cur1->next;
				cur2 = cur2->next->next;
			}
			if (!check)
				f << "NO";
			else
				f << "YES";
		}
	}
	f.close();
	return;
}