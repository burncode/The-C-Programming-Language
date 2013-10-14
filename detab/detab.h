// Author: jrjbear@gmail.com
// Date: Sun Oct 13 21:08:07 2013
//
// File: detab.h
// Description: Global declarations


#ifndef DETAB_DETAB_H_
#define DETAB_DETAB_H_

enum Option {
    NUMBER = 0,
    BEGIN = 1,
    INC = 2,
    ERROR = 3,
};

// getopt.cpp
Option my_getopt(const char* arg, char* s);

// detab.cpp
void detab(const bool tab_flags[], int size);


#endif // DETAB_DETAB_H_
