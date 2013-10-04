// Author: jrjbear@gmail.com
// Date: Fri Oct  4 17:54:23 2013
//
// File: 2-9.cpp
// Description: Bit counting

#include <stdio.h>
#include <stdint.h>

int bitcount(uint32_t x);

int main(int argc, char* argv[])
{
    uint32_t x = 0;
    while (true) {
        printf("Input parameters in hexadecimal(x): ");
        if (scanf("%x", &x) != 1) {
            break;
        }
        printf("%#x has %d bits\n\n", x, bitcount(x));
    }
    
    return 0;
}

int bitcount(uint32_t x)
{
    if (x == 0) {
        return 0;
    }
    int count = 1;
    for (; (x &= (x - 1)) != 0; count++) {
        ;
    }
    return count;
}
