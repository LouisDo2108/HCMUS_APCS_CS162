#pragma once
#ifndef _Header_H_
#define _Header_H_

#include <iostream>
#include <fstream>

using namespace std;

struct Node
{
	int data;
	Node* next = nullptr;
};

void initLinkedlist(ifstream& f, Node*& head);
void remove_all_x(Node*& head, Node* prev, Node* cur, int& x);
void output(ofstream& f, Node*& head);
void delLinkedlist(Node*& head);
#endif