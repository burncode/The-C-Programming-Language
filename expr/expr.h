// Author: jrjbear@gmail.com
// Date: Sun Oct 13 15:15:28 2013
//
// File: expr.h
// Description: Global declarations

#ifndef EXPR_EXPR_H_
#define EXPR_EXPR_H_

// Constants to distinguish tokens
const int NUMBER = '0';
const int MATH = 'm';
const int ERROR = 'e';

// stack.cpp
void push(double f);
double pop();
double top();
bool empty();
void clear();

// check_type.cpp
int check_type(const char s[]);

#endif // EXPR_EXPR_H_
