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