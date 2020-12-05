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
void delLinkedlist(Node*& head);
void list_to_num(ofstream& f, Node*& head);
#endif
