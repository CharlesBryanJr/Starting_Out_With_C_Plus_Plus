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
                /*
                *****************************************************
                Chapter 14 More About Classes - 3. Day of the Year Modification

                Modify the DayOfYear class, written in Programming Challenge 2, to add a constructor that takes two parameters: 
                a string object representing a month and an integer in the range 0 through 31 representing the day of the month. 

                The constructor should then initialize the integer member of the class to represent the day specified by the month and day of month parameters. 

                The constructor should terminate the program with an appropriate error message if the number entered for a day is outside the range of days for the month given.

                Add the following overloaded operators:
                ++ prefix and postfix increment operators. 
                These operators should modify the DayOfYear object so that it represents the next day. 
                If the day is already the end of the year, the new value of the object will represent the first day of the year.

                −− prefix and postfix decrement operators. 
                These operators should modify the DayOfYear object so that it represents the previous day. 
                If the day is already the first day of the year, the new value of the object will represent the last day of the year.
                *****************************************************
                */

                std::string monthString{"June"};
                int dayNumber{31};

                DayOfYear whatDay(monthString,dayNumber);

                std::cout << "DayNumber : " << whatDay.getDayNumber() << "\n"; 
                dayNumber = whatDay.getDayNumber();

                DayOfYear randomDay(dayNumber);
                randomDay.print();

                std::cout << "--overloaded operators--" << "\n";
                ++randomDay;
                ++randomDay;
                ++randomDay;
                ++randomDay;
                --randomDay;
                ++randomDay;
                std::cout << "DayNumber : " << randomDay.getDayNumber() << "\n";
                randomDay.print();

                std::cout << " " << "\n";
            }
            if(tolower(userChoice) == 'd')
            {
                /*
                *****************************************************
                // Chapter 14 More About Classes - 4. NumDays Class

                Design a class called NumDays. 
                The class’s purpose is to store a value that represents a number of work hours and convert it to a number of days. 

                For example, 8 hours would be converted to 1 day, 12 hours would be converted to 1.5 days, and 18 hours would be converted to 2.25 days. 
                The class should have a constructor that accepts a number of hours, as well as member functions for storing and retrieving the hours and days.

                The class should also have the following overloaded operators:

                + Addition operator. 
                When two NumDays objects are added together, the overloaded + operator should return the sum of the two objects’ hours members.

                − Subtraction operator. 
                When one NumDays object is subtracted from another, the overloaded − operator should return the difference of the two objects’ hours members.

                ++ Prefix and postfix increment operators. 
                These operators should increment the number of hours stored in the object. 
                When incremented, the number of days should be automatically recalculated.

                −− Prefix and postfix decrement operators. 
                These operators should decrement the number of hours stored in the object. 
                When decremented, the number of days should be automatically recalculated.
                *****************************************************
                */
                int myHours{100};
                NumDays myDays(myHours);

                int yourHours{100};
                NumDays yourDays(yourHours);

                std::cout << "getNumberOfWorkDays : " << myDays.getNumberOfWorkDays() << "\n"; 
                    std::cout << " " << "\n";
                std::cout << "+ Addition operator. " << myDays+yourDays << "\n";
                    std::cout << " " << "\n";
                std::cout << "- Subtraction operator. " << myDays-yourDays << "\n";
                    std::cout << " " << "\n";
                ++myDays;
                    std::cout << "++ Prefix increment operators. " << myDays.getNumberOfWorkHours() << "\n";
                    std::cout << " " << "\n";
                myDays++;
                    std::cout << "++ Postfix increment operators. " << myDays.getNumberOfWorkHours() << "\n";
                    std::cout << " " << "\n";
                --myDays;
                    std::cout << "-- Prefix decrement operators. " << myDays.getNumberOfWorkHours() << "\n";
                    std::cout << " " << "\n";
                myDays--;
                    std::cout << "-- Postfix decrement operators. " << myDays.getNumberOfWorkHours() << "\n";
                    std::cout << " " << "\n";
            
                std::cout << " " << "\n";
            }
            if(towlower(userChoice) == 'f')
            {
                /*
                *****************************************************
                Chapter 14 More About Classes - 5. Time Off
                Design a class named TimeOff. 
                The purpose of the class is to track an employee’s sick leave, vacation, and unpaid time off. 
                It should have, as members, the following instances of the NumDays class described in Programming Challenge 4:

                maxSickDays A NumDays object that records the maximum number of days of sick leave the employee may take.
                sickTaken A NumDays object that records the number of days of sick leave the employee has already taken.
                maxVacation A NumDays object that records the maximum number of days of paid vacation the employee may take.
                vacTaken A NumDays object that records the number of days of paid vacation the employee has already taken.
                maxUnpaid A NumDays object that records the maximum number of days of unpaid vacation the employee may take.
                unpaidTaken A NumDays object that records the number of days of unpaid leave the employee has taken.

                Additionally, the class should have members for holding the employee’s name and identification number. 
                It should have an appropriate constructor and member functions for storing and retrieving data in any of the member objects.

                Input Validation: Company policy states that an employee may not accumulate more than 240 hours of paid vacation. 
                The class should not allow the maxVacation object to store a value greater than this amount.
                *****************************************************
                */
                std::string eN = "Charles Bryan";
                int eId = 14;
                int msD = 10;
                int sT = 20;
                int mV = 250;
                int vT = -10;
                int mU = 50;
                int uT = 60;

                TimeOff CharlesBryan( eN, eId, msD, sT, mV, vT, mU, uT );

                std::cout << "maxSickDays: " << CharlesBryan.getMaxSickDays() << "\n";
                std::cout << "sickTaken: " << CharlesBryan.getSickTakenDays() << "\n";
                std::cout << "maxVacation: " << CharlesBryan.getMaxVacationDays() << "\n";
                std::cout << "vacTaken: " << CharlesBryan.getVacationTakenDays() << "\n";
                std::cout << "maxUnpaid: " << CharlesBryan.getMaxUnpaidDays() << "\n";
                std::cout << "unpaidTaken: " << CharlesBryan.getUnpaidTakenDays() << "\n";
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