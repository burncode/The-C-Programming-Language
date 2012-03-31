#include <stdio.h>

#define MAXLINE 1024
#define THRESHOLD 80

int my_getline (char line[], int lim);

int main ()
{
    int len;
    char line[MAXLINE];

    while ((len = my_getline (line, MAXLINE)) > 0) {
        if (len > THRESHOLD) {
            printf("%s", line);
        }
    }

    return 0;
}

int my_getline (char s[], int lim) 
{
    int c, i;

    // i < lim - 1 because we should leave at least
    // one space for \0.
    for (i = 0; i < lim - 1 
         && (c = getchar ()) != EOF 
         && c != '\n'; i++) {
        s[i] = c;
    }

    if (c == '\n') {
        // Here i can never be lim - 1, because
        // the loop condition above has already
        // check i < lim - 1 when c == \n.
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
