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
void sum(ofstream& f, Node*& headin, Node*& headout)
{
	f.open("output.txt");
	if (headin == nullptr || !f.is_open())
		cout << "Either can't open the file or the input is null.";
	else
	{
		Node* curin = headin, *curout = nullptr;
		int sum = 0;
		while (curin != nullptr)
		{
			sum += curin->data;
			if (headout == nullptr)
			{
				headout = new Node;
				headout->data = sum;
				curout = headout;
			}
			else
			{
				curout->next = new Node;
				curout = curout->next;
				curout->data = sum;
			}
			curin = curin->next;
		}
		curout = headout;
		while (curout != nullptr)
		{
			f << curout->data << " ";
			curout = curout->next;
		}
		f << 0;
	}
	f.close();
	return;
}