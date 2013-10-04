// Author: jrjbear@gmail.com
// Date: Fri Oct  4 19:11:00 2013
//
// File: 3-1.cpp
// Description: Binary search


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binary_search(const int v[], int n, int x);

int main(int argc, char* argv[])
{
    const int SIZE = 20;
    srand(time(NULL));

    int arr[SIZE];
    printf("Input array: [");
    for (int i = 0, elem = 0; i < SIZE; ++i) {
        elem += rand() % 3;
        printf("%d, ", elem);
        arr[i] = elem;
    }
    printf("\b\b]\n\n");

    printf("Binary search for element -1: %d\n", 
           binary_search(arr, SIZE, -1));
    printf("Binary search for element 10000: %d\n", 
           binary_search(arr, SIZE, 10000));
    for (int i = 0; i < 10; ++i) {
        int x = rand() % SIZE;
        printf("Binary search for element %d: %d\n", 
               x, binary_search(arr, SIZE, x));
    }

    return 0;
}

int binary_search(const int v[], int n, int x)
{
    int low = -1;
    int high = n;
    while (high > low + 1) {
        // We ensure index of `x' is in range (`low', `high'].
        int mid = (low + high) >> 1;
        if (x > v[mid]) {
            low = mid;
        } else {
            high = mid;
            // Now `x' may equal to `v[high]'. If so, variable
            // `high' will not change in the loop while variable
            // `low' keeps increasing until `low' + 1 >= `high'.
        }
    }

    if (high >= n || v[high] != x) {
        return -1;
    } else {
        return high;
    }
}
