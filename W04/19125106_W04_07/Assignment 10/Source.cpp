#include <iostream>
#include <fstream>
#include <cmath>
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
		while (data != -1)
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
void list_to_num(ofstream& f, Node*& head)
{
	f.open("output.txt");
	if (!f.is_open() || head == nullptr)
		cout << "Either can't open the file or the input is null." << endl;
	else
	{
		Node* current = head;
		int m = -1, result = 0;
		while (current != nullptr)
		{
			++m;
			current = current->next;
		}
		current = head;
		while (current != nullptr)
		{
			result += current->data * pow(10, m--);
			current = current->next;
		}
		f << result;
	}
	f.close();
	return;
}