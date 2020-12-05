#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

void remove_all_x(Node*& head, Node* prev, Node* cur, int& x)
{
	if (!head || !cur)
		return;
	remove_all_x(head, cur, cur->next, x);
	if (cur && cur->data == x)
	{
		if (cur == head)
			head = head->next;
		else if(prev) prev->next = cur->next;
		delete cur;
	}
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
	Node* current = head, * del;

	while (current)
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
		cout << "Failed to open the output file.";
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
	f.close();
	return;
}