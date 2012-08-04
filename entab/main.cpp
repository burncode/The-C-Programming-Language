/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--07--01                                                   **
 *                                                                      **
 * File: main.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include "entab.h"

#define MAXLINE 1024

#define DFTINC 8
#define DFTBEGIN 0

int main (int argc, char* argv[]) 
{
    // `tab_flags' marks the position of each tab locates.
    // For example, if `tab_flags[1~7]' is `NO'
    // and `tab_flags[8]' is `YES', then a '\t' in position 1~8
    // will move the cursor directly to 9, which means
    // the character right after '\t' will appear at postion 9.
    bool inc_mode, list_mode;
    int begin, inc, stop, op;
    char tab_flags[MAXSIZE];
    char s[MAXLINE];

    inc_mode = false;
    list_mode = false;
    begin = DFTBEGIN;
    inc = DFTINC;

    for (int i = 0; i < MAXSIZE; ++i) {
        tab_flags[i] = NO;
    }

    while (--argc > 0) {
        op = getop (*++argv, s);

        switch (op) {
        case BEGIN:
            begin = atoi (s);
            inc_mode = true;
            break;

        case INC:
            inc = atoi (s);
            inc_mode = true;
            break;

        case NUMBER:
            stop = atoi (s);
            tab_flags[stop] = YES;
            list_mode = true;
            break;

        case UNKNOWN:
        default:
            print_help ();
            return -1;
        }
    }

    if (inc_mode && list_mode) {
        print_help ();
        return -1;
    }

    if (!list_mode) {
        for (int i = begin; i < MAXSIZE; i += inc) {
            tab_flags[i] = YES;
        }
    }

    entab (tab_flags);
    return 0;
}

