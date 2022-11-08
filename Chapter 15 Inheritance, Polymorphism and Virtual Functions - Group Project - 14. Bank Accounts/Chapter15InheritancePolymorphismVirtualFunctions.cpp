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
// Definition of the GradedActivity class's mutator functions. 
// These functions return and display the values in these member variables.
// Update other member variables if needed.	
//*****************************************************

void GradedActivity::setScore(double s)
{ 
    while( s>100 || s<0 )
    {
        std::cout << "ERROR: Score must be 0 to 100" << "\n";
        std::cout << "Input Score : " << "\n";
            std::cin >> s;
        std::cout << " " << "\n";
    }
    score = s;
    determineGrade(); 
}

void GradedActivity::determineGrade() 
{
    if (score > 89)
        letter = 'A';
    else if (score > 79)
        letter = 'B';
    else if (score > 69)
        letter = 'C';
    else if (score > 59)
        letter = 'D';
    else
        letter = 'F';
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
// Definition of the class Essay : public GradedActivity class's operator functions. 
// redefine the way a particular operator works with an object
// Update other member variables if needed.	
//*****************************************************

std::ostream& operator << (std::ostream& out, const Essay& essay)
{
    out << "Score : " << essay.getScore() << "\n" 
        << "Letter : " << essay.getLetterGrade() << "\n"; 
		return out;
}

//*****************************************************
// Definition of the  class's mutator functions. 
// These functions return and display the values in these member variables.
// Update other member variables if needed.	
//*****************************************************

void Essay::setGrammarScore( double& GrammarScore )
{
    while( GrammarScore > 30 || GrammarScore < 0 )
    {
        std::cout << "ERROR: GrammarScore must be 0 to 30" << "\n";
        std::cout << "Input GrammarScore : " << "\n";
            std::cin >> GrammarScore;
        std::cout << " " << "\n";
    }
    m_GrammarScore = GrammarScore;
    setScore();
}

void Essay::setSpellingScore( double& SpellingScore )
{
    while( SpellingScore > 20 || SpellingScore < 0 )
    {
        std::cout << "ERROR: SpellingScore must be 0 to 20" << "\n";
        std::cout << "Input SpellingScore : " << "\n";
            std::cin >> SpellingScore;
        std::cout << " " << "\n";
    }
    m_SpellingScore = SpellingScore;
    setScore();
}

void Essay::setCorrectLengthScore( double& CorrectLengthScore )
{
    while( CorrectLengthScore > 20 || CorrectLengthScore < 0 )
    {
        std::cout << "ERROR: CorrectLengthScore must be 0 to 20" << "\n";
        std::cout << "Input CorrectLengthScore : " << "\n";
            std::cin >> CorrectLengthScore;
        std::cout << " " << "\n";
    }
    m_CorrectLengthScore = CorrectLengthScore;
    setScore();
}

void Essay::setContentScore( double& ContentScore )
{
    while( ContentScore > 30 || ContentScore < 0 )
    {
        std::cout << "ERROR: GrammarScore must be 0 to 30" << "\n";
        std::cout << "Input GrammarScore : " << "\n";
            std::cin >> ContentScore;
        std::cout << " " << "\n";
    }
    m_ContentScore = ContentScore;
    setScore();
}

//********************************************************
// set function *
// The parameters are the number of questions and the *
// number of questions missed. *
//********************************************************
void FinalExam::set(int questions, int missed)
{
    double numericScore; // To hold the numeric score

    // Set the number of questions and number missed.
    numQuestions = questions;
    numMissed = missed;

    // Calculate the points for each question.
    pointsEach = 100.0 / numQuestions;
    // Calculate the numeric score for this exam.
    numericScore = 100.0 - (missed * pointsEach);
    // Call the inherited setScore function to set the numeric score.
    setScore(numericScore);
    // Call the adjustScore function to adjust the score.
    adjustScore();
}
//**************************************************************
// Definition of Test::adjustScore. If score is within *
// 0.5 points of the next whole point, it rounds the score up *
// and recalculates the letter grade. *
//**************************************************************

void FinalExam::adjustScore()
{
    double fraction = score - static_cast<int>(score);

    if (fraction >= 0.5)
    {
    // Adjust the score variable in the GradedActivity class.
    score += (1.0 - fraction);
    }
}

//*****************************************************
// Definition of the PersonData class's operator functions. 
// redefine the way a particular operator works with an object
// Update other member variables if needed.	
//*****************************************************

std::ostream& operator << (std::ostream& out, const PersonData& personData)
{
    out << "LastName : " << personData.m_LastName << "\n" 
        << "FirstName : " << personData.m_FirstName << "\n" 
        << "Address : " << personData.m_Address << "\n"
        << "City : " << personData.m_City << "\n"
        << "State : " << personData.m_State << "\n"
        << "Zip : " << personData.m_Zip << "\n"
        << "Phone : " << personData.m_Phone << "\n";
	return out;
}

//*****************************************************
// Definition of the class CustomerData : public PersonData class's operator functions. 
// redefine the way a particular operator works with an object
// Update other member variables if needed.	
//*****************************************************

std::ostream& operator << ( std::ostream& out, const CustomerData& customerData )
{
    out << "LastName : " << customerData.getLastName() << "\n" 
        << "FirstName : " << customerData.getFirstName() << "\n" 
        << "Address : " << customerData.getAddress() << "\n"
        << "City : " << customerData.getCity() << "\n"
        << "State : " << customerData.getState() << "\n"
        << "Zip : " << customerData.getZip() << "\n"
        << "Phone : " << customerData.getPhone() << "\n"
        << "CustomerNumber : " << customerData.m_CustomerNumber << "\n"
        << "MailingList : " << customerData.m_MailingList << "\n";
	return out;
}

//*****************************************************
// Definition of the class PreferredCustomer : public CustomerDataclass's operator functions. 
// redefine the way a particular operator works with an object
// Update other member variables if needed.	
//*****************************************************

std::ostream& operator << (std::ostream& out, const PreferredCustomer& preferredCustomer)
{
    out << "LastName : " << preferredCustomer.getLastName() << "\n" 
        << "FirstName : " << preferredCustomer.getFirstName() << "\n" 
        << "Address : " << preferredCustomer.getAddress() << "\n"
        << "City : " << preferredCustomer.getCity() << "\n"
        << "State : " << preferredCustomer.getState() << "\n"
        << "Zip : " << preferredCustomer.getZip() << "\n"
        << "Phone : " << preferredCustomer.getPhone() << "\n"
        << "CustomerNumber : " << preferredCustomer.getCustomerNumber() << "\n"
        << "MailingList : " << preferredCustomer.getMailingList() << "\n"
        << "PurchasesAmount : " << preferredCustomer.m_PurchasesAmount << "\n"
        << "DiscountLevel : " << preferredCustomer.m_DiscountLevel << "\n";
	return out;
}

//*****************************************************
// Definition of the class CourseGrades operator functions. 
// redefine the way a particular operator works with an object
// Update other member variables if needed.	
//*****************************************************

std::ostream& operator << (std::ostream& out, const CourseGrades& courseGrades)
{
    out << "GradedActivity.getScore() : " << (*courseGrades.m_grades[0]).getScore() << "\n" 
        << "GradedActivity.getLetterGrade() : " << (*courseGrades.m_grades[0]).getLetterGrade() << "\n"
    
        << "PassFailExam.getScore() : " << (*courseGrades.m_grades[1]).getScore() << "\n" 
        << "PassFailExam.getLetterGrade() : " << (*courseGrades.m_grades[1]).getLetterGrade() << "\n"

        << "Essay.getScore() : " << (*courseGrades.m_grades[2]).getScore() << "\n" 
        << "Essay.getLetterGrade() : " << (*courseGrades.m_grades[2]).getLetterGrade() << "\n"

        << "FinalExam.getScore() : " << (*courseGrades.m_grades[3]).getScore() << "\n" 
        << "FinalExam.getLetterGrade() : " << (*courseGrades.m_grades[3]).getLetterGrade() << "\n";
    
	return out;
}

//*****************************************************
// Definition of the BasicShape class's operator functions. 
// redefine the way a particular operator works with an object
// Update other member variables if needed.	
//*****************************************************

std::ostream& operator << (std::ostream& out, const BasicShape& basicShape)
{
    out << "Area : " << basicShape.getArea() << "\n"; 
	return out;
}

//*****************************************************
// Definition of the Circle class's operator functions. 
// redefine the way a particular operator works with an object
// Update other member variables if needed.	
//*****************************************************

std::ostream& operator << (std::ostream& out, const Circle& circle)
{
    out << "getCenterX : " << circle.getCenterX() << "\n"
        << "getCenterY : " << circle.getCenterY() << "\n"
        << "getRadius : " << circle.getRadius() << "\n"
        << "calcArea : " << circle.BasicShape::getArea() << "\n";
	return out;
}

//*****************************************************
// Definition of the Rectangle class's operator functions. 
// redefine the way a particular operator works with an object
// Update other member variables if needed.	
//*****************************************************

std::ostream& operator << (std::ostream& out, const Rectangle& rectangle)
{
    out << "getWidth : " << rectangle.getWidth() << "\n"
        << "getLength : " << rectangle.getLength() << "\n"
        << "calcArea : " << rectangle.BasicShape::getArea() << "\n";
	return out;
}

//*****************************************************
// Definition of the BankAccount class's mutator functions. 
// These functions return and display the values in these member variables.
// Update other member variables if needed.	
//*****************************************************

// updates the balance by calculating the monthly interest earned by the account, and adding this interest to the balance.
void BankAccount::calculateIntrest() // virtual function 
{
    double monthlyInterestRate{ m_AnnualIntrestRate / 12 };
    double monthlyInterest{ monthlyInterestRate * m_Balance };
    m_Balance += monthlyInterest;
}

//subtracts the monthly service charges from the balance, 
//calls the calcInt function, 
//and then sets the variables that hold the number of withdrawals, number of deposits, and monthly service charges to zero.
void BankAccount::monthlyProcess() // virtual function
{
    m_Balance -= m_MonthlyServiceCharges;
    calculateIntrest();
    m_NumberOfWithdraws = 0;
    m_NumberOfDeposits = 0;
    m_MonthlyServiceCharges = 0;
}

void BankAccount::withdraw( const double &WithdrawAmount )
{
    // active account && balance > WithdrawAmount
    if( getBalance() > WithdrawAmount )  
    {
        m_Balance -= WithdrawAmount;
    }

    else // WithdrawAmount > getBalance()
    {
        std::cout << "ERROR: Withdraw amount " << WithdrawAmount << ", is greater that Account balance, " << getBalance() << "\n";
        std::cout << " " << "\n";
    }
}

void BankAccount::addMonthlyServiceCharges( const int& addAmount )
{
    m_MonthlyServiceCharges = m_MonthlyServiceCharges + addAmount;
}

//*****************************************************
// Definition of the bankAccount class's operator functions. 
// redefine the way a particular operator works with an object
// Update other member variables if needed.	
//*****************************************************

std::ostream& operator << (std::ostream& out, const BankAccount& bankAccount)
{
    out << "Balance : " << bankAccount.m_Balance << "\n"
        << "NumberOfDeposits : " << bankAccount.m_NumberOfDeposits << "\n"
        << "NumberOfWithdraws : " << bankAccount.m_NumberOfWithdraws << "\n"
        << "AnnualIntrestRate : " << bankAccount.m_AnnualIntrestRate << "\n"
        << "MonthlyServiceCharges : " << bankAccount.m_MonthlyServiceCharges << "\n";
	return out;
}


//*****************************************************
// Definition of the SavingAccount class's mutator functions. 
// These functions return and display the values in these member variables.
// Update other member variables if needed.	
//*****************************************************

void SavingAccount::withdraw( const double &WithdrawAmount )
{
    // active account && balance > withdraw
    if( ( m_Status == false ) && ( BankAccount::getBalance() > WithdrawAmount ) ) 
    {
        BankAccount::withdraw(WithdrawAmount);
        std::cout << "getBalance() : " << BankAccount::getBalance() << "\n";
    }

    // active account && withdraw > balance
    else if(( m_Status == true ) && ( BankAccount::getBalance() > WithdrawAmount ) )
    {
        std::cout << "ERROR: Withdraw amount " << WithdrawAmount << ", is greater that Saving Account balance, " << BankAccount::getBalance() << "\n";
        std::cout << " " << "\n";
    }

    else // inactive account
    {
        std::cout << "ERROR: A withdraw can not be made from an inactive account." << "\n";
        std::cout << "getBalance() : " << BankAccount::getBalance() << "\n";
        std::cout << " " << "\n";
    }
}

void SavingAccount::deposit( const double &DepositAmount )
{
    // active account 
    if( m_Status == true ) 
    {
        BankAccount::deposit(DepositAmount);
    }

    // inactive account now an active account
    else if( m_Status == false )
    {
        m_Status = true;
        BankAccount::deposit(DepositAmount);
        std::cout << "After adding DepositAmount, " << DepositAmount << ", Saving Account is now ACTIVE." << "\n";
        std::cout << "getBalance() : " << BankAccount::getBalance() << "\n";
        std::cout << " " << "\n";
    }

    else // still inactive account
    {
        BankAccount::deposit(DepositAmount);
        std::cout << "After adding DepositAmount, " << DepositAmount << ", Saving Account is INACTIVE." << "\n";
        std::cout << "getBalance() : " << BankAccount::getBalance() << "\n";
        std::cout << " " << "\n";
    }
}

void SavingAccount::monthlyProcess()
{
    if( BankAccount::getNumberOfWithdraws() > 4 )
    {
        for(int i{5}; i <= getNumberOfWithdraws(); ++i )
        {
            BankAccount::incrementMonthlyServiceCharges();
        }
    }

    if( BankAccount::getBalance() - BankAccount::getMonthlyServiceCharges() < 25 )
    {
        m_Status = false;
    }

    BankAccount::monthlyProcess();
}
//*****************************************************
// Definition of the bankAccount class's operator functions. 
// redefine the way a particular operator works with an object
// Update other member variables if needed.	
//*****************************************************

std::ostream& operator << (std::ostream& out, const SavingAccount& savingAccount)
{
    out << "Balance : " << savingAccount.BankAccount::getBalance() << "\n"
        << "NumberOfDeposits : " << savingAccount.BankAccount::getNumberOfDeposits()<< "\n"
        << "NumberOfWithdraws : " << savingAccount.BankAccount::getNumberOfWithdraws() << "\n"
        << "AnnualIntrestRate : " << savingAccount.BankAccount::getAnnualIntrestRate() << "\n"
        << "MonthlyServiceCharges : " << savingAccount.BankAccount::getMonthlyServiceCharges() << "\n"
        << "Status : " << savingAccount.m_Status << "\n";
	return out;
}

//*****************************************************
// Definition of the CheckingAccount class's mutator functions. 
// These functions return and display the values in these member variables.
// Update other member variables if needed.	
//*****************************************************

void CheckingAccount::withdraw( const double &WithdrawAmount )
{

    if( WithdrawAmount > BankAccount::getBalance() )
    {
        for( unsigned i{0}; i<15; ++i)
        {
            BankAccount::incrementMonthlyServiceCharges();
        }
    }

    else // BankAccount::getBalance() > WithdrawAmount
    {
        BankAccount::withdraw(WithdrawAmount);
    }

}

void CheckingAccount::monthlyProcess()
{
    for( unsigned i{0}; i<5; ++i)
    {
        BankAccount::incrementMonthlyServiceCharges();
    }

    BankAccount::addMonthlyServiceCharges( BankAccount::getNumberOfWithdraws() * 0.10 );    

    BankAccount::monthlyProcess();
}


//*****************************************************
// Definition of the bankAccount class's operator functions. 
// redefine the way a particular operator works with an object
// Update other member variables if needed.	
//*****************************************************
/*
std::ostream& operator << (std::ostream& out, const CheckingAccount& checkingAccount)
{
    out << "Balance : " << checkingAccount.BankAccount::getBalance() << "\n"
        << "NumberOfDeposits : " << checkingAccount.BankAccount::getNumberOfDeposits()<< "\n"
        << "NumberOfWithdraws : " << checkingAccount.BankAccount::getNumberOfWithdraws() << "\n"
        << "AnnualIntrestRate : " << checkingAccount.BankAccount::getAnnualIntrestRate() << "\n"
        << "MonthlyServiceCharges : " << checkingAccount.BankAccount::getMonthlyServiceCharges() << "\n";
    return out;
}
*/
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
        std::cout << "G) Chapter 15 Inheritance, Polymorphism and Virtual Functions - 6. Essay class " << "\n";
        std::cout << "H) Chapter 15 Inheritance, Polymorphism and Virtual Functions - 7. PersonData and CustomerData classes" << "\n";
        std::cout << "I) Chapter 15 Inheritance, Polymorphism and Virtual Functions - 8. PreferredCustomer Class " << "\n";
        std::cout << "J) Chapter 15 Inheritance, Polymorphism and Virtual Functions - 9. File Filter" << "\n";
        std::cout << "K) Chapter 15 Inheritance, Polymorphism and Virtual Functions - 10. File Double-Spacer " << "\n";
        std::cout << "L) Chapter 15 Inheritance, Polymorphism and Virtual Functions - 11. Course Grades" << "\n";
        std::cout << "M) Chapter 15 Inheritance, Polymorphism and Virtual Functions - 12. Ship, CruiseShip, and CargoShip Classes " << "\n";
        std::cout << "N) Chapter 15 Inheritance, Polymorphism and Virtual Functions - 13. Pure Abstract Base Class Project " << "\n";
        std::cout << "O) Chapter 15 Inheritance, Polymorphism and Virtual Functions - Group Project - 14. Bank Accounts " << "\n";
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