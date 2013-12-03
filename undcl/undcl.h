// Author: jrjbear@gmail.com
// Date: Tue Dec  3 17:58:29 2013
//
// File: undcl.h
// Description: Global declarations

#ifndef UNDCL_UNDCL_H_
#define UNDCL_UNDCL_H_

// Constants to distinguish tokens
const int NUMBER = '0';
const int NAME = 'N';
const int CONST = 'C';


// gettoken.cpp
int gettoken(char s[]);

// Unget the lastest token that has been returned by `gettoken'.
// Note that tokens of older lines can't be ungotten.
void unget_token();

// Print error message along with the position of the latest token
void undcl_error(const char* err);


// stack.cpp
void push(int i);
int pop();
int top();
bool empty();
void clear();

#endif // UNDCL_UNDCL_H_
