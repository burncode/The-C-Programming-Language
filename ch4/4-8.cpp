/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--16                                                   **
 *                                                                      **
 * File: 4-8.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define BUFSIZE 100

char last_c = 0;

char getch_c ();
void ungetch_c (char c);

int main ()
{
    srand (time (NULL));

    char c;
    bool buffed;

    buffed = false;
    while ((c = getch_c ()) != EOF) {
        if (buffed) {
            buffed = false;
            putchar (c);

        } else {
            if (rand () % 100 < 30) {
                ungetch_c (c);
                buffed = true;
            } else {
                putchar (c);
            }
        }
    }
    
    return 0;
}

char getch_c () 
{
    char ret = (last_c != 0)? last_c: getchar();
    last_c = 0;
    return ret;
}

void ungetch_c (char c)
{
    if (last_c != 0) {
        printf ("Overwrite last ungetch_c character: %c\n", 
                last_c);
    } 
    
    last_c = c;
}
