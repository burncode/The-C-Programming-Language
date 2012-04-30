/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--04--30                                                   **
 *                                                                      **
 * File: 3-1.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int binary_search (int x, int v[], int n);

int main ()
{
    srand (time (NULL));

    int arr[SIZE];

    printf ("Input array: [");
    for (int i = 0, elem = 0; i < SIZE; ++i) {
        elem += rand () % 3;
        printf ("%d, ", elem);
        arr[i] = elem;
    }
    printf("\b\b]\n\n");

    printf("Binary search for element -1: %d\n", 
           binary_search (-1, arr, SIZE));
    printf("Binary search for element 10000: %d\n", 
           binary_search (10000, arr, SIZE));
    for (int i = 0; i < 10; ++i) {
        int x = rand () % SIZE;
        printf("Binary search for element %d: %d\n", 
               x, binary_search (x, arr, SIZE));
    }

    return 0;
}

int binary_search (int x, int v[], int n)
{
    int low, high, mid;

    low = -1;
    high = n;

    while (high > low + 1) {
        // We ensure x's index is in range (low, high].
        mid = (low + high) >> 1;
        if (x > v[mid]) {
            low = mid;
        } else {
            high = mid;
            // Now x may equal to v[high].
            // If so, variable high will not change
            // in the loop while variable low keeps
            // increasing until low + 1 >= high.
        }
    }

    if (high >= n || v[high] != x) {
        return -1;
    } else {
        return high;
    }
}
