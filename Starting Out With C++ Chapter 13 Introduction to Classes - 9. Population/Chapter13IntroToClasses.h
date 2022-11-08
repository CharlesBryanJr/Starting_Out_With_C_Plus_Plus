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
Starting Out With C++ Chapter 13 Introduction to Classes - 9. Population
In a population, the birth rate and death rate are calculated as follows:
Birth Rate = Number of Births ÷ Population
Death Rate = Number of Deaths ÷ Population

For example, in a population of 100,000 that has 8,000 births and 6,000 deaths per
year, the birth rate and death rate are:
Birth Rate = 8,000 ÷ 100,000 = 0.08
Death Rate = 6,000 ÷ 100,000 = 0.06

Design a Population class that stores a population, number of births, and number of deaths for a period of time. 
Member functions should return the birth rate and death rate. 
Implement the class in a program.

Input Validation: Do not accept population figures less than 1, or birth or death numbers less than 0.
//*****************************************************
*/

class Population
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        double population; 
        double numberOfBirths;
        double numberOfDeaths;
        double birthRate;
        double deathRate;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions

            Population();

            Population(double &p, double &nob, double &nod);

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            void getPopulation() const;
            void getBirthRate() const;
            void getDeathRate() const;

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables. 
            void setPopulation(double &p);
            void setNumberOfBirths(double &nob);
            void setNumberOfDeaths(double &nod);

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Population(){}
            
};

/*
//*****************************************************
Starting Out With C++ Chapter 13 Introduction to Classes - 8. Circle Class
• radius: a double
• pi: a double initialized with the value 3.14159

The class should have the following member functions:
• Default Constructor. A default constructor that sets radius to 0.0.
• Constructor. Accepts the radius of the circle as an argument.
• setRadius. A mutator function for the radius variable.
• getRadius. An accessor function for the radius variable.
• getArea. Returns the area of the circle, which is calculated as area = pi * radius * radius
• getDiameter. Returns the diameter of the circle, which is calculated as diameter = radius * 2
• getCircumference. Returns the circumference of the circle, which is calculated as circumference = 2 * pi * radius
//*****************************************************
*/

class Circle
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        double radius; 
        double PI;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions

            Circle() 
            { radius = 0.00; PI = 3.14159; }

            Circle(double &r);

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            void getRadius() const;
            void getArea() const;
            void getDiameter() const;
            void getCircumference() const;

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            void setRadius(double &r);

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Circle(){}
            
};

/*
//*****************************************************
Starting Out With C++ Chapter 13 Introduction to Classes - 7. TestScores Class
Design a TestScores class that has member variables to hold three test scores. 
The class should have a constructor, accessor, and mutator functions for the test score fields and a member function that returns the average of the test scores. 
Demonstrate the class by writing a separate program that creates an instance of the class. 
The program should ask the user to enter three test scores, which are stored in the TestScores object. 
Then the program should display the average of the scores, as reported by the TestScores object.
//*****************************************************
*/

class TestScores
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing

        int testScore1; // An int that holds the score for test 1
        int testScore2; // An int that holds the score for test 2
        int testScore3; // An int that holds the score for test 3
        int averageTestScore;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions

            TestScores() 
            { testScore1 = 0; testScore2 = 0; testScore3 = 0; }

            TestScores(int &ts1, int &ts2, int &ts3);

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            void getTestScores1() const;
            void getTestScores2() const;
            void getTestScores3() const;

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            void setTestScores1();
            void setTestScores2();
            void setTestScores3(); 
            void averageTestScores(); // a member function that returns the average of the test scores.

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~TestScores(){}
            
};

/*
//*****************************************************
Starting Out With C++ Chapter 13 Introduction to Classes - 6. Inventory Class
Design an Inventory class that can hold information and calculate data for items in a retail store’s inventory. 
The class should have the following private member variables:

itemNumber An int that holds the item’s item number.
quantity An int for holding the quantity of the items on hand.
cost A double for holding the wholesale per-unit cost of the item
totalCost A double for holding the total inventory cost of the item (calculated as quantity times cost ).

Default Constructor Sets all the member variables to 0.
Constructor #2 Accepts an item’s number, cost, and quantity as arguments.
The function should copy these values to the appropriate member variables and then call the setTotalCost function.

setItemNumber Accepts an integer argument that is copied to the itemNumber member variable.
setQuantity Accepts an integer argument that is copied to the quantity member variable.
setCost Accepts a double argument that is copied to the cost member variable.
setTotalCost Calculates the total inventory cost for the item ( quantity times cost) and stores the result in totalCost.
getItemNumber Returns the value in itemNumber.
getQuantity Returns the value in quantity.
getCost Returns the value in cost.
getTotalCost Returns the value in totalCost.
Input Validation: Do not accept negative values for item number, quantity, or cost.
//*****************************************************
*/

class Inventory
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing

        int itemNumber; // An int that holds the item’s item number.
        int quantity; // An int for holding the quantity of the items on hand.
        double cost; // double for holding the wholesale per-unit cost of the item
        double totalCost; // A double for holding the total inventory cost of the item (calculated as quantity times cost ).

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 


        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions

            Inventory() 
            { itemNumber = 0; quantity = 0; cost = 0.00; totalCost = 0.00; }

            Inventory(int &iN, int &q, double &c);

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            void getItemNumber() const; // Returns the value in itemNumber.
            void getQuantity() const; // Returns the value in quantity.
            void getCost() const; // Returns the value in cost.
            void getTotalCost() const; // Returns the value in totalCost.

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            void setItemNumber(int &iN); // Accepts an integer argument that is copied to the itemNumber member variable.
            void setQuantity(int &q); // Accepts an integer argument that is copied to the quantity member variable.
            void setCost(double &c); // Accepts a double argument that is copied to the cost member variable.
            void setTotalCost(); // Calculates the total inventory cost for the item ( quantity times cost) and stores the result in totalCost.

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Inventory(){}
            
};

/*
//*****************************************************
Starting Out With C++ Chapter 13 Introduction to Classes - 5. Retail Item Class
Write a class named RetailItem that holds data about an item in a retail store. 

The class should have the following member variables:
• description . A string that holds a brief description of the item.
• unitsOnHand . An int that holds the number of units currently in inventory.
• price . A double that holds the item’s retail price.

Write a constructor that accepts arguments for each member variable, 
appropriate mutator functions that store values in these member variables, 
and accessor functions.
that return the values in these member variables. 
//*****************************************************
*/

class RetailItem
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing

        std::string description; // A string that holds a brief description of the item.
        int unitsOnHand; // An int that holds the number of units currently in inventory.
        double price; // A double that holds the item’s retail price.

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 


        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions

            RetailItem() 
            {   
                description = "";
                unitsOnHand = 0;
                price = 0.00;
            }

            RetailItem(std::string &d, int &uOH, double &p);

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables. 
            void getRetailItemDescription() const;
            void getRetailItemUnitsOnHand() const;
            void getRetailItemPrice() const;

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            void setRetailItemDescription(std::string &d);
            void setRetailItemUnitsOnHand(int &uOH);
            void setRetailItemPrice(double &p);

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~RetailItem(){}
            
};

/*
//*****************************************************
Starting Out With C++ Chapter 13 Introduction to Classes - 4. Personal Information Class

Design a class that holds the following personal data: name, address, age, and phone number. 
Write appropriate accessor and mutator functions.
//*****************************************************
*/

class PersonalInformation
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing

        std::string name; 
        std::string address; 
        int age; 
        std::string phoneNumber;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 


        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions

            PersonalInformation() 
            {   
                name = "John Doe";
                address = "1 Arrowhead Drive";
                age = 25;
                phoneNumber = "111-111-1111";
            }

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables. 
            void getPersonalInformationName() const;
            void getPersonalInformationAddress() const;
            void getPersonalInformationAge() const;
            void getPersonalInformationPhoneNumber() const;

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            void setPersonalInformationName(std::string &n);
            void setPersonalInformationAddress(std::string &addr);
            void setPersonalInformationAge(int &a);
            void setPersonalInformationPhoneNumber(std::string &pN);

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~PersonalInformation(){}
            
};

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