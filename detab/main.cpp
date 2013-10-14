// Author: jrjbear@gmail.com
// Date: Sun Oct 13 21:57:08 2013
//
// File: main.cpp
// Description: Replace TABs with blanks


#include <stdio.h>
#include <stdlib.h>             // atoi
#include "detab.h"

void print_usage();

int main(int argc, char* argv[]) 
{
    const int MAXLINE = 1024;
    const int DFTINC = 8;
    const int DFTBEGIN = 0;
    
    bool inc_mode = false;
    bool list_mode = false;
    int begin = DFTBEGIN;
    int inc = DFTINC;
    int stop = 0;
    char buf[MAXLINE];

    // `tab_flags[i]' is true means that a TAB before position `i' will
    // immediately move the cursor to `i+1'.
    bool tab_flags[MAXLINE];
    for (int i = 0; i < MAXLINE; ++i) {
        tab_flags[i] = false;
    }

    while (--argc > 0) {
        Option op = my_getopt(*++argv, buf);
        switch (op) {
        case BEGIN:
            begin = atoi(buf);
            inc_mode = true;
            break;

        case INC:
            inc = atoi(buf);
            inc_mode = true;
            break;

        case NUMBER:
            stop = atoi(buf);
            tab_flags[stop] = true;
            list_mode = true;
            break;

        case ERROR:
            printf("Wrong format argument: %s\n", *argv);
            print_usage();
            return -1;
        default:
            printf("Impossible to reach here!\n");
            return -1;
        }
    }

    if (inc_mode && list_mode) {
        print_usage();
        return -1;
    }
    // Uses INC mode by default
    if (!list_mode) {
        for (int i = begin; i < MAXLINE; i += inc) {
            tab_flags[i] = true;
        }
    }

    detab(tab_flags, MAXLINE);
    return 0;
}

void print_usage()
{
    printf("Usage: detab [-BEGIN] [+INC].\n"
           "       detab [STOPs...].\n\n");

    printf("BEGIN marks the first position of \\t. Default value\n"
           "of BEGIN is 0. INC marks the number of spaces between\n"
           "every two \\t. Default value of INC is 8.\n\n");

    printf("STOP marks the exact position of a \\t.\n\n");

    printf("Note that these 2 modes above cannot be specified at\n"
           "the same time.\n");
}
