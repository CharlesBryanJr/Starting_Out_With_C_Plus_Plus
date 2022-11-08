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

enum startOfMonth
{JanuaryStartOfMonth = 1, FebruaryStartOfMonth = 32, MarchStartOfMonth = 60, AprilStartOfMonth = 91, MayStartOfMonth = 121, JuneStartOfMonth = 152, 
JulyStartOfMonth = 182, AugustStartOfMonth = 213, SeptemberStartOfMonth = 244, OctoberStartOfMonth = 274, NovemberStartOfMonth = 305, DecemberStartOfMonth = 335 };

enum monthMaxDays
{JanuaryMaxDays = 31, FebruaryMaxDays = 28, MarchMaxDays = 31, AprilMaxDays = 30, MayMaxDays = 31, JuneMaxDays = 30, 
JulyMaxDays = 31, AugustMaxDays = 31, SeptemberMaxDays = 30, OctoberMaxDays = 31, NovemberMaxDays = 30, DecemberMaxDays = 31 };

enum MonthNumber
{JanuaryMonthNumber =1 , FebruaryMonthNumber =2 , MarchMonthNumber =3 , AprilMonthNumber =4 , MayMonthNumber =5 , JuneMonthNumber =6, 
JulyMonthNumber =7, AugustMonthNumber =8, SeptemberMonthNumber =9 , OctoberMonthNumber =10 , NovemberMonthNumber =11, DecemberMonthNumber =12};

std::ostream& operator << (std::ostream& out, const Employee& employee)
{
	out << "EmployeeName : " << employee.m_EmployeeName << "\n" 
        << "EmployeeNumber : " << employee.m_EmployeeNumber << "\n" 
        << "HireDate : " << employee.m_HireDate << "\n";
		return out;
}

std::ostream& operator << (std::ostream& out,  const ProductionWorker& productionWorker)
{
	out << "EmployeeName : " << productionWorker.getEmployeeName() << "\n" 
        << "EmployeeNumber : " << productionWorker.getEmployeeNumber() << "\n" 
        << "HireDate : " << productionWorker.getHireDate() << "\n"
        << "Shift : " << productionWorker.m_Shift << "\n" 
        << "HourlyPayRate : " << productionWorker.m_HourlyPayRate << "\n";
		return out;
}

//*****************************************************
// Definition of function displayProgramMenu. 
// This function displays the program's menu on the screen. 
//*****************************************************

void displayProgramMenu()
{
    std::cout << "***----displayProgramMenu----***" << "\n"; std::cout << " " << "\n";

    std::cout << "User, choice a program to run." << "\n";
        std::cout << "A) Chapter 15 Inheritance, Polymorphism and VirtualFunctions " << "\n";
        std::cout << "B)  " << "\n";
        std::cout << "C)  " << "\n";
        std::cout << "D)  " << "\n";
        std::cout << "E) --- EXIT ---" << "\n";
        std::cout << "F)  " << "\n";
        std::cout << "G)  " << "\n";
        std::cout << "H)  " << "\n";
        std::cout << "I)  " << "\n";
        std::cout << "J)  " << "\n";
        std::cout << "K)  " << "\n";
        std::cout << "L)  " << "\n";
        std::cout << "M)  " << "\n";
        std::cout << "N)  " << "\n";
        std::cout << "O)  " << "\n";
        std::cout << "P)  " << "\n";
        std::cout << "Q)  " << "\n";
        std::cout << "R)  " << "\n";
        std::cout << "S)  " << "\n";
        std::cout << "T)  " << "\n";
        std::cout << "U)  " << "\n";
        std::cout << "V)  " << "\n";
        std::cout << "W)  " << "\n";
        std::cout << "X)  " << "\n";
        std::cout << "Y)  " << "\n";
        std::cout << "Z)  " << "\n";
}

// end

//*****************************************************
// Definition of  Class's costructors. 
//*****************************************************

//*****************************************************
// Definition of the  class's accessor functions. 
// These functions return and display the values in these member variables.
//*****************************************************

//*****************************************************
// Definition of the  class's mutator functions. 
// These functions return and display the values in these member variables.
// Update other member variables if needed.	
//*****************************************************

//*****************************************************
// Definition of the  class's operator functions. 
// redefine the way a particular operator works with an object
// Update other member variables if needed.	
//*****************************************************

//*****************************************************
// Definition of  Class's destructors. 
//*****************************************************