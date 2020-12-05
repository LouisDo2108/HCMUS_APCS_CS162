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
void sum(Node* headin, Node*& headout, Node* cur, int data)
{
	if (!headin)
		return;
	Node* temp = new Node;
	temp->data = headin->data + data;
	if (!headout)
	{
		headout = temp;
		return sum(headin->next, headout, headout, headin->data + data);
	}
	cur->next = temp; 
	return sum(headin->next, headout, cur->next, headin->data + data);
}
void output(ofstream& f, Node*& headout)
{
	f.open("output.txt");
	if (!f.is_open())
		cout << "Failed to open the output file" << endl;
	else
	{
		Node* cur = headout;
		while (cur)
		{
			f << cur->data << " ";
			cur = cur->next;
		}
		f << 0;
	}
}