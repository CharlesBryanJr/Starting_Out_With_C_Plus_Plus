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
#include <string_view>

#include "Chapter15InheritancePolymorphismVirtualFunctions.h"
#include "Chapter15InheritancePolymorphismVirtualFunctions.cpp"

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
                std::cout << "Please make a choice in the range of A through U: "; std::cout << " " << "\n";
                displayProgramMenu();
                    std::cin >> userChoice;
            }
            
            if(tolower(userChoice) == 'a') 
            {
                std::cout << "---------------------" << std::endl;
                CivilEngineer civil_eng1("John Travolta",51,"Tiny Dog 42St#89",31,"Road Strength");
                std::cout << "civil_eng1 : " << civil_eng1 << std::endl;

            }

            if(tolower(userChoice) == 'b')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */


                std::cout << " " << "\n";
            }

            if(tolower(userChoice) == 'c')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */


                std::cout << " " << "\n";
            }
            if(tolower(userChoice) == 'd')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */


                std::cout << " " << "\n";
            }
            if(towlower(userChoice) == 'f')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */


                std::cout << " " << "\n";
            }
            if(towlower(userChoice) == 'g')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */


                std::cout << " " << "\n";
            }
            if(towlower(userChoice) == 'h')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */


                std::cout << " " << "\n";
            }
            if(towlower(userChoice) == 'i')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */


                std::cout << " " << "\n";           
            }
            if(towlower(userChoice) == 'j')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */


                std::cout << " " << "\n";             
            }
            if(towlower(userChoice) == 'k')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */


                std::cout << " " << "\n";             
            }
            if(towlower(userChoice) == 'l')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */


                std::cout << " " << "\n";             
            }
            if(towlower(userChoice) == 'm')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */


                std::cout << " " << "\n";            
            }
            if(towlower(userChoice) == 'n')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */


                std::cout << " " << "\n";          
            }
            if(towlower(userChoice) == 'o')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */


                std::cout << " " << "\n";           
            }
            if(towlower(userChoice) == 'p')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */


                std::cout << " " << "\n";            
            }
            if(towlower(userChoice) == 'q')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */


                std::cout << " " << "\n";
            }
            if(towlower(userChoice) == 'r')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */

                std::cout << " " << "\n"; 
            }             
            if(towlower(userChoice) == 's')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */


                std::cout << " " << "\n";          
            }
            if(towlower(userChoice) == 't')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */


                std::cout << " " << "\n";
            }
            if(towlower(userChoice) == 'u')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */


                std::cout << " " << "\n"; 
            }
            if(towlower(userChoice) == 'v')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 1. Employee and ProductionWorker Classes

                //*****************************************************
                */

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