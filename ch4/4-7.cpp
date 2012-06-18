/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--16                                                   **
 *                                                                      **
 * File: 4-7.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define BUFSIZE 1000

char buf[BUFSIZE];
int bufp = 0;

char getch ();
void ungetch (char c);
void ungets (const char s[]);


int main ()
{
    srand (time (NULL));
   
    char c;
    char buf[BUFSIZE];
    int pos, chance;

    /*
    ungets ("asdf");
    printf ("%c", getch ());
    ungets ("q");
  printf ("%c", getch ());
 printf ("%c", getch ());
 printf ("%c", getch ());
printf ("%c", getch ());
    */

    pos = 0;
    while ((c = getch ()) != EOF) {
        buf[pos++] = c;

        chance = rand () % 100;
        if (chance < 20) {
            buf[pos] = '\0';
            printf ("%s", buf);
            pos = 0;

        } else if (chance > 85) {
            buf[pos] = '\0';
            ungets (buf);
            pos = 0;
        } 
    }
    
    buf[pos] = '\0';
    printf ("%s", buf);
    return 0;
}


char getch () 
{ return (bufp > 0)? buf[--bufp]: getchar (); }

void ungetch (char c)
{
    if (bufp >= BUFSIZE) {
        printf ("Stack overflow\n");
    } else {
        buf[bufp++] = c;
    }
}

void ungets (const char s[])
{
    for (int i = strlen (s) - 1; i >= 0; --i) {
        ungetch (s[i]);
    }
}

