// Author: jrjbear@gmail.com
// Date: Thu Oct  3 13:59:59 2013
//
// File: 1-20.cpp
// Description: Replace TABs with blanks

#include <stdio.h>

void detab(int tab_offset);

int main(int argc, char* argv[])
{
    const int TAB_OFFSET = 8;
    detab(TAB_OFFSET);
    return 0;
}

void detab(int tab_offset) 
{
    // `next' marks the next tab position, which is a multiple of `tab_offset'.
    // Note that position `next' cannot hold any character, input after
    // `next' position starts from `next + 1'.
    int next = -1;
    int c = -1;

    // `i' marks the current position.
    for (int i = 1; (c = getchar()) != EOF; ++i) {
        if (c == '\t') {
            // Replace tab with blanks.
            for (next = (i + tab_offset - 1) / tab_offset * tab_offset; 
                 i <= next; ++i) {
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
