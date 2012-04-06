/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--06                                                   **
 *                                                                      **
 * File: 2-9.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>

int bitcount (unsigned long x);
void unit_test(unsigned long x);

int main ()
{
    unsigned long x;

    while (scanf ("%lx", &x) == 1) {
        printf ("x = %#lx\n", x);
        printf ("x has %d bits\n\n", 
                bitcount (x));
    }
    
    return 0;
}

void unit_test(unsigned long x)
{
    printf("x = %#lx\n", x);
    printf("x has %d bits\n\n", bitcount(x));
}

int bitcount (unsigned long x)
{
    int count;

    if (x == 0) {
        return 0;
    }

    for (count = 1; (x &= (x - 1)) != 0; count++) {
        ;
    }
    return count;
}
