// Author: jrjbear@gmail.com
// Date: Sat Nov 30 20:55:59 2013
//
// File: dcl.h
// Description: Global declarations

#ifndef DCL_DCL_H_
#define DCL_DCL_H_

// Constants to distinguish tokens
const int NUMBER = '0';
const int NAME = 'N';
const int CONST = 'C';
const int VAL = 'v';

typedef bool (*TryFn)(int type);

// gettoken.cpp
int gettoken(char s[]);

// Unget the lastest token that has been returned by `gettoken'.
// Note that tokens of older lines can't be ungotten.
void unget_token();

// Print error message along with the position of the latest token
void dcl_error(const char* err);


// stack.cpp
void push(int i);
int pop();
int top();
bool empty();
void clear();


// dcl.cpp
int declaration(char* result);
int declarator(char* result);
int direct_declarator(char* result);

// try_token.cpp
bool try_name(int type);
bool try_array(int type);
bool try_right_paran(int type);
bool try_right_bracket(int type);
bool try_func_array(int type);
bool try_func_array_dcl(int type);
bool try_func_param(int type);
bool try_func_comma(int type);
bool try_declaration(int type);
bool try_declarator(int type);
bool try_direct_declarator(int type);

// Consume tokens until `expect' or `next_expect' returns true.
// When `next_expect' matches, `err' will be printed and this
// token will be ungotten. Returns the required token (through
// parameters) and the number of errors it came across. Note
// that `EOF' and '\n' as special cases will be always treated
// like `next_expect'.
int try_tokens_until(int* type, char token[], TryFn expect, 
                     TryFn next_expect, const char* err);

#endif // DCL_DCL_H_
