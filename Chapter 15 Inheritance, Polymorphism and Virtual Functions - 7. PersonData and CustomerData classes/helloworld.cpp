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
                Chapter 15 Inheritance, Polymorphism and VirtualFunctions - 3. TeamLeader Class
                In a particular factory, a team leader is an hourly paid production worker who leads a small team. 
                In addition to hourly pay, team leaders earn a fixed monthly bonus.
                Team leaders are required to attend a minimum number of hours of training per year.
                Design a TeamLeader class that extends the ProductionWorker class you designed in Programming Challenge 1. 
                The TeamLeader class should have member variables for the monthly bonus amount, the required number of training hours, and the number of training hours that the team leader has attended. 
                Write one or more constructors and the appropriate accessor and mutator functions for the class. 
                Demonstrate the class by writing a program that uses a TeamLeader object.
                //*****************************************************
                */

                TeamLeader TeamLeader1;
                    std::cout << TeamLeader1 << std::endl;
                    std::cout << " " << "\n";

                TeamLeader TeamLeader2("Charles Bryan",14,"6/30/1997",1,55,2000,1,0);
                    std::cout << TeamLeader2 << std::endl;

                std::cout << " " << "\n";
            }
            if(tolower(userChoice) == 'd')
            {
                /*
                *****************************************************
                Chapter 15 Inheritance, Polymorphism and VirtualFunctions - 4. Time Format
                In Program 15-20, the file Time.h contains a Time class. 
                Design a class called MilTime that is derived from the Time class. 
                The MilTime class should convert time in military (24-hour) format to the standard time format used by the Time class. 

                The class should have the following member variables: 
                milHours: Contains the hour in 24-hour format. 
                For example, 1:00 pm would be stored as 1300 hours, and 4:30 pm would be stored as 1630 hours.

                milSeconds: Contains the seconds in standard format.

                The class should have the following member functions:
                Constructor: The constructor should accept arguments for the hour and seconds, in military format. 
                The time should then be converted to standard time and stored in the hours, min, and sec variables of the Time class.

                setTime: Accepts arguments to be stored in the milHours and milSeconds variables. 
                The time should then be converted to standard time and stored in the hours, min, and sec variables of the Time class.

                getHour: Returns the hour in military format.
                getStandHr: Returns the hour in standard format.

                Demonstrate the class in a program that asks the user to enter the time in military format. 
                The program should then display the time in both military and standard format.

                Input Validation: The MilTime class should not accept hours greater than 2359, or less than 0. 
                It should not accept seconds greater than 59 or less than 0.
                *****************************************************
                */
                int Hour{11};
                int Minute{33};
                int Second{47};
                std::string AMorPM{"PM"};

                MilitaryTime MilitaryTime1{Hour,Minute,Second,AMorPM};
                    std::cout << MilitaryTime1 << std::endl;
                    std::cout << " " << "\n";

                int MilitaryTimeHours{2333};
                int MilitaryTimeSeconds{47};
                
                MilitaryTime MilitaryTime2{MilitaryTimeHours,MilitaryTimeSeconds};
                    std::cout << MilitaryTime2 << std::endl;
                    std::cout << " " << "\n";

                Hour = 8;
                Minute = 14;
                Second = 1;
                AMorPM = "AM";

                MilitaryTime MilitaryTime3{Hour,Minute,Second,AMorPM};
                    std::cout << MilitaryTime3 << std::endl;
                    std::cout << " " << "\n";

                MilitaryTimeHours = 814;
                MilitaryTimeSeconds = 1;
                
                MilitaryTime MilitaryTime4{MilitaryTimeHours,MilitaryTimeSeconds};
                    std::cout << MilitaryTime4 << std::endl;
                    std::cout << " " << "\n";

                std::cout << " " << "\n";
            }
            if(towlower(userChoice) == 'f')
            {
                /*
                *****************************************************
                Chapter 15 Inheritance, Polymorphism and Virtual Functions - 5. Time Clock
                Design a class named TimeClock. 
                The class should be derived from the MilTime class you designed in Programming Challenge 4. 
                The class should allow the programmer to pass two times to it: starting time and ending time. 
                The class should have a member function that returns the amount of time elapsed between the two times. 
                For example, if the starting time is 900 hours (9:00 am), and the ending time is 1300 hours (1:00 pm), the elapsed time is 4 hours.
                Input Validation: The class should not accept hours greater than 2359 or less than 0.
                *****************************************************
                */

                TimeClock TimeClock1;
                    std::cout << TimeClock1 << std::endl;
                    std::cout << " " << "\n";
                
                int StartingTime{111};
                int EndingTime{1313};

                TimeClock TimeClock2(StartingTime,EndingTime);
                    std::cout << TimeClock2 << std::endl;
                    std::cout << " " << "\n";

                int Hour{2};
                int Minute{25};
                int Second{10};
                std::string AMorPM{"AM"};

                int Hour2{7};
                int Minute2{42};
                int Second2{58};
                std::string AMorPM2{"PM"};

                TimeClock TimeClock3(Hour,Minute,Second,AMorPM,Hour2,Minute2,Second2,AMorPM2);
                    std::cout << TimeClock3 << std::endl;
                    std::cout << " " << "\n";

                std::cout << " " << "\n";
            }
            if(towlower(userChoice) == 'g')
            {
                /*
                *****************************************************
                Chapter 15 Inheritance, Polymorphism and Virtual Functions - 6. Essay class
                Design an Essay class that is derived from the GradedActivity class presented in this chapter. 
                The Essay class should determine the grade a student receives on an essay.
                The student’s essay score can be up to 100, and is determined in the following manner:
                • Grammar: 30 points
                • Spelling: 20 points
                • Correct length: 20 points
                • Content: 30 points
                Demonstrate the class in a simple program.
                *****************************************************
                */

                Essay Essay1;
                    std::cout << Essay1 << "\n";

                double GrammarScore{28}, 
                       SpellingScore{18}, 
                       CorrectLengthScore{18}, 
                       ContentScore{28};
                
                Essay Essay2(GrammarScore,SpellingScore,CorrectLengthScore,ContentScore);
                    std::cout << Essay2 << "\n";

                std::cout << " " << "\n";
            }
            if(towlower(userChoice) == 'h')
            {
                /*
                *****************************************************
                Chapter 15 Inheritance, Polymorphism and Virtual Functions - 7. PersonData and CustomerData classes
                Design a class named PersonData with the following member variables:
                • lastName
                • firstName
                • address
                • city
                • state
                • zip
                • phone
                Write the appropriate accessor and mutator functions for these member variables.
                Next, design a class named CustomerData, which is derived from the PersonData class. 
                The CustomerData class should have the following member variables:
                • customerNumber
                • mailingList
                The customerNumber variable will be used to hold a unique integer for each customer.
                The mailingList variable should be a bool. 

                It will be set to true if the customer wishes to be on a mailing list, or false if the customer does not wish to be on a mailing list. 
                Write appropriate accessor and mutator functions for these member variables.

                Demonstrate an object of the CustomerData class in a simple program.
                *****************************************************
                */
                
                CustomerData CustomerData1;
                    std::cout << CustomerData1 << "\n";
                    std::cout << " " << "\n";
                
                CustomerData CustomerData2("Bryan","Charles","1 Arrowhead Drive","Kansas City","Missouri","64129","(816) 920-9300",14,true);
                    std::cout << CustomerData2 << "\n";
                    std::cout << " " << "\n";
            

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