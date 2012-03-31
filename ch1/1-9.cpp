#include <stdio.h>

int main ()
{
    int c, lastc;

    for (lastc = -1; (c = getchar ()) != EOF; 
         lastc = c) {
        if (lastc != ' ' || c != ' ') {
            putchar (c);
        }
    }

    return 0;
}
