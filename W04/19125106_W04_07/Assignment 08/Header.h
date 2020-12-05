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

void initLinkedlist(ifstream& f, Node*& head1, Node*& head2);
void delLinkedlist(Node*& head);
void two_into_one(ofstream& f, Node*& head1, Node*& head2);
#endif