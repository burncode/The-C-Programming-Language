/*************************************************************************
 *                                                                      **
 * Author: bear         <jrjbear@gmail.com>                             **
 * Date: 2012--06--22                                                   **
 *                                                                      **
 * File: 5-8.cpp                                                        **
 * Description:                                                         **
 *                                                                      **
 *************************************************************************
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
};

int day_of_year (int year, int month, int day);
int month_day (int year, int yearday, 
               int* pmonth, int* pday);

int main()
{
    srand (time (NULL));

    int year, month, day, yearday, ret;

    printf ("month_day (1900, 366): ");
    month_day (1900, 366, &month, &day);
    month_day (2000, 366, &month, &day);
    printf ("month_day (2000, 366): %02d/%02d\n\n", 
            month, day);

    printf ("day_of_year (1900, 2, 29): ");
    day_of_year (1900, 2, 29);
    printf ("day_of_year (2000, 3, 1): %d\n", 
            day_of_year (2000, 3, 1));

    printf ("\n********************************"
            "*******************************\n\n");

    for (int i = 0; i < 10; ++i) {
        year = rand () % 101 + 1900;
        yearday = rand () % 400;

        printf ("month_day (%d, %d): ", 
                year, yearday);
        ret = month_day (year, yearday, &month, &day);
        if (ret == 0) {
            printf ("%02d/%02d\n", month, day);
            printf ("day_of_year (%d, %d, %d): %d\n", 
                    year, month, day, 
                    day_of_year (year, month, day));
        }

        printf ("\n");
    }    

    return 0;
}

int day_of_year (int year, int month, int day)
{
    int i, leap;

    if (month <= 0 || month > 12) {
        printf ("Incorrect month number: %d\n", 
                month);
        return -1;
    }

    leap = (year % 4 == 0 && year % 100 != 0)
        || (year % 400 == 0);

    if (day > daytab[leap][month]) {
        printf ("Incorrect day number: %d\n", 
                day);
        return -1;
    }

    for (i = 1; i < month; i++) {
        day += daytab[leap][i];
    }

    return day;
}

int month_day (int year, int yearday, 
               int* pmonth, int* pday)
{
    int i, leap, day;

    if (yearday <= 0) {
        printf ("Incorrect yearday number: %d", 
                yearday);
        return -1;
    }

    leap = (year % 4 == 0 && year % 100 != 0) 
        || (year % 400 == 0);

    day = yearday;
    for (i = 1; day > daytab[leap][i] && i <= 12; i++) {
        day -= daytab[leap][i];
    }

    if (i > 12) {
        printf ("Incorrect yearday number: %d\n", 
                yearday);
        return -1;
    }

    *pmonth = i;
    *pday = day;
    return 0;
}
