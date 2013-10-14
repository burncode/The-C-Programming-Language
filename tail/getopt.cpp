// Author: jrjbear@gmail.com
// Date: Mon Oct 14 23:04:58 2013
//
// File: getopt.cpp
// Description: Parse command line arguments into options


#include <ctype.h>
#include "tail.h"

Option my_getopt(const char* arg, char* buf)
{
    Option ret = NUMBER;
    if (*arg++ != '-') {
        return ERROR;
    }

    while (isdigit(*arg)) {
        *buf++ = *arg++;
    }
    *buf = '\0';

    if (*arg != '\0' || !isdigit(*(arg - 1))) {
        ret = ERROR;
    }
    return ret;
}

