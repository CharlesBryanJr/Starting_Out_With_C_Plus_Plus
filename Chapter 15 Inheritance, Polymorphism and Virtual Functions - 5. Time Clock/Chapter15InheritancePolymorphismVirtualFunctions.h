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
	            MilitaryTime(){}; // default constructor 

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
        int m_StartingTime{0};
        int m_EndingTime{0};
        int m_ElaspedTime{0};

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
	            TimeClock(){}; // default constructor 

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

// end

#endif