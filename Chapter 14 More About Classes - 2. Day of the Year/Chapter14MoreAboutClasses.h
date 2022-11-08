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
        int day;
        static std::string month[13];
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
                day = doty;
                foundDay = false; // switch off
            }

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            int getDay() const { return day; }
            std::string getDayOfYear() const { return monthDayFormat; }

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void translationDayOfYear(const int &startOfMonth, const int &monthNumber);
            void print();

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~DayOfYear(){}
            
};

std::string DayOfYear::month[13]
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