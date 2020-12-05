#pragma once
#ifndef _Header_H_
#define _Header_H_

#include <iostream>

using namespace std;

struct Room
{
	char ID[4];
	int UsableArea;
	bool Furnished;
	int NumOfPeople;
	bool HaveBreakFast;
};

struct Node
{
	Room room;
	Node* next = nullptr;
};

void init(Node*& head);
void inputRoom(Node*& head);
void deleteRoom(Node*& head, char id[4]);
void displayInfo(Node* head);
void searchRoom(Node* head, int num, bool breakfast);
void removeRoomK(Node*& head, int k);
void removeAll(Node*& head);
void displayAll(Node* head);
#endif