/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: 2-1.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include <limits.h>

int main () 
{
    printf ("Boundary calculated by program:\n");
    printf ("%15s%15s%15s\n", "Type", "Max Value", "Min Value");

    // Note that ~0 will produce a signed value (0xffffffff on 32-bit machine).
    // As a result ~0 >> 1 is equal to ~0 since shifting will take
    // sign bit into consideration.
    // We need to convert ~0 into unsigned value before shifting in this program.
    // For example, (char) ((unsigned char) ~0) >> 1) = 0x7f,
    // while (char) (~0 >> 1) = (char) (~((unsigned char) 0) >> 1) = 0xff
    // on this machine.

    printf ("%15s%15hhd%15hhd\n", "char", (char) ((unsigned char) ~0 >> 1), 
            (char) (1 << (sizeof (char) * 8 - 1)));
    printf ("%15s%15hhu%15hhu\n", "unsigned char", (unsigned char) ~0, 0u);

    printf ("%15s%15hd%15hd\n", "short", (short) ((unsigned short) ~0 >> 1), 
            (short) (1 << (sizeof (short) * 8 - 1)));
    printf ("%15s%15hu%15hu\n", "unsigned short", (unsigned short) ~0, 0u);

    printf ("%15s%15d%15d\n", "int", (int) ((unsigned int) ~0 >> 1), 
            (int) (1 << (sizeof (int) * 8 - 1)));
    printf ("%15s%15u%15u\n", "unsigned int", (unsigned int) ~0, 0u);

    printf ("%15s%15ld%15ld\n", "long", (long) ((unsigned long) ~0 >> 1), 
            (long) (1 << (sizeof (long) * 8 - 1)));
    printf ("%15s%15lu%15lu\n", "unsigned long", (unsigned long) ~0, 0ul);

    printf ("\nBoundary in system head file:\n");
    printf ("%15s%15s%15s\n", "Type", "Max Value", "Min Value");
	
    printf ("%15s%15hhd%15hhd\n", "char", CHAR_MAX, CHAR_MIN);
    printf ("%15s%15hhu%15hhu\n", "unsigned char", UCHAR_MAX, 0);
    printf ("%15s%15hd%15hd\n", "short", SHRT_MAX, SHRT_MIN);
    printf ("%15s%15hu%15hu\n", "unsigned short", USHRT_MAX, 0);
    printf ("%15s%15d%15d\n", "int", INT_MAX, INT_MIN);
    printf ("%15s%15u%15u\n", "unsigned int", UINT_MAX, 0);
    printf ("%15s%15ld%15ld\n", "long", LONG_MAX, LONG_MIN);
    printf ("%15s%15lu%15lu\n", "unsigned long", ULONG_MAX, 0ul);
}
