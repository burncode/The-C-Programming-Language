// Author: jrjbear@gmail.com
// Date: Mon Oct 14 01:09:57 2013
//
// File: entab.cpp
// Description: Replace blanks with TABs


#include <stdio.h>
#include "entab.h"

void entab(const bool tab_flags[], int size) 
{
    int c = -1;
    // `i' marks the current point of the input, starts from 1.
    // `next' marks the next tab point. Note that the point
    // `next' cannot hold any character, input after `next'
    // point starts from `next + 1'.
    for (int i = 1, last = 0; (c = getchar()) != EOF; i++) {
        if (c == '\t') {
            int next = find_next_stop(tab_flags, size, i);
            i = (next > 0? next: i);

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
                for (int next = find_next_stop(tab_flags, size, last);
                     i > next && next > 0; 
                     last = next + 1, 
                         next = find_next_stop(tab_flags, size, last)) {
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

int find_next_stop(const bool tab_flags[], int size, int pos)
{
    for (int i = pos; i < size; ++i) {
        if (tab_flags[i]) {
            return i;
        }
    }
    return -1;
}
