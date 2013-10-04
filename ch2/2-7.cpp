// Author: jrjbear@gmail.com
// Date: Fri Oct  4 17:41:53 2013
//
// File: 2-7.cpp
// Description: Bit operations

#include <stdio.h>
#include <stdint.h>

// Invert `n' bits that begin at position `p' of `x'.
int invert(uint32_t* x, int p, int n);

int main(int argc, char* argv[])
{
    uint32_t x = 0;
    int p = -1;
    int n = -1;
    while (true) {
        printf("Input parameters in hexadecimal(x p n): ");
        if (scanf("%x%d%d", &x, &p, &n) != 3) {
            break;
        }
        uint32_t save_x = x;
        if (invert(&x, p, n) == 0) {
            printf ("After invert(%#x, %d, %d): %#x\n\n", 
                    save_x, p, n, x);
        } else {
            break;
        }
    }

    return 0;
}

int invert(uint32_t* x, int p, int n)
{
    static const int BITSIZE = sizeof(uint32_t) * 8;

    if (p >= BITSIZE || p < 0 || n < 0 || n > p + 1) {
        printf("Invalid parameter (p, n): (%d, %d)\n", p, n);
        return -1;
    }

    uint32_t mask = ~(~0 << n) << (p - n + 1);
    *x ^= mask;
    return 0;
}
