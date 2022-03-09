#include "Date.h"
#include <iostream>
#include <string>

//Constructor that validates input
Date :: Date(int d, int m,int y)
{
    if (setDay(d) == false) return;
    else setDay(d);

    if (setMonth(m) == false) return;
    else setDay(d);

    if (setYear(y) == false) return; 
    else setDay(y);
}
//Sets day and validates input
bool Date :: setDay(int d)
{
    if(d < 01 || d > totalDays[month-1]){
        return false;
    }
    else
    {
        day=d;
        return true;
    }
}
//Sets month and validates input
bool Date :: setMonth(int m)
{
        if(m < 01 || m > 12){
        return false;
    }
    else
    {
        month=m;
        return true;
    }
}
//Sets year and validates input
bool Date :: setYear(int y)
{
    if(y != 2021 && y != 2022)
    {
        return false;
    }
    else
    {
        year = y;
        return true;
    }
}

//Returns day
int Date :: getDay()
{
    return day;
}

//Returns month
int Date :: getMonth()
{
    return month;
}

// Returns year
int Date :: getYear()
{
    return year;
}

// Returns a string of the date
std::string Date :: showDate()
{
std::string date;
    date += std::to_string(month);
    date += "/";
    date += std::to_string(day);
    date += "/";
    date += std::to_string(year);
    return date;
}