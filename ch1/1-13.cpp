#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXVLST 40
#define MAXWORD 14

int main ()
{
    int c, state, i, length, j, overflow, max;
    int count[MAXWORD];

    for (i = 0; i < MAXWORD; i++) {
        count[i] = 0;
    }
    overflow = length = max = 0;

    for (state = OUT; (c = getchar ()) != EOF; ) {
        if (c == ' ' || c == '\t' || c =='\n') {
            if (state == IN) {
                // A word ended here.
                state = OUT;
                if (length > MAXWORD) {
                    overflow++;
                } else {
                    ++count[length - 1];
                }
            }

        } else if (state == OUT) {
            // Come across the beginning of a word.
            length = 1;
            state = IN;
        } else {
            length++;
        }
    }
	
    // Find the max count value.
    for (i = 0; i < MAXWORD; i++) {
        if (max < count[i]) {
            max = count[i];
        }
    }

    if (max == 0) {
        printf ("No word found\n");
        return 0;
    }

    // Get the percentage of count[j] to max, and then
    // decide how many * should be displayed.
    for (i = MAXVLST; i > 0; i--) {
        for (j = 0; j < MAXWORD; j++) {
            if ((count[j] * MAXVLST + max - 1) / max 
                >= i) {
                printf ("%4c", '*');
            } else {
                printf ("%4c", ' ');
            }
        }
        printf ("\n");
    }

    for (i = 1; i <= MAXWORD; i++) {
        printf ("%4d", i);
    }
    printf (" length\n");
    for (i = 0; i < MAXWORD; i++) {
        printf ("%4d", count[i]);
    }
    printf(" times\n");
	
    if (overflow > 0) {
        printf ("There are %d words that have more than"
                " %d letters\n", 
                overflow, MAXWORD);
    }

    return 0;
}
