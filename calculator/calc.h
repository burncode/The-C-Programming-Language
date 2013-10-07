// Author: jrjbear@gmail.com
// Date: Sun Oct  6 13:25:03 2013
//
// File: calc.h
// Description: Global declarations

#ifndef CALCULATOR_CALC_H_
#define CALCULATOR_CALC_H_

// Constants to distinguish tokens
const int NUMBER = '0';
const int ALPHA = 'A';
const int MATH = 'm';
const int VAL = 'v';
const int ERROR = 'e';

// stack.cpp
void push(double f, char c = '\0');
double pop();
double top();
char top_alpha();
void dup();
void swap();
bool empty();
void clear();

// getop.cpp
int getop(char s[]);

#endif // CALCULATOR_CALC_H_

