/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--06                                                   **
 *                                                                      **
 * File: 2-10.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>

int lower (int c)
{ return (c >= 'A' && c <= 'Z')? c - 'A' + 'a': c; }

int main ()
{
    char c;
    while (scanf ("%c", &c) == 1) {
        if (c == '\n') {
            continue;
        }

        printf ("lower (%c) is %c\n", c, 
                lower (c));
    }

    return 0;
}
