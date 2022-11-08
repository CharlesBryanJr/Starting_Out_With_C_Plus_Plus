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
Starting Out With C++ Chapter 13 Introduction to Classes - 2. Employee Class
Write a class named Employee that has the following member variables:
• name. A string that holds the employee’s name.
• idNumber. An int variable that holds the employee’s ID number.
• department. A string that holds the name of the department where the employee works.
• position. A string that holds the employee’s job title.

The class should have the following constructors:
• A constructor that accepts the following values as arguments and assigns them to the appropriate member variables: 
employee’s name, employee’s ID number, department, and position.

• A constructor that accepts the following values as arguments and assigns them to the
appropriate member variables: employee’s name and ID number. 
The department and position fields should be assigned an empty string ( "" ).

• A default constructor that assigns empty strings ( "") to the name, department, and position member variables, and 0 to the idNumber member variable.

Write appropriate mutator functions that store values in these member variables and accessor functions that return the values in these member variables. 
Once you have written the class, write a separate program that creates three Employee objects to hold the following data.

Name ID Number Department Position
Susan Meyers 47899 Accounting Vice President
Mark Jones 39119 IT Programmer
Joy Rogers 81774 Manufacturing Engineer

The program should store this data in the three objects and then display the data for each employee on the screen.
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

            if(tolower(userChoice) == 'b')
            {
                // local variables
                std::string n;
                int id;
                std::string dep;
                std::string pos;

                // Susan Meyers 47899 Accounting Vice President
                    n = "Susan Meyers";
                    id = 47899;
                    dep = "Accounting";
                    pos = "Vice President";
                    Employee VicePresident;
                        VicePresident.getEmployeeName();
                        VicePresident.getEmployeeID();
                        VicePresident.getEmployeeDepartment();
                        VicePresident.getEmployeePosition();

                        VicePresident.setEmployeeName(n);
                        VicePresident.setEmployeeID(id);
                        VicePresident.setEmployeeDepartment(dep);
                        VicePresident.setEmployeePosition(pos);

                        VicePresident.getEmployeeName();
                        VicePresident.getEmployeeID();
                        VicePresident.getEmployeeDepartment();
                        VicePresident.getEmployeePosition();

                std::cout << " " << "\n";
                // Mark Jones 39119 IT Programmer
                    n = "Mark Jones";
                    id = 39119;
                    dep = "IT";
                    pos = "Programmer";
                    Employee Programmer(n, id);
                        Programmer.getEmployeeName();
                        Programmer.getEmployeeID();
                        Programmer.getEmployeeDepartment();
                        Programmer.getEmployeePosition();

                std::cout << " " << "\n";
                // Joy Rogers 81774 Manufacturing Engineer
                    n = "Joy Rogers";
                    id = 81774;
                    dep = "Manufacturing";
                    pos = "Engineer";
                    Employee Engineer(n, id, dep, pos);
                        Engineer.getEmployeeName();
                        Engineer.getEmployeeID();
                        Engineer.getEmployeeDepartment();
                        Engineer.getEmployeePosition();
                
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