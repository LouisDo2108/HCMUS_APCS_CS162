	#include <iostream>
#include <string>
#include <cmath>
#include "Header.h"

using namespace std;
void push(Stack& s, double x)
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
double pop(Stack& s)
{
	if (!s.head)
		return INT64_MIN;
	else
	{
		Node* del = s.head;
		double result = s.head->data;
		s.head = s.head->next;
		delete del;
		return result;
	}
}
double calc(double a, double b, char ope)
{
	switch (ope)
	{
	case '+':
		return a + b;

	case '-':
		return a - b;

	case '*':
		return a * b;

	case '/':
		return a / b;

	case '**':
		return pow(a, b);

	case '^':
		return pow(a, b);

	default:
		return INT_MIN;
	}
}
void polish(string x, string& p, Stack& op)
{
	double temp = 0;
	int prio = 0, count = 0;
	for (int i = 0; i < x.length(); ++i)
	{
		temp = (double)x[i];

		if (x[i] == ' ') 
			continue;
		else if (temp - '0' >= 0 && temp - '0' <= 9)
			p += x[i];
		else if (x[i] == '(')
		{
			++count;
			prio = 0;
		}
		else if (x[i] == ')')
		{
			--count;
			while (op.head)
				p += (char)pop(op);
			prio = 0;
		}
		else
		{
			p += ' ';
			if (prio == 1)
			{
				if (!((char)temp == '*' || (char)temp == '/'))
				{
					prio = 0;
					while (op.head)
						p += (char)pop(op);
				}
				push(op, temp);
			}
			else
			{
				push(op, temp);
				if ((char)temp == '*' || (char)temp == '/')
					prio = 1;
				else prio = 0;
			}
		}
	}
	while (op.head)
		p += (char)pop(op);
}
double output(string p, Stack& num, Stack& value)
{
	double temp = 0, a = 0, b = 0, result = 0, data = 0;
	int exp;
	for (int i = 0; i < p.length(); ++i)
	{
		if (p[i] == ' ')
		{
			exp = 0, data = 0;
			if (value.head)
			{
				while (value.head)
					data += pop(value) * pow(10, exp++);
				push(num, data);
			}
			continue;
		}
		temp = (double)p[i];
		if (temp - '0' >= 0 && temp - '0' <= 9)
			push(value, temp - '0');
		else
		{
			exp = 0, data = 0;
			if (value.head)
			{
				while (value.head)
					data += pop(value) * pow(10, exp++);
				push(num, data);
			}
			b = pop(num);
			a = pop(num);
			result = calc(a, b, p[i]);
			push(num, result);
		}
	}
	return pop(num);
}