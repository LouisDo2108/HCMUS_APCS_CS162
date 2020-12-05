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
void remove_duplicate_x(Node*& head, Node* cur1, Node* cur2, Node* prev)
{
	if (!head || !cur1->next)
		return;
	if (!cur2)
		return remove_duplicate_x(head, cur1->next, cur1->next->next, cur1->next);
	if (cur1->data == cur2->data)
	{
		prev->next = cur2->next;
		delete cur2;
		return remove_duplicate_x(head, cur1, prev->next, prev);
	}
	else return remove_duplicate_x(head, cur1, cur2->next, cur2);
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

void output(ofstream& f, Node*& head)
{
	f.open("output.txt");
	if (!f.is_open())
		cout << "Failed to open the output file" << endl;
	else
	{
		Node* cur = head;
		while (cur)
		{
			f << cur->data << " ";
			cur = cur->next;
		}
		f << 0;
	}
}