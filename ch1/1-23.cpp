/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: 1-23.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>

#define CODE 0
#define LINE_COMMENT 1
#define MULTI_COMMENT 2

void enter_quotes (char c);

int main () 
{
    int state, c;

    state = CODE;

    while ((c = getchar ()) != EOF) {
        if (state == CODE) {
            if (c == '\"' || c == '\'') {
                putchar (c);
                enter_quotes (c);

            } else if (c == '/') {
                c = getchar ();
                if (c == '/') {
                    state = LINE_COMMENT;
                } else if (c == '*') {
                    state = MULTI_COMMENT;
                } else {
                    // '/' is not followed by '/' or '*', 
                    // so we should ouput what we read.
                    putchar('/');
                    putchar(c);
                }

            } else {
                putchar(c);
            }

        } else if (state == LINE_COMMENT && c == '\n') {
            state = CODE;
            putchar (c);

        } else if (c == '*' && state == MULTI_COMMENT) {
            if (getchar () == '/') {
                state = CODE;
            }
        }

        // Comment area, do not output.
    } 

    return 0;
}

void enter_quotes (char c) 
{
    char d, e;

    // d marks the current character.
    // e marks the last character.
    e = 0;
    while ((d = getchar ()) != EOF) {
        putchar (d);

        // Loop until we encounter a non-escaped quote.
        if (e != '\\' && d == c) {
            break;
        }
        e = d;
    }
}
