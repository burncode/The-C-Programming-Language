/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--06                                                   **
 *                                                                      **
 * File: 4-2.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "common.hpp"

#define BUFSIZE 1024

double atof (const char s[]);

int main ()
{
    char line[BUFSIZE];
  
    while (my_getline (line, BUFSIZE) >= 0) {
        printf ("atof (%s): %f\n", line, atof (line));
    }

    return 0;
}

double atof (const char s[])
{
    int val, power, i, sign, exp;

    for (i = 0; isspace (s[i]); i++) {
        ;
    }

    sign = (s[i] == '-')? -1: 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    for (val = 0; isdigit (s[i]); i++) {
        val = 10 * val + (s[i] - '0');
    }

    if (s[i] == '.' && isdigit (s[i + 1])) {
        i++;
    }

    for (power = 0; isdigit (s[i]); i++) {
        val = 10 * val + (s[i] - '0');
        power--;
    }
    val *= sign;
	
    if (tolower (s[i++]) == 'e') {
        sign = (s[i] == '-')? -1: 1;
        if (s[i] == '+' || s[i] == '-') {
            i++;
        }

        for (exp = 0; isdigit (s[i]); i++) {
            exp = 10 * exp + (s[i] - '0');
        }
        power += sign * exp;
    }

    return val * pow (10.0, power);
}
