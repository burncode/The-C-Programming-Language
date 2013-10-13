// Author: jrjbear@gmail.com
// Date: Sun Oct 13 13:05:16 2013
//
// File: 5-8.cpp
// Description: Convert between dates and days


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Both function will validate the parameter. Return -1 on error.
int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int* pmonth, int* pday);

int main(int argc, char* argv[])
{
    srand(time(NULL));

    int month = 0;
    int day = 0;
    printf("month_day(1900, 366): %d\n", 
           month_day(1900, 366, &month, &day));    
    printf("month_day(2000, 366): %d. ",
           month_day(2000, 366, &month, &day));
    printf("It's %02d/%02d\n\n", month, day);

    printf("day_of_year(1900, 2, 29): %d\n", day_of_year(1900, 2, 29));
    printf("day_of_year(2000, 3, 1): %d\n\n\n", day_of_year(2000, 3, 1));

    for (int i = 0; i < 10; ++i) {
        int year = rand() % 101 + 1900;
        int yearday = rand() % 400;
        printf("month_day(%d, %d): ", year, yearday);
        int ret = month_day(year, yearday, &month, &day);
        if (ret == 0) {
            printf("%02d/%02d\n", month, day);
            printf("day_of_year(%d, %d, %d): %d\n", 
                    year, month, day, 
                    day_of_year(year, month, day));
        }
        printf("\n");
    }    

    return 0;
}


const char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
};

int day_of_year(int year, int month, int day)
{
    if (month <= 0 || month > 12) {
        printf("Invalid month: %d\n", month);
        return -1;
    }
    
    int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (day > daytab[leap][month]) {
        printf("Invalid day: %d\n", day);
        return -1;
    }
    int days = day;
    for (int i = 1; i < month; i++) {
        days += daytab[leap][i];
    }
    return days;
}

int month_day(int year, int yearday, int* pmonth, int* pday)
{
    if (yearday <= 0) {
        printf("Invalid yearday: %d\n", yearday);
        return -1;
    }

    int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int day = yearday;
    int month = 1;
    for (; day > daytab[leap][month] && month <= 12; month++) {
        day -= daytab[leap][month];
    }
    if (month > 12) {
        printf("Invalid yearday: %d\n", yearday);
        return -1;
    }
    *pmonth = month;
    *pday = day;
    return 0;
}
