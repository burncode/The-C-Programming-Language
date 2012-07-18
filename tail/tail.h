/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--07--18                                                   **
 *                                                                      **
 * File: tail.h                                                         **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#ifndef _TAIL_H_
#define _TAIL_H_

// utils.cpp

// Note that s contains '\n' and this function
// returns the number of characters including '\n'.
int my_getline (char s[], int lim);



// char_pool.cpp

// Add chunk ptr to free list.
// Note that the free list is ordered by address of each chunk
// and chunks can merge into bigger one if they are contiguous.
void free_mem (void* ptr);

// Return a pointer the a memory chunk in this pool.
// This function will check free list first.
void* alloc_mem (int size);

#endif // _TAIL_H_
