// Author: jrjbear@gmail.com
// Date: Mon Oct  7 13:29:47 2013
//
// File: 4-8.cpp
// Description: Implement ungetch without stack


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

char getch();
// Overwrite last unget character if exists.
void ungetch(char c);

int main(int argc, char* argv[])
{
    srand(time(NULL));

    char c = '\0';
    bool buffed = false;
    while ((c = getch()) != EOF) {
        if (buffed) {
            putchar(c);
            buffed = false;
        } else {
            if (rand() % 100 < 30) {
                ungetch(c);
                buffed = true;
            } else {
                putchar(c);
            }
        }
    }
    return 0;
}

static int last = EOF;

char getch() 
{
    char ret = (last == EOF)? getchar(): last;
    last = EOF;
    return ret;
}

void ungetch(char c)
{
    if (last != EOF) {
        printf("Overwrite last unget character: %c\n", last);
    } 
    last = c;
}
