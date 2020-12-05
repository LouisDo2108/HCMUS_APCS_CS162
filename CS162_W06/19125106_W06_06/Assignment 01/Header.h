#pragma once
#ifndef  _Header_H_
#define _Header_H_

#include <iostream>

using namespace std;

struct Stack
{
	int* data;
	int top;
	int size;
};

void init(Stack& s, int size);
void push(Stack& s, int x);
int pop(Stack& s);
bool isEmpty(Stack& s);
void empty(Stack& s);
int size(Stack& s);

#endif // ! _Header_H_
