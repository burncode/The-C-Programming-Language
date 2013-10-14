// Author: jrjbear@gmail.com
// Date: Mon Oct 14 01:08:47 2013
//
// File: entab.h
// Description: 

#ifndef ENTAB_ENTAB_H_
#define ENTAB_ENTAB_H_

enum Option {
    NUMBER = 0,
    BEGIN = 1,
    INC = 2,
    ERROR = 3,
};

// getopt.cpp
Option my_getopt(const char* arg, char* s);

// entab.cpp
void entab(const bool tab_flags[], int size);
int find_next_stop(const bool tab_flags[], int size, int pos);

#endif // ENTAB_ENTAB_H_
