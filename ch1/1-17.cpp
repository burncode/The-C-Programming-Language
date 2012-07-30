/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: 1-17.cpp                                                       **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include "utils.h"

#define MAXLINE 1024
#define THRESHOLD 80


int main ()
{
    int len;
    char line[MAXLINE];

    while ((len = my_getline (line, MAXLINE)) > 0) {
        if (len > THRESHOLD) {
            printf("%s", line);
        }
    }

    return 0;
}
