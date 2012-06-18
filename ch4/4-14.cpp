/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--18                                                   **
 *                                                                      **
 * File: 4-14.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>

#define swap(t, x, y)                           \
    {                                           \
        t __temp__;                             \
        __temp__ = x;                           \
        x = y;                                  \
        y = __temp__;                           \
    }

int main ()
{
    int a_int[] = {1, 2};
    double a_double[] = {1.1, 2.2};
    const char* ap_buf[] = {"hello", "world"};

    printf ("x = %d, y = %d\n", a_int[0], a_int[1]);
    swap (int, a_int[0], a_int[1]);
    printf ("After swap: x = %d, y = %d\n\n", 
            a_int[0], a_int[1]);
		
    printf ("x = %g, y = %g\n", a_double[0], a_double[1]);
    swap (double, a_double[0], a_double[1]);
    printf ("After swap: x = %g, y = %g\n\n", 
            a_double[0], a_double[1]);
    
    printf ("x = %s, y = %s\n", ap_buf[0], ap_buf[1]);
    swap (const char*, ap_buf[0], ap_buf[1]);
    printf ("After swap: x = %s, y = %s\n\n", 
            ap_buf[0], ap_buf[1]);

    return 0;
}
