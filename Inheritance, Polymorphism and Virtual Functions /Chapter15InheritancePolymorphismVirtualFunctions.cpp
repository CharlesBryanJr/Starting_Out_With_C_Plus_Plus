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

Person::Person(){
    std::cout << "Default constructor for Person called..." << std::endl;
}

Person::Person(std::string_view fullname, int age,std::string_view address) 
    : m_full_name{fullname}, m_age{age}, m_address{address}
{
    std::cout << "Custom constructor for Person called..." << std::endl;
}

Person::Person(const Person& source)
    : m_full_name{source.m_full_name} , m_age{source.m_age}, m_address{source.m_address}
{
    std::cout << "Custom copy constructor for Person called..." << std::endl;
}

void Person::do_something() const{
    std::cout << "Hello" << std::endl;
}

std::ostream& operator<<(std::ostream& out , const Person& person){
   out << "Person [Full name :" << person.get_full_name() <<
                      ", Age:" << person.get_age() <<
                      ", Address:" << person.get_address() << "]";
  return out;
}


Person::~Person()
{
}


Engineer::Engineer()
{
    std::cout << "Default constructor for Engineer called..." << std::endl;
}

Engineer::Engineer(std::string_view fullname,int age,std::string_view address,int contract_count_param) 
    : Person(fullname,age,address), contract_count{contract_count_param}
{
    std::cout << "Custom constructor for Engineer called..." << std::endl;
}

Engineer::Engineer(const Engineer& source)
     : Person(source), contract_count(source.contract_count)
{
    std::cout << "Custom copy constructor for Engineer called..." << std::endl;
}

std::ostream& operator<<(std::ostream& out , const Engineer& operand){
     out << "Engineer [Full name : " << operand.get_full_name() <<
                    ",age : " << operand.get_age() << 
                    ",address : " << operand.get_address() <<
                    ",contract_count : " << operand.contract_count << "]";
    return out;   
}


Engineer::~Engineer()
{
}


CivilEngineer::CivilEngineer()
{
    std::cout << "Default constructor called for CivilEngineer ... " << std::endl;
}

CivilEngineer::CivilEngineer
(std::string_view fullname,int age, std::string_view address,int contract_count, std::string_view speciality)
    : Engineer(fullname,age,address,contract_count), m_speciality(speciality)
{
    std::cout << "Custom constructor called for CivilEngineer ... " << std::endl;
}

CivilEngineer::CivilEngineer(const CivilEngineer& source)
    : Engineer(source) , m_speciality(source.m_speciality)
{
    std::cout << "Custom copy constructor called for CivilEngineer ... " << std::endl;
}

std::ostream& operator<<(std::ostream& out, const CivilEngineer& operand){
     out << "CivilEngineer [Full name : " << operand.get_full_name() <<
                    ",age : " << operand.get_age() << 
                    ",address : " << operand.get_address() <<
                    ",contract_count : " << operand.get_contract_count() <<
                    ",speciality : " << operand.m_speciality << "]";
                    		
    return out;  
}

CivilEngineer::~CivilEngineer()
{
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