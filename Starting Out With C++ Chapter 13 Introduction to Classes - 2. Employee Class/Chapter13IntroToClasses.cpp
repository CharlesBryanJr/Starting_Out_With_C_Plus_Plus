/*
Starting Out With C++ Chapter 11 Structured Data - 1. Date
Design a class called Date. The class should store a date in three integers: month, day, and year. 
There should be member functions to print the date in the following forms:
12/25/2014
December 25, 2014
25 December 2014
Demonstrate the class by writing a complete program implementing it.
Input Validation: Do not accept values for the day greater than 31 or less than 1. 
Input Validation:Do not accept values for the month greater than 12 or less than 1.
*/

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

#include "Chapter13IntroToClasses.h"


enum MonthsOfYear{January, February, March, April, May, June, July, August, September, October, November, December};


//*****************************************************
// Definition of the Employee class's accessor functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void Employee::getEmployeeName()
{
    std::cout << "***----getEmployeeName----***" << "\n"; std::cout << " " << "\n";

    std::cout << "The Employee's name is : " << name << "\n";
    std::cout << " " << "\n";
}

void Employee::getEmployeeID()
{
    std::cout << "***----getEmployeeID----***" << "\n"; std::cout << " " << "\n";

    std::cout << "The Employee's ID Number is : " << idNumber << "\n";
    std::cout << " " << "\n";
}

void Employee::getEmployeeDepartment()
{
    std::cout << "***----getEmployeeDepartment----***" << "\n"; std::cout << " " << "\n";

    std::cout << "The Employee's department is : " << department << "\n";
    std::cout << " " << "\n";
}

void Employee::getEmployeePosition()
{
    std::cout << "***----getEmployeePosition----***" << "\n"; std::cout << " " << "\n";

    std::cout << "The Employee's position is : " << position << "\n";
    std::cout << " " << "\n";
}

//*****************************************************
// Definition of the Employee class's mutator functions. 
// These functions store values in these member variables 
//*****************************************************

void Employee::setEmployeeName(std::string &n)
{
    std::cout << "***----setEmployeeName----***" << "\n"; std::cout << " " << "\n";
    name = n;
}

void Employee::setEmployeeID(int &id)
{
    std::cout << "***----setEmployeeID----***" << "\n"; std::cout << " " << "\n";
    idNumber = id;
}

void Employee::setEmployeeDepartment(std::string &dep)
{
    std::cout << "***----setEmployeeDepartment----***" << "\n"; std::cout << " " << "\n";
    department = dep;
}

void Employee::setEmployeePosition(std::string &pos)
{
    std::cout << "***----setEmployeePosition----***" << "\n"; std::cout << " " << "\n";
    position = pos;
}

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
// Definition of getDateFormat1 fucntions. 
// These functions display the date in different formats 
//*****************************************************

void Date::getDateFormat1(const int &month, const int &day, const int &year) // retrieves the data in this format 12/25/2014
{
    std::cout << "***----getDateFormat1----***" << "\n"; std::cout << " " << "\n";

    std::cout << "DateFormat1 : " << month << '/' << day << '/' << year << "\n";
} 

void Date::getDateFormat2(const int &month, const int &day, const int &year) // retrieves the data in this format December 25, 2014
{
    std::cout << "***----getDateFormat2----***" << "\n"; std::cout << " " << "\n";

    std::cout << "DateFormat2 : ";

    switch (month-1)
    {
        case January:
            std::cout << "January";
            break;
        case February:
            std::cout << "February";
            break;
        case March:
            std::cout << "March";
            break;
        case April:
            std::cout << "April";
            break;
        case May:
            std::cout << "May";
            break;
        case June:
            std::cout << "June";
            break;
        case July:
            std::cout << "July";
            break;
        case August:
            std::cout << "August";
            break;
        case September:
            std::cout << "September";
            break;
        case October:
            std::cout << "October";
            break;
        case November:
            std::cout << "November";
            break;
        case December:
            std::cout << "December";
            break;
        
        default:
            break;
    }

    std::cout << " " << day << ", " << year << "\n";
}

void Date::getDateFormat3(const int &month, const int &day, const int &year) // retrieves the data in this format 25 December 2014
{
    std::cout << "***----getDateFormat3----***" << "\n"; std::cout << " " << "\n";

    std::cout << "DateFormat3 : " << day << " ";

    switch (month-1)
    {
        case January:
            std::cout << "January";
            break;
        case February:
            std::cout << "February";
            break;
        case March:
            std::cout << "March";
            break;
        case April:
            std::cout << "April";
            break;
        case May:
            std::cout << "May";
            break;
        case June:
            std::cout << "June";
            break;
        case July:
            std::cout << "July";
            break;
        case August:
            std::cout << "August";
            break;
        case September:
            std::cout << "September";
            break;
        case October:
            std::cout << "October";
            break;
        case November:
            std::cout << "November";
            break;
        case December:
            std::cout << "December";
            break;
        
        default:
            break;
    }

    std::cout << " " << year << " " << "\n";
}

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
// Definition of the Date class's deconstructors. 
// This function displays the program's menu on the screen. 
//*****************************************************
Date::~Date(){}

//*****************************************************
// Definition of function displayProgramMenu. 
// This function displays the program's menu on the screen. 
//*****************************************************
void displayProgramMenu()
{
    std::cout << "***----displayProgramMenu----***" << "\n"; std::cout << " " << "\n";

    std::cout << "User, choice a program to run." << "\n";
        std::cout << "A) Starting Out With C++ Chapter 11 Structured Data - 1. Date" << "\n";
        std::cout << "B) Starting Out With C++ Chapter 11 Structured Data - 2. Employee Class" << "\n";
        std::cout << "E) --- EXIT ---" << "\n";
}

//*****************************************************
// Definition of function inputValidation functions. 
// These functions return a postive number. 
//*****************************************************

int inputValidation_postiveInteger(int &integer)
{
    std::cin >> integer;

    while( integer<0  )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "Input again : ";
            std::cin >> integer;
    }
    return integer;
}

int inputValidation_postiveInteger(int *integer)
{
    std::cin >> *integer;

    while( *integer<0  )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "Input again : ";
            std::cin >> *integer;
    }
    return *integer;
}

double inputValidation_postiveDouble(double &decimal)
{
    std::cin >> decimal;

    while( decimal<0  )
    {
        std::cin.clear();
        std::cout << "Input Validation: Do not accept negative values." << "\n";
        std::cout << "Input again : ";
            std::cin >> decimal;
    }
    return decimal;
}

double inputValidation_postiveInteger_array(double postiveInteger_array[], const int &ele)
{
	std::cin >> postiveInteger_array[ele];

    while( postiveInteger_array[ele] < 0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "Input again : ";
            std::cin >> postiveInteger_array[ele];
    }
    return postiveInteger_array[ele];
}

int inputValidation_postiveInteger_array2D(int MonkeyBusiness[][5], const int row_ele, const int column_ele)
{
    std::cin >> MonkeyBusiness[row_ele][column_ele];

    while( MonkeyBusiness[row_ele][column_ele] < 0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer" << "\n";
        std::cout << "Input again : ";
            std::cin >> MonkeyBusiness[row_ele][column_ele];
    }
    return MonkeyBusiness[row_ele][column_ele];
}

// end