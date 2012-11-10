/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: 1-22.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>

#define THRESHOLD 80
#define NUM 8

// Output `buf' with `len' long starting at `pos'.
// If the buffer exceeds `THRESHOLD', it will be fold.
int output (int pos, const char buf[], int len);

int main () 
{
    // `i' marks the point of the next character, starts from 1.
    // `len' is the length of `temp'.
    int c, i, len;
    char temp[THRESHOLD + 1];

    i = 1;
    len = 0;
    while ((c = getchar ()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            // We come across a blank character, first check if
            // we have former buffer to output.
            i = output (i, temp, len);
            len = 0;

            if (c == ' ') {
                if (i > THRESHOLD) {
                    putchar ('\n');
                    putchar (c);
                    i = 2;
                } else {
                    putchar (c);
                    ++i;
                }

            } else if (c == '\t') {
                // Caculate the next position after this tab.
                i = (i + NUM) / NUM * NUM + 1;
                if (i > THRESHOLD) {
                    putchar ('\n');
                    putchar (c);
                    i = NUM + 1;
                } else {
                    putchar (c);
                }

            } else if (c == '\n') {
                putchar (c);
                i = 1;
            }

        } else {
            // Stores `c' in a buffer, so that we can ouput this
            // when we encounter a blank character.
            temp[len++] = c;
            if (len >= THRESHOLD) {
                // Buffer has already overflowed. Now we can just
                // flush buffer since itself will occupy an entire line.
                i = output (i, temp, len);
                len = 0;
            }
        }
    }

    return 0;
}

int output (int pos, const char buf[], int len) 
{
    if (len == 0) {
        return pos;
    }

    if (pos + len - 1 > THRESHOLD) {
        putchar ('\n');
        pos = 1;
    }

    for (int i = 0; i < len; ++i) {
        putchar (buf[i]);
    }

    return pos + len;
}
