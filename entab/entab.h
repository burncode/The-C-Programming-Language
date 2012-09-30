/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--07--22                                                   **
 *                                                                      **
 * File: entab.h                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#ifndef _ENTAB_H_
#define _ENTAB_H_

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
int find_next_stop (int i, const char tab_flags[]);
void print_help ();

// entab.cpp
void entab (const char tab_flags[]);


#endif // _ENTAB_H_
