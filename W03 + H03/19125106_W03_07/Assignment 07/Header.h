#pragma once
#ifndef _Header_H_
#define _Header_H_

#include <iostream>
#include <fstream>

using namespace std;

void read_correct_answers(ifstream& f, char *&canswers, int& n);
void read_student_answers(ifstream& f, char *&sanswers, int& n);
void output_result(char* canswers, char* sanswers, int& n);

#endif