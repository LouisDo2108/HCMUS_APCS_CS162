#include <iostream>
#include "Header.h"

using namespace std;

void init(Stack& s, int size)
{
	s.data = new int[size];
	s.size = size;
	s.top = 0;
}

void push(Stack& s, int x)
{
	if (s.top >= s.size)
		cout << "Stack is full" << endl;
	else
		s.data[s.top++] = x;
	return;
}

int pop(Stack& s)
{
	if (s.top <= 0)
		cout << "Stack is empty";
	else
	{
		int result = s.data[s.top - 1];
		s.data[s.top - 1] = 0;	
		--s.top;
		return result;
	}
	return 0;
}

bool isEmpty(Stack& s)
{
	if (s.top == 0)
		return true;
	return false;
}

void empty(Stack& s)
{
	if (s.top == 0)
		cout << "Stack is already empty" << endl;
	while (s.top != 0)
		s.data[--s.top] = 0;
	return;
}

int size(Stack& s)
{
	return s.size;
}