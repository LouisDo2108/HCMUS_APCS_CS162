#pragma once
#ifndef _Header_H_
#define _Header_H_
#include <iostream>
#include <string>

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

void push(Stack& s, int x);
int pop(Stack& s);
void display(Stack& s);
void emptyStack(Stack& s);

void dec_to_bin(Stack& s, int dec);
int bin_to_dec(Stack& q, string bin);

void dec_to_hex(Stack& s, int dec);
int hex_to_dec(Stack& s, string hex);

#endif // !_Header_H_
