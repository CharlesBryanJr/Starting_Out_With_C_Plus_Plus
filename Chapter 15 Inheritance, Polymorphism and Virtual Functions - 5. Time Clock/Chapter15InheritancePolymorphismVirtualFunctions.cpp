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

enum HoursNumber
{ One=1, Two=2, Three=3, Four=4, Five=5, Six=6, Seven=7, Eight=8, Nine=9, Ten=10, Eleven=11, Twelve=12};

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

std::ostream& operator << (std::ostream& out,  const ShiftSupervisor& shiftSupervisor)
{
	out << "EmployeeName : " << shiftSupervisor.getEmployeeName() << "\n" 
        << "EmployeeNumber : " << shiftSupervisor.getEmployeeNumber() << "\n" 
        << "HireDate : " << shiftSupervisor.getHireDate() << "\n"
        << "AnnualSalary : " << shiftSupervisor.m_AnnualSalary << "\n" 
        << "AnnualProductionBonus : " << shiftSupervisor.m_AnnualProductionBonus << "\n";
		return out;
}

std::ostream& operator << (std::ostream& out, const TeamLeader& teamLeader)
{
	out << "EmployeeName : " << teamLeader.getEmployeeName() << "\n" 
        << "EmployeeNumber : " << teamLeader.getEmployeeNumber() << "\n" 
        << "HireDate : " << teamLeader.getHireDate() << "\n"
        << "Shift : " << teamLeader.getShift() << "\n" 
        << "HourlyPayRate : " << teamLeader.getHourlyPayRate() << "\n"
        << "MonthlyBonusAmount : " << teamLeader.m_MonthlyBonusAmount << "\n"
        << "RequiredTrainingHours : " << teamLeader.m_RequiredTrainingHours << "\n"
        << "TrainingHours : " << teamLeader.m_TrainingHours << "\n";
		return out;
}

std::ostream& operator << (std::ostream& out, const Time& time)
{
    out << "Hour : " << time.m_Hour << "\n" 
        << "Minute : " << time.m_Minute << "\n" 
        << "Second : " << time.m_Second << "\n";
		return out;
}

std::ostream& operator << (std::ostream& out, const MilitaryTime& militaryTime)
{
    out << "Hour : " << militaryTime.m_Hour << "\n" 
        << "Minute : " << militaryTime.m_Minute << "\n" 
        << "Second : " << militaryTime.m_Second << "\n"
        << "MilitaryTimeHours : " << militaryTime.m_MilitaryTimeHours << "\n"
        << "m_MilitaryTimeSeconds : " << militaryTime.m_MilitaryTimeSeconds << "\n";
		return out;
}

//*****************************************************
// Definition of Time Class's costructors. 
//*****************************************************

                Time::Time( int &Hour, int &Minute, int &Second, std::string &AMorPM ) 
                {
                    while( Hour > 12 || Hour < 0 )
                    {
                        std::cout << "ERROR: Hour must be less than or equal to 12." << "\n";
                        std::cout << "Input Hour : ";
                            std::cin >> Hour;
                            std::cout << " " << "\n";
                    }
                    m_Hour = Hour;

                    while( Minute > 59 || Minute < 0 )
                    {
                        std::cout << "ERROR: Minute must be less than or equal to 59." << "\n";
                        std::cout << "Input Minute : ";
                            std::cin >> Minute;
                            std::cout << " " << "\n";
                    }
                    m_Minute = Minute;

                    while( Second > 59 || Second < 0 )
                    {
                        std::cout << "ERROR: Second must be less than or equal to 59." << "\n";
                        std::cout << "Input Second : ";
                            std::cin >> Second;
                            std::cout << " " << "\n";
                    }
                    m_Second = Second;

                    while
                    ( 
                        AMorPM != "AM" &&
                        AMorPM != "am" &&
                        AMorPM != "PM" &&
                        AMorPM != "pm" 
                    )
                    {
                        std::cout << "ERROR: AMorPM must be AM or PM" << "\n";
                        std::cout << "Input AMorPM : ";
                            std::cin >> AMorPM;
                            std::cout << " " << "\n";
                    }
                    m_AMorPM = AMorPM;

                } 

//*****************************************************
// Definition of MilitaryTime : public Time Class's costructors. 
//*****************************************************

                MilitaryTime::MilitaryTime( int &Hour, int &Minute, int &Second, std::string &AMorPM ) 
                {
                    while( Hour > 12 || Hour < 0 )
                    {
                        std::cout << "ERROR: Hour must be less than or equal to 12." << "\n";
                        std::cout << "Input Hour : ";
                            std::cin >> Hour;
                            std::cout << " " << "\n";
                    }
                    m_Hour = Hour;

                    while( Minute > 59 || Minute < 0 )
                    {
                        std::cout << "ERROR: Minute must be less than or equal to 59." << "\n";
                        std::cout << "Input Minute : ";
                            std::cin >> Minute;
                            std::cout << " " << "\n";
                    }
                    m_Minute = Minute;

                    while( Second > 59 || Second < 0 )
                    {
                        std::cout << "ERROR: Second must be less than or equal to 59." << "\n";
                        std::cout << "Input Second : ";
                            std::cin >> Second;
                            std::cout << " " << "\n";
                    }
                    m_Second = Second;

                    while
                    ( 
                        AMorPM != "AM" &&
                        AMorPM != "am" &&
                        AMorPM != "PM" &&
                        AMorPM != "pm" 
                    )
                    {
                        std::cout << "ERROR: AMorPM must be AM or PM" << "\n";
                        std::cout << "Input AMorPM : ";
                            std::cin >> AMorPM;
                            std::cout << " " << "\n";
                    }
                    m_AMorPM = AMorPM;

                    updateMilitaryTime();
                } 

MilitaryTime::MilitaryTime( int &MilitaryTimeHours, int &MilitaryTimeSeconds ) 
{
    if( MilitaryTimeHours > 2359 || MilitaryTimeHours < 0 )
    {
        std::cout << "ERROR: Hour must be less than or equal to 2359." << "\n";
        std::cout << "Input Military Time Hours : ";
            std::cin >> MilitaryTimeHours;
            std::cout << " " << "\n";
    }
    m_MilitaryTimeHours = MilitaryTimeHours;

    if( MilitaryTimeSeconds > 59 || MilitaryTimeSeconds < 0 )
    {
        std::cout << "ERROR: MilitaryTimeSeconds must be less than or equal to 59." << "\n";
        std::cout << "Input MilitaryTimeSeconds : ";
            std::cin >> MilitaryTimeSeconds;
        std::cout << " " << "\n";
    }
    m_MilitaryTimeSeconds = MilitaryTimeSeconds;
    updateTime();
}

//*****************************************************
// Definition of the class MilitaryTime : public Time class's mutator functions. 
// These functions return and display the values in these member variables.
// Update other member variables if needed.	
//*****************************************************

int MilitaryTime::setMilitaryTime( int &MilitaryTimeHours, int &MilitaryTimeSeconds )
{
    if( MilitaryTimeHours > 2359 || MilitaryTimeHours < 0 )
    {
        std::cout << "ERROR: Hour must be less than or equal to 2359." << "\n";
        std::cout << "Input Military Time Hours : ";
            std::cin >> MilitaryTimeHours;
            std::cout << " " << "\n";
    }
    m_MilitaryTimeHours = MilitaryTimeHours;

    if( MilitaryTimeSeconds > 59 || MilitaryTimeSeconds < 0 )
    {
        std::cout << "ERROR: MilitaryTimeSeconds must be less than or equal to 59." << "\n";
        std::cout << "Input MilitaryTimeSeconds : ";
            std::cin >> MilitaryTimeSeconds;
        std::cout << " " << "\n";
    }
    m_MilitaryTimeSeconds = MilitaryTimeSeconds;

    updateTime();
    return MilitaryTimeHours;
}

void MilitaryTime::updateMilitaryTime()
{
    if ( m_AMorPM == "PM" )
    {
        m_MilitaryTimeHours = 1200;

        if( m_Hour == Eleven )
        {
            m_MilitaryTimeHours += 1100;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == Ten )
        {
            m_MilitaryTimeHours += 1000;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == Nine )
        {
            m_MilitaryTimeHours += 900;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == Eight )
        {
            m_MilitaryTimeHours += 800;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == Seven )
        {
            m_MilitaryTimeHours += 700;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == Six )
        {
            m_MilitaryTimeHours += 600;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == Five )
        {
            m_MilitaryTimeHours += 500;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == Four )
        {
            m_MilitaryTimeHours += 400;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == Three )
        {
            m_MilitaryTimeHours += 300;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == Two )
        {
            m_MilitaryTimeHours += 200;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == One )
        {
            m_MilitaryTimeHours += 100;
            m_MilitaryTimeHours += m_Minute;
        }
    }
    else // m_AMorPM == "AM"
    {
        if( m_Hour == Eleven )
        {
            m_MilitaryTimeHours = 1100;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == Ten )
        {
            m_MilitaryTimeHours = 1000;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == Nine )
        {
            m_MilitaryTimeHours = 900;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == Eight )
        {
            m_MilitaryTimeHours = 800;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == Seven )
        {
            m_MilitaryTimeHours = 700;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == Six )
        {
            m_MilitaryTimeHours = 600;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == Five )
        {
            m_MilitaryTimeHours = 500;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == Four )
        {
            m_MilitaryTimeHours = 400;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == Three )
        {
            m_MilitaryTimeHours = 300;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == Two )
        {
            m_MilitaryTimeHours = 200;
            m_MilitaryTimeHours += m_Minute;
        }
        else if ( m_Hour == One )
        {
            m_MilitaryTimeHours = 100;
            m_MilitaryTimeHours += m_Minute;
        }
    }
    
    m_MilitaryTimeSeconds = m_Second;
}

void MilitaryTime::updateTime()
{
    if( m_MilitaryTimeHours > 1200 ) // PM
    {
        m_Hour = m_MilitaryTimeHours - 1200;
        
        if( m_Hour > 1100 )
        {
            m_Minute = m_Hour - 1100;
            m_Hour = Eleven;
            m_AMorPM = "PM";
        }
        else if ( m_Hour > 1000 )
        {
            m_Minute = m_Hour - 1000;
            m_Hour = Ten;
            m_AMorPM = "PM";
        }
        else if ( m_Hour > 900 )
        {
            m_Minute = m_Hour - 900;
            m_Hour = Nine;
            m_AMorPM = "PM";
        }
        else if ( m_Hour > 800 )
        {
            m_Minute = m_Hour - 800;
            m_Hour = Eight;
            m_AMorPM = "PM";
        }
        else if ( m_Hour > 700 )
        {
            m_Minute = m_Hour - 700;
            m_Hour = Seven;
            m_AMorPM = "PM";
        }
        else if ( m_Hour > 600 )
        {
            m_Minute = m_Hour - 600;
            m_Hour = Six;
            m_AMorPM = "PM";
        }
        else if ( m_Hour > 500 )
        {
            m_Minute = m_Hour - 500;
            m_Hour = Five;
            m_AMorPM = "PM";
        }
        else if ( m_Hour > 400 )
        {
            m_Minute = m_Hour - 400;
            m_Hour = Four;
            m_AMorPM = "PM";
        }
        else if ( m_Hour > 300 )
        {
            m_Minute = m_Hour - 300;
            m_Hour = Three;
            m_AMorPM = "PM";
        }
        else if ( m_Hour > 200 )
        {
            m_Minute = m_Hour - 200;
            m_Hour = Two;
            m_AMorPM = "PM";
        }
        else if ( m_Hour > 100 )
        {
            m_Minute = m_Hour - 100;
            m_Hour = One;
            m_AMorPM = "PM";
        }
    }
    else
    {        
        bool foundHour{false};

        if( m_MilitaryTimeHours > 1100 && foundHour == false )
        {
            m_Minute = m_MilitaryTimeHours - 1100;
            m_Hour = Eleven;
            m_AMorPM = "AM";
            foundHour = true;
        }
        else if ( m_MilitaryTimeHours > 1000 && foundHour == false )
        {
            m_Minute = m_MilitaryTimeHours - 1000;
            m_Hour = Ten;
            m_AMorPM = "AM";
            foundHour = true;
        }
        else if ( m_MilitaryTimeHours > 900 && foundHour == false )
        {
            m_Minute = m_MilitaryTimeHours - 900;
            m_Hour = Nine;
            m_AMorPM = "AM";
            foundHour = true;
        }
        else if ( m_MilitaryTimeHours > 800 && foundHour == false )
        {
            m_Minute = m_MilitaryTimeHours - 800;
            m_Hour = Eight;
            m_AMorPM = "AM";
            foundHour = true;
        }
        else if ( m_MilitaryTimeHours > 700 && foundHour == false )
        {
            m_Minute = m_MilitaryTimeHours - 700;
            m_Hour = Seven;
            m_AMorPM = "AM";
            foundHour = true;
        }
        else if ( m_MilitaryTimeHours > 600 && foundHour == false )
        {
            m_Minute = m_MilitaryTimeHours - 600;
            m_Hour = Six;
            m_AMorPM = "AM";
            foundHour = true;
        }
        else if ( m_MilitaryTimeHours > 500 && foundHour == false )
        {
            m_Minute = m_MilitaryTimeHours - 500;
            m_Hour = Five;
            m_AMorPM = "AM";
            foundHour = true;
        }
        else if ( m_MilitaryTimeHours > 400 && foundHour == false )
        {
            m_Minute = m_MilitaryTimeHours - 400;
            m_Hour = Four;
            m_AMorPM = "AM";
            foundHour = true;
        }
        else if ( m_MilitaryTimeHours > 300 && foundHour == false )
         {
            m_Minute = m_MilitaryTimeHours - 300;
            m_Hour = Three;
            m_AMorPM = "AM";
            foundHour = true;
        }
        else if ( m_MilitaryTimeHours > 200 && foundHour == false )
        {
            m_Minute = m_MilitaryTimeHours - 200;
            m_Hour = Two;
            m_AMorPM = "AM";
            foundHour = true;
        }
        else if ( m_MilitaryTimeHours > 100 && foundHour == false )
        {
            m_Minute = m_MilitaryTimeHours - 100;
            m_Hour = One;
            m_AMorPM = "AM";
            foundHour = true;
        }
        foundHour = false;
    }
    
    m_Second = m_MilitaryTimeSeconds;
}

//*****************************************************
// Definition of TimeClock : public MilitaryTime Class's costructors. 
//*****************************************************

TimeClock::TimeClock
( 
    int &Hour, int &Minute, int &Second, std::string &AMorPM, 
    int &Hour2, int &Minute2, int &Second2, std::string &AMorPM2 
) 
{
    m_Hour = Hour;
    m_Minute = Minute;
    m_Second = Second;
    m_AMorPM = AMorPM;
    updateMilitaryTime();
    m_StartingTime = m_MilitaryTimeHours;

    m_Hour = Hour2;
    m_Minute = Minute2;
    m_Second = Second2;
    m_AMorPM = AMorPM2;
    updateMilitaryTime();
    m_EndingTime = m_MilitaryTimeHours;
    
    updateElaspedTime();
} 

//*****************************************************
// Definition of the class TimeClock : public MilitaryTime class's mutator functions. 
// These functions return and display the values in these member variables.
// Update other member variables if needed.	
//*****************************************************

void TimeClock::updateElaspedTime()
{
    if( m_EndingTime > m_StartingTime )
    {
        m_ElaspedTime = m_EndingTime - m_StartingTime;
    }
    else // m_StartingTime > m_EndingTime
    {
        std::cout << "ERROR: EndingTime is before StartingTime" << "\n";
        m_ElaspedTime = 0;
    }
}

//*****************************************************
// Definition of the TimeClock : public MilitaryTime class's operator functions. 
// redefine the way a particular operator works with an object
// Update other member variables if needed.	
//*****************************************************

std::ostream& operator << (std::ostream& out, const TimeClock& timeClock)
{
    out << "StartingTime : " << timeClock.m_StartingTime << "\n" 
        << "EndingTime : " << timeClock.m_EndingTime << "\n" 
        << "ElaspedTime : " << timeClock.m_ElaspedTime << "\n";
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
        std::cout << "B) Chapter 15. Inheritance, Polymorphism and Virtual Functions - 2. ShiftSupervisor Class " << "\n";
        std::cout << "C) Chapter 15 Inheritance, Polymorphism and VirtualFunctions - 3. TeamLeader Class " << "\n";
        std::cout << "D) Chapter 15 Inheritance, Polymorphism and VirtualFunctions - 4. Time Format " << "\n";
        std::cout << "E) --- EXIT ---" << "\n";
        std::cout << "F) Chapter 15 Inheritance, Polymorphism and Virtual Functions - 5. Time Clock " << "\n";
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