#pragma once
#ifndef _Header_H_
#define _Header_H_
#include <iostream>
#include <string>

using namespace std;

struct Node
{
	double data;
	Node* next = nullptr;
};

struct Stack
{
	Node* head = nullptr;
};

void push(Stack& s, double x);
double pop(Stack& s);

void polish(string x, string& p, Stack& op);
double calc(double a, double b, char ope);
double output(string p, Stack& num, Stack& value);

#endif