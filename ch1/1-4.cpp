// Author: jrjbear@gmail.com
// Date: Wed Oct  2 22:47:48 2013
//
// File: 1-4.cpp
// Description: Convert Celsius to Fahrenheit

#include <stdio.h>

int main(int argc, char* argv[])
{
    int lower = -20;
    int upper = 180;
    int step = 10;

    float celsius = lower;
    printf("%4s %6s\n", "^C", "^F");
    while (celsius <= upper) {
        float fahr = (9.0 / 5.0) * celsius + 32;
        printf("%4.0f %6.0f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}
