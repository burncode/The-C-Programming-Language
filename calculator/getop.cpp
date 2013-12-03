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
    static char line[MAXLINE] = "";
    static int pos = 0;

    int c = line[pos];
    int i = 0;
    s[i] = '\0';
    do {
        if (c == '\0') {
            pos = 0;
            if (my_getline(line, MAXLINE) <= 0) {
                return EOF;
            }
        }	

        do {
            c = line[pos++];
        } while (c == ' ' || c == '\t');
    } while (c == '\0');

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
            return (isupper(s[0])? ALPHA: s[0]);
        }
    }

    // Notice characters that can be the leading character of a number.     
    if (!isdigit(c) && c != '.' && c != '-' && c != '+') {
        return c;
    }
    if (c == '-' || c == '+') {
        s[i++] = c;
        c = line[pos++];
    }

    bool has_number = false;
    while (isdigit(c)) {
        s[i++] = c;
        c = line[pos++];
        has_number = true;
    }
    if (c == '.') {
        if (!isdigit(line[pos])) {
            // Cases such as .abc or -.abc or 123.abc.
            pos -= (has_number? 1: i);
            s[i] = '\0';
            return (has_number? NUMBER: (i > 0? s[0]: c));
        }
        do {
            s[i++] = c;
            c = line[pos++];
            has_number = true;
        } while (isdigit(c));
    }
    pos--;
    s[i] = '\0';
    return (has_number? NUMBER: s[0]);
}
