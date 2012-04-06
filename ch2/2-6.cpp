/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--06                                                   **
 *                                                                      **
 * File: 2-6.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>

#define SIZE sizeof (unsigned long) * 8
#define MAXLINE 1024

int setbits (unsigned long* x, int p, 
             int n, unsigned long y);

int main ()
{
    unsigned long x, y;
    int p, n;

    while (scanf ("%lx%d%d%lx", &x, &p, 
                  &n, &y) == 4) {
        printf ("x = %#lx, y = %#lx\n", x, y);
        if (setbits (&x, p, n, y) < 0) {
            printf ("Invalid parameter\n\n");
        } else {
            printf ("After setbits (x, %d, %d, y): ", 
                    p, n);
            printf ("%#lx\n\n", x);
        }
    }

    return 0;
}

int setbits (unsigned long* x, int p, 
             int n, unsigned long y)
{
    if (p >= SIZE || p < 0 
        || n < 0 || n > p + 1) {
        return -1;
    }	

    // mask used to clear the required bits of x to 0
    unsigned long mask = ~0 << n;
    mask = ~mask;
    mask <<= (p - n + 1);
    mask = ~mask;

    // bits to set to x
    unsigned long bits = y & ~(~0 << n);
    bits <<= (p - n + 1);

    *x &= mask;
    *x |= bits;
    return 0;
}
