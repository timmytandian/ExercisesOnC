#include "stdio.h"
/*
Write a program that, given a date, three ints (for example, 11 27 1997), 
will print the number of that day within its year: 
i.e. Jan 1st is always 1, Dec 31st is either 365 or 366.
The months of the year have lengths according to the following rules:
 - The odd months up to and including month 7 have 31 days.
 - The even months from 8 upwards, have 31 days.
 - Month 2 has 28 days except in a leap year when it has 29 days.
 - The rest of the months have 30 days.
*/

int IsLeapYear (int year);

int main()
{
	// variables to hold days-related value
    int day, month, year, is_leap_year, num_of_days;
    // variable to hold loop counter
    int i;
    // Initialize days_lookup with number of days in each month, assuming non leap year.
    int days_lookup[12]={31,28,31,30,31,30,31,31,30,31,30,31};

    // Read date
    printf("Program to get a date's day of the year.\n");
    printf("Please input the date (dd MM yyyy)");
    scanf("%d %d %d",&day, &month, &year);

    // Set February to have 29 days in case of leap year
    is_leap_year = IsLeapYear(year);
    if (is_leap_year)
        days_lookup[1]=29;
    
    // Start counting until MM-1
    num_of_days = 0;
    for (i=0; i<month-1; ++i){
        num_of_days += days_lookup[i];
    }
    
    // Add the number of days in month M specified in the input date
    num_of_days += day;
    printf("%d-%d-%d is a day number %d in that year.\n", day,month,year,num_of_days);
    
    return 0;
}


int IsLeapYear (int year){
    int is_leap = 0;
    
    // Check leap year from the least restrictive condition
    if (year % 4 == 0) // least restrictive
        is_leap = 1;
    if (year % 100 == 0) // a bit restrictive
        is_leap = 0;
    if (year % 400 == 0) // more restrictive
        is_leap = 1;
    if (year < 1752) // the most restrictive
        is_leap = 0;

    return is_leap;
}
