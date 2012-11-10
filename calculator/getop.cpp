/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--16                                                   **
 *                                                                      **
 * File: getop.cpp                                                      **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "calc.h"

#define MAXLINE 1024

int getop (char s[])
{
    static char line[MAXLINE];
    static int pos = 0;

    int i, c;

    if (line[pos] == '\0') {
        if (my_getline (line, MAXLINE) <= 0) {
            return EOF;
        } else {
            pos = 0;
        }
    }	       

    i = 0;
    s[i] = '\0';

    do {
        c = line[pos++];
    } while (c == ' ' || c == '\t');

    if (isalpha (c)) {
        // Mathematic commands or single character.
        do {
            s[i++] = c;
            c = line[pos++];
        } while (isalpha (c));

        // unget a character.
        pos--;
        s[i] = '\0';

        if (i > 1) {
            return MATH;
        } else {
            if (isupper (s[0])) {
                return ALPHA;
            } else {
                return s[0];
            }
        }
    }

    // These characters can be the leading character of a number.     
    if (!isdigit (c) && c != '.' 
        && c != '-' && c != '+') {
        return c;
    }
   
    // '+' and '-' should be followed by a digit to be a number
    // or be followed by a '.'. For example, -.123.
    if ((c == '-' || c == '+')
        && !isdigit (line[pos])
        && line[pos] != '.') {
        return c;
    }

    // '.' should be followed by a digit to be a pure digit number.
    if (c == '.' && !isdigit (line[pos])) {
        return c;
    }

    do {
        s[i++] = c;
        c = line[pos++];
    } while (isdigit (c));
     
    if (c == '.') {
        // '.' should be followed by a digit to be a digit number.
        if (!isdigit (line[pos])) {
            // Unget the '.'.
            pos--;
            s[i] = '\0';

            if (!isdigit (s[0]) && i <= 1) {
                // Case such as +.abc.
                return s[0];
            } else {
                // Case such as -123..
                return NUMBER;
            }
        }

        do {
            s[i++] = c;
            c = line[pos++];
        } while (isdigit (c));
    }

    s[i] = '\0';
    pos--;
    return NUMBER;
}

