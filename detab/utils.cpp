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

int find_next_stop (int i, char tab_flags[]) 
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
    printf ("Usage: detab [-BEGIN] [+INC].\n");
    printf ("       detab [STOP...].\n\n");
    printf ("BEGIN marks the first position \\t.\n");
    printf ("Default value of BEGIN is 0.\n");
    printf ("INC marks the number of spaces between every two \\t.\n");
    printf ("Default value of INC is 8.\n\n");

    printf ("STOP marks the exact position of a \\t.\n\n");

    printf ("Note that 2 modes above cannot be specified ");
    printf ("at the same time.\n");
}

