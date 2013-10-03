// Author: jrjbear@gmail.com
// Date: Thu Oct  3 00:52:27 2013
//
// File: 1-13.cpp
// Description: Show statistic of each word's length

#include <stdio.h>

enum State {
    IN = 0,
    OUT = 1,
};

int main(int argc, char* argv[])
{
    const int MAXVLST = 40;
    const int MAXWORD = 14;

    int count[MAXWORD];
    for (int i = 0; i < MAXWORD; i++) {
        count[i] = 0;
    }

    int overflow = 0;
    int length = 0;
    int max = 0;
    int c = -1;
    State state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c =='\n') {
            if (state == IN) {
                // We find a word here.
                state = OUT;
                if (length > MAXWORD) {
                    overflow++;
                } else {
                    ++count[length - 1];
                }
            }

        } else if (state == OUT) {
            // This is the beginning of a word.
            length = 1;
            state = IN;
        } else {
            length++;
        }
    }
	
    // Find the max count value.
    for (int i = 0; i < MAXWORD; i++) {
        if (max < count[i]) {
            max = count[i];
        }
    }

    if (max == 0) {
        printf("No word found\n");
        return 0;
    }

    // Get the percentage of `count[j]' to `max', and then
    // decide how many '*' should be displayed.
    for (int i = MAXVLST; i > 0; i--) {
        for (int j = 0; j < MAXWORD; j++) {
            if ((count[j] * MAXVLST + max - 1) / max >= i) {
                printf ("%4c", '*');
            } else {
                printf ("%4c", ' ');
            }
        }
        printf ("\n");
    }

    for (int i = 1; i <= MAXWORD; i++) {
        printf("%4d", i);
    }
    printf(" length\n");
    for (int i = 0; i < MAXWORD; i++) {
        printf("%4d", count[i]);
    }
    printf(" times\n");
	
    if (overflow > 0) {
        printf ("There are %d words that have more than %d letters\n", 
                overflow, MAXWORD);
    }
    return 0;
}
