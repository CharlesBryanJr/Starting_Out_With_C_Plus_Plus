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