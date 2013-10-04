// Author: jrjbear@gmail.com
// Date: Fri Oct  4 17:47:17 2013
//
// File: 2-8.cpp
// Description: Bit operations

#include <stdio.h>
#include <stdint.h>

// Right rotate `x' by `n' bits.
int rightrot(uint32_t* x, int n);

int main(int argc, char* argv[])
{
    uint32_t x = 0;
    int n = -1;
    while (true) {
        printf("Input parameters in hexadecimal(x n): ");
        if (scanf("%x%d", &x, &n) != 2) {
            break;
        }
        uint32_t save_x = x;
        if (rightrot(&x, n) == 0) {
            printf("After rightrot(%#x, %d): %#x\n\n", save_x, n, x);
        } else {
            break;
        }
    }

    return 0;
}

int rightrot(uint32_t* x, int n)
{
    static const int BITSIZE = sizeof(uint32_t) * 8;
    if (n < 0) {
        printf("Invalid parameter(n): %d\n", n);
        return -1;
    }

    n %= BITSIZE;
    uint32_t head = *x << (BITSIZE - n);
    uint32_t tail = *x >> n;
    *x = head | tail;
    return 0;
}
