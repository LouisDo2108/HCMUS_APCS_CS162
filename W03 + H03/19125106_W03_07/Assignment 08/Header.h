#pragma once
#ifndef _Header_H_
#define _Header_H_
#include <iostream>

using namespace std;

void login(int**& labs, int& currentID, int& currentLab, int& currentStation, int& lab, int*& station);
void logout(int**& labs, int& lab, int*& station);
bool search(int**& labs, int& lab, int*& station, int& resultlab, int& resultstation, int id);
void display(int** labs, int lab, int* station);
void createLabs(int**& labs, int& lab, int*& station);
#endif