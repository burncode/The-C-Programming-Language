// Author: jrjbear@gmail.com
// Date: Mon Oct 14 23:07:35 2013
//
// File: tail.h
// Description: Global declarations


#ifndef TAIL_TAIL_H_
#define TAIL_TAIL_H_

enum Option {
    NUMBER = 0,
    ERROR = 1,
};

// getopt.cpp
Option my_getopt(const char* arg, char* s);

#endif // TAIL_TAIL_H_
