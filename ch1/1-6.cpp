/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: 1-6.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>

int main ()
{
    int c;
    printf ("Input a character: ");
    c = getchar () != EOF;
    printf ("Value of getchar() != EOF is: %d\n", c);

    return 0;
}
