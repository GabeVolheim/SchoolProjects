#include "Date.h"
#include "calcDays.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
int d,m,y;
char userChoice,userExposed,vax;
// Gets choice for if user test positive
cout << "Did you test postive for covid, enter either Y for positive or N for negative: ";
cin >> userChoice;
    while(userChoice != 'Y' && userChoice != 'N' )
    {
        cout << "Error, user inputed invalid value. Please try again: ";
        cin >> userChoice;
    }
// If the user tested positive
if(userChoice == 'Y')
{
    Date dateP; // Creates an object dateP from class Date
    
    // Gets user choice for month and validates the input
    cout << "Enter the month tested postive: ";
    cin >> m;
    dateP.setMonth(m);
    while(dateP.setMonth(m) == false)
    {
        cout << "Error, improper value detected, please enter a value between 1 and 12: ";
        cin >> m;
        dateP.setMonth(m);
    }
    // Gets the day that the user tested positive
    cout << "Enter the day tested postive: ";
    cin >> d;
    dateP.setDay(d);
    while(dateP.setDay(d) == false)
    {
        cout << "Error, improper value detected, please enter a value between 1 and 31: ";
        cin >> d;
        dateP.setDay(d);
    }

    // Gets the year tested positive
    cout << "Enter the year tested postive: ";
    cin >> y;
    dateP.setYear(y);
    while(dateP.setYear(y) == false)
    {
        cout << "Error, improper value detected, please enter a value between 2021 and 2022: ";
        cin >> y;
        dateP.setYear(y);
    }
    // Returns user information
    cout << "Test result: positive" << endl;
    cout << "Day tested positive: " << dateP.showDate(); 
    cout << endl << "You must isolate for 5 days" << endl;
}
// If user tested negative
else 
{
    // Testing if user was exposed and validates user input
    cout << "Where you exposed to covid? Y for yes N for no: ";
    cin >> userExposed;
    while (userExposed != 'Y' && userExposed != 'N')
    {
        cout << "Error, improper format detected. Please try again: ";
        cin >> userExposed;
    }

    // If user both tests negative and also isnt exposed
    if (userExposed == 'N')
    {
        // Displaying user results
        cout << "Test result: negative" << endl;
        cout << "Exposed to positive case: No" << endl;
        cout << "Length of isolation: 0 Days" << endl; 
        return 0;
    }
    // If user was exposed
    else 
    {
        Date dateE; // Creates a class for exposure

        // Getting user exposed month and validating input
        cout << "Enter the month exposed: ";
        cin >> m;
        dateE.setMonth(m);
        while(dateE.setMonth(m) == false)
        {
            cout << "Error, improper value detected, please enter a value between 1 and 12: ";
            cin >> m;
            dateE.setMonth(m);
        }

        // Getting user exposed day and validating input
        cout << "Enter the day exposed: ";
        cin >> d;
        dateE.setDay(d);
        while(dateE.setDay(d) == false)
        {
            cout << "Error, improper value detected, please enter a value between 1 and 31: ";
            cin >> d;
            dateE.setDay(d);
        }

        // Getting user exposed year and validating input
        cout << "Enter the year exposed: ";
        cin >> y;
        dateE.setYear(y);
        while(dateE.setYear(y) == false)
        {
            cout << "Error, improper value detected, please enter a value between 2021 and 2022: ";
            cin >> y;
            dateE.setYear(y);
        }

        //Getting user vaccination status and validating input
        cout << "Have you received your second vaccine dose? (Y for yes or N for no): ";
        cin >> vax;
        while (vax != 'Y' && vax != 'N')
        {
            cout << "Error, invalid input detected, please enter either a Y or an N";
            cin >> vax;
        }

        //If user has not recieved second dose
        if(vax == 'N')
        {
            // Printing user information 
            cout << "Test Result: Negative" << endl;
            cout << "Exposed to positive case: Yes" << endl;
            cout << "Date exposed to positive case: " << dateE.showDate() << endl;
            cout << "Second vaccine dose received: No" << endl;
            cout << "Vaccination status at time of exposure: not fully vaccinated" << endl;
            cout << "Length of isolation: 10 days" << endl;
        }

        // If user did receive second vaccine does
        else
        {
            Date dateV; //Creating a class for vaccination
            // Getting month for user vaccination and validating
            cout << "Enter the month vaccinated: ";
            cin >> m;
            dateV.setMonth(m);
            while(dateV.setMonth(m) == false)
            {
                cout << "Error, improper value detected, please enter a value between 1 and 12: ";
                cin >> m;
                dateV.setMonth(m);
            }
            // Getting day user was vaccinated and validating input
            cout << "Enter the day vaccinated: ";
            cin >> d;
            dateV.setDay(d);
            while(dateV.setDay(d) == false)
            {
                cout << "Error, improper value detected, please enter a value between 1 and 31: ";
                cin >> d;
                dateV.setDay(d);
            }
            // Getting user year vaccinated and validating input
            cout << "Enter the year vaccinated: ";
            cin >> y;
            dateV.setYear(y);
            while(dateV.setYear(y) == false)
            {
                cout << "Error, improper value detected, please enter a value between 2021 and 2022: ";
                cin >> y;
                dateV.setYear(y);
            }
            // Checking to see if user if fully vaccinated at time of exposure
            if(calcDays(dateE, dateV) < 14)
            {
                // If user is not fully vaccinated, they are told they need to isolate for 10 days
                cout << "Test Result: Negative" << endl;
                cout << "Exposed to positive case: Yes" << endl;
                cout << "Date exposed to positive case: " << dateE.showDate() << endl;
                cout << "Second vaccine dose received: Yes" << endl;
                cout << "Date second vaccine does received: " << dateV.showDate() << endl;
                cout << "Vaccination status at time of exposure: not fully vaccinated" << endl;
                cout << "Length of isolation: 10 days" << endl;
            }
            else
            {
                // If user is fully vaccinated, they are told they need to isolate for 5 days
                cout << "Test Result: Negative" << endl;
                cout << "Exposed to positive case: Yes" << endl;
                cout << "Date exposed to positive case: " << dateE.showDate() << endl;
                cout << "Second vaccine dose received: Yes" << endl;
                cout << "Date second vaccine does received: " << dateV.showDate() << endl;
                cout << "Vaccination status at time of exposure: fully vaccinated" << endl;
                cout << "Length of isolation: 5 days" << endl;
            }
        }
    }
}
}
