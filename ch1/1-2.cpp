#include <stdio.h>

int main ()
{
    // We get an unknown escape character warning here.
    printf ("Let's see what happens when printing"
            " \\c: \c\n"); 
    return 0;
}
