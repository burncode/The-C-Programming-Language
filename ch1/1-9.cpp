/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: 1-9.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>

int main ()
{
    int c, lastc;

    for (lastc = -1; (c = getchar ()) != EOF; 
         lastc = c) {
        if (lastc != ' ' || c != ' ') {
            putchar (c);
        }
    }

    return 0;
}
