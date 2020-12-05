#include <iostream>
#include "Header.h"

using namespace std;

void init(Queue& q, int size)
{
	q.head = nullptr;
	q.tail = nullptr;
	q.size = size;
	q.count = 0;
	return;
}

void enqueue(Queue& q, int x)
{
	if (q.count >= q.size)
	{
		cout << "Queue is full" << endl;
		return;
	}
	else
	{
		Node* temp = new Node;
		temp->data = x;
		temp->next = nullptr;
		if (!q.head)
		{
			q.head = temp;
			q.tail = q.head;
		}
		else
		{
			q.tail->next = temp;
			q.tail = temp;
		}
		++q.count;
	}
	return;
}

int dequeue(Queue& q)
{
	if (!q.head)
	{
		cout << "Queue is empty" << endl;
		return INT_MIN;
	}
	Node* del = q.head;	
	int result = q.head->data;
	if (q.head == q.tail)
	{
		q.head = nullptr;
		q.tail = nullptr;
	}
	else
		q.head = q.head->next;
	delete del;
	--q.count;
	return result;
}

bool isEmpty(Queue& q)
{
	if (q.head)
		return false;
	else
		return true;
}

void empty(Queue& q)
{
	if (!q.head)
		cout << "Queue is already emtpy" << endl;
	else
	{
		Node* cur = q.head, * del;
		while (!cur)
		{
			del = cur;
			cur = cur->next;
			delete cur;
		}
		q.head = nullptr;
		q.tail = nullptr;
	}
	return;
}

int size(Queue& q)
{
	return q.size;
}

void displayAll(Queue q)
{
	if (!q.head)
	{
		cout << "Queue is empty" << endl;
		return;
	}
	else
	{
		Node* cur = q.head;
		while (cur)
		{
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << endl;
	}
	return;
}

