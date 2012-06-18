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
#include "common.hpp"

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

        if (i > 1) {
            s[i] = '\0';
            return MATH;
        } else {
            s[1] = '\0';
            if (isupper (s[0])) {
                return ALPHA;
            } else {
                return s[0];
            }
        }
    }
        
    if (!isdigit (c) && c != '.' 
        && c != '-' && c != '+') {
        return c;
    }

    // These characters can be the leading character
    // of a number.
    if ((c == '.' || c == '-' || c == '+')
        && !isdigit (line[pos])) {
        return c;
    }

    do {
        s[i++] = c;
        c = line[pos++];
    } while (isdigit (c));

    // Deal with special case that contains multiple '.'
    // in elements.
    // For example, .123.456.
    if (c == '.' && s[0] != '.') {
        do {
            s[i++] = c;
            c = line[pos++];
        } while (isdigit (c));
    }

    s[i] = '\0';
    pos--;
    return NUMBER;
}

