#include <iostream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <cctype>
#include <cstring>
#include <string>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <cmath>
#include <stdlib.h> 

#include "Chapter14MoreAboutClasses.h"

//*****************************************************
// Definition of the DayOfYear class's mutator functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void DayOfYear::translationDayOfYear(const int &startOfMonth, const int &monthNumber)
{
    if( day >= startOfMonth && foundDay == false ) // December
    {
        foundDay = true;
        std::cout << month[monthNumber] << " ";

        for(int it{0}; it<32; ++it)
        {
            if( it == (day-startOfMonth) )
            {
                std::cout << daysOfMonth[it+1] << "\n";
            }
        }
    }
}

void DayOfYear::print()
{
    int startOfMonth;
    int monthNumber;

    // December
    startOfMonth = 335;
    monthNumber = 12;
    translationDayOfYear(startOfMonth,monthNumber);

    // November
    startOfMonth = 305;
    monthNumber = 11;
    translationDayOfYear(startOfMonth,monthNumber);

    // October
    startOfMonth = 274;
    monthNumber = 10;
    translationDayOfYear(startOfMonth,monthNumber);

    // September
    startOfMonth = 244;
    monthNumber = 9;
    translationDayOfYear(startOfMonth,monthNumber);

    // August
    startOfMonth = 213;
    monthNumber = 8;
    translationDayOfYear(startOfMonth,monthNumber);

    // July
    startOfMonth = 182;
    monthNumber = 7;
    translationDayOfYear(startOfMonth,monthNumber);

    // June
    startOfMonth = 152;
    monthNumber = 6;
    translationDayOfYear(startOfMonth,monthNumber);

    // May
    startOfMonth = 121;
    monthNumber = 5;
    translationDayOfYear(startOfMonth,monthNumber);

    // April
    startOfMonth = 91;
    monthNumber = 4;
    translationDayOfYear(startOfMonth,monthNumber);

    // March
    startOfMonth = 60;
    monthNumber = 3;
    translationDayOfYear(startOfMonth,monthNumber);

    // February
    startOfMonth = 32;
    monthNumber = 2;
    translationDayOfYear(startOfMonth,monthNumber);

    // January
    startOfMonth = 1;
    monthNumber = 1;
    translationDayOfYear(startOfMonth,monthNumber);
}

//*****************************************************
// Definition of the Numbers class's mutator functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void Numbers::setNumber( int &n )
{
    while( n<0 )
    {
        std::cout << "Input validation: Numbers class can only accept non negative numbers." << "\n";
        std::cout << "Input a postive number : ";
            std::cin >> n;
        std::cout << " " << "\n";
    }
    number = n;
};


void Numbers::NumberToEnglishTranslation()
{
// variable declarations to track pieces of number
            // tempNumber keeps track of remaining pieces of number as it is broken up
            int tempNumber;
            int thousands;
            int hundreds;
            int ten;
            int ones;
            
            // calculates thousands place and updates tempNumber with remainder
            thousands = number / 1000;
            tempNumber = number % 1000;
            
            // displays thousands, if any
            if (thousands > 0)
            {
                std::cout << lessThan20[thousands] << " "<< thousand;
            }
            
            // calculates hundreds place and updates tempNumber with remainder
            hundreds = tempNumber / 100;
            tempNumber = tempNumber % 100;
            
            // displays hundreds, if any
            if (hundreds > 0)
            {
                // if statement adds space if thousands were displayed
                if (thousands)
                    std::cout << ' ';
                std::cout << lessThan20[hundreds] << " " << hundred;
            }
            
            // calculates tens place and updates tempNumber with remainder
            ten = tempNumber / 10;
            
            // displays tens place as 'twenty', 'thirty', etc.
            // if else handles teen numbers when tens less than 2 ('twenty')
            if (ten > 1)
            {
                if (hundreds)
                    std::cout << ' ';
                std::cout << tens[ten];
                tempNumber = tempNumber % 10;
                if (tempNumber > 0)
                    std::cout << ' ' << lessThan20[tempNumber];
            }
            else
            {
                if (hundreds && tempNumber)
                    std::cout << ' ';
                if (tempNumber > 0)
                    std::cout << lessThan20[tempNumber];
            }
}

//*****************************************************
// Definition of function displayProgramMenu. 
// This function displays the program's menu on the screen. 
//*****************************************************

void displayProgramMenu()
{
    std::cout << "***----displayProgramMenu----***" << "\n"; std::cout << " " << "\n";

    std::cout << "User, choice a program to run." << "\n";
        std::cout << "A) Chapter 14 More About Classes - 1. Numbers Class " << "\n";
        std::cout << "B) Chapter 14 More About Classes - 2. Day of the Year " << "\n";
        // std::cout << "A) " << "\n";

}

// end

//*****************************************************
// Definition of  Class's costructor. 
//*****************************************************

//*****************************************************
// Definition of the  class's accessor functions. 
// These functions return and display the values in these member variables.
//*****************************************************

//*****************************************************
// Definition of the  class's mutator functions. 
// These functions return and display the values in these member variables.
//*****************************************************