/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--07--22                                                   **
 *                                                                      **
 * File: detab.h                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#ifndef _DETAB_H_
#define _DETAB_H_

#define MAXSIZE 200

#define NUMBER '0'
#define BEGIN '-'
#define INC '+'
#define UNKNOWN '\0'

#define YES 1
#define NO 0


// getop.cpp
int getop (const char* arg, char* s);

// utils.cpp
int find_next_stop (int i, char tab_flags[]);
void print_help ();

// detab.cpp
void detab (char tab_flags[]);


#endif // _DETAB_H_
