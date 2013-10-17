// Author: jrjbear@gmail.com
// Date: Tue Oct 15 23:41:31 2013
//
// File: qsort.cpp
// Description: Implementation of quick sort


#include <string.h>
#include <ctype.h>
#include "sort.h"


void qsort(char* v[], int left, int right, CmpFn cmp)
{
    if (left >= right) {
        return;
    }

    // `begin' marks the beginning character's index of the required field.
    // `end' marks the end of that field. The character at `end' position
    // will be replaced by '\0' while its original value stored in `cend'.
    int begin1 = 0;
    int end1 = 0;
    char cend1 = '\0';
    int begin2 = 0;
    int end2 = 0;
    char cend2 = '\0';

    // Select the middle element as the pivot.
    swap(v, left, (left + right) / 2);

    // `last' marks the rightmost element that is less than or equal to pivot.
    int last = left;
    for (int i = left + 1; i <= right; i++) {
        select_field(v[i], g_field_num, &begin1, &end1);
        cend1 = v[i][end1];

        select_field(v[left], g_field_num, &begin2, &end2);
        cend2 = v[left][end2];

        // Terminate these two filed strings temporarily for comparison.
        v[i][end1] = v[left][end2] = '\0';
        int ret = (*cmp)(v[i] + begin1, v[left] + begin2);
        v[i][end1] = cend1;
        v[left][end2] = cend2;
        if (ret < 0) {
            swap(v, ++last, i);
        } 
    }
    
    swap(v, left, last);
    qsort(v, left, last - 1, cmp);
    qsort(v, last + 1, right, cmp);
}

void swap(char* v[], int i, int j)
{
    char* temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void select_field(const char* s, int field_num, int* begin, int* end)
{
    int count = 0;
    int i = 0;
    
    if (field_num < 1) {
        *begin = 0;
        *end = strlen(s);
        return;
    }

    while (s[i] != '\0') {
        while (isblank(s[i])) {
            i++;
        }
        if (++count >= field_num) {
            break;
        }
        while (!isblank(s[i]) && s[i] != '\0') {
            i++;
        }
    }
    *begin = i;

    while (!isblank(s[i]) && s[i] != '\0') {
        i++;
    }
    *end = i;
}
