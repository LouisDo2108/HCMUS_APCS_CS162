#pragma once
#ifndef _Header_H_
#define _Header_H_

#include <iostream>
#include <fstream>	

using namespace std;

struct Node
{
	int data;
	Node* next = nullptr, *prev = nullptr;
};

void initDoublyLinkedList(ifstream& f, Node*& head1, Node*& head2);
void sum(ofstream& f, Node*& head1, Node*& head2);
void deleteAll(Node*& head);
#endif