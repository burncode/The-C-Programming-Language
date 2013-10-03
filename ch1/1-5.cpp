// Author: jrjbear@gmail.com
// Date: Wed Oct  2 22:48:37 2013
//
// File: 1-5.cpp
// Description: Convert Fahrenheit to Celsius in descending order

#include <stdio.h>

int main(int argc, char* argv[])
{
    int lower = 0;
    int upper = 300;
    int step = 20;

    printf("%3s %6s\n", "^F", "^C");
    for (float fahr = upper; fahr >= lower; fahr -= step) {
        float celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f %6.1f\n", fahr, celsius);
    }

    return 0;
}
