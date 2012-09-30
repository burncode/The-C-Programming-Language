/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--07--22                                                   **
 *                                                                      **
 * File: detab.cpp                                                      **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include "detab.h"

void detab (const char tab_flags[])
{
    int c,  i,  next;

    // `i' marks the current point of the input, starts from 1.
    // `next' marks the next tab point.
    // Note that the point `next' cannot hold any character, 
    // input after `next' point starts from next + 1.
    for (i =  1; (c =  getchar ()) !=  EOF; ++i) {
        if (c ==  '\t') {
            // Replace tab with blanks.
            for (next =  find_next_stop (i,  tab_flags);
                 i <=  next && next > 0; ++i) {
                putchar (' ');
            }
            i--;

        } else if (c ==  '\n') {
            putchar (c);
            i =  0;

        } else {
            putchar (c);
        }
    }
}
