#include <stdio.h>

int main ()
{
    int c, ns, nt, nl;

    for (c = getchar (), ns = 0, nt = 0, nl = 0; 
         c != EOF; c = getchar ()) {
        if (c == '\n') {
            nl++;
        } else if (c == '\t') {
            nt++;
        } else if (c == ' ') {
            ns++;
        }
    }

    printf("%-15s %5d\n", "Total Spaces", ns);
    printf("%-15s %5d\n", "Total Tabs", nt);
    printf("%-15s %5d\n", "Total Lines", nl);

    return 0;
}

