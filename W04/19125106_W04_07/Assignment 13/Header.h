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

void initLinkedlist(ifstream& f, Node*& head, bool& check, Node*& originalTail);
void delLinkedlist(Node*& head, bool& check, Node*& originalTail);
void check_loop(ofstream& f, Node*& head, bool& check);
#endif