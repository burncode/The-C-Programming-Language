/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--06                                                   **
 *                                                                      **
 * File: 2-8.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>

#define SIZE sizeof (unsigned long) * 8

int rightrot (unsigned long* x, int n);

int main ()
{
    unsigned long x;
    int n;

    while (scanf ("%lx%d", &x, &n) == 2) {
        printf ("x = %#lx\n", x);
        if (rightrot (&x, n) < 0) {
            printf ("Invalid parameter\n\n");
        } else {
            printf ("After rightrot (x, %d): ", n);
            printf ("%#lx\n\n", x);
        }
    }

    return 0;
}

void unit_test(unsigned long x, int n)
{
    printf("x = %#lx\n", x);
    printf("After rightrot(x, %d): ", n);

    if(rightrot(&x, n) < 0) {
        printf("Invalid parameter\n\n");
    } else {
        printf("%#lx\n\n", x);
    }
}

int rightrot (unsigned long* x, int n)
{
    if (n < 0) {
        return -1;
    }

    n %= SIZE;
    unsigned long head = *x << (SIZE - n);
    unsigned long tail = *x >> n;

    *x = head | tail;
    return 0;
}
