/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--07--25                                                   **
 *                                                                      **
 * File: compare.cpp                                                    **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include <ctype.h>
#include <stdlib.h>
#include "sort.h"

// Use this macro to compare between characters
// since it takes `g_ignore_case' into account.
#define CHAR_CMP(_c1_, _c2_, _ret_)                     \
    if (g_ignore_case) {                                \
        _ret_ = toupper (_c1_) - toupper (_c2_);        \
    } else {                                            \
        _ret_ = (_c1_) - (_c2_);                        \
    }                                                   




int my_strcmp (char* s1, char* s2)
{
    int ret;

    do {
       CHAR_CMP (*s1, *s2, ret);
       if (ret != 0) {
           return ret;
       }    
    } while (*s1++ != '\0' && *s2++ != '\0');

    return ret;
}

int numcmp (char* s1, char* s2)
{
    double v1, v2;

    v1 = atof (s1);
    v2 = atof (s2);

    return (v1 > v2? 1: v1 == v2? 0: -1);
}

int dircmp (char* s1, char* s2)
{
    int ret;
    while (*s1 != '\0' && *s2 != '\0') {
        if (!isalnum (*s1) && !isblank (*s1)) {
            s1++;
            continue;
        }

        if (!isalnum (*s2) && !isblank (*s2)) {
            s2++;
            continue;
        }

        CHAR_CMP (*s1, *s2, ret);
        if (ret == 0) {
            s1++;
            s2++;
        } else {
            return ret;
        }            
    }
        
    CHAR_CMP (*s1, *s2, ret);
    return ret;
}
