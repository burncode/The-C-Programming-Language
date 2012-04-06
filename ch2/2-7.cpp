/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--06                                                   **
 *                                                                      **
 * File: 2-7.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>

#define SIZE sizeof (unsigned long) * 8

int invert (unsigned long* x, int p, int n);

int main ()
{
    unsigned long x;
    int p, n;

    while (scanf ("%lx%d%d", &x, 
                  &p, &n) == 3) {
        printf ("x = %#lx\n", x);
        if (invert (&x, p, n) < 0) {
            printf ("Invalid parameter\n\n");
        } else {
            printf ("After invert (x, %d, %d): ", 
                    p, n);
            printf ("%#lx\n\n", x);
        }
    }

    return 0;
}

int invert (unsigned long* x, int p, int n)
{
    if (p >= SIZE || p < 0 
        || n < 0 || n > p + 1) {
        return -1;
    }

    unsigned long mask = ~(~0 << n) << (p - n + 1);
    *x ^= mask;
    return 0;
}
