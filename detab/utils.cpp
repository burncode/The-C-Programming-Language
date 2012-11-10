/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--07--22                                                   **
 *                                                                      **
 * File: utils.cpp                                                      **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include "detab.h"

int find_next_stop (int i, const char tab_flags[]) 
{
    for (; i < MAXSIZE; ++i) {
        if (tab_flags[i] == YES) {
            return i;
        }
    }
    
    return -1;
}

void print_help ()
{
    printf ("Usage: detab [-BEGIN] [+INC].\n"
            "       detab [STOP...].\n\n");

    printf ("BEGIN marks the first position of \\t. Default value\n"
            "of BEGIN is 0. INC marks the number of spaces between\n"
            "every two \\t. Default value of INC is 8.\n\n");

    printf ("STOP marks the exact position of a \\t.\n\n");

    printf ("Note that these 2 modes above cannot be specified at\n"
            "the same time.\n");
}

