/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--04                                                   **
 *                                                                      **
 * File: common.hpp                                                     **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#ifndef _COMMON_HPP_
#define _COMMON_HPP_

#include <stdio.h>

int my_getline (char s[], int lim) 
{
    int c, i;

    // i < lim - 1 because we should leave at least
    // one space for \0.
    for (i = 0; i < lim - 1 
         && (c = getchar ()) != EOF 
         && c != '\n'; i++) {
        s[i] = c;
    }

    s[i] = '\0';
    if (c == EOF) {
        return -1;
    } else {
        return i;
    }
}

#endif // _COMMON_HPP_
