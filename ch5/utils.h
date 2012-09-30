/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--07--19                                                   **
 *                                                                      **
 * File: utils.h                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#ifndef _UTILS_H_
#define _UTILS_H_

// Note that '\n' is removed in s and this function
// returns the number of the remaining characters.
int my_getline (char s[], int lim);

void reverse (char s[]);

int getch ();

void ungetch (int c);


#endif // _UTILS_H_
