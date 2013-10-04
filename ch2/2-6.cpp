// Author: jrjbear@gmail.com
// Date: Fri Oct  4 17:20:04 2013
//
// File: 2-6.cpp
// Description: Bit operations

#include <stdio.h>
#include <stdint.h>

// Set `n' bits beginning at the position `p' of `x' to the rightmost `n'`
// bits of `y'.
int setbits(uint32_t* x, int p, int n, uint32_t y);

int main(int argc, char* argv[])
{
    uint32_t x = 0;
    uint32_t y = 0;
    int p = -1;
    int n = -1;
    while (true) {
        printf("Input parameters in hexadecimal(x p n y): ");
        if (scanf("%x%d%d%x", &x, &p, &n, &y) != 4) {
            break;
        }
        uint32_t save_x = x;
        if (setbits(&x, p, n, y) == 0) {
            printf("After setbits(%#x, %d, %d, %#x): %#x\n\n", 
                   save_x, p, n, y, x);
        } else {
            break;
        }
    }

    return 0;
}

int setbits(uint32_t* x, int p, int n, uint32_t y)
{
    static const int BITSIZE = sizeof(uint32_t) * 8;

    if (p >= BITSIZE || p < 0 || n < 0 || n > p + 1) {
        printf("Invalid parameter (p, n): (%d, %d)\n", p, n);
        return -1;
    }

    // `mask' will be used to clear the required bits of x to 0.
    uint32_t mask = ~0 << n;
    mask = ~mask;
    mask <<= (p - n + 1);
    mask = ~mask;
    *x &= mask;

    // `bits' will be set to x.
    uint32_t bits = y & ~(~0 << n);
    bits <<= (p - n + 1);
    *x |= bits;

    return 0;
}
