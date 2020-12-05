#include <iostream>
#include <fstream>
#include "Header.h"

using namespace std;

void initLinkedlist(ifstream& f, Node*& head1, Node*& head2)
{
	f.open("input.txt");
	if (!f.is_open())
		cout << "Can't open the file!" << endl;
	else
	{
		int data = INT_MIN;
		Node* cur1 = head1, *cur2 = head2;
		f >> data;
		while (data != 0)
		{
			if (head1 == nullptr)
			{
				head1 = new Node;
				head1->data = data;
				cur1 = head1;
			}
			else
			{
				cur1->next = new Node;
				cur1 = cur1->next;
				cur1->data = data;
			}
			f >> data;
		}
		f >> data;
		while (data != 0)
		{
			if (head2 == nullptr)
			{
				head2 = new Node;
				head2->data = data;
				cur2 = head2;
			}
			else
			{
				cur2->next = new Node;
				cur2 = cur2->next;
				cur2->data = data;
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

	while (current != nullptr)
	{
		del = current;
		current = current->next;
		delete del;
	}
	return;
}
void two_into_one(ofstream& f, Node*& head1, Node*& head2)
{
	int check = 0;
	f.open("output.txt");
	if ((head1 == nullptr && head2 == nullptr) || (!f.is_open()))
		cout << "Either can't open the file or the input is null." << endl;
	else
	{
		if (head1 != nullptr && head2 == nullptr)
			check = 1;
		else if(head2 != nullptr && head1 == nullptr)
			check = 2;
		else
		{
			int index = 1;
			Node* cur1 = head1, *temp;
			while (cur1 != nullptr && head2 != nullptr)
			{
				if (cur1->next == nullptr)
				{
					cur1->next = head2;
					break;
				}
				if (index % 2 != 0)
				{
					temp = head2;
					head2 = head2->next;
					temp->next = cur1->next;
					cur1->next = temp;
				}
				cur1 = cur1->next;
				++index;
			}
			head2 = nullptr;
			check = 1;
		}
		Node* cur = nullptr;
		if (check == 1)
			cur = head1;
		else if (check == 2)
			cur = head2;
		while (cur != nullptr)
		{
			f << cur->data << " ";
			cur = cur->next;
		}
		f << 0;
	}
	f.close();
	return;
}