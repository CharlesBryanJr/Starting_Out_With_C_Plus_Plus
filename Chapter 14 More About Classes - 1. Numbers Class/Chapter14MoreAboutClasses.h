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
//*****************************************************
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
//*****************************************************
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
