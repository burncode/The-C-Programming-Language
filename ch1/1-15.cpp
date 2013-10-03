// Author: jrjbear@gmail.com
// Date: Thu Oct  3 01:09:49 2013
//
// File: 1-15.cpp
// Description: Convert Fahrenheit to Celsius using fucntion

#include <stdio.h>

float fahr_to_celsius(float fahr);

int main(int argc, char* argv[])
{
    int lower = 0;
    int upper = 300;
    int step = 20;

    float fahr = lower;
    printf("%3s %6s\n", "^F", "^C");
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, fahr_to_celsius(fahr));
        fahr = fahr + step;
    }
}

float fahr_to_celsius(float fahr) 
{ return (5.0 / 9.0) * (fahr - 32); }
