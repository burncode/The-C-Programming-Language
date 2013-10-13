// Author: jrjbear@gmail.com
// Date: Sun Oct 13 15:19:44 2013
//
// File: check_type.cpp
// Description: Determine which kind of token the input is


#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "expr.h"

int check_type(const char s[])
{
    int i = 0;
    char c = s[i];

    // Notice characters that can be the leading character of a number.     
    if (!isdigit(c) && c != '.' && c != '-' && c != '+') {
        return (s[i + 1] == '\0'? c: ERROR);
    }
    if (c == '-' || c == '+') {
        c = s[++i];
    }

    while (isdigit(c)) {
        c = s[++i];
    }     
    if (c == '.') {
        if (!isdigit(s[i + 1])) {
            // Cases such as .abc or -.abc or 123.abc.
            return ERROR;
        }
        do {
            c = s[++i];
        } while (isdigit(c));
    }
    
    if (c == '\0') {
        if (isdigit(s[i - 1])) {
            return NUMBER;
        } else if (i == 1) {
            return s[0];
        }
    }
    return ERROR;
}

