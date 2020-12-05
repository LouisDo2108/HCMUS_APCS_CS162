#include <iostream>
#include "Header.h"
using namespace std;

void init(Stack &s, int size)
{
	s.head = nullptr;
	s.size = size;
	s.count = 0;
	return;
}

void push(Stack &s, int x)
{
	if (s.count >= s.size)
		cout << "Stack is full" << endl;
	else
	{
		Node* temp = new Node;
		temp->data = x;
		temp->next = nullptr;
		if (!s.head)
			s.head = temp;
		else
		{
			temp->next = s.head;
			s.head = temp;
		}
		++s.count;
	}
	return;
}

int pop(Stack& s)
{
	if (!s.head && s.count == 0)
		cout << "Stack is empty" << endl;
	else
	{
		int result = s.head->data;
		Node* del = s.head;
		s.head = s.head->next;
		delete del;
		--s.count;
		return result;
	}
	return INT_MIN;
}

bool isEmpty(Stack& s)
{
	if (!s.head && s.count == 0)
		return true;
	else
		return false;
}

void empty(Stack& s)
{
	if (!s.head && s.count == 0)
		cout << "Stack is already empty" << endl;
	else
	{
		Node* cur = s.head, *del;
		while (cur)
		{
			del = cur;
			cur = cur->next;
			delete del;
		}
		s.count = 0;
	}
	s.head = nullptr;
	return;
}

int size(Stack& s)
{
	return s.size;
}

void displayAll(Stack& s)
{
	if (s.head)
	{
		Node* cur = s.head;
		while (cur)
		{
			cout << cur->data << " ";
			cur = cur->next;
		}
	}
	else
		cout << "Stack is empty" << endl;
	return;
}