// Author: jrjbear@gmail.com
// Date: Thu Oct  3 16:20:57 2013
//
// File: 1-22.cpp
// Description: Fold lines that exceeds THRESHOLD

#include <stdio.h>

int main(int argc, char* argv[])
{
    const int THRESHOLD = 80;
    const int TAB_OFFSET = 8;

    // `i' marks the position where the next character will be.
    // `len' is the current length of `temp'.
    int i = 1;
    int len = 0;
    int c = -1;
    char temp[THRESHOLD + 1];
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            // Check if we have former buffer to print.
            if (len > 0) {
                temp[len] = '\0';
                printf("%s", temp);
                i += len;
                len = 0;
            }

            if (c == ' ') {
                if (i > THRESHOLD) {
                    putchar('\n');
                    putchar(c);
                    i = 2;
                } else {
                    putchar(c);
                    ++i;
                }

            } else if (c == '\t') {
                // Caculate the next position after this tab.
                i = (i + TAB_OFFSET - 1) / TAB_OFFSET * TAB_OFFSET;
                if (i > THRESHOLD) {
                    putchar('\n');
                    putchar(c);
                    i = TAB_OFFSET + 1;
                } else {
                    putchar (c);
                    ++i;
                }

            } else if (c == '\n') {
                putchar(c);
                i = 1;
            }

        } else {
            temp[len++] = c;
            if (len + i > THRESHOLD) {
                // Buffer has already exceeded THRESHOLD
                temp[len] = '\0';
                if (i == 1) {
                    // Beginning of a line
                    printf("%s\n", temp);
                } else {
                    printf("\n%s", temp);
                    i = len + 1;
                }
                len = 0;
            }
        }
    }

    return 0;
}
