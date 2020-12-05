#pragma once
#ifndef _Header_H_
#define _Header_H_

#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct Stack
{
	Node* head;
	int size;
	int count;
};

void init(Stack& s, int size);
void push(Stack& s, int x);
int pop(Stack& s);
bool isEmpty(Stack& s);
void empty(Stack& s);
int size(Stack& s);
void displayAll(Stack& s);

#endif // ! _Header_H_