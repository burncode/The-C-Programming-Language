#include <stdio.h>

#define NUM 8

void entab ();

int main () 
{
    entab ();
    return 0;
}

void entab () 
{
    int c, i, next, last;

    // i marks the current point of the input, starts from 1.
    // last marks the last non-blank point.
    // next marks the next tab point, which is a multiple of NUM.
    // Note that the point next cannot hold any character,
    // input after next point starts from next + 1.
    for (i = 1, last = 0; 
         (c = getchar ()) != EOF; i++) {
        if (c == '\t') {
            next = (i + NUM) / NUM * NUM;
            i = next;

        } else if (c == '\n') {
            putchar (c);
            i = last = 0;

        } else if (c != ' ') {
            if (last < i - 1) {
                // Insert tabs.
                for (last++, next = (last + NUM) / NUM * NUM; 
                     i > next; last = next + 1, next += NUM) {
                    putchar ('\t');
                }

                // Fill the rest part with blanks.
                for(; last < i; last++) {
                    putchar (' ');
                }
            }

            // Now we reach the same position as input.

            last = i;
            putchar (c);
        }

        // Ignore blanks.
    }
}
