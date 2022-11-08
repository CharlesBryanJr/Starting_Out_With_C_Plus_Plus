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
                /*
                *****************************************************
                Chapter 15 Inheritance, Polymorphism and VirtualFunctions - 1. Employee and ProductionWorker Classes
                Design a class named Employee. 
                The class should keep the following information in
                • Employee name
                • Employee number
                • Hire date
                Write one or more constructors and the appropriate accessor and mutator functions for the class.
                Next, write a class named ProductionWorker that is derived from the Employee class.
                The ProductionWorker class should have member variables to hold the following information:
                • Shift (an integer)
                • Hourly pay rate (a double )
                The workday is divided into two shifts: day and night. 
                The shift variable will hold an integer value representing the shift that the employee works. 
                The day shift is shift 1, and the night shift is shift 2. 
                Write one or more constructors and the appropriate accessor and mutator functions for the class. 
                Demonstrate the classes by writing a program that uses a ProductionWorker object.
                *****************************************************
                */

                Employee Employee1;
                    std::cout << Employee1 << std::endl;
                    Employee1.setEmployeeName("Charles Bryan");
                    Employee1.setEmployeeNumber(14);
                    Employee1.setHireDate("6/30/1997");
                    std::cout << Employee1 << std::endl;
                
                ProductionWorker ProductionWorker1;
                    std::cout << ProductionWorker1 << std::endl;
                    ProductionWorker1.setEmployeeName("Denzel Washington");
                    ProductionWorker1.setEmployeeNumber(3);
                    ProductionWorker1.setHireDate("December 28, 1954");
                    ProductionWorker1.setShift(1);
                    ProductionWorker1.setHourlyPayRate(88);
                    std::cout << ProductionWorker1 << std::endl;

            }

            if(tolower(userChoice) == 'b')
            {
                /*
                //*****************************************************
                Chapter 15. Inheritance, Polymorphism and Virtual Functions - 2. ShiftSupervisor Class
                In a particular factory a shift supervisor is a salaried employee who supervises a shift.
                In addition to a salary, the shift supervisor earns a yearly bonus when his or her shift meets production goals. 
                Design a ShiftSupervisor class that is derived from the Employee class you created in Programming Challenge 1. 
                The ShiftSupervisor class should have a member variable that holds the annual salary and a member variable that holds the annual production bonus that a shift supervisor has earned. 
                Write one or more constructors and the appropriate accessor and mutator functions for the class.
                Demonstrate the class by writing a program that uses a ShiftSupervisor object.
                //*****************************************************
                */
                ShiftSupervisor ShiftSupervisor1("Charles Bryan",14,"6/30/1997",100000,3000);
                    std::cout << ShiftSupervisor1 << std::endl;

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