// Author: jrjbear@gmail.com
// Date: Sun Oct 13 21:23:11 2013
//
// File: detab.cpp
// Description: Replace TABs with blanks


#include <stdio.h>
#include "detab.h"

void detab(const bool tab_flags[], int size)
{
    // `next' marks the next tab position, which is indicated by `tab_flags'.
    // Note that position `next' cannot hold any character, input after `next'
    // position starts from `next + 1'.
    int next = -1;
    int c = -1;

    // `i' marks the current position.
    for (int i = 1; (c = getchar()) != EOF; ++i) {
        if (c == '\t') {
            for (int j = i, next = -1; j < size; ++j) {
                if (tab_flags[j]) {
                    next = j;
                    break;
                }
            }
            // Replace tab with blanks.
            for (; i <= next && next > 0; ++i) {
                putchar(' ');
            }
            i--;

        } else if (c == '\n') {
            putchar(c);
            i = 0;

        } else {
            putchar(c);
        }
    }
}
