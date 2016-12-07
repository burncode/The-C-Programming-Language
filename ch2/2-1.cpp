// Author: jrjbear@gmail.com
// Date: Thu Oct  3 22:03:56 2013
//
// File: 2-1.cpp
// Description: Print max/min value of each type


#include <stdio.h>
#include <limits.h>

int main(int argc, char* argv[])
{
    printf("Boundary calculated by program:\n");
    printf("%15s%24s%24s\n", "Type", "Max Value", "Min Value");

    // Note that ~0 will produce a signed value (0xffffffff on 32-bit machine).
    // As a result ~0 >> 1 is equal to ~0 since shifting will take sign bit
    // into consideration. We need to convert ~0 into unsigned value before
    // shifting in this program. For example, (char)((unsigned char)~0 >> 1) = 0x7f,
    // while (char)(~0 >> 1) = 0xff on this machine.

    printf("%15s%24hhd%24hhd\n", "char", (char)((unsigned char)~0 >> 1), 
           (char)(1 << (sizeof(char) * 8 - 1)));
    printf("%15s%24hhu%24hhu\n", "unsigned char", (unsigned char)~0, (unsigned char)0);

    printf("%15s%24hd%24hd\n", "short", (short)((unsigned short)~0 >> 1), 
           (short)(1 << (sizeof(short) * 8 - 1)));
    printf("%15s%24hu%24hu\n", "unsigned short", (unsigned short)~0, (unsigned short)0);

    printf("%15s%24d%24d\n", "int", (int)((unsigned int)~0 >> 1), 
           (int)(1 << (sizeof(int) * 8 - 1)));
    printf("%15s%24u%24u\n", "unsigned int", (unsigned int)~0, 0u);

    printf("%15s%24ld%24ld\n", "long", (long)((unsigned long)~0 >> 1), 
           (long)(1l << (sizeof(long) * 8 - 1)));
    printf("%15s%24lu%24lu\n", "unsigned long", (unsigned long)~0, 0ul);

    printf("\nBoundary in system head file:\n");
    printf("%15s%24s%24s\n", "Type", "Max Value", "Min Value");
	
    printf("%15s%24d%24d\n", "char", CHAR_MAX, CHAR_MIN);
    printf("%15s%24u%24u\n", "unsigned char", UCHAR_MAX, 0);
    printf("%15s%24d%24d\n", "short", SHRT_MAX, SHRT_MIN);
    printf("%15s%24u%24u\n", "unsigned short", USHRT_MAX, 0);
    printf("%15s%24d%24d\n", "int", INT_MAX, INT_MIN);
    printf("%15s%24u%24u\n", "unsigned int", UINT_MAX, 0);
    printf("%15s%24ld%24ld\n", "long", LONG_MAX, LONG_MIN);
    printf("%15s%24lu%24lu\n", "unsigned long", ULONG_MAX, 0ul);
}
