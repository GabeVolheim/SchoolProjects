#ifndef DATE_H_
#define DATE_H_
#include <string>
#include <iostream>
class Date
{
private:

int day = {01};
int month = {01};
int year = {2021};
int totalDays[12]= {31,28,31,30,31,30,31,31,30,31,30,31}; //Array of all days of year

public:
//Constructors
Date() = default;
Date(int d, int m,int y);

//Set Functions
bool setDay(int d);
bool setMonth(int m);
bool setYear(int y);

//Get Functions
int getDay();
int getMonth();
int getYear();

//Function that returns a string thats a combination of all.
std::string showDate();

};

#endif 