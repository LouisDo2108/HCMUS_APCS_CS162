#pragma once
#ifndef _Header_H_
#define _Header_H_

#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next = nullptr;
};

struct Stack
{
	Node* head = nullptr;
};

void push(Stack& s, int data);
int pop(Stack& s);

void display(Node* cur);
void displayAll(Stack& A, Stack& B, Stack& C);

void init(Stack& A, int N);
void move(Stack& source, Stack& destination);
void tower(int n, Stack& source, Stack& destination, Stack& support, Stack& A, Stack& B, Stack& C);

void remove(Stack& s);
void removeAll(Stack& A, Stack& B, Stack& C);
#endif // !_Header_H_
