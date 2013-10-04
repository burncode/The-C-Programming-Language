// Author: jrjbear@gmail.com
// Date: Fri Oct  4 19:10:37 2013
//
// File: 3-2.cpp
// Description: Conver escape characters into visable ones and visa versa


#include <stdio.h>
#include "utils/utils.h"

int escape(char dst[], const char src[]);
int unescape(char dst[], const char src[]);

int main(int argc, char* argv[])
{
    const int BUFSIZE = 1024;

    char buf[BUFSIZE];
    char line[BUFSIZE];
    while (my_getline(line, BUFSIZE) > 0) {
        escape(buf, line);
        printf("After escape: %s\n", buf);
        unescape(line, buf);
        printf("Unescape back to origin: %s\n", line);
    }

    return 0;
}

int escape(char dst[], const char src[])
{
    int offset = 0;
    for (int i = 0; src[i] != '\0'; ++i) {
        switch (src[i]) {
        case '\t':
            dst[offset++] = '\\';
            dst[offset++] = 't';
            break;
        case '\n':
            dst[offset++] = '\\';
            dst[offset++] = 'n';
            break;
        case '\b':
            dst[offset++] = '\\';
            dst[offset++] = 'b';
            break;
        default:
            dst[offset++] = src[i];
            break;
        }
    }
    dst[offset] = '\0';
    return 0;
}

int unescape(char dst[], const char src[])
{
    int offset = 0;
    for (int i = 0; src[i] != '\0'; ++i) {
        if (src[i] == '\\') {
            switch (src[++i]) {
            case 't':
                dst[offset++] = '\t';
                break;
            case 'n':
                dst[offset++] = '\n';
                break;
            case 'b':
                dst[offset++] = '\b';
                break;
            default:
                --i;
                dst[offset++] = '\\';
                break;
            }
        } else {
            dst[offset++] = src[i];
        }
    }
    dst[offset] = '\0';
    return 0;
}
