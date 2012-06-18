/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--16                                                   **
 *                                                                      **
 * File: 4-9.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include <stdio.h>
#include <string.h>

#define BUFSIZE 100


int buf[BUFSIZE];
int bufp = 0;

int getch ();
void ungetch (int c);

int main ()
{
    char c;

    while (true) {
        c = getch ();
        ungetch (c);
        c = getch ();

        if (c == EOF) {
            break;
        } else {
            putchar (c);
        }
    }

    return 0;
}

int getch () 
{ return (bufp > 0)? buf[--bufp]: getchar (); }

void ungetch (int c)
{
    if (bufp >= BUFSIZE) {
        printf ("Stack overflow\n");
    } else {
        buf[bufp++] = c;
    }
}
