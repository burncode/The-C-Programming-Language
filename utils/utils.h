// Author: jrjbear@gmail.com
// Date: Wed Oct  2 20:45:59 2013
//
// File: utils.h
// Description: 

#ifndef UTILS_UTILS_H_
#define UTILS_UTILS_H_

// utils.cpp

// Note that `line' contains '\n' and this function
// returns the number of characters including '\n'.
int my_getline(char line[], int lim);
void reverse(char s[]);

// string_pool.cpp
void* alloc_mem(int size);
void free_mem (void* ptr);

#endif // UTILS_UTILS_H_
