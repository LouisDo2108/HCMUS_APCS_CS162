#include <iostream>
#include "Header.h"

using namespace std;

void init(Queue& s, int size)
{
	s.data = new int[size];
	s.size = size;
	s.in = 0;
	s.out = 0;
	return;
}

void enqueue(Queue& s, int x)
{	
	if (s.in >= s.size && s.out == 0)
	{
		cout << "Queue is full" << endl;
		return;
	}
	else if(s.out != 0)
	{
		for (int i = 0; i < s.size; ++i)
		{
			if (s.out == s.in)
			{
				s.in = i;
				break;
			}
			s.data[i] = s.data[s.out];
			s.data[s.out++] = 0;
		}
		s.out = 0;
	}
	s.data[s.in++] = x;
	return;
}

int dequeue(Queue& s)
{
	if (s.out == s.in || s.out >= s.size)
		cout << "Queue is empty" << endl;
	else
	{
		int result = s.data[s.out];
		s.data[s.out++] = 0;
		return result;
	}
	return INT_MIN;
}
bool isEmpty(Queue& s)
{
	if (s.in == 0 || s.out >= s.size)
		return true;
	else
		return false;
}

void empty(Queue& s)
{
	if (s.in == 0 && s.out == 0)
	{
		cout << "Queue is already empty" << endl;
		return;
	}
	for (int i = 0; i < s.in; ++i)
		s.data[i] = 0;
	s.in = 0;
	s.out = 0;
	return;
}
int size(Queue& s)
{
	return s.size;
}