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

#ifndef Chapter15InheritancePolymorphismVirtualFunctions_H
#define Chapter15InheritancePolymorphismVirtualFunctions_H

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

class Employee
{
    friend std::ostream& operator << (std::ostream& out, const Employee& employee);

	private: 
        // Private members of the base class are inaccessible to the derived class.

        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing
            std::string m_EmployeeName{"Employee name"};
            int m_EmployeeNumber{-1};
            std::string m_HireDate{"Hire date"};

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 
    
    protected:
        // If base class is Private: Protected members of the base class become private members of the derived class.
            // If base class is Protected: Protected members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What protected data is the class responsible of storing
            //std::string m_HireDate{"Hire date"};

        // ***--- methods or member functions ---***
            // What protected actions is the class responsible of executing 
    
    public:
        // If base class is Private: Public members of the base class become private members of the derived class.
        // If base class is Protected: Public members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
            // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            Employee(){ std::cout << "Employee default constructor" << "\n"; }; // default constructor 

                Employee( const std::string_view EmployeeName, const int &EmployeeNumber, const std::string_view HireDate ) 
                    : m_EmployeeName(EmployeeName), m_EmployeeNumber(EmployeeNumber), m_HireDate(HireDate)
                {} 

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                std::string getEmployeeName() const 
                    { return m_EmployeeName; }

                int getEmployeeNumber() const 
                    { return m_EmployeeNumber; }

                std::string getHireDate() const 
                    { return m_HireDate; }

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed. (return this;)
                void setEmployeeName( const std::string_view EmployeeName ) 
                    { m_EmployeeName = EmployeeName; }

                void setEmployeeNumber( const int &EmployeeNumber )
                    { m_EmployeeNumber = EmployeeNumber; }

                void setHireDate( const std::string_view HireDate ) 
                    { m_HireDate = HireDate; }

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            virtual ~Employee(){ std::cout << "Employee default destructor" << "\n"; }; // default destructor 				
            
};

class ProductionWorker : public Employee
{
    friend std::ostream& operator << (std::ostream& out, const ProductionWorker& productionWorker);

	private: 
        // Private members of the base class are inaccessible to the derived class.

        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing
            int m_Shift{-1};
            int m_HourlyPayRate{-1};

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 
    
    protected:
        // If base class is Private: Protected members of the base class become private members of the derived class.
            // If base class is Protected: Protected members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What protected data is the class responsible of storing

        // ***--- methods or member functions ---***
            // What protected actions is the class responsible of executing 
    
    public:
        // If base class is Private: Public members of the base class become private members of the derived class.
        // If base class is Protected: Public members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
            // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            ProductionWorker(){ std::cout << "ProductionWorker default constructor" << "\n"; }; // default constructor 

                ProductionWorker( const int &Shift, const int &HourlyPayRate ) 
                    : m_Shift(Shift), m_HourlyPayRate(m_HourlyPayRate)
                {} 

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                int getShift() const 
                    { return m_Shift; }

                int getHourlyPayRate() const 
                    { return m_HourlyPayRate; }

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed. (return this;)
                void setShift( const int &Shift ) 
                    { m_Shift = Shift; }

                void setHourlyPayRate( const int &HourlyPayRate )
                    { m_HourlyPayRate = HourlyPayRate; }

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            virtual ~ProductionWorker(){ std::cout << "ProductionWorker default destructor" << "\n"; }; // default destructor 					
            
};

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

class ShiftSupervisor : public Employee
{
    friend std::ostream& operator << (std::ostream& out, const ShiftSupervisor& shiftSupervisor);

	private: 
        // Private members of the base class are inaccessible to the derived class.

        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing
            int m_AnnualSalary{0};
            int m_AnnualProductionBonus{0};

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 
    
    protected:
        // If base class is Private: Protected members of the base class become private members of the derived class.
            // If base class is Protected: Protected members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What protected data is the class responsible of storing

        // ***--- methods or member functions ---***
            // What protected actions is the class responsible of executing 
    
    public:
        // If base class is Private: Public members of the base class become private members of the derived class.
        // If base class is Protected: Public members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
            // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            ShiftSupervisor(){} // default constructor 

                ShiftSupervisor
                ( const std::string_view EmployeeName, 
                  const int &EmployeeNumber, 
                  const std::string_view HireDate, 
                  const int &AnnualSalary, 
                  const int &AnnualProductionBonus 
                ) 
                    : m_AnnualSalary(AnnualSalary), m_AnnualProductionBonus(AnnualProductionBonus)
                {
                    setEmployeeName(EmployeeName);
                    setEmployeeNumber(EmployeeNumber);
                    setHireDate(HireDate);
                } 

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                int getAnnualSalary() const 
                    { return m_AnnualSalary; }

                int getAnnualProductionBonus() const 
                    { return m_AnnualProductionBonus; }

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed. (return this;)
                void setAnnualSalary( const int &AnnualSalary ) 
                    { m_AnnualSalary = AnnualSalary; }

                void setAnnualProductionBonus( const int &AnnualProductionBonus )
                    { m_AnnualProductionBonus = AnnualProductionBonus; }

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            virtual ~ShiftSupervisor(){}				
            
};

/*
*****************************************************
Chapter 15 Inheritance, Polymorphism and VirtualFunctions - 3. TeamLeader Class
In a particular factory, a team leader is an hourly paid production worker who leads a small team. 
In addition to hourly pay, team leaders earn a fixed monthly bonus.
Team leaders are required to attend a minimum number of hours of training per year.
Design a TeamLeader class that extends the ProductionWorker class you designed in Programming Challenge 1. 
The TeamLeader class should have member variables for the monthly bonus amount, the required number of training hours, and the number of training hours that the team leader has attended. 
Write one or more constructors and the appropriate accessor and mutator functions for the class. 
Demonstrate the class by writing a program that uses a TeamLeader object.
*****************************************************
*/

class TeamLeader : public ProductionWorker
{
    friend std::ostream& operator << (std::ostream& out, const TeamLeader& teamLeader);

	private: 
        // Private members of the base class are inaccessible to the derived class.

        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing
            int m_MonthlyBonusAmount{1000};
            int m_RequiredTrainingHours{10};
            int m_TrainingHours{0};

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 
    
    protected:
        // If base class is Private: Protected members of the base class become private members of the derived class.
            // If base class is Protected: Protected members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What protected data is the class responsible of storing

        // ***--- methods or member functions ---***
            // What protected actions is the class responsible of executing 
    
    public:
        // If base class is Private: Public members of the base class become private members of the derived class.
        // If base class is Protected: Public members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
            // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            TeamLeader(){ std::cout << "TeamLeader default constructor" << "\n"; }; // default constructor 

                TeamLeader
                ( const std::string_view EmployeeName, 
                  const int &EmployeeNumber, 
                  const std::string_view HireDate, 
                  const int &Shift, 
                  const int &HourlyPayRate,
                  const int &MonthlyBonusAmount,
                  const int &RequiredTrainingHours, 
                  const int &TrainingHours 
                ) 
                    : m_MonthlyBonusAmount(MonthlyBonusAmount) , m_RequiredTrainingHours(RequiredTrainingHours), m_TrainingHours(TrainingHours)
                {
                    setEmployeeName(EmployeeName);
                    setEmployeeNumber(EmployeeNumber);
                    setHireDate(HireDate);
                    setShift(Shift);
                    setHourlyPayRate(HourlyPayRate);
                } 

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                int getMonthlyBonusAmount() const 
                    { return m_MonthlyBonusAmount; }

                int getRequiredTrainingHours() const 
                    { return m_RequiredTrainingHours; }

                int getTrainingHours() const 
                    { return m_TrainingHours; }


            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed. (return this;)
                void setMonthlyBonusAmount( const int &MonthlyBonusAmount ) 
                    { m_MonthlyBonusAmount = MonthlyBonusAmount; }

                void setRequiredTrainingHours( const int &RequiredTrainingHours ) 
                    { m_RequiredTrainingHours = RequiredTrainingHours; }

                void setTrainingHours( const int &TrainingHours ) 
                    { m_TrainingHours = TrainingHours; }

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            virtual ~TeamLeader(){ std::cout << "TeamLeader default destructor" << "\n"; }; // default destructor 					
            
};

/*
*****************************************************
Chapter 15 Inheritance, Polymorphism and VirtualFunctions - 4. Time Format
In Program 15-20 , the file Time.h contains a Time class. 
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

class Time
{
    friend std::ostream& operator << (std::ostream& out, const Time& time);

	private: 
        // Private members of the base class are inaccessible to the derived class.

        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 
    
    protected:
        // If base class is Private: Protected members of the base class become private members of the derived class.
            // If base class is Protected: Protected members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What protected data is the class responsible of storing
            int m_Hour{0};
            int m_Minute{0};
            int m_Second{0};
            std::string m_AMorPM{"AM"};

        // ***--- methods or member functions ---***
            // What protected actions is the class responsible of executing 
    
    public:
        // If base class is Private: Public members of the base class become private members of the derived class.
        // If base class is Protected: Public members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
            // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            Time(){}; // default constructor 

                Time( int &Hour, int &Minute, int &Second, std::string &AMorPM );

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                int getHour() const 
                    { return m_Hour; }

                int getMinute() const 
                    { return m_Minute; }

                int getSecond() const 
                    { return m_Second; }

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed. (return this;)

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            virtual ~Time(){}				
            
};

class MilitaryTime : public Time
{
    friend std::ostream& operator << (std::ostream& out, const MilitaryTime& militaryTime);

	private: 
        // Private members of the base class are inaccessible to the derived class.

        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 
    
    protected:
        // If base class is Private: Protected members of the base class become private members of the derived class.
            // If base class is Protected: Protected members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What protected data is the class responsible of storing
            int m_MilitaryTimeHours{0000};
            int m_MilitaryTimeSeconds{0};

        // ***--- methods or member functions ---***
            // What protected actions is the class responsible of executing 
    
    public:
        // If base class is Private: Public members of the base class become private members of the derived class.
        // If base class is Protected: Public members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
            // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            MilitaryTime() : Time()
                {}; // default constructor 

                MilitaryTime( int &Hour, int &Minute, int &Second, std::string &AMorPM );

                MilitaryTime( int &MilitaryTimeHours, int &MilitaryTimeSeconds );

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                int getMilitaryTimeHour() const 
                    { return m_Hour; }

                int getMilitaryTimeSecond() const 
                    { return m_Second; }

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed. (return this;)
                int setMilitaryTime( int &MilitaryTimeHours, int &MilitaryTimeSeconds );
                void updateMilitaryTime();
                void updateTime();

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            virtual ~MilitaryTime(){}				
            
};

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

class TimeClock : public MilitaryTime // public Time
{
    friend std::ostream& operator << (std::ostream& out, const TimeClock& timeClock);

	private: 
        // Private members of the base class are inaccessible to the derived class.

        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing
            int m_StartingTime{0};
            int m_EndingTime{0};
            int m_ElaspedTime{0};

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 
    
    protected:
        // If base class is Private: Protected members of the base class become private members of the derived class.
            // If base class is Protected: Protected members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What protected data is the class responsible of storing

        // ***--- methods or member functions ---***
            // What protected actions is the class responsible of executing 
    
    public:
        // If base class is Private: Public members of the base class become private members of the derived class.
        // If base class is Protected: Public members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
            // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            TimeClock() : MilitaryTime()
                {}; // default constructor 

                TimeClock( int& StartingTime, int& EndingTime ) 
                {
                    int seconds{0};
                    m_StartingTime = setMilitaryTime(StartingTime,seconds);
                    m_EndingTime = setMilitaryTime(EndingTime,seconds);
                    updateElaspedTime();
                }

                TimeClock
                ( 
                    int &Hour, int &Minute, int &Second, std::string &AMorPM, 
                    int &Hour2, int &Minute2, int &Second2, std::string &AMorPM2 
                );

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                int getStartingTime() const 
                    { return m_StartingTime; }

                int getEndingTime() const 
                    { return m_EndingTime; }

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed. (return this;)
                void setStartingTime( int& StartingTime ) 
                { 
                    int seconds{0}; 
                    m_StartingTime = setMilitaryTime(StartingTime,seconds); 
                    updateElaspedTime(); 
                }

                void setEndingTime( int& EndingTime )
                { 
                    int seconds{0}; 
                    m_EndingTime = setMilitaryTime(EndingTime,seconds); 
                    updateElaspedTime();
                }
                
                void updateElaspedTime();

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            virtual ~TimeClock(){}				
            
};

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

class GradedActivity
{
    protected:
        char letter; // To hold the letter grade
        double score; // To hold the numeric score
        void determineGrade(); // Determines the letter grade

    public:
        // Default constructor
        GradedActivity()
        { letter = ' '; score = 0.0; }

        // Mutator function
        virtual void setScore(double s);

        // Accessor functions
        double getScore() const
        { return score; }

        virtual char getLetterGrade() const
        { return letter; }
};

class CurvedActivity : public GradedActivity
{
    protected:

        double rawScore; // Unadjusted score
        double percentage; // Curve percentage

    public:
        // Default constructor
        CurvedActivity() : GradedActivity()
        { rawScore = 0.0; percentage = 0.0; }

        // Mutator functions
        virtual void setScore(double s)
        { 
            rawScore = s;
            GradedActivity::setScore(rawScore * percentage); 
        }

        void setPercentage(double c)
            { percentage = c; }

        // Accessor functions
        double getPercentage() const
            { return percentage; }

        double getRawScore() const
            { return rawScore; }
};

class PassFailActivity : public GradedActivity
{
    protected:
        double minPassingScore; // Minimum passing score
        
    public:
        // Default constructor
        PassFailActivity() : GradedActivity()
        { minPassingScore = 0.0; }

        // Constructor
        PassFailActivity(double mps) : GradedActivity()
        { minPassingScore = mps; }

        // Mutator
        void setMinPassingScore(double mps)
        { minPassingScore = mps; }

        // Accessors
        double getMinPassingScore() const
            { return minPassingScore; }

        virtual char getLetterGrade() const
            { return letter; }
};

class Essay : public GradedActivity
{
	private: 
        // Private members of the base class are inaccessible to the derived class.

        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing
            double m_GrammarScore{0};
            double m_SpellingScore{0};
            double m_CorrectLengthScore{0};
            double m_ContentScore{0};

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 
    
    protected:
        // If base class is Private: Protected members of the base class become private members of the derived class.
            // If base class is Protected: Protected members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What protected data is the class responsible of storing

        // ***--- methods or member functions ---***
            // What protected actions is the class responsible of executing 
    
    public:
        // If base class is Private: Public members of the base class become private members of the derived class.
        // If base class is Protected: Public members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
            // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            Essay(){}; // default constructor 

                Essay( double& GrammarScore, double& SpellingScore, double& CorrectLengthScore, double& ContentScore ) 
                {
                    setGrammarScore(GrammarScore);
                    setSpellingScore(SpellingScore);
                    setCorrectLengthScore(CorrectLengthScore);
                    setContentScore(ContentScore);
                } 

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                double getGrammarScore() const { return m_GrammarScore; }
                
                double getSpellingScore() const { return m_SpellingScore; }

                double getCorrectLengthScore() const { return m_CorrectLengthScore; }

                double getContentScore() const { return m_ContentScore;  }

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed. (return this;)
                void setGrammarScore( double& GrammarScore );

                void setSpellingScore( double& SpellingScore ); 

                void setCorrectLengthScore( double& CorrectLengthScore );

                void setContentScore( double& ContentScore );

                virtual void setScore()
                {
                    GradedActivity::setScore( m_GrammarScore + m_SpellingScore + m_CorrectLengthScore + m_ContentScore );
                }

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		
                friend std::ostream& operator << (std::ostream& out, const Essay& essay);

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            virtual ~Essay(){}				
            
};


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

class PersonData
{
	private: 
        // Private members of the base class are inaccessible to the derived class.
    
        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing
            std::string m_LastName{"lastName"};
            std::string m_FirstName{"firstName"};
            std::string m_Address{"address"};
            std::string m_City{"city"};
            std::string m_State{"state"};
            std::string m_Zip{"zip"};
            std::string m_Phone{"phone"};

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 
    
    protected:
        // If base class is Private: Protected members of the base class become private members of the derived class.
            // If base class is Protected: Protected members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What protected data is the class responsible of storing

        // ***--- methods or member functions ---***
            // What protected actions is the class responsible of executing 
    
    public:
        // If base class is Private: Public members of the base class become private members of the derived class.
        // If base class is Protected: Public members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
            // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            PersonData(){}; // default constructor 

                PersonData
                ( const std::string_view LastName, const std::string_view FirstName, const std::string_view Address, const std::string_view City, 
                  const std::string_view State, const std::string_view Zip, const std::string_view Phone ) 
                    : m_LastName(LastName), m_FirstName(FirstName), m_Address(Address), m_City(City), m_State(State), m_Zip(Zip), m_Phone(Phone)
                {} 

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                std::string getLastName() const 
                    { return m_LastName; }

                std::string getFirstName() const 
                    { return m_FirstName; }
                
                std::string getAddress() const 
                    { return m_Address; }

                std::string getCity() const 
                    { return m_City; }

                std::string getState() const 
                    { return m_State; }

                std::string getZip() const 
                    { return m_Zip; }
                
                std::string getPhone() const 
                    { return m_Phone; }

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed. (return this;)
                void setLastName( const std::string_view LastName ) 
                    { m_LastName = LastName; }

                void setFirstName( const std::string_view FirstName ) 
                    { m_FirstName = FirstName; }

                void setAddress( const std::string_view Address ) 
                    { m_Address = Address; }

                void setCity( const std::string_view City ) 
                    { m_City = City; }

                void setState( const std::string_view State ) 
                    {m_State = State; }

                void setZip( const std::string_view Zip ) 
                    { m_Zip = Zip; }

                void setPhone( const std::string_view Phone ) 
                    { m_Phone = Phone; }

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.	
                friend std::ostream& operator << (std::ostream& out, const PersonData& personData);	

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            virtual ~PersonData(){}				
            
};

class CustomerData : public PersonData
{
	private: 
        // Private members of the base class are inaccessible to the derived class.
        int m_CustomerNumber{-1}; // hold a unique integer for each customer.
        bool m_MailingList{false}; // set to true if the customer wishes to be on a mailing list, or false if the customer does not wish to be on a mailing list.

        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 
    
    protected:
        // If base class is Private: Protected members of the base class become private members of the derived class.
            // If base class is Protected: Protected members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What protected data is the class responsible of storing

        // ***--- methods or member functions ---***
            // What protected actions is the class responsible of executing 
    
    public:
        // If base class is Private: Public members of the base class become private members of the derived class.
        // If base class is Protected: Public members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
            // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            CustomerData(){}; // default constructor 

                CustomerData
                ( const std::string_view LastName, const std::string_view FirstName, const std::string_view Address, const std::string_view City, 
                  const std::string_view State, const std::string_view Zip, const std::string_view Phone, const int& CustomerNumber, const bool MailingList ) 
                    : m_CustomerNumber(CustomerNumber), m_MailingList(MailingList)
                {
                    setLastName(LastName);
                    setFirstName(FirstName);
                    setAddress(Address);
                    setCity(City);
                    setState(State);
                    setZip(Zip);
                    setPhone(Phone);
                } 

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                int getCustomerNumber() const 
                    { return m_CustomerNumber; }

                bool getMailingList() const 
                    { return m_MailingList; }

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed. (return this;)
                void setCustomerNumber( const int& CustomerNumber ) 
                    { m_CustomerNumber = CustomerNumber; }

                void setMailingList( const bool MailingList )
                    { m_MailingList = MailingList; }

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		
				friend std::ostream& operator << ( std::ostream& out, const CustomerData& customerData );

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            virtual ~CustomerData(){}				
            
};

/*
*****************************************************
Chapter 15 Inheritance, Polymorphism and Virtual Functions - 8. PreferredCustomer Class
A retail store has a preferred customer plan where customers may earn discounts on all their purchases. 
The amount of a customer’s discount is determined by the amount of the customer’s cumulative purchases in the store.
• When a preferred customer spends $500, he or she gets a 5% discount on all future purchases.
• When a preferred customer spends $1,000, he or she gets a 6% discount on all future purchases.
• When a preferred customer spends $1,500, he or she gets a 7% discount on all future purchases.
• When a preferred customer spends $2,000 or more, he or she gets a 10% discount on all future purchases.

Design a class named PreferredCustomer, which is derived from the CustomerData class you created in Programming Challenge 7. 

The PreferredCustomer class should have the following member variables:
• purchasesAmount (a double )
• discountLevel (a double )
The purchasesAmount variable holds the total of a customer’s purchases to date. 
The discountLevel variable should be set to the correct discount percentage, according to the store’s preferred customer plan. 
Write appropriate member functions for this class and demonstrate it in a simple program.
Input Validation: Do not accept negative values for any sales figures.
*****************************************************
*/

class PreferredCustomer : public CustomerData
{
	private: 
        // Private members of the base class are inaccessible to the derived class.
        double m_PurchasesAmount{0}; // holds the total of a customer’s purchases to date.
        double m_DiscountLevel{0}; // set to the correct discount percentage, according to the store’s preferred customer plan.

        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 
    
    protected:
        // If base class is Private: Protected members of the base class become private members of the derived class.
            // If base class is Protected: Protected members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What protected data is the class responsible of storing

        // ***--- methods or member functions ---***
            // What protected actions is the class responsible of executing 
    
    public:
        // If base class is Private: Public members of the base class become private members of the derived class.
        // If base class is Protected: Public members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
            // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            PreferredCustomer(){}; // default constructor 

                PreferredCustomer
                ( const std::string_view LastName, const std::string_view FirstName, const std::string_view Address, const std::string_view City, 
                  const std::string_view State, const std::string_view Zip, const std::string_view Phone, const int& CustomerNumber, const bool MailingList,
                  const int& PurchasesAmount ) 
                    : m_PurchasesAmount(PurchasesAmount)
                {
                    setLastName(LastName);
                    setFirstName(FirstName);
                    setAddress(Address);
                    setCity(City);
                    setState(State);
                    setZip(Zip);
                    setPhone(Phone);
                    setCustomerNumber(CustomerNumber);
                    setMailingList(MailingList);
                    updateDiscountLevel();
                } 

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                int getPurchasesAmount() const 
                    { return m_PurchasesAmount; }

                int getDiscountLevel() const 
                    { return m_DiscountLevel; }

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed. (return this;)
                void setPurchasesAmount( const int& PurchasesAmount ) 
                    { m_PurchasesAmount = PurchasesAmount; 
                    updateDiscountLevel(); }
                
                void updateDiscountLevel()
                {
                    bool updateMade{false};

                    if( m_PurchasesAmount > 2000 && updateMade == false )
                    {
                        m_DiscountLevel = 0.10;
                        updateMade = true;
                    }
                    if( m_PurchasesAmount > 1500 && updateMade == false )
                    {
                        m_DiscountLevel = 0.07;
                        updateMade = true;
                    }
                    if( m_PurchasesAmount > 1000 && updateMade == false )
                    {
                        m_DiscountLevel = 0.06;
                        updateMade = true;
                    }
                    if( m_PurchasesAmount > 500 && updateMade == false )
                    {
                        m_DiscountLevel = 0.05;
                        updateMade = true;
                    }
                    
                    updateMade = false;
                }

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		
				friend std::ostream& operator << (std::ostream& out, const PreferredCustomer& preferredCustomer);

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            virtual ~PreferredCustomer(){}				
            
};

/*
*****************************************************
Chapter 15 Inheritance, Polymorphism and Virtual Functions - 11. Course Grades
In a course, a teacher gives the following tests and assignments:
• A lab activity that is observed by the teacher and assigned a numeric score.
• A pass/fail exam that has 10 questions. The minimum passing score is 70.
• An essay that is assigned a numeric score.
• A final exam that has 50 questions.

Write a class named CourseGrades. 
The class should have a member named grades that is an array of GradedActivity pointers. 
The grades array should have four elements, one for each of the assignments previously described. 
The class should have the following member functions:

setLab: This function should accept the address of a GradedActivity object as its argument. 
This object should already hold the student’s score for the lab activity. 
Element 0 of the grades array should reference this object.

setPassFailExam: This function should accept the address of a PassFailExam object as its argument. 
This object should already hold the student’s score for the pass/fail exam. 
Element 1 of the grades array should reference this object.

setEssay: This function should accept the address of an Essay object as its argument. 
(See Programming Challenge 6 for the Essay class. If you have not completed Programming Challenge 6, use a GradedActivity object instead.) 
This object should already hold the student’s score for the essay. Element 2 of the grades array should reference this object.

setPassFailExam: This function should accept the address of a FinalExam object asits argument. 
This object should already hold the student’s score for the final exam. 
Element 3 of the grades array should reference this object.

print: This function should display the numeric scores and grades for each element in the grades array.

Demonstrate the class in a program.
*****************************************************
*/

class FinalExam : public GradedActivity
{
    private:
        int numQuestions; // Number of questions
        double pointsEach; // Points for each question
        int numMissed; // Number of questions missed
    public:
        // Default constructor
        FinalExam()
        { numQuestions = 0;
        pointsEach = 0.0;
        numMissed = 0; }

        // Constructor
        FinalExam(int questions, int missed)
        { set(questions, missed); }

        // Mutator functions
        void set(int, int); // Defined in FinalExam.cpp
        void adjustScore(); // Defined in FinalExam.cpp

        // Accessor functions
        double getNumQuestions() const
        { return numQuestions; }

        double getPointsEach() const
        { return pointsEach; }

        int getNumMissed() const
        { return numMissed; }
};


class CourseGrades
{
	private: 
        // Private members of the base class are inaccessible to the derived class. 

        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing
            GradedActivity* m_grades[4];

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 
    
    protected:
        // If base class is Private: Protected members of the base class become private members of the derived class.
            // If base class is Protected: Protected members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What protected data is the class responsible of storing

        // ***--- methods or member functions ---***
            // What protected actions is the class responsible of executing 
    
    public:
        // If base class is Private: Public members of the base class become private members of the derived class.
        // If base class is Protected: Public members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
            // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            CourseGrades( GradedActivity* const ptr_GradedActivity, 
                              PassFailActivity* const ptr_PassFailExam,
                              Essay* const ptr_Essay,
                              FinalExam* const ptr_FinalExam )
                { 
                    setLab(ptr_GradedActivity); // m_grades[0] = ptr_GradedActivity;
                    setPassFailExam(ptr_PassFailExam); // m_grades[1] = ptr_PassFailExam;
                    setEssay(ptr_Essay); // m_grades[2] = ptr_Essay;
                    setPassFailExam(ptr_FinalExam); // m_grades[3] = ptr_FinalExam;
                }; // default constructor 

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed. (return this;)
                
                void setLab( GradedActivity* const ptr_GradedActivity ) 
                    { m_grades[0] = ptr_GradedActivity; }
                
                void setPassFailExam( PassFailActivity* const ptr_PassFailExam ) 
                    { m_grades[1] = ptr_PassFailExam; }
                
                void setEssay( Essay* const ptr_Essay ) 
                    { m_grades[2] = ptr_Essay; }
                
                void setPassFailExam( FinalExam* const ptr_FinalExam ) 
                    { m_grades[3] = ptr_FinalExam; }
                
			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		
				friend std::ostream& operator << (std::ostream& out, const CourseGrades& courseGrades);

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            virtual ~CourseGrades(){}				
            
};

/*
*****************************************************
Chapter 15 Inheritance, Polymorphism and Virtual Functions - 12. Ship, CruiseShip, and CargoShip Classes

Design a Ship class that has the following members:
• A member variable for the name of the ship (a string)
• A member variable for the year that the ship was built (a string)
• A constructor and appropriate accessors and mutators
• A virtual print function that displays the ship’s name and the year it was built.

Design a CruiseShip class that is derived from the Ship class. 
The CruiseShip class should have the following members:
• A member variable for the maximum number of passengers (an int )
• A constructor and appropriate accessors and mutators
• A print function that overrides the print function in the base class. 
The CruiseShip class’s print function should display only the ship’s name and the maximum number of passengers.

Design a CargoShip class that is derived from the Ship class. 
The CargoShip class should have the following members:
• A member variable for the cargo capacity in tonnage (an int ).
• A constructor and appropriate accessors and mutators.
• A print function that overrides the print function in the base class. 
The CargoShip class’s print function should display only the ship’s name and the ship’s cargo capacity.

Demonstrate the classes in a program that has an array of Ship pointers. 
The array elements should be initialized with the addresses of dynamically allocated Ship, CruiseShip, and CargoShip objects. 
(See Program 15-14 , lines 17 through 22, for an example of how to do this.) 
The program should then step through the array, calling each object’s print function.
*****************************************************
*/

class Ship
{
	private: 
        // Private members of the base class are inaccessible to the derived class.
        
        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing
            std::string m_ShipName{"Ship Name"};
            std::string m_ShipYearBuilt{"2000"};

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 
    
    protected:
        // If base class is Private: Protected members of the base class become private members of the derived class.
        // If base class is Protected: Protected members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What protected data is the class responsible of storing

        // ***--- methods or member functions ---***
            // What protected actions is the class responsible of executing 
    
    public:
        // If base class is Private: Public members of the base class become private members of the derived class.
        // If base class is Protected: Public members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
            // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            Ship(){}; // default constructor 

                Ship( const std::string_view ShipName, const std::string_view ShipYearBuilt ) 
                    : m_ShipName(ShipName), m_ShipYearBuilt(ShipYearBuilt)
                {} 

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                std::string getShipName() const 
                    { return m_ShipName; }

                std::string getShipYearBuilt() const 
                    { return m_ShipYearBuilt; }

                virtual void print() const
                {
                    std::cout << "ShipName : " << getShipName() << "\n";
                    std::cout << "ShipYearBuilt : " << getShipYearBuilt() << "\n";
                    std::cout << " " << "\n";
                }

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed. (return this;)
                void setShipName( const std::string_view ShipName ) 
                    { m_ShipName = ShipName; }

                void setShipYearBuilt( const std::string_view ShipYearBuilt ) 
                    { m_ShipYearBuilt = ShipYearBuilt; }

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            virtual ~Ship(){}				
            
};

class CruiseShip : public Ship
{
	private: 
        // Private members of the base class are inaccessible to the derived class.
        
        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing
            int m_CruiseShipMaxPassengers{0};

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 
    
    protected:
        // If base class is Private: Protected members of the base class become private members of the derived class.
        // If base class is Protected: Protected members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What protected data is the class responsible of storing

        // ***--- methods or member functions ---***
            // What protected actions is the class responsible of executing 
    
    public:
        // If base class is Private: Public members of the base class become private members of the derived class.
        // If base class is Protected: Public members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
            // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            CruiseShip(){}; // default constructor 

                CruiseShip( const std::string_view ShipName, const std::string_view ShipYearBuilt, const int& CruiseShipMaxPassengers) 
                    : Ship(ShipName,ShipYearBuilt), m_CruiseShipMaxPassengers(CruiseShipMaxPassengers)
                {} 

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                int getCruiseShipMaxPassengers() const 
                    { return m_CruiseShipMaxPassengers; }

                virtual void print() const
                {
                    std::cout << "ShipName : " << Ship::getShipName() << "\n";
                    std::cout << "CruiseShipMaxPassengers : " << getCruiseShipMaxPassengers() << "\n";
                    std::cout << " " << "\n";
                }

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed. (return this;)
                void setCruiseShipMaxPassengers( const int& CruiseShipMaxPassengers ) 
                    { m_CruiseShipMaxPassengers = CruiseShipMaxPassengers; }

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            virtual ~CruiseShip(){}				
            
};

class CargoShip : public Ship
{
	private: 
        // Private members of the base class are inaccessible to the derived class.
        
        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing
            int m_CargoCapacity{0};

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 
    
    protected:
        // If base class is Private: Protected members of the base class become private members of the derived class.
        // If base class is Protected: Protected members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What protected data is the class responsible of storing

        // ***--- methods or member functions ---***
            // What protected actions is the class responsible of executing 
    
    public:
        // If base class is Private: Public members of the base class become private members of the derived class.
        // If base class is Protected: Public members of the base class become protected members of the derived class.

        // ***--- attributes or member variables ---***
            // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
            // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            CargoShip(){}; // default constructor 

                CargoShip( const std::string_view ShipName, const std::string_view ShipYearBuilt, const int& CargoCapacity ) 
                    : Ship(ShipName,ShipYearBuilt), m_CargoCapacity(CargoCapacity)
                {} 

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                int getCargoCapacity() const 
                    { return m_CargoCapacity; }

                virtual void print() const
                {
                    std::cout << "ShipName : " << Ship::getShipName() << "\n";
                    std::cout << "CargoCapacity : " << getCargoCapacity() << "\n";
                    std::cout << " " << "\n";
                }

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed. (return this;)
                void setCargoCapacity( const int& CargoCapacity ) 
                    { m_CargoCapacity = CargoCapacity; }

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            virtual ~CargoShip(){}				
            
};


// end

#endif