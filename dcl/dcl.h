/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--11--04                                                   **
 *                                                                      **
 * File: dcl.h                                                          **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#ifndef _DCL_H_
#define _DCL_H_

#define NUMBER '0'
#define NAME 'N'
#define CONST 'C'


// gettoken.cpp
int gettoken (char s[]);

// Unget the last token that has been returned by `gettoken'. Note that
// you can only put back one token (which is the last one).
void unget_token ();

// Print error message preceded by the position information.
void dcl_error (const char* err);



// utils.cpp

// Note that '\n' is removed in `s' and this function returns the
// number of the remaining characters.
int my_getline (char s[], int lim);



// dcl.cpp
int declaration (char* result);
int declarator (char* result);
int direct_declarator (char* result);

#endif // _DCL_H_
