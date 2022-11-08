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

#ifndef Chapter14MoreAboutClasses_H
#define Chapter14MoreAboutClasses_H

/*
*****************************************************
// Chapter 14 More About Classes - 4. NumDays Class

Design a class called NumDays. 
The class’s purpose is to store a value that represents a number of work hours and convert it to a number of days. 
For example, 8 hours would be converted to 1 day, 12 hours would be converted to 1.5 days, and 18 hours would be converted to 2.25 days. 

The class should have a constructor that accepts a number of hours, as well as member functions for storing and retrieving the hours and days.

The class should also have the following overloaded operators:

+ Addition operator. 
When two NumDays objects are added together, the overloaded + operator should return the sum of the two objects’ hours members.

− Subtraction operator. 
When one NumDays object is subtracted from another, the overloaded − operator should return the difference of the two objects’ hours members.

++ Prefix and postfix increment operators. 
These operators should increment the number of hours stored in the object. 
When incremented, the number of days should be automatically recalculated.

−− Prefix and postfix decrement operators. 
These operators should decrement the number of hours stored in the object. 
When decremented, the number of days should be automatically recalculated.
*****************************************************
*/

class NumDays
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        int workHours;
        int workDays;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            NumDays(){ workHours = 0; updateNumberOfWorkDays(); } // default constructor

            NumDays(int &wH)
            {
                while( wH <0 )
                {
                    std::cout << "Input validation: Do not accept negative values for the number of hours worked." << "\n";
                    std::cout << "Input the work hours : ";
                        std::cin >> wH;
                    std::cout << " " << "\n";
                }
                workHours = wH;
                updateNumberOfWorkDays();
            }

            // ***--- copy costructors ---***
            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
			// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            int getNumberOfWorkHours() const { return workHours; }
            int getNumberOfWorkDays() const { return workDays; }

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void setNumberOfWorkHours(int &wH)
            { 
                while( wH <0 )
                {
                    std::cout << "Input validation: Do not accept negative values for the number of hours worked." << "\n";
                    std::cout << "Input the work hours : ";
                        std::cin >> wH;
                    std::cout << " " << "\n";
                }
                workHours = wH;  
                updateNumberOfWorkDays();
            }

            void updateNumberOfWorkDays(){ workDays = workHours / 8; }

			// ***--- operator functions ---***
            // redefine the way a particular operator works with an object
            // Update other member variables if needed.	
	
            // When two NumDays objects are added together, the overloaded + operator should return the sum of the two objects’ hours members.
            int operator + (const NumDays &right) // + Addition operator.
            {
                return workHours + right.workHours;
            }

            // When one NumDays object is subtracted from another, the overloaded − operator should return the difference of the two objects’ hours members.
            int operator - (const NumDays &right) // - Subtraction operator.
            {
                return workHours - right.workHours;
            }

            // These operators should increment the number of hours stored in the object. 
            // When incremented, the number of days should be automatically recalculated.
            NumDays& operator ++ () // ++ Prefix increment operators.
            { 
                ++workHours; 
                updateNumberOfWorkDays(); 
                return *this; 
            } 
            
            NumDays operator ++ ( int ) // ++ Postfix increment operators.
            {
                (*this).workHours = (*this).workHours + 1;
                updateNumberOfWorkDays();
                return *this;
            }

            // These operators should decrement the number of hours stored in the object. 
            // When decremented, the number of days should be automatically recalculated.
            NumDays& operator -- () // −− Prefix decrement operators. 
            { 
                --workHours; 
                updateNumberOfWorkDays(); 
                return *this; 
            } 

            NumDays operator -- ( int ) // -- Postfix decrement operators.
            {
                (*this).workHours = (*this).workHours - 1;
                updateNumberOfWorkDays();
                return *this;
            }

			// ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~NumDays(){}				
            
};

/*
*****************************************************
Chapter 14 More About Classes - 5. Time Off
Design a class named TimeOff. 
The purpose of the class is to track an employee’s sick leave, vacation, and unpaid time off. 
It should have, as members, the following instances of the NumDays class described in Programming Challenge 4:

maxSickDays A NumDays object that records the maximum number of days of sick leave the employee may take.
sickTaken A NumDays object that records the number of days of sick leave the employee has already taken.
maxVacation A NumDays object that records the maximum number of days of paid vacation the employee may take.
vacTaken A NumDays object that records the number of days of paid vacation the employee has already taken.
maxUnpaid A NumDays object that records the maximum number of days of unpaid vacation the employee may take.
unpaidTaken A NumDays object that records the number of days of unpaid leave the employee has taken.

Additionally, the class should have members for holding the employee’s name and identification number. 
It should have an appropriate constructor and member functions for storing and retrieving data in any of the member objects.

Input Validation: Company policy states that an employee may not accumulate more than 240 hours of paid vacation. 
The class should not allow the maxVacation object to store a value greater than this amount.
*****************************************************
*/

class TimeOff
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        NumDays maxSickDays; // A NumDays object that records the maximum number of days of sick leave the employee may take.
        NumDays sickTaken; // A NumDays object that records the number of days of sick leave the employee has already taken.
        NumDays maxVacation; // A NumDays object that records the maximum number of days of paid vacation the employee may take.
        NumDays vacationTaken; // A NumDays object that records the number of days of paid vacation the employee has already taken.
        NumDays maxUnpaid; // A NumDays object that records the maximum number of days of unpaid vacation the employee may take.
        NumDays unpaidTaken; // A NumDays object that records the number of days of unpaid leave the employee has taken.

        std::string employeeName;
        int employeeId;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            TimeOff(); // default constructor
            TimeOff( std::string &eN, int &eId, int &msD, int &sT, int &mV, int &vT, int &mU, int &uT );

            // ***--- copy costructors ---***
            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
			// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            int getMaxSickDays() const { return maxSickDays.getNumberOfWorkDays(); }
            int getSickTakenDays() const { return sickTaken.getNumberOfWorkDays(); }
            int getMaxVacationDays() const { return maxVacation.getNumberOfWorkDays(); }
            int getVacationTakenDays() const { return vacationTaken.getNumberOfWorkDays(); }
            int getMaxUnpaidDays() const { return maxUnpaid.getNumberOfWorkDays(); }
            int getUnpaidTakenDays() const { return unpaidTaken.getNumberOfWorkDays(); }
            std::string getEmployeeName() const { return employeeName; }
            int setEmployeeId() const { return employeeId; }

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void setMaxSickDays(int &msD);
            void setSickTaken(int &sT);
            void setMaxVacation(int &mV);
            void setVacationTaken(int &vT);
            void setMaxUnpaid(int &mU);
            void setUnpaidTaken(int &uT);
            void setEmployeeName( std::string eN ){ employeeName = eN; }
            void setEmployeeId( int &eId ){ employeeId = eId; }

			// ***--- operator functions ---***
            // redefine the way a particular operator works with an object
            // Update other member variables if needed.		

			// ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~TimeOff(){}				
            
};

/*
*****************************************************
Chapter 14 More About Classes - 6. Personnel Report

Write a program that uses an instance of the TimeOff class you designed in Programming Challenge 5. 
The program should ask the user to enter the number of months an employee has worked for the company. 
It should then use the TimeOff object to calculate and display the employee’s maximum number of sick leave and vacation days. 
Employees earn 12 hours of vacation leave and 8 hours of sick leave per month.
*****************************************************
*/

/*
*****************************************************
Chapter 14 More About Classes - 3. Day of the Year Modification

Modify the DayOfYear class, written in Programming Challenge 2, to add a constructor that takes two parameters: 
a string object representing a month and an integer in the range 0 through 31 representing the day of the month. 

The constructor should then initialize the integer member of the class to represent the day specified by the month and day of month parameters. 

The constructor should terminate the program with an appropriate error message if the number entered for a day is outside the range of days for the month given.

Add the following overloaded operators:
++ prefix and postfix increment operators. 
These operators should modify the DayOfYear object so that it represents the next day. 
If the day is already the end of the year, the new value of the object will represent the first day of the year.

−− prefix and postfix decrement operators. 
These operators should modify the DayOfYear object so that it represents the previous day. 
If the day is already the first day of the year, the new value of the object will represent the last day of the year.
*****************************************************
*/


/*
*****************************************************
Chapter 14 More About Classes - 2. Day of the Year

Assuming that a year has 365 days, write a class named DayOfYear that takes an integer 
representing a day of the year and translates it to a string consisting of the month followed by day of the month. 

For example,
Day 2 would be January 2 .
Day 32 would be February 1 .
Day 365 would be December 31.
The constructor for the class should take as parameter an integer representing the day
of the year, and the class should have a member function print() that prints the day in the month–day format. 

The class should have an integer member variable to repre-
sent the day and should have static member variables holding string objects that can
be used to assist in the translation from the integer format to the month-day format.

Test your class by inputting various integers representing days and printing out their representation in the month–day format.
*****************************************************
*/

class DayOfYear
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        int dayNumber;
        std::string day;
        std::string month;
        static std::string months[13];
        static std::string daysOfMonth[32];
        std::string monthDayFormat;
        bool foundDay; // switch on or off

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            DayOfYear(int &doty)
            {
                while(doty<0)
                {
                    std::cout << "Input validation: Day of the Year must be postive." << "\n";
                    std::cout << "Input the Day of the Year :";
                        std::cin >> doty;
                    std::cout << " " << "\n";
                }
                dayNumber = doty;
                foundDay = false; // switch off
            }

            DayOfYear(std::string &m, int &dayOfMonth);

            // ***--- copy costructors ---***
            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
			// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            int getDayNumber() const { return dayNumber; }
            std::string getDayOfYear() const { return monthDayFormat; }

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void monthDayCountValidation(std::string &m, int &dayOfMonth, const int &monthMaxDays);
            void translationDayOfYear(const int &startOfMonth, const int &monthNumber);
            void print();

            // ***--- operator functions ---***
            // redefine the way a particular operator works with an object
            // Update other member variables if needed.	
            DayOfYear& operator ++ (){ ++dayNumber; return *this; }
            DayOfYear& operator -- (){ --dayNumber; return *this; }

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~DayOfYear(){}
};

std::string DayOfYear::months[13]
{"zero", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

std::string DayOfYear::daysOfMonth[32]
{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", 
"11", "12", "13", "14", "15", "16", "17", "18", "19", "20", 
"21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};

/*
*****************************************************
Chapter 14 More About Classes - 1. Numbers Class
Design a class Numbers that can be used to translate whole dollar amounts in the range 0 through 9999 into an English description of the number. 

For example, the number 713 would be translated into the string seven hundred thirteen, and 8203 would be translated into eight thousand two hundred three. 
The class should have a single integer member variable:
int number; 
and a static array of string objects that specify how to translate key dollar amounts into the desired format. 
For example, you might use static strings such as
string lessThan20[20] = {"zero", "one", ..., "eighteen", "nineteen"};
string hundred = "hundred";
string thousand = "thousand";

The class should have a constructor that accepts a nonnegative integer and uses it to initialize the Numbers object. 
It should have a member function print() that prints the English description of the Numbers object. 
Demonstrate the class by writing a main program that asks the user to enter a number in the proper range and then prints out its English description. 
*****************************************************
*/

class Numbers
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        int number;
        std::string numberEnglishTranslation;
        static std::string lessThan20[20];
        static std::string tens[10];
        static std::string hundred;
        static std::string thousand;
        static std::string million;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 
        
    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            Numbers(int &n)
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

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            int getNumber() const { return number; }
            std::string printEnglishTranslation() const { return numberEnglishTranslation; }

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void setNumber( int &n );
            void NumberToEnglishTranslation();

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Numbers(){}
            
};

std::string Numbers::lessThan20[20]{"zero", "one", "two", "three", "four", "five", "six", 
                                    "seven", "eight", "nine", "ten", "eleven",
                                    "twelve", "thirteen", "fourteen", "fifthteen", 
                                    "sixteen", "seventeen", "eightteen", "nineteen"};
std::string Numbers::tens[10]{ "zero", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
std::string Numbers::hundred = "hundred";
std::string Numbers::thousand = "thousand";
std::string Numbers::million = "million";

// end

#endif