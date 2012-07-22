/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--07--22                                                   **
 *                                                                      **
 * File: entab.cpp                                                      **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include "entab.h"

void entab (char tab_flags[]) 
{
    int c, i, next, last;

    // i marks the current point of the input, starts from 1.
    // last marks the last non-blank point.
    // next marks the next tab point, which is a multiple of NUM.
    // Note that the point next cannot hold any character,
    // input after next point starts from next + 1.
    for (i = 1, last = 0; 
         (c = getchar ()) != EOF; i++) {
        if (c == '\t') {
            next = find_next_stop (i, tab_flags);
            i = (next > 0? next: i);

        } else if (c == '\n') {
            putchar (c);
            i = last = 0;

        } else if (c != ' ') {
            if (last < i - 1) {
                // Insert tabs.
                for (last++, 
                     next = find_next_stop (last, tab_flags);
                     i > next && next > 0; 
                     last = next + 1, 
                     next = find_next_stop (last, tab_flags)) {
                    putchar ('\t');
                }

                // Fill the rest part with blanks.
                for(; last < i; last++) {
                    putchar (' ');
                }
            }

            // Now we reach the same position as input.

            last = i;
            putchar (c);
        }

        // Ignore blanks.
    }
}
