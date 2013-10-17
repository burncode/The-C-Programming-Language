// Author: jrjbear@gmail.com
// Date: Tue Oct 15 23:40:49 2013
//
// File: sort.h
// Description: Global declarations


#ifndef SORT_SORT_H_
#define SORT_SORT_H_


typedef int (*CmpFn)(const char*, const char*);

extern bool g_ignore_case;
extern int g_field_num;

// qsort.cpp
void qsort(char* lineptr[], int left, int right, CmpFn fn);
void swap(char* v[], int i, int j);

// Find the `field_num'th field in `s'. Fields are separated by
// blanks. Results will be returned in `begin' and `end' so that
// [`begin', `end') marks this field string.
void select_field(const char* s, int field_num, int* begin, int* end);


// compare.cpp
int my_strcmp(const char* s1, const char* s2);
int numcmp(const char* s1, const char* s2);
int dircmp(const char* s1, const char* s2);




void print_help ();


#endif // SORT_SORT_H_
