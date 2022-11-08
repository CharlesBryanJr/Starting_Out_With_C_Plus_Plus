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
#include "Chapter14MoreAboutClasses.cpp"

//*****************************************************
// Definition of function inputValidation_y_or_n function. 
// This function returns a y or n char.
//*****************************************************

char inputValidation_y_or_n(char &letter)
{
    std::cin >> letter;
		while (tolower(letter) != 'y' && tolower(letter) != 'n')
    {
        std::cout << "ERROR: a 'y' or an 'n' must be entered: ";
        std::cin.clear();
        std::cin >> letter;
    }
    return letter;
}

//*****************************************************
//	*=== START MAIN FUNCTION ===*

int main()
{
    char letter,
         userChoice;

	while(letter != 'n')
	{
        displayProgramMenu();
            std::cin >> userChoice;

        while(tolower(userChoice) != 'e')
        {
            while (toupper(userChoice) < 'A' || toupper(userChoice) > 'U')
            {
                std::cout << "Please make a choice in the range of A through U: "; std::cout << " " << "\n";
                displayProgramMenu();
                    std::cin >> userChoice;
            }
            
            if(tolower(userChoice) == 'a') 
            {
                /*
                //*****************************************************
                Chapter 14 More About Classes - 1. Numbers Class

                Assuming that a year has 365 days, write a class named DayOfYear that takes an inte-
                ger representing a day of the year and translates it to a string consisting of the month followed by day of the month. 
                For example,
                Day 2 would be January 2 .
                Day 32 would be February 1 .
                Day 365 would be December 31.
                The constructor for the class should take as parameter an integer representing the day of the year, and the class should have a member function print() that prints the day in the month–day format. 
                The class should have an integer member variable to represent the day and should have static member variables holding string objects that can be used to assist in the translation from the integer format to the month-day format.
                Test your class by inputting various integers representing days and printing out their
                representation in the month–day format.
                //*****************************************************
                */
                int myNumber{-999};
    
                Numbers Number(myNumber);

                Number.NumberToEnglishTranslation();

                std::cout << " " << "\n";
            }

            if(tolower(userChoice) == 'b')
            {
                /*
                //*****************************************************
                Chapter 14 More About Classes - 2. Day of the Year

                Assuming that a year has 365 days, write a class named DayOfYear that takes an integer 
                representing a day of the year and translates it to a string consisting of the month followed by day of the month. 

                For example,
                Day 2 would be January 2 .
                Day 32 would be February 1 .
                Day 365 would be December 31.
                The constructor for the class should take as parameter an integer representing the day
                of the year, and the class should have a member function print() that prints the day in the month–day format. 

                The class should have an integer member variable to represent the day 
                and 
                should have static member variables holding string objects that can be used to assist in the translation from the integer format to the month-day format.

                Test your class by inputting various integers representing days and printing out their representation in the month–day format.
                //*****************************************************
                */

                int dayNumber{-7};

                DayOfYear myDay(dayNumber);

                myDay.print();

                std::cout << " " << "\n";
            }

            if(tolower(userChoice) == 'c')
            {
                
                std::cout << " " << "\n";
            }
            if(tolower(userChoice) == 'd')
            {
                
                std::cout << " " << "\n";
            }
            if(towlower(userChoice) == 'f')
            {
                
                std::cout << " " << "\n";
            }
            if(towlower(userChoice) == 'g')
            {
                
                std::cout << " " << "\n";
            }
            if(towlower(userChoice) == 'h')
            {
                
                std::cout << " " << "\n";
                            
            }
            if(towlower(userChoice) == 'i')
            {
                
                std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 'j')
            {
                
                std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 'k')
            {
                
                std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 'l')
            {
                
                std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 'm')
            {
                
                std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 'n')
            {

                std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 'o')
            {
            
                std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 'p')
            {

                std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 'q')
            {
                
                std::cout << " " << "\n";   
            }
            if(towlower(userChoice) == 'r')
            {

                std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 's')
            {
                
                std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 't')
            {
                std::cout << " " << "\n";
            }
            if(towlower(userChoice) == 'u')
            {
                
                std::cout << " " << "\n";   
            }
            if(towlower(userChoice) == 'v')
            {

                std::cout << " " << "\n";              
            }

            std::cout << " " << "\n";
            displayProgramMenu();
                std::cin >> userChoice;
        }
        
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
			inputValidation_y_or_n(letter);	std::cout << " " << "\n";
    }

	return 0;
}

// *=== END MAIN FUNCTION ===* 
//*****************************************************