// Author: jrjbear@gmail.com
// Date: Sun Oct  6 13:22:21 2013
//
// File: getop.cpp
// Description: Get the next token from stdin


#include <stdio.h>
#include <ctype.h>
#include "utils/utils.h"
#include "calc.h"

int getop(char s[])
{
    static const int MAXLINE = 1024;
    static char line[MAXLINE];
    static int pos = 0;

    if (line[pos] == '\0') {
        if (my_getline(line, MAXLINE) > 0) {
            pos = 0;
        } else {
            return EOF;
        }
    }	       

    int i = 0;
    s[i] = '\0';

    int c = -1;
    do {
        c = line[pos++];
    } while (c == ' ' || c == '\t');

    if (isalpha(c)) {
        // Mathematic commands or single character.
        do {
            s[i++] = c;
            c = line[pos++];
        } while (isalpha(c));
        pos--;
        s[i] = '\0';

        if (i > 1) {
            return MATH;
        } else {
            if (isupper(s[0])) {
                return ALPHA;
            } else {
                return s[0];
            }
        }
    }

    // Notice characters that can be the leading character of a number.     
    if (!isdigit(c) && c != '.' && c != '-' && c != '+') {
        return c;
    }
    if (c == '-' || c == '+') {
        // '+' and '-' may be followed by a digit or a '.'.
        if (isdigit(line[pos]) || (line[pos] == '.' 
                                   && isdigit(line[pos + 1]))) {
            // Case such as +.123 or +123.
        } else {
            return c;
        }
    }
    // '.' should be followed by a digit to be a pure digit number.
    if (c == '.' && !isdigit(line[pos])) {
        return c;
    }
    do {
        s[i++] = c;
        c = line[pos++];
    } while (isdigit(c));

    if (c == '.') {
        if (!isdigit(line[pos])) {
            // Case such as 123.abc.
            pos--;
            s[i - 1] = '\0';
            return NUMBER;
        }
        do {
            s[i++] = c;
            c = line[pos++];
        } while (isdigit(c));
    }
    s[i] = '\0';
    pos--;
    return NUMBER;
}

