#pragma once
#ifndef _Header_H_
#define _Header_H_

using namespace std;

bool isSafe(bool*& column, bool*& ld, bool*& rd, int r, int c, int n);
void solveNQueen(int*& queens, bool*& column, bool*& ld, bool*& rd, int r, int n);
void displayChess(int* queens, int n);
#endif // !_Header_H_

