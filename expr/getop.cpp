/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--07--01                                                   **
 *                                                                      **
 * File: getop.cpp                                                      **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "expr.h"

int getop (char s[])
{
    int i;
    char c;

    i = 0;
    c = s[i];
    
    if (isalpha (c)) {
        while (isalpha (s[++i])) {
            ;
        }

        if (s[i] == '\0') {
            return (i > 1? MATH: c);
        } else {
            return UNKNOWN;
        }
    }

    // These characters can be the leading character
    // of a number.     
    if (!isdigit (c) && c != '.' 
        && c != '-' && c != '+') {
        return (s[i + 1] == '\0'? c: UNKNOWN);
    }
   
    // '+' and '-' should be followed by a digit
    // to be a number or be followed by a '.'.
    // For example, -.123.
    if ((c == '-' || c == '+')
        && !isdigit (s[i + 1])
        && s[i + 1] != '.') {
        return (s[i + 1] == '\0'? c: UNKNOWN);
    }
  
    // Ugly stuff, unget '.' which will be handled later.
    if (c == '.') {
        i--;
    }
    
    while (isdigit (s[++i])) {
        ;
    }
     
    if (s[i] == '.') {
        // '.' should be followed by a digit
        // to be a digit number.
        if (!isdigit (s[i + 1])) {
            return UNKNOWN;
        }

        while (isdigit (s[++i])) {
            ;
        }
    }

    return (s[i] == '\0'? NUMBER: UNKNOWN);
}

