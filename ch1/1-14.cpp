// Author: jrjbear@gmail.com
// Date: Thu Oct  3 01:04:59 2013
//
// File: 1-14.cpp
// Description: Show statistic of each character's frequency


#include <stdio.h>
#include <ctype.h>


int main(int argc, char* argv[])
{
    const int MAXHLST = 80;
    const int MAXCHAR = 128;

    int count[MAXCHAR];
    for (int i = 0; i < MAXCHAR; i++) {
        count[i] = 0;
    }

    int c = -1;
    // Count characters whose ASCII value is less than `MAXCHAR'.
    while ((c = getchar()) != EOF) {
        if (c < MAXCHAR) {
            ++count[c];
        }
    }

    int max = 0;
    // Find the max count value.
    for (int i = 0; i < MAXCHAR; i++) {
        if (max < count[i]) {
            max = count[i];
        }
    }
    if (max == 0) {
        printf("No character found\n");
        return 0;
    }

    printf("%5s,%5s,%5s:\n", "INT", "CHAR", "FREQ");
    for (int i = 0; i < MAXCHAR; i++) {
        if (isprint(i)) {
            printf("%5d,%5c,%5d: ", i, i, count[i]);
        } else {
            printf("%5d,%5c,%5d: ", i, ' ', count[i]);
        }

        // Get the percentage of `count[i]' to `max', and then
        // decide how many '*' should be displayed.
        for (int len = (MAXHLST * count[i] + max - 1) / max; 
             len > 0; len--) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
