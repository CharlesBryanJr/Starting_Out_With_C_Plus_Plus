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
Starting Out With C++ Chapter 13 Introduction to Classes - 4. Personal Information Class

Design a class that holds the following personal data: name, address, age, and phone number. 
Write appropriate accessor and mutator functions. 

Demonstrate the class by writing a program that creates three instances of it. 

One instance should hold your information, and the other two should hold your friends’ or family members’ information.
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

            if(tolower(userChoice) == 'c')
            {
                // Demonstrate the class in a program that creates a Car object, and then calls the accelerate function five times. 
                // After each call to the accelerate function, get the current speed of the car and display it. 
                // Then, call the brake function five times.
                // After each call to the brake function, get the current speed of the car and display it.

                //local variables
                int yM{2023};
                std::string m{"Tesla Roadster"};
                int s{60}; // 1.9 secs
                int laps{12};
                
                Car TeslaRoadster(yM,m);
                    TeslaRoadster.getCarMake();
                    TeslaRoadster.getCarYearModel();
                    TeslaRoadster.getCarSpeed();

                    for(unsigned int it{0}; it<laps; ++it)
                    {
                        TeslaRoadster.accelerateCar();
                        TeslaRoadster.getCarSpeed();
                    }

                    for(unsigned int it{0}; it<laps; ++it)
                    {
                        TeslaRoadster.brakeCar();
                        TeslaRoadster.getCarSpeed();
                    }
                
                std::cout << " " << "\n";

            }
            if(tolower(userChoice) == 'd')
            {
                // Demonstrate the class by writing a program that creates three instances of it. 
                // One instance should hold your information, and the other two should hold your friends’ or family members’ information.
                std::string n; 
                std::string addr; 
                int a; 
                std::string pN;

                PersonalInformation MichaelJordan;
                    n = "Air Jordan";
                        MichaelJordan.setPersonalInformationName(n);
                    addr = "2700 Point Dr, Highland Park, IL 60035";
                        MichaelJordan.setPersonalInformationAddress(addr);
                    a = 37;
                        MichaelJordan.setPersonalInformationAge(a);
                    pN = "(800) 806-6453";
                        MichaelJordan.setPersonalInformationPhoneNumber(pN);

                        MichaelJordan.getPersonalInformationName();
                        MichaelJordan.getPersonalInformationAddress();
                        MichaelJordan.getPersonalInformationAge();
                        MichaelJordan.getPersonalInformationPhoneNumber();

                PersonalInformation TomBrady;
                    n = "TB12";
                        TomBrady.setPersonalInformationName(n);
                    addr = "333 Far away";
                        TomBrady.setPersonalInformationAddress(addr);
                    a = 45;
                        TomBrady.setPersonalInformationAge(a);
                    pN = "(800) 999-9999";
                        TomBrady.setPersonalInformationPhoneNumber(pN);

                        TomBrady.getPersonalInformationName();
                        TomBrady.getPersonalInformationAddress();
                        TomBrady.getPersonalInformationAge();
                        TomBrady.getPersonalInformationPhoneNumber();

                PersonalInformation TigerWoods;
                    n = "TW";
                        TigerWoods.setPersonalInformationName(n);
                    addr = "111 Far Far away";
                        TigerWoods.setPersonalInformationAddress(addr);
                    a = 41;
                        TigerWoods.setPersonalInformationAge(a);
                    pN = "(800)-888-3333";
                        TigerWoods.setPersonalInformationPhoneNumber(pN);

                        TigerWoods.getPersonalInformationName();
                        TigerWoods.getPersonalInformationAddress();
                        TigerWoods.getPersonalInformationAge();
                        TigerWoods.getPersonalInformationPhoneNumber();

                std::cout << " " << "\n";
            }

            // Demonstrate the class by writing a program that creates three instances of it. 
            // One instance should hold your information, and the other two should hold your friends’ or family members’ information.

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