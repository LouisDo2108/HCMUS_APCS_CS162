#pragma once
#ifndef _Header_H_
#define _Header_H_
#include <iostream>

using namespace std;

struct Queue
{
	int* data;
	int in, out, size;
};

void init(Queue& s, int size);
void enqueue(Queue& s, int x);
int dequeue(Queue& s);
bool isEmpty(Queue& s);
void empty(Queue& s);
int size(Queue& s);
#endif