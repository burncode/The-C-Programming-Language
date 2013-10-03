// Author: jrjbear@gmail.com
// Date: Wed Oct  2 22:46:18 2013
//
// File: 1-2.cpp
// Description: Generate an unknow-escape warning

#include <stdio.h>

int main(int argc, char* argv[])
{
    // We get an unknown escape character warning here.
    printf("Let's see what happens when printing \\c: \c\n"); 
    return 0;
}
