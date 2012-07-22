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
#include "entab.h"

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
    printf ("Usage: entab [-begin] [+inc].\n");
    printf ("       entab [stop...].\n");
    printf ("Note that 2 modes above cannot be specified ");
    printf ("at the same time.\n");
    printf ("If no arguments are specified, ");
    printf ("the default mode is inc-mode with ");
    printf ("begin = 0 and inc = 8.\n");
}


