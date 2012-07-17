/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--16                                                   **
 *                                                                      **
 * File: calc.h                                                         **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#ifndef _CALC_H_
#define _CALC_H_

#define NUMBER '0'
#define ALPHA 'A'
#define MATH 'm'
#define VAL 'v'

// stack.cpp
void push (double f);
double pop ();
double top ();
void dup ();
void swap ();
void clear ();

// getop.cpp
int getop (char s[]);

// utils.cpp

// Note that s contains '\n' and this function
// returns the number of characters including '\n'.
int my_getline (char s[], int lim);
void reverse (char s[]);


#endif // _CALC_H_



