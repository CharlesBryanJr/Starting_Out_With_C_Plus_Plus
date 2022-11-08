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
#include "Chapter13IntroToClasses.cpp"

/*
Starting Out With C++ Chapter 11 Structured Data - 1. Date
Design a class called Date. The class should store a date in three integers: month, day, and year. 
There should be member functions to print the date in the following forms:
12/25/2014
December 25, 2014
25 December 2014
Demonstrate the class by writing a complete program implementing it.
Input Validation: Do not accept values for the day greater than 31 or less than 1. 
Input Validation: Do not accept values for the month greater than 12 or less than 1.
*/

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
            while (toupper(userChoice) < 'A' || toupper(userChoice) > 'Z')
            {
                std::cout << "Please make a choice in the range of A through Z: ";
                displayProgramMenu();
                    std::cin >> userChoice;
            }
            
            if(tolower(userChoice) == 'a') 
            {
                // local variables 
                int m{0},
                    d{33},
                    y{1997};

                Date Sunday;
                    Sunday.displayDateFormat1(); std::cout << " " << "\n";
                    Sunday.displayDateFormat2(); std::cout << " " << "\n";
                    Sunday.displayDateFormat3(); std::cout << " " << "\n";
                
                std::cout << " " << "\n";

                Date Monday(m);
                    Monday.displayDateFormat1(); std::cout << " " << "\n";
                    Monday.displayDateFormat2(); std::cout << " " << "\n";
                    Monday.displayDateFormat3(); std::cout << " " << "\n";
                
                std::cout << " " << "\n";
                
                Date Tuesday(m,d);
                    Tuesday.displayDateFormat1(); std::cout << " " << "\n";
                    Tuesday.displayDateFormat2(); std::cout << " " << "\n";
                    Tuesday.displayDateFormat3(); std::cout << " " << "\n";
                
                std::cout << " " << "\n";
                
                Date Wednesday(m,d,y);
                    Wednesday.displayDateFormat1(); std::cout << " " << "\n";
                    Wednesday.displayDateFormat2(); std::cout << " " << "\n";
                    Wednesday.displayDateFormat3(); std::cout << " " << "\n";
                
                m = 18;
                d = 0;
                y = 2022;

                Date Today;
                    Today.updateMonth(m);
                    Today.updateDay(d);
                    Today.updateYear(y);
                    Today.displayDateFormat1(); std::cout << " " << "\n";
                    Today.displayDateFormat2(); std::cout << " " << "\n";
                    Today.displayDateFormat3(); std::cout << " " << "\n";
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
