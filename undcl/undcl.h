/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--11--04                                                   **
 *                                                                      **
 * File: undcl.h                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#ifndef _UNDCL_H_
#define _UNDCL_H_

#define NUMBER '0'
#define NAME 'N'
#define CONST 'C'


// gettoken.cpp
int gettoken (char s[]);

// Unget the last token that has been returned by `gettoken'. Note that
// you can only put back one token (which is the last one).
void unget_token ();

// Print error message preceded by the position information.
void undcl_error (const char* err);



// utils.cpp

// Note that `s' contains '\n' and this function
// returns the number of characters including '\n'.
int my_getline (char s[], int lim);



// dcl.cpp
int declaration (char* result);
int declarator (char* result);
int direct_declarator (char* result);

#endif // _UNDCL_H_
