/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--16                                                   **
 *                                                                      **
 * File: expr.h                                                         **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#ifndef _EXPR_H_
#define _EXPR_H_

#define NUMBER '0'
#define MATH 'm'
#define UNKNOWN '\0'

// stack.cpp
void push (double f);
double pop ();
double top ();
void dup ();
void swap ();
void clear ();

// getop.cpp
int getop (char s[]);


#endif // _EXPR_H_



