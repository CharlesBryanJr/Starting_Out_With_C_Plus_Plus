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
        std::string m_EmployeeName{"Employee name"};
        int m_EmployeeNumber{-1};
        std::string m_HireDate{"Hire date"};

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
	            Employee(){}; // default constructor 

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
	            virtual ~Employee(){}				
            
};

class ProductionWorker : public Employee
{
    friend std::ostream& operator << (std::ostream& out, const ProductionWorker& productionWorker);

	private: 
        // Private members of the base class are inaccessible to the derived class.
        int m_Shift{-1};
        int m_HourlyPayRate{-1};

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
	            ProductionWorker(){}; // default constructor 

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
	            virtual ~ProductionWorker(){}				
            
};

// end

#endif