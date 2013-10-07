// Author: jrjbear@gmail.com
// Date: Sun Oct  6 00:14:16 2013
//
// File: 4-7.cpp
// Description: Implementation of ungets


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

static const int BUFSIZE = 1024;

char getch();
void ungetch(char c);
void ungets(const char s[]);

int main(int argc, char* argv[])
{
    srand(time(NULL));
   
    char c = '\0';
    int pos = 0;
    char buf[BUFSIZE];
    while ((c = getch()) != EOF) {
        buf[pos++] = c;

        int chance = rand() % 100;
        if (chance < 20) {
            buf[pos] = '\0';
            printf("%s", buf);
            pos = 0;
        } else if (chance > 85) {
            buf[pos] = '\0';
            ungets(buf);
            pos = 0;
        } 
    }
    
    buf[pos] = '\0';
    printf("%s", buf);
    return 0;
}

static char buf[BUFSIZE];
static int bufp = 0;

char getch() 
{ return (bufp > 0)? buf[--bufp]: getchar(); }

void ungetch(char c)
{
    if (bufp >= BUFSIZE) {
        printf("Stack overflow\n");
    } else {
        buf[bufp++] = c;
    }
}

void ungets(const char s[])
{
    for (int i = strlen(s) - 1; i >= 0; --i) {
        ungetch(s[i]);
    }
}

