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

enum startOfMonth
{JanuaryStartOfMonth = 1, FebruaryStartOfMonth = 32, MarchStartOfMonth = 60, AprilStartOfMonth = 91, MayStartOfMonth = 121, JuneStartOfMonth = 152, 
JulyStartOfMonth = 182, AugustStartOfMonth = 213, SeptemberStartOfMonth = 244, OctoberStartOfMonth = 274, NovemberStartOfMonth = 305, DecemberStartOfMonth = 335 };

enum monthMaxDays
{JanuaryMaxDays = 31, FebruaryMaxDays = 28, MarchMaxDays = 31, AprilMaxDays = 30, MayMaxDays = 31, JuneMaxDays = 30, 
JulyMaxDays = 31, AugustMaxDays = 31, SeptemberMaxDays = 30, OctoberMaxDays = 31, NovemberMaxDays = 30, DecemberMaxDays = 31 };

enum MonthsOfYear{JanuaryMonthNumber =1 , FebruaryMonthNumber =2 , MarchMonthNumber =3 , AprilMonthNumber =4 , MayMonthNumber =5 , JuneMonthNumber =6, 
JulyMonthNumber =7, AugustMonthNumber =8, SeptemberMonthNumber =9 , OctoberMonthNumber =10 , NovemberMonthNumber =11, DecemberMonthNumber =12};

//*****************************************************
// Definition of DayOfYear Class's costructor. 
//*****************************************************

DayOfYear::DayOfYear(std::string &m, int &dayOfMonth)
{                
    int foundMonth;

    for(int i{JanuaryMonthNumber}; i<=DecemberMonthNumber; ++i)
    {
        if( m == months[i] )
        {
            foundMonth = i;
        }
    }

    switch (foundMonth)
    {
        case 0:
            /* code */
            break;
        case 1:
            dayNumber = JanuaryStartOfMonth;
            monthDayCountValidation(m, dayOfMonth, JanuaryMaxDays);
            break;
        case 2:
            dayNumber = FebruaryStartOfMonth;
            monthDayCountValidation(m, dayOfMonth, FebruaryMaxDays);
            break;
        case 3:
            dayNumber = MarchStartOfMonth;
            monthDayCountValidation(m, dayOfMonth, MarchMaxDays);
            break;
        case 4:
            dayNumber = AprilStartOfMonth;
            monthDayCountValidation(m, dayOfMonth, AprilMaxDays);
            break;
        case 5:
            dayNumber = MayStartOfMonth;
            monthDayCountValidation(m, dayOfMonth, MayMaxDays);
            break;
        case 6:
            dayNumber = JuneStartOfMonth;
            monthDayCountValidation(m, dayOfMonth, JuneMaxDays);
            break;
        case 7:
            dayNumber = JulyStartOfMonth;
            monthDayCountValidation(m, dayOfMonth, JulyMaxDays);
            break;
        case 8:
            dayNumber = AugustStartOfMonth;
            monthDayCountValidation(m, dayOfMonth, AugustMaxDays);
            break;
        case 9:
            dayNumber = SeptemberStartOfMonth;
            monthDayCountValidation(m, dayOfMonth, SeptemberMaxDays);
            break;
        case 10:
            dayNumber = OctoberStartOfMonth;
            monthDayCountValidation(m, dayOfMonth, OctoberMaxDays);
            break;
        case 11:
            dayNumber = NovemberStartOfMonth;
            monthDayCountValidation(m, dayOfMonth, NovemberMaxDays);
            break;
        case 12:
            dayNumber = DecemberStartOfMonth;
            monthDayCountValidation(m, dayOfMonth, DecemberMaxDays);
            break;
        default:
            break;
    }

    // subract one for day 1 of the month
    dayNumber = (dayNumber-1) + dayOfMonth;

    foundDay = false; // switch off
}

//*****************************************************
// Definition of the DayOfYear class's mutator functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void DayOfYear::monthDayCountValidation(std::string &m, int &dayOfMonth, const int &monthMaxDays)
{
    while (dayOfMonth > monthMaxDays)
    {
        std::cout << "Input validation: For month " << m << ", the max number of days is " << monthMaxDays << "\n";
        std::cout << "Input a postive number less than or equal to " << monthMaxDays << "\n";
            std::cin >> dayOfMonth;
        std::cout << " " << "\n";
    }
}

void DayOfYear::translationDayOfYear(const int &startOfMonth, const int &monthNumber)
{
    if( dayNumber >= startOfMonth && foundDay == false ) 
    {
        foundDay = true;
        month = months[monthNumber];
        std::cout << month << " ";

        for(int it{0}; it<32; ++it)
        {
            if( it == (dayNumber-startOfMonth) )
            {
                day = daysOfMonth[it+1];
                std::cout << day << "\n";
            }
        }
    }
}

void DayOfYear::print()
{
    translationDayOfYear(DecemberStartOfMonth,DecemberMonthNumber);

    translationDayOfYear(NovemberStartOfMonth,NovemberMonthNumber);

    translationDayOfYear(OctoberStartOfMonth,OctoberMonthNumber);

    translationDayOfYear(SeptemberStartOfMonth,SeptemberMonthNumber);

    translationDayOfYear(AugustStartOfMonth,AugustMonthNumber);

    translationDayOfYear(JulyStartOfMonth,JulyMonthNumber);

    translationDayOfYear(JuneStartOfMonth,JuneMonthNumber);

    translationDayOfYear(MayStartOfMonth,MayMonthNumber);

    translationDayOfYear(AprilStartOfMonth,AprilMonthNumber);

    translationDayOfYear(MarchStartOfMonth,MarchMonthNumber);

    translationDayOfYear(FebruaryStartOfMonth,FebruaryMonthNumber);

    translationDayOfYear(JanuaryStartOfMonth,JanuaryMonthNumber);

    foundDay = false;
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
        std::cout << "C) Chapter 14 More About Classes - 3. Day of the Year Modification" << "\n";
        std::cout << "D) Chapter 14 More About Classes - 4. NumDays Class " << "\n";
        std::cout << "E) --- EXIT ---" << "\n";
        // std::cout << "A) " << "\n";
        // std::cout << "A) " << "\n";
        // std::cout << "A) " << "\n";
        // std::cout << "A) " << "\n";
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