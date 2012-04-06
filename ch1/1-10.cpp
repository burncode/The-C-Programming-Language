/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: 1-10.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>

int main ()
{
    int c;

    for (c = getchar (); c != EOF; c = getchar ()) {
        if (c == '\t') {
            putchar ('\\');
            putchar ('t');
        } else if (c == '\b') {
            putchar ('\\');
            putchar ('b');
        } else if (c == '\\') {
            putchar ('\\');
            putchar ('\\');
        } else {
            putchar (c);
        }
    }

    return 0;
}
