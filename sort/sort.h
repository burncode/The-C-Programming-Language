/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--07--21                                                   **
 *                                                                      **
 * File: sort.h                                                         **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#ifndef _SORT_H_
#define _SORT_H_

#define FLAG '-'
#define NUMBER '0'
#define UNKNOWN '\0'

#define MAXLINE 1024


typedef int (*CmpFn) (const void*, const void*);


extern bool g_ignore_case;
extern int g_field_num;

// qsort.cpp
void qsort (char* lineptr[], int left, int right, CmpFn fn);


// compare.cpp
int my_strcmp (const char* s1, const char* s2);
int numcmp (const char* s1, const char* s2);
int dircmp (const char* s1, const char* s2);





// char_pool.cpp

// Return a pointer to a memory chunk in this pool. This function
// will check free list first.
void* alloc_mem (int size);

// Add chunk `ptr' to free list. Note that the free list is ordered
// by address of each chunk and chunks can merge into bigger one
// if they are contiguous.
void free_mem (void* ptr);


// utils.cpp

// Note that '\n' is removed in `s' and this function returns the
// number of the remaining characters.
int my_getline (char s[], int lim);

void swap (char* v[], int i, int j);

// Find the `field_num'th field in `s'. Fields are separated by
// blanks. Results will be returned in `begin' and `end' so that
// [`begin', `end') marks this field string.
void find_field (const char* s, int field_num, int* begin, int* end);

void print_help ();




// getop.cpp
int getop (const char* arg, char* s);


#endif // _SORT_H_

