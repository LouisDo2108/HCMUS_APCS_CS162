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

void initCircularLinkedList(ifstream& f, Node*& head, Node*& tail);
void removeDuplicate(ofstream& f, Node*& head, Node*& tail);
void deleteAll(Node*& head, Node*& tail);
#endif