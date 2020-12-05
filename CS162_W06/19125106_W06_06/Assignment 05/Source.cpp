#include <iostream>
#include <math.h>
#include "Header.h"

using namespace std;

void push(Stack& s, int x)
{
	Node* temp = new Node;
	temp->data = x;
	if (!s.head)
		s.head = temp;
	else
	{
		temp->next = s.head;
		s.head = temp;
	}
	return;
}

int pop(Stack& s)
{
	if (!s.head)
	{
		cout << "Stack is emtpy" << endl;
		return INT_MIN;
	}
	else
	{
		Node* del = s.head;
		int result = s.head->data;
		s.head = s.head->next;
		delete del;
		return result;
	}
}

void display(Stack& s)
{
	while (s.head)
		cout << pop(s);
	cout << endl;
	return;
}

void emptyStack(Stack& s)
{
	if (!s.head)
		cout << "Stack is already empty" << endl;
	else
	{
		Node* cur = s.head, * del;
		while (cur)
		{
			del = cur;
			cur = cur->next;
			delete del;
		}
	}
	s.head = nullptr;
	return;
}

void dec_to_bin(Stack& s, int dec)
{
	push(s, dec % 2);
	dec /= 2;
	while (dec != 0)
		return dec_to_bin(s, dec);
	display(s);
}

int bin_to_dec(Stack& s, string bin)
{
	int result = 0, i, temp, counter = 0;
	for (i = 0; i < bin.length(); ++i)
		push(s, (int)bin[i] - '0');

	while (s.head)
	{
		temp = pop(s);
		if (temp == 1)
			result += pow(2, counter);
		++counter;
	}
	return result;
}

void dec_to_hex(Stack& s, int dec)
{
	int result = 0;
	while (dec != 0)
	{
		if (dec % 16 > 9)
			push(s, 'F' - 15 + dec % 16);
		else
			push(s, dec % 16);
		dec /= 16;
	}
	while (s.head)
	{
		result = pop(s);
		if (result > 9)
			cout << (char)result;
		else cout << result;
	}
	return;
}

int hex_to_dec(Stack& s, string hex)
{
	int result = 0, i = 0, temp = 0, counter = 0;
	for (i = 0; i < hex.length(); ++i)
		push(s, (int)hex[i]);
	while (s.head)
	{
		temp = pop(s);
		if (temp - '0' >= 0 && temp - '0' <= 9)
			result += (temp - '0') * pow(16, counter);
		else if (temp - 'A' >= 0 && temp - 'A' <= 5)
			result += (temp - 'A' + 10) * pow(16, counter);
		else
			result += (temp - 'a' + 10) * pow(16, counter);
		++counter;
	}
	return result;
}