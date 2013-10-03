// Author: jrjbear@gmail.com
// Date: Wed Oct  2 22:46:51 2013
//
// File: 1-3.cpp
// Description: Convert Fahrenheit to Celsius

#include <stdio.h>

int main(int argc, char* argv[])
{
    int lower = 0;
    int upper = 300;
    int step = 20;

    float fahr = lower;
    printf("%3s %6s\n", "^F", "^C");
    while (fahr <= upper) {
        float celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}
