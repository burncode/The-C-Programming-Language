#include <stdio.h>

#define NEWLINE 1
#define OLDLINE 0

int main ()
{
    int c, state;

    for (state = NEWLINE, c = getchar (); 
         c != EOF; c = getchar ()) {
        if (c == ' ' || c == '\t' || c =='\n') {
            if (state == OLDLINE) {
                putchar ('\n');
                state = NEWLINE;
            }

            // state == NEWLINE here, which means
            // we do not output empty lines when
            // reading successive blanks.
        } else {
            putchar (c);
            state = OLDLINE;
        }
    }

    return 0;
}
