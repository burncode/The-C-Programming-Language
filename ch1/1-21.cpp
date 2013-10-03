// Author: jrjbear@gmail.com
// Date: Thu Oct  3 14:10:15 2013
//
// File: 1-21.cpp
// Description: Replace blanks with TABs

#include <stdio.h>

void entab(int tab_offset);

int main(int argc, char* argv[])
{
    const int TAB_OFFSET = 8;
    entab(TAB_OFFSET);
    return 0;
}

void entab(int tab_offset)
{
    int c = -1;

    // `i' marks the current position. `last' marks the last non-blank position.
    for (int i = 1, last = 0; (c = getchar()) != EOF; i++) {
        if (c == '\t') {
            i = (i + tab_offset - 1) / tab_offset * tab_offset;

        } else if (c == '\n') {
            putchar(c);
            i = last = 0;

        } else if (c != ' ') {
            if (last < i - 1) {
                // Ready to insert tabs after `last' position
                ++last;
                // `next' marks the next tab position, which is a multiple
                // of `tab_offset'. Note that position `next' cannot hold
                // any character, input after `next' position starts from
                // `next + 1'.
                for (int next = (last + tab_offset - 1) 
                         / tab_offset * tab_offset;
                     i > next; last = next + 1, next += tab_offset) {
                    putchar('\t');
                }

                // Fill the rest part with blanks.
                for(; last < i; last++) {
                    putchar(' ');
                }
            }

            // Now we reach the same position as input.
            last = i;
            putchar(c);
        }

        // Ignore blanks.
    }
}
