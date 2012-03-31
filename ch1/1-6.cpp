#include <stdio.h>

int main ()
{
    int c;
    printf ("Input a character: ");
    c = getchar () != EOF;
    printf ("Value of getchar() != EOF is: %d\n", c);

    return 0;
}
