#include "calcDays.h"
#include "Date.h"
#include <iostream>
/* 
This function takes two class inputs of date and returns the total days between the two 
*/

int calcDays(Date a, Date b)
{
int daysDiff1=0,daysDiff2=0;
int totalDays[12]= {31,28,31,30,31,30,31,31,30,31,30,31}; //Array that contains all values for the months

if (a.getYear() == 2022) daysDiff1 += 365; //Adds an entire years worth of days if the year is above 2022

//Iterating and adding the total amount of days for every month 
for(int i = 0; i < a.getMonth(); i++)
{
    daysDiff1 += totalDays[i];
}
daysDiff1 += a.getDay(); // adds the final day value

// Does the same as above but this time for class b
if (b.getYear() == 2022) daysDiff2 += 365;
for(int i = 0; i < b.getMonth(); i++)
{
    daysDiff2 += totalDays[i];
}
daysDiff2 +=b.getDay();

//Returns the difference of the total days of each given class
return (daysDiff1-daysDiff2);
}