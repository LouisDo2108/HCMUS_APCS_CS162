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

struct Queue
{
	Node* head, *tail;
	int count, size;
};

void init(Queue& q, int size);
void enqueue(Queue& q, int x);
int dequeue(Queue& q);
bool isEmpty(Queue& q);
void empty(Queue& q);
int size(Queue& q);
void displayAll(Queue q);
#endif 