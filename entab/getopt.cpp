// Author: jrjbear@gmail.com
// Date: Sun Oct 13 21:15:15 2013
//
// File: getopt.cpp
// Description: Parse command line arguments into options


#include <ctype.h>
#include "entab.h"

Option my_getopt(const char* arg, char* buf)
{
    Option ret = NUMBER;
    if (*arg == '-' || *arg == '+') {
        arg++;
        ret = (*arg == '-'? BEGIN: INC);
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

