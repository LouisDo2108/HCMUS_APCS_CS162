#include <iostream>
#include <fstream>
#include <string>
#include "Header.h"

using namespace std;
void initDoublyLinkedList(ifstream& f, Node*& head1, Node*& head2)
{
	f.open("input.txt");
	if (!f.is_open())
		cout << "Can't open the file";
	else
	{
		Node* cur = head1;
		string a, b;
		int x;
		getline(f, a);
		getline(f, b);
		if (a.length() != 0 && b.length() != 0)
		{
			for (int i = 0; i < a.length(); ++i)
			{
				x = a[i] - '0';
				if (!head1)
				{
					head1 = new Node;
					head1->data = x;
					head1->prev = nullptr;
					cur = head1;
				}
				else
				{
					cur->next = new Node;
					cur->next->data = x;
					cur->next->prev = cur;
					cur = cur->next;
				}
			}

			cur = head2;
			for (int i = 0; i < b.length(); ++i)
			{
				x = b[i] - '0';
				if (!head2)
				{
					head2 = new Node;
					head2->data = x;
					head2->prev = nullptr;
					cur = head2;
				}
				else
				{
					cur->next = new Node;
					cur->next->data = x;
					cur->next->prev = cur;
					cur = cur->next;
				}
			}
		}
		else cout << "Please input two linked lists!" << endl;
	}
	f.close();
	return;
}
void sum(ofstream& f, Node*& head1, Node*& head2)
{
	int check = 0, state = 1, x = 0;
	Node* cur1 = head1, * cur2 = head2, *cur;
	f.open("output.txt");
	if (!f.is_open() || (head1 == nullptr && head2 == nullptr))
		cout << "Either can't open the file or the input is null";
	else
	{
		if (!head1 && head2)
			state = 2;
		else if (!head2 && head1)
			state = 1;
		else
		{
			while (cur1->next)
				cur1 = cur1->next;
			while (cur2->next)
				cur2 = cur2->next;

			if (cur1->data + cur2->data >= 10)
			{
				x = 1;
				cur1->data = cur1->data + cur2->data - 10;
			}
			else
				cur1->data = cur1->data + cur2->data;

			if (!cur1->prev && cur2->prev)
				check = 2;
			else if (!cur2->prev && cur1->prev)
				check = 1;
			else
			{
				cur1 = cur1->prev;
				cur2 = cur2->prev;
				while (cur1 && cur2)
				{
					if (cur1->data + cur2->data >= 10)
					{
						cur1->data = cur1->data + cur2->data - 10 + x;
						x = 1;
					}
					else
					{
						cur1->data = cur1->data + cur2->data + x;
						x = 0;
					}
					if (!cur1->prev && cur2->prev != nullptr)
					{
						check = 2;
						break;
					}
					if (!cur2->prev && cur1->prev)
					{
						check = 1;
						break;
					}
					cur1 = cur1->prev;
					cur2 = cur2->prev;
				}
			}
			if (check == 1)
				cur1->prev->data += x;
			else if (check == 2)
			{
				cur2->prev->data += x;
				Node* del = cur2;
				cur2->prev->next = head1;
				head1 = head2;
				deleteAll(del);
				head2 = nullptr;
			}
			else if (cur1 == head1 && cur2 == head2)
			{
				if (cur1->data + cur2->data >= 10)
				{
					head1->data = head1->data + head2->data + x - 10;
					Node* temp = new Node;
					temp->data = 1;
					temp->next = head1;
					head1->prev = temp;
					head1 = temp;
				}
				else
					head1->data = head1->data + head2->data + x;
			}
		}

		if (state == 2)
			cur = head2;
		else
			cur = head1;

		while (cur)
		{
			f << cur->data;
			cur = cur->next;
		}
		f.close();
		return;
	}
}

void deleteAll(Node*& head)
{
	if (head == nullptr)
		return;
	else
	{
		Node* current = head, * del;
		while (current != nullptr)
		{
			del = current;
			current = current->next;
			delete del;
		}
	}
	return;
}