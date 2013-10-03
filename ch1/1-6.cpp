// Author: jrjbear@gmail.com
// Date: Wed Oct  2 22:50:44 2013
//
// File: 1-6.cpp
// Description: Return value of `getchar'

#include <stdio.h>

int main(int argc, char* argv[])
{
    int c = -1;
    printf("Input a character: ");
    c = (getchar() != EOF);
    printf("Value of `getchar() != EOF' is: %d\n", c);

    return 0;
}
