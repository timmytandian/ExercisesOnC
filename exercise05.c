#include "stdio.h"
/*
Given the following rules, write a program to read a year (4 digit integer) 
and tell whether the given year is/was a leap year.
 - There were no leap years before 1752.
 - If the year divides by 400 then it is a leap year.
 - All other years that divide by 100 are not leap years.
 - All other years that divide by four are leap years.
For example, 1800,1900 were not leap years but 2000 will be; 
1904, 1908,...,1996 were/will be leap years.

*/

int main()
{
	int year, is_leap;

    // Read year
    printf("Program to check leap year. Please input year: \n");
    scanf("%d",&year);

    while((year<0)||(year>9999)){
        printf("ERROR!!! Please input year as integer between 0-9999: \n");
        scanf("%d",&year);
    }

    is_leap = 0;
    
    // Check leap year from the least restrictive condition
    if (year % 4 == 0) // least restrictive
        is_leap = 1;
    if (year % 100 == 0) // a bit restrictive
        is_leap = 0;
    if (year % 400 == 0) // more restrictive
        is_leap = 1;
    if (year < 1752) // the most restrictive
        is_leap = 0;
    
    if (is_leap)
        printf("%d is a leap year.\n", year);
    else
        printf("%d is not a leap year.\n", year);
    return 0;
}