/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--07--21                                                   **
 *                                                                      **
 * File: qsort.cpp                                                      **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */


#include "sort.h"
#include <stdio.h>

void qsort (char* v[], int left, int right, CmpFn cmp)
{
    // `begin1' and `begin2' marks the beginning position of a field.
    // `end1' and `end2' marks the end position of a field.
    int i, last, begin1, end1, begin2, end2, ret;
    char tmp1, tmp2;
	
    if (left >= right) {
        return;
    }

    // Select the middle element as the pivot. `last' marks the
    // right most element that is less than or equal to pivot.
    swap (v, left, (left + right) / 2);
    last = left;

    for (i = left + 1; i <= right; i++) {
        // Get the `g_field_num'th field and then replace character
        // at the end with '\0'.
       
        find_field (v[i], g_field_num, &begin1, &end1);
        tmp1 = v[i][end1];
        v[i][end1] = '\0';

        find_field (v[left], g_field_num, &begin2, &end2);
        tmp2 = v[left][end2];
        v[left][end2] = '\0';
       
        ret = (*cmp) (v[i] + begin1, v[left] + begin2);

        // Recover the original value.
        v[i][end1] = tmp1;
        v[left][end2] = tmp2;

        if (ret < 0) {
            swap (v, ++last, i);
        } 
    }
    
    swap (v, left, last);
    qsort (v, left, last - 1, cmp);
    qsort (v, last + 1, right, cmp);
}

