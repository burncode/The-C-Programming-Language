// Author: jrjbear@gmail.com
// Date: Thu Oct  3 22:48:01 2013
//
// File: 2-3.cpp
// Description: Convert hexadecimal number into integer


#include <stdio.h>
#include <ctype.h>
#include "utils/utils.h"

// Returns 0 on success, otherwise -1.
int htoi(const char s[], int* result);

int main(int argc, char* argv[])
{
    const int MAXLINE = 1024;

    char line[MAXLINE];
    int len = 0;
    int result = 0;
    while (true) {
        printf("Inpute a hexadecimal: ");
        if ((len = my_getline(line, MAXLINE)) <= 0) {
            break;
        }
        line[len - 1] = '\0';
        if (htoi(line, &result) != 0) {
            printf("Invalid input: %s\n", line);
        } else {
            printf("Value is: %d\n\n", result);
        }
    }
    return 0;
}

int htoi(const char s[], int* result)
{
    int i = 0;
    int sign = 1;
    if (s[i] == '-' || s[i] == '+') {
        sign = (s[i] == '-'? 0: 1);
        i++;
    }
    if (s[i] == '0' && tolower (s[i + 1]) =='x') {
        i += 2;
    }
    if (s[i] == '\0') {
        return -1;
    }
    int value = 0;
    for (char c = tolower(s[i]); c != '\0'; c = tolower(s[++i])) {
        if (c >= '0' && c <= '9') {
            value = value * 16 + c - '0';
        } else if (c >= 'a' && c <= 'f') {
            value = value * 16 + c - 'a' + 10;
        } else {
            return -1;
        }
    }
    *result = (sign == 0? -value: value);
    return 0;
}
