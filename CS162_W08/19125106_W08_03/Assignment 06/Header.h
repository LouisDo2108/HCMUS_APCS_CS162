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
void sum(Node* headin, Node*& headout, Node* cur, int data);
void delLinkedlist(Node*& head);
void output(ofstream& f, Node*& headout);
#endif