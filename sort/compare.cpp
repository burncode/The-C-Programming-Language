// Author: jrjbear@gmail.com
// Date: Wed Oct 16 21:31:48 2013
//
// File: compare.cpp
// Description: Comparison functions


#include <ctype.h>
#include <stdlib.h>
#include "sort.h"

int my_strcmp(const char* s1, const char* s2)
{
    int ret = 0;
    do {
        ret = (g_ignore_case? toupper(*s1) - toupper(*s2): *s1 - *s2);
        if (ret != 0) {
            return ret;
        }
    } while (*s1++ != '\0' && *s2++ != '\0');
    // `s1' equals to `s2' here since they are both '\0'.
    return ret;
}

int numcmp(const char* s1, const char* s2)
{
    double v1 = atof(s1);
    double v2 = atof(s2);
    if (v1 == v2) {
        return my_strcmp(s1, s2);
    } else {
        return (v1 > v2? 1: -1);
    }
}

int dircmp(const char* s1, const char* s2)
{
    while (*s1 != '\0' && *s2 != '\0') {
        if (!isalnum(*s1) && !isblank(*s1)) {
            s1++;
            continue;
        }
        if (!isalnum(*s2) && !isblank(*s2)) {
            s2++;
            continue;
        }
        int ret = (g_ignore_case? toupper(*s1) - toupper(*s2): *s1 - *s2);
        if (ret != 0) {
            return ret;
        }
        s1++;
        s2++;
    }
    return (g_ignore_case? toupper(*s1) - toupper(*s2): *s1 - *s2);
}
