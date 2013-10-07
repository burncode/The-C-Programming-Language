// Author: jrjbear@gmail.com
// Date: Mon Oct  7 13:43:06 2013
//
// File: 4-9.cpp
// Description: EOF can also be pushed back in ungetch



#include <stdio.h>
#include <string.h>

int getch();
void ungetch(int c);

int main(int argc, char* argv[])
{
    while (true) {
        char c = getch();
        ungetch(c);
        c = getch();
        if (c == EOF) {
            break;
        } else {
            putchar(c);
        }
    }
    return 0;
}

static const int BUFSIZE = 1024;
static int buf[BUFSIZE];
static int bufp = 0;

int getch() 
{ return (bufp > 0)? buf[--bufp]: getchar(); }

void ungetch (int c)
{
    if (bufp >= BUFSIZE) {
        printf("Stack overflow\n");
    } else {
        buf[bufp++] = c;
    }
}
