#include <stdio.h>

#define NUM 8

void detab ();

int main()
{
    detab ();
    return 0;
}

void detab () 
{
    int c, i, next;

    // i marks the current point of the input, starts from 1.
    // next marks the next tab point, which is a multiple of NUM.
    // Note that the point next cannot hold any character,
    // input after next point starts from next + 1.
    for (i = 1; (c = getchar ()) != EOF; ++i) {
        if (c == '\t') {
            // Replace tab with blanks.
            for (next = (i + NUM) / NUM * NUM; 
                 i <= next; ++i) {
                putchar (' ');
            }
            i--;

        } else if (c == '\n') {
            putchar (c);
            i = 0;

        } else {
            putchar (c);
        }
    }
}
