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

#ifndef Chapter13IntroToClasses_H
#define Chapter13IntroToClasses_H

/*
//*****************************************************
Starting Out With C++ Chapter 13 Introduction to Classes - 3. Car Class
Write a class named Car that has the following member variables:
• yearModel . An int that holds the car’s year model.
• make . A string that holds the make of the car.
• speed . An int that holds the car’s current speed.

In addition, the class should have the following constructor and other member functions.

• Constructor. The constructor should accept the car’s year model and make as arguments. 
These values should be assigned to the object’s yearModel and make member variables. 
The constructor should also assign 0 to the speed member variables.
• Accessor. Appropriate accessor functions to get the values stored in an object’s yearModel, make, and speed member variables.
• accelerate . The accelerate function should add 5 to the speed member variable each time it is called.
• brake . The brake function should subtract 5 from the speed member variable each time it is called.
//*****************************************************
*/

class Car
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing

        int yearModel; // • yearModel . An int that holds the car’s year model.
        std::string make; // • make . A string that holds the make of the car.
        int speed; // • speed . An int that holds the car’s current speed.

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 


        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            
            Car(int &yM, std::string &m) // • Constructor. The constructor should accept the car’s year model and make as arguments. 
            {   
                yearModel = yM;
                make = m;
                speed = 0;
            }

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables. 
            void getCarYearModel() const;
            void getCarMake() const;
            void getCarSpeed() const;

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            void accelerateCar();
            void brakeCar();

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Car(){}
            
};

/*
//*****************************************************
Class specification : Employee Class
Write a class named Employee that has the following member variables:
• name. A string that holds the employee’s name.
• idNumber. An int variable that holds the employee’s ID number.
• department. A string that holds the name of the department where the employee works.
• position. A string that holds the employee’s job title.

The class should have the following constructors:
• A constructor that accepts the following values as arguments and assigns them to the appropriate member variables: 
employee’s name, employee’s ID number, department, and position.

• A constructor that accepts the following values as arguments and assigns them to the appropriate member variables: employee’s name and ID number. 
The department and position fields should be assigned an empty string ( "" ).

• A default constructor that assigns empty strings ( "") to the name, department, and position member variables, and 0 to the idNumber member variable.
//*****************************************************
*/

class Employee
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing

        std::string name; // • name. A string that holds the employee’s name.
        int idNumber; // • idNumber. An int variable that holds the employee’s ID number.
        std::string department; // • department. A string that holds the name of the department where the employee works.
        std::string position; // • position. A string that holds the employee’s job title.

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 


        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions

            // • A default constructor that assigns empty strings ( "") to the name, department, and position member variables, and 0 to the idNumber member variable.
            Employee()
            { name = ""; idNumber = 0; department = ""; position = ""; }

            // • A constructor that accepts the following values as arguments and assigns them to the appropriate member variables: employee’s name and ID number. 
            // The department and position fields should be assigned an empty string ( "" ).
            Employee(std::string &n, int &id)
            { name = n; idNumber = id; department = ""; position = ""; }

            // • A constructor that accepts the following values as arguments and assigns them to the appropriate member variables: 
            // employee’s name, employee’s ID number, department, and position.
            Employee(std::string &n, int &id, std::string &dep, std::string &pos)
            { name = n; idNumber = id; department = dep; position = pos; }

            // ***--- accessor or getter ---***
            // Write appropriate accessor functions that return the values in these member variables. 
            void getEmployeeName() const;
            void getEmployeeID() const;
            void getEmployeeDepartment() const;
            void getEmployeePosition() const;

            // ***--- mutator or setter  ---***
            // Write appropriate mutator functions that store values in these member variables 
            void setEmployeeName(std::string &n);
            void setEmployeeID(int &id);
            void setEmployeeDepartment(std::string &dep);
            void setEmployeePosition(std::string &pos);
            
            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Employee(){}
            
};

/*
//*****************************************************
Class specification : Date
The Date class stores a date in three integers: month, day, and year.
The Date class can print the date in three forms:
12/25/2014
December 25, 2014
25 December 2014
Input Validation: Do not accept values for the day greater than 31 or less than 1. 
Input Validation: Do not accept values for the month greater than 12 or less than 1.
//*****************************************************
*/

class Date
{
    private:

        // attributes or member variables 
        // What private data is the class responsible of storing
        int month;
        int day;
        int year;

        // methods or member functions 
        // What private actions is the class responsible of executing 

        void setMonthDayYear(int &month, int &day, int &year);

        void setMonthDayYear(int &month, int &day, int &year, int &m);

        void setMonthDayYear(int &month, int &day, int &year, int &m, int &d);

        void setMonthDayYear(int &month, int &day, int &year, int &m, int &d, int &y);

    public:
        
        // attributes or member variables 
        // What public data is the class responsible of storing 


        // methods or member functions 
        // What public actions is the class responsible of executing 

            // costructors
            // Useful for initializing private member variables or executing private member functions
            Date();
    
            Date(int &m);

            Date(int &m, int &d);

            Date(int &m, int &d, int &y);
    
            // --- accessor or getter ---

            void getDateFormat1(const int &month, const int &day, const int &year) const; // retrieves the data in this format 12/25/2014

                void displayDateFormat1() 
                {  getDateFormat1(month, day, year); }
            
            void getDateFormat2(const int &month, const int &day, const int &year) const; // retrieves the data in this format December 25, 2014
                
                void displayDateFormat2()
                {  getDateFormat2(month, day, year); }

            void getDateFormat3(const int &month, const int &day, const int &year) const; // retrieves the data in this format 25 December 2014

                void displayDateFormat3()
                {  getDateFormat3(month, day, year); }
            
            // --- mutator or setter  ---
            
            void setMonth(int &month, int &m); // updates the month member variable 

                void updateMonth(int &m)
                { setMonth(month, m); }
            
            void setDay(int &day, int &d); // updates the day member variable 

                void updateDay(int &d)
                { setDay(day, d); }
            
            void setYear(int &year, int &y); // updates the year member variable 

                void updateYear(int &y)
                { setYear(year, y); }
            
            // --- destructors ---
            // Useful to free memory that was dynamically allocated by the class object
            ~Date(){};
            
            
};

#endif