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

enum MonthNumber{JanuaryMonthNumber =1 , FebruaryMonthNumber =2 , MarchMonthNumber =3 , AprilMonthNumber =4 , MayMonthNumber =5 , JuneMonthNumber =6, 
JulyMonthNumber =7, AugustMonthNumber =8, SeptemberMonthNumber =9 , OctoberMonthNumber =10 , NovemberMonthNumber =11, DecemberMonthNumber =12};


//**************************************************************
// Definition of member function simplify. This function *
// checks for values in the inches member greater than *
// twelve or less than zero. If such a value is found, *
// the numbers in feet and inches are adjusted to conform *
// to a standard feet & inches expression. For example, *
// 3 feet 14 inches would be adjusted to 4 feet 2 inches and *
// 5 feet −2 inches would be adjusted to 4 feet 10 inches. *
/*
void FeetInches::simplify()
{
    if (inches >= 12)
    {
        feet += (inches / 12);
        inches = inches % 12;
    }
    else if (inches < 0)
    {
        feet -= ((abs(inches) / 12) + 1);
        inches = 12 - (abs(inches) % 12);
    }
}
*/
//**************************************************************

/*
//**********************************************
// Overloaded binary + operator. *
FeetInches FeetInches::operator + (const FeetInches &right)
{
    FeetInches temp;
    temp.inches = inches + right.inches;
    temp.feet = feet + right.feet;
    temp.simplify();
    return temp;
}
//**********************************************
*/

/*
//**********************************************
// Overloaded binary − operator. *
FeetInches FeetInches::operator - (const FeetInches &right)
{
    FeetInches temp;
    temp.inches = inches - right.inches;
    temp.feet = feet - right.feet;
    temp.simplify();
    return temp;
}
//**********************************************
*/

//*****************************************************
// Definition of Date Class's overloaded costructors. 
// These costructors set the month, day and year based on arugments passed.
//*****************************************************
Date::Date()
{ setMonthDayYear(month, day, year); }
        
Date::Date(int &m)
{ setMonthDayYear(month, day, year, m); }

Date::Date(int &m, int &d)
{ setMonthDayYear(month, day, year, m, d); }

Date::Date(int &m, int &d, int &y)
{ setMonthDayYear(month, day, year, m, d, y); }

//*****************************************************
// Definition of setMonthDayYear overloaded functions. 
// These functions set the month day and year respectively based on the amount of arguments passed. 
//*****************************************************
        
void Date::setMonthDayYear(int &month, int &day, int &year)
{ 
    month = 01; 
    day = 01; 
    year = 0001; 
}
        
void Date::setMonthDayYear(int &month, int &day, int &year, int &m)
{ 
    while(m < 1 || m > 12)
    {
        std::cout << "Input Validation: Do not accept values for the month greater than 12 or less than 1." << '\n';
        std::cout << "Input a new value for the month : ";
            std::cin >> m;
    }
    month = m;
    day = 01; 
    year = 0001; 
}

void Date::setMonthDayYear(int &month, int &day, int &year, int &m, int &d)
{ 
    while(m < 1 || m > 12)
    {
        std::cout << "Input Validation: Do not accept values for the month greater than 12 or less than 1." << '\n';
        std::cout << "Input a new value for the month : ";
            std::cin >> m;
    }
    month = m; 

    while(d < 1 || d > 31)
    {
        std::cout << "Input Validation: Do not accept values for the day greater than 31 or less than 1." << '\n';
        std::cout << "Input a new value for the day : ";
            std::cin >> d;
    }
    day = d; 

    year = 0001; 
}

void Date::setMonthDayYear(int &month, int &day, int &year, int &m, int &d, int &y)
{ 
    while(m < 1 || m > 12)
    {
        std::cout << "Input Validation: Do not accept values for the month greater than 12 or less than 1." << '\n';
        std::cout << "Input a new value for the month : ";
            std::cin >> m;
    }
    month = m; 

    while(d < 1 || d > 31)
    {
        std::cout << "Input Validation: Do not accept values for the day greater than 31 or less than 1." << '\n';
        std::cout << "Input a new value for the day : ";
            std::cin >> d;
    }
    day = d; 

    year = y; 
}

//*****************************************************
// Definition of getDateFormat1 fucntions. 
// These functions display the date in different formats 
//*****************************************************

void Date::getDateFormat1(const int &month, const int &day, const int &year) const // retrieves the data in this format 12/25/2014
{
    std::cout << "***----getDateFormat1----***" << "\n"; std::cout << " " << "\n";

    std::cout << "DateFormat1 : " << month << '/' << day << '/' << year << "\n";
} 

void Date::getDateFormat2(const int &month, const int &day, const int &year) const // retrieves the data in this format December 25, 2014
{
    std::cout << "***----getDateFormat2----***" << "\n"; std::cout << " " << "\n";

    std::cout << "DateFormat2 : ";

    switch (month)
    {
        case JanuaryMonthNumber:
            std::cout << "January";
            break;
        case FebruaryMonthNumber:
            std::cout << "February";
            break;
        case MarchMonthNumber:
            std::cout << "March";
            break;
        case AprilMonthNumber:
            std::cout << "April";
            break;
        case MayMonthNumber:
            std::cout << "May";
            break;
        case JuneMonthNumber:
            std::cout << "June";
            break;
        case JulyMonthNumber:
            std::cout << "July";
            break;
        case AugustMonthNumber:
            std::cout << "August";
            break;
        case SeptemberMonthNumber:
            std::cout << "September";
            break;
        case OctoberMonthNumber:
            std::cout << "October";
            break;
        case NovemberMonthNumber:
            std::cout << "November";
            break;
        case DecemberMonthNumber:
            std::cout << "December";
            break;
        
        default:
            break;
    }

    std::cout << " " << day << ", " << year << "\n";
}

void Date::getDateFormat3(const int &month, const int &day, const int &year) const // retrieves the data in this format 25 December 2014
{
    std::cout << "***----getDateFormat3----***" << "\n"; std::cout << " " << "\n";

    std::cout << "DateFormat3 : " << day << " ";

    switch (month)
    {
        case JanuaryMonthNumber:
            std::cout << "January";
            break;
        case FebruaryMonthNumber:
            std::cout << "February";
            break;
        case MarchMonthNumber:
            std::cout << "March";
            break;
        case AprilMonthNumber:
            std::cout << "April";
            break;
        case MayMonthNumber:
            std::cout << "May";
            break;
        case JuneMonthNumber:
            std::cout << "June";
            break;
        case JulyMonthNumber:
            std::cout << "July";
            break;
        case AugustMonthNumber:
            std::cout << "August";
            break;
        case SeptemberMonthNumber:
            std::cout << "September";
            break;
        case OctoberMonthNumber:
            std::cout << "October";
            break;
        case NovemberMonthNumber:
            std::cout << "November";
            break;
        case DecemberMonthNumber:
            std::cout << "December";
            break;
        
        default:
            break;
    }

    std::cout << " " << year << " " << "\n";
}

//*****************************************************
// Definition of the  class's operator functions. 
// redefine the way a particular operator works with an object
// Update other member variables if needed.	
//*****************************************************

//*****************************************************
// Definition of set date fucntions
// These function update one specfic member varible of the Date class
//*****************************************************

void Date::setMonth(int &month, int &m) // updates the month member variable 
{
    std::cout << "***----setMonth----***" << "\n"; std::cout << " " << "\n";
    
    while(m < 1 || m > 12)
    {
        std::cout << "Input Validation: Do not accept values for the month greater than 12 or less than 1." << '\n';
        std::cout << "Input a new value for the month : ";
            std::cin >> m;
    }

    month = m;
}

void Date::setDay(int &day, int &d) // updates the month member variable 
{
    std::cout << "***----setDay----***" << "\n"; std::cout << " " << "\n";

    while(d < 1 || d > 31)
    {
        std::cout << "Input Validation: Do not accept values for the day greater than 31 or less than 1." << '\n';
        std::cout << "Input a new value for the day : ";
            std::cin >> d;
    }
    day = d; 
}

void Date::setYear(int &year, int &y) // updates the month member variable 
{
    std::cout << "***----setYear----***" << "\n"; std::cout << " " << "\n";

    year = y;
}

//*****************************************************
// Definition of Month Class's costructor. 
//*****************************************************

Month::Month( std::string &n )
{
    DayOfYear dOY;

    for( int it{JanuaryMonthNumber}; it<=DecemberMonthNumber; ++it)
    {
        if( n == dOY.getMonthNames(it) )
        {
            monthFound = true;
            name = n;
            monthNumber = it;
        }
    }

    while( monthFound == false )
    {
        std::cout << "Input Validation: Month name does not exist." << '\n';
        std::cout << "Input a valid month name : ";
            std::cin >> n;
        std::cout << " " << "\n";
            
        for( int it{JanuaryMonthNumber}; it<=DecemberMonthNumber; ++it)
        {
            if( n == dOY.getMonthNames(it) )
            {
                monthFound = true;
                name = n;
                monthNumber = it;
            }
        }
    }
    monthFound = false;
}

Month::Month( int &mN )
{
    DayOfYear dOY;

    for( int it{JanuaryMonthNumber}; it<=DecemberMonthNumber; ++it)
    {
        if( mN == it )
        {
            monthFound = true;
            monthNumber = it;
            name = dOY.getMonthNames(it);
        }
    }

    while( monthFound == false )
    {
        std::cout << "Input Validation: Month number does not exist." << '\n';
        std::cout << "Input a valid month number : ";
            std::cin >> mN;
        std::cout << " " << "\n";
            
        for( int it{JanuaryMonthNumber}; it<=DecemberMonthNumber; ++it)
        {
            if( mN == it )
            {
                monthFound = true;
                monthNumber = it;
                name = dOY.getMonthNames(it);
            }
        }
    }
    monthFound = false;
}

//*****************************************************
// Definition of the Month class's mutator functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void Month::setMonthName( std::string &n )
{
    DayOfYear dOY;

    for( int it{JanuaryMonthNumber}; it<=DecemberMonthNumber; ++it)
    {
        if( n == dOY.getMonthNames(it) )
        {
            monthFound = true;
            name = n;
            monthNumber = it;
        }
    }

    while( monthFound == false )
    {
        std::cout << "Input Validation: Month name does not exist." << '\n';
        std::cout << "Input a valid month name : ";
            std::cin >> n;
        std::cout << " " << "\n";
            
        for( int it{JanuaryMonthNumber}; it<=DecemberMonthNumber; ++it)
        {
            if( n == dOY.getMonthNames(it) )
            {
                monthFound = true;
                name = n;
                monthNumber = it;
            }
        }
    }
    monthFound = false;
}

void Month::setMonthName( int &mN )
{
    DayOfYear dOY;

    for( int it{JanuaryMonthNumber}; it<=DecemberMonthNumber; ++it)
    {
        if( mN == it )
        {
            monthFound = true;
            monthNumber = it;
            name = dOY.getMonthNames(it);
        }
    }

    while( monthFound == false )
    {
        std::cout << "Input Validation: Month number does not exist." << '\n';
        std::cout << "Input a valid month number : ";
            std::cin >> mN;
        std::cout << " " << "\n";
            
        for( int it{JanuaryMonthNumber}; it<=DecemberMonthNumber; ++it)
        {
            if( mN == it )
            {
                monthFound = true;
                monthNumber = it;
                name = dOY.getMonthNames(it);
            }
        }
    }
    monthFound = false;
}

void Month::setMonthNumber( int &mN )
{
    DayOfYear dOY;

    for( int it{JanuaryMonthNumber}; it<=DecemberMonthNumber; ++it)
    {
        if( mN == it )
        {
            monthFound = true;
            monthNumber = it;
            name = dOY.getMonthNames(it);
        }
    }

    while( monthFound == false )
    {
        std::cout << "Input Validation: Month number does not exist." << '\n';
        std::cout << "Input a valid month number : ";
            std::cin >> mN;
        std::cout << " " << "\n";
            
        for( int it{JanuaryMonthNumber}; it<=DecemberMonthNumber; ++it)
        {
            if( mN == it )
            {
                monthFound = true;
                monthNumber = it;
                name = dOY.getMonthNames(it);
            }
        }
    }
    monthFound = false;
}

void Month::setMonthNumber( std::string &n )
{
    DayOfYear dOY;

    for( int it{JanuaryMonthNumber}; it<=DecemberMonthNumber; ++it)
    {
        if( n == dOY.getMonthNames(it) )
        {
            monthFound = true;
            name = n;
            monthNumber = it;
        }
    }

    while( monthFound == false )
    {
        std::cout << "Input Validation: Month name does not exist." << '\n';
        std::cout << "Input a valid month name : ";
            std::cin >> n;
        std::cout << " " << "\n";
            
        for( int it{JanuaryMonthNumber}; it<=DecemberMonthNumber; ++it)
        {
            if( n == dOY.getMonthNames(it) )
            {
                monthFound = true;
                name = n;
                monthNumber = it;
            }
        }
    }
    monthFound = false;
}

//*****************************************************
// Definition of the  class's operator functions. 
// redefine the way a particular operator works with an object
// Update other member variables if needed.	
//*****************************************************

Month& Month::operator ++ () // ++ Prefix increment operators.
{ 
    ++monthNumber;
    if( monthNumber == 13 )
    {
        monthNumber = 1; 
    }
    setMonthName( monthNumber );
    return *this; 
}

Month Month::operator ++ ( int ) // ++ Postfix increment operators.
{
    ++monthNumber;
    if( monthNumber == 13 )
    {
        monthNumber = 1;
    }
    setMonthName( monthNumber );
    return *this; 
}

Month& Month::operator -- () // -- Prefix decrement operators.
{ 
    --monthNumber;
    if( monthNumber == 0 )
    {
        monthNumber = 12;
    } 
    setMonthName( monthNumber );
    return *this; 
}

Month Month::operator -- ( int ) // -- Postfix decrement operators.
{ 
    --monthNumber;
    if( monthNumber == 0 )
    {
        monthNumber = 12;
    } 
    setMonthName( monthNumber );
    return *this; 
}

//*****************************************************
// Definition of TimeOff Class's costructor. 
//*****************************************************

TimeOff::TimeOff() // default constructor
{
    int hours{0};
    maxSickDays.setNumberOfWorkHours(hours);
    sickTaken.setNumberOfWorkHours(hours);
    maxVacation.setNumberOfWorkHours(hours);
    vacationTaken.setNumberOfWorkHours(hours);
    maxUnpaid.setNumberOfWorkHours(hours);
    unpaidTaken.setNumberOfWorkHours(hours);
    employeeName = "John Doe";
    employeeId = 1;
}

TimeOff::TimeOff( std::string &eN, int &eId, int &msD, int &sT, int &mV, int &vT, int &mU, int &uT )
{
    employeeName = eN;
    employeeId = eId;
    maxSickDays.setNumberOfWorkHours(msD);
    sickTaken.setNumberOfWorkHours(sT);
    while ( mV > 240 )
    {
        std::cout << "Input Validation: Company policy states that an employee may not accumulate more than 240 hours of paid vacation." << '\n';
        std::cout << "Input maxVacation hours : ";
            std::cin >> mV;
        std::cout << " " << "\n";
    }
    maxVacation.setNumberOfWorkHours(mV);
    vacationTaken.setNumberOfWorkHours(vT);
    maxUnpaid.setNumberOfWorkHours(mU);
    unpaidTaken.setNumberOfWorkHours(uT);
}
//*****************************************************
// Definition of the TimeOff class's mutator functions. 
// These functions return and display the values in these member variables.
//*****************************************************
void TimeOff::setMaxSickDays(int &msD)
{
    maxSickDays.setNumberOfWorkHours(msD);
}

void TimeOff::setSickTaken(int &sT)
{
    sickTaken.setNumberOfWorkHours(sT);
}

void TimeOff::setMaxVacation(int &mV)
{
    while ( mV > 240 )
    {
        std::cout << "Input Validation: Company policy states that an employee may not accumulate more than 240 hours of paid vacation." << '\n';
        std::cout << "Input maxVacation hours : ";
            std::cin >> mV;
        std::cout << " " << "\n";
    }
    maxVacation.setNumberOfWorkHours(mV);
}

void TimeOff::setVacationTaken(int &vT)
{
    vacationTaken.setNumberOfWorkHours(vT);
}

void TimeOff::setMaxUnpaid(int &mU)
{
    maxUnpaid.setNumberOfWorkHours(mU);
}

void TimeOff::setUnpaidTaken(int &uT)
{
    unpaidTaken.setNumberOfWorkHours(uT);
}

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
        std::cout << "F) Chapter 14 More About Classes - 5. Time Off " << "\n";
        std::cout << "G) Chapter 14 More About Classes - 6. Personnel Report " << "\n";
        std::cout << "H) Chapter 14 More About Classes - 7. Month Class " << "\n";
        std::cout << "I) Chapter 14 More About Classes - 8. Date Class Modification " << "\n";
        std::cout << "J) Chapter 14 More About Classes - 9. FeetInches Modification " << "\n";
        std::cout << "K)  " << "\n";
        std::cout << "L)  " << "\n";
        std::cout << "M)  " << "\n";
        std::cout << "N)  " << "\n";
        std::cout << "O)  " << "\n";
        std::cout << "P)  " << "\n";
        std::cout << "Q)  " << "\n";
        std::cout << "R)  " << "\n";
        std::cout << "S)  " << "\n";
        std::cout << "T)  " << "\n";
        std::cout << "U)  " << "\n";
        std::cout << "V)  " << "\n";
        std::cout << "W)  " << "\n";
        std::cout << "X)  " << "\n";
        std::cout << "Y)  " << "\n";
        std::cout << "Z)  " << "\n";
}

// end

//*****************************************************
// Definition of  Class's costructors. 
//*****************************************************

//*****************************************************
// Definition of the  class's accessor functions. 
// These functions return and display the values in these member variables.
//*****************************************************

//*****************************************************
// Definition of the  class's mutator functions. 
// These functions return and display the values in these member variables.
// Update other member variables if needed.	
//*****************************************************

//*****************************************************
// Definition of the  class's operator functions. 
// redefine the way a particular operator works with an object
// Update other member variables if needed.	
//*****************************************************

//*****************************************************
// Definition of  Class's destructors. 
//*****************************************************