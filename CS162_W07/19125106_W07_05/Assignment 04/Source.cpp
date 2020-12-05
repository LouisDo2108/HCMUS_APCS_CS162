#include <iostream>
#include "Header.h"

using namespace std;

void push(Stack& s, int data)
{
	Node* temp = new Node;
	temp->data = data;
	if (!s.head)
		s.head = temp;
	else
	{
		temp->next = s.head;
		s.head = temp;
	}
}

int pop(Stack& s)
{
	if (!s.head)
		return INT_MIN;
	else
		return s.head->data;
}

void init(Stack& A, int N)
{
	for (int i = N; i > 0; --i)
		push(A, i);
	return;
}

void move(Stack& source, Stack& destination)
{
	if (source.head)
	{
		if (!destination.head || (destination.head && pop(destination) > pop(source)))
		{
			push(destination, pop(source));
			Node* del = source.head;
			source.head = source.head->next;
			delete del;
			return;
		}
	}
}

void tower(int n, Stack& source, Stack& destination, Stack& support, Stack& A, Stack& B, Stack& C)
{
	if (n == 1)
	{
		move(source, destination);
		displayAll(A, B, C);
		return;
	}
	tower(n - 1, source, support, destination, A, B, C);
	move(source, destination);
	displayAll(A, B, C);
	tower(n - 1, support, destination, source, A, B, C);
	return;
}

void display(Node* cur)
{
	if (!cur)
		return;
	display(cur->next);
	cout << cur->data << " ";
}
void displayAll(Stack& A, Stack& B, Stack& C)
{
	cout << "A: ";
	display(A.head);
	cout << endl;
	cout << "B: ";
	display(B.head);
	cout << endl;
	cout << "C: ";
	display(C.head);
	cout << endl;
	cout << endl;
}

void remove(Stack& s)
{
	if (!s.head)
		return;
	Node* cur = s.head, * del;
	while (cur)
	{
		del = cur;
		cur = cur->next;
		delete del;
	}
}

void removeAll(Stack& A, Stack& B, Stack& C)
{
	remove(A);
	remove(B);
	remove(C);
}

