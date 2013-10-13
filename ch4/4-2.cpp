// Author: jrjbear@gmail.com
// Date: Sat Oct  5 23:58:38 2013
//
// File: 4-2.cpp
// Description: Convert string to double number


#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include "utils/utils.h"

double atof(const char s[]);

int main(int argc, char* argv[])
{
    const int MAXLINE = 1024;
    
    int len = 0;
    char line[MAXLINE];
    while (true) {
        printf("Input a number(decimal, can be scientific/digit one): ");
        if ((len = my_getline(line, MAXLINE)) <= 0) {
            break;
        }
        line[len - 1] = '\0';
        printf("atof(%s): %f\n", line, atof(line));
    }
    return 0;
}

double atof(const char s[])
{
    int i = 0;
    for (; isspace(s[i]); i++) {
        ;
    }
    int sign = (s[i] == '-')? -1: 1;
    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    double val = 0;
    for (; isdigit(s[i]); i++) {
        val = 10 * val + (s[i] - '0');
    }
    if (s[i] == '.' && isdigit(s[i + 1])) {
        i++;
    }

    int power = 0;
    for (; isdigit(s[i]); i++) {
        val = 10 * val + (s[i] - '0');
        power--;
    }
    val *= sign;
    if (tolower(s[i++]) == 'e') {
        sign = (s[i] == '-')? -1: 1;
        if (s[i] == '+' || s[i] == '-') {
            i++;
        }
        int exp = 0;
        for (; isdigit(s[i]); i++) {
            exp = 10 * exp + (s[i] - '0');
        }
        power += sign * exp;
    }
    return val * pow(10.0, power);
}
