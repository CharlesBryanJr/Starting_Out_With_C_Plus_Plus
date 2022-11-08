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

#include "Chapter13IntroToClasses.h"

enum MonthsOfYear{January, February, March, April, May, June, July, August, September, October, November, December};

int inputValidation_postiveInteger(int &integer);
int inputValidation_postiveInteger(int *integer);
double inputValidation_postiveDouble(double &decimal);
double inputValidation_postiveInteger_array(double postiveInteger_array[], const int &ele);
int inputValidation_postiveInteger_array2D(int MonkeyBusiness[][5], const int row_ele, const int column_ele);

//*****************************************************
// Definition of Payroll Class's costructor. 
//*****************************************************

Payroll::Payroll()
{
    hourlyPayRate = 1; 
    numberOfHoursWorked = 1; 
    totalPay = hourlyPayRate * numberOfHoursWorked;
}

//*****************************************************
// Definition of the Payroll class's accessor functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void Payroll::getPayrollValues() // • Retrieve a number from any element of the array
{
    std::cout << "***----getPayrollValues----***" << "\n"; std::cout << " " << "\n";

    std::cout << "hourlyPayRate: " << hourlyPayRate << "\n";
    std::cout << "numberOfHoursWorked: " << numberOfHoursWorked << "\n";
    std::cout << "totalPay: " << totalPay << "\n";
    std::cout << " " << "\n";
}

//*****************************************************
// Definition of the Payroll class's mutator functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void Payroll::setTotalPay(int &HPR, int &NOHW)
{
    std::cout << "***----setTotalPay----***" << "\n"; std::cout << " " << "\n";

    while(HPR<1)
    {
        std::cout << "Input validation: hourlyPayRate can not be less than 1." << "\n";
        std::cout << "Input the hourlyPayRate : ";
            std::cin >> HPR;
        std::cout << " " << "\n";
    }
    hourlyPayRate = HPR;

    while(NOHW<0 || NOHW >60)
    {
        std::cout << "Input validation: numberOfHoursWorked can not be less than 1 or greater than 60." << "\n";
        std::cout << "Input the numberOfHoursWorked : ";
            std::cin >> NOHW;
        std::cout << " " << "\n";
    }
    numberOfHoursWorked = NOHW;

    totalPay = hourlyPayRate * numberOfHoursWorked;
    std::cout << " " << "\n";
}

//*****************************************************
// Definition of NumberArray Class's costructor. 
//*****************************************************

NumberArray::NumberArray() 
{
    sizeOF_floatArray = 100;
    floatArray = new float[sizeOF_floatArray];

    for(int index{0}; index<sizeOF_floatArray; ++index)
    {
        *(floatArray+index) = 1.1+index;
    }
}

NumberArray::NumberArray(int &sizeOfArray) // The constructor should accept an integer argument and dynamically allocate the array to hold that many numbers. 
{
    sizeOF_floatArray = sizeOfArray;
    floatArray = new float[sizeOF_floatArray];

    for(int index{0}; index<sizeOF_floatArray; ++index)
    {
        *(floatArray+index) = 1.1+index;
    }
}

//*****************************************************
// Definition of the NumberArray class's accessor functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void NumberArray::getArrayValue(int &index) // • Retrieve a number from any element of the array
{
    std::cout << "***----getArrayValue----***" << "\n"; std::cout << " " << "\n";

    std::cout << "The value stored in the array at index " << index << ", is : " << *(floatArray+index) << "\n";
    std::cout << " " << "\n";
}

void NumberArray::getArrayValues() // • Retrieve all the values in the array
{
    std::cout << "***----getArrayValues----***" << "\n"; std::cout << " " << "\n";

    for(int index{0}; index<sizeOF_floatArray; ++index)
    {
        std::cout << "Index " << index << ", value : " << *(floatArray+index) << "\n";
    }
    std::cout << " " << "\n";
}

void NumberArray::getArrayHighestValue() // • Return the highest value stored in the array
{
    std::cout << "***----getArrayHighestValue----***" << "\n"; std::cout << " " << "\n";

    highestValue = *(floatArray+0); // set highestValue to first element of the array
    
    for(int index{0}; index<sizeOF_floatArray; ++index)
    {
        if( *(floatArray+index) > highestValue ) // if we find a higher value
        {
            highestValue = *(floatArray+index); // update highestValue
        }
    }

    std::cout << "The highestValue stored in the array is : " << highestValue << "\n";
    std::cout << " " << "\n";
}

void NumberArray::getArrayLowestValue() // • Return the lowest value stored in the array
{
    std::cout << "***----getArrayLowestValue----***" << "\n"; std::cout << " " << "\n";

    lowestValue = *(floatArray+0); // set lowestValue to first element of the array
    
    for(int index{0}; index<sizeOF_floatArray; ++index)
    {
        if( *(floatArray+index) < lowestValue ) // if we find a lower value
        {
            lowestValue = *(floatArray+index); // update lowestValue
        }
    }

    std::cout << "The lowestValue stored in the array is : " << lowestValue << "\n";
    std::cout << " " << "\n";
}

void NumberArray::getArrayAverageValue() // • Return the average of all the numbers stored in the array
{
    std::cout << "***----getArrayAverageValue----***" << "\n"; std::cout << " " << "\n";

    sumValues = 0; // reset counter
    
    for(int index{0}; index<sizeOF_floatArray; ++index)
    {
        sumValues += *(floatArray+index);
    }

    averageValue = sumValues / sizeOF_floatArray;

    std::cout << "The averageValue stored in the array is : " << averageValue << "\n";
    std::cout << " " << "\n";
}

//*****************************************************
// Definition of the NumberArray class's mutator functions. 
// These functions return and display the values in these member variables.
// Update other member variables if needed.
//*****************************************************

void NumberArray::setArrayValue(int &index, float &value) // • Store a number in any element of the array
{
    std::cout << "***----setArrayValue----***" << "\n"; std::cout << " " << "\n";
    
    while(index < 0 || index>sizeOF_floatArray ) 
    {
        std::cout << "Input validation, for this array, the boundaries are : 0-" << (sizeOF_floatArray-1) << "\n";
        std::cout << "Input a valid index to store a value in : ";
            std::cin >> index;
    }

    *(floatArray+index) = value;

    std::cout << "Update made, here is the new value stored at index " << index << ", : " << *(floatArray+index) << "\n";
    std::cout << " " << "\n";

    getArrayLowestValue();
    getArrayHighestValue();
    getArrayAverageValue();
    std::cout << " " << "\n";
}

//*****************************************************
// Definition of Population Class's costructor. 
//*****************************************************

Population::Population()
{
    population = 1; 
    numberOfBirths = 0; 
    numberOfDeaths = 0; 
    birthRate = 100 * (numberOfBirths / population);
    deathRate = 100 * (numberOfDeaths / population);
}

Population::Population(double &p, double &nob, double &nod)
{
    while(p<1)
    {
        std::cout << "Input validation: population can not be less than 1." << "\n";
        std::cout << "Input the population : ";
            std::cin >> p;
        std::cout << " " << "\n";
    }
    population = p;

    while(nob<0)
    {
        std::cout << "Input validation: numberOfBirths can not be negative." << "\n";
        std::cout << "Input the numberOfBirths : ";
            std::cin >> nob;
        std::cout << " " << "\n";
    }
    numberOfBirths = nob;

    while(nod<0)
    {
        std::cout << "Input validation: numberOfDeaths can not be negative." << "\n";
        std::cout << "Input the numberOfDeaths : ";
            std::cin >> nod;
        std::cout << " " << "\n";
    }
    numberOfDeaths = nod;

    birthRate = 100 * (numberOfBirths / population);
    deathRate = 100 * (numberOfDeaths / population);
}

//*****************************************************
// Definition of the Population class's accessor functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void Population::getPopulation() const
{
    std::cout << "***----getPopulation----***" << "\n"; std::cout << " " << "\n";
    std::cout << "population: " << population << "\n";
    std::cout << " " << "\n";
}

void Population::getBirthRate() const
{
    std::cout << "***----getBirthRate----***" << "\n"; std::cout << " " << "\n";
    std::cout << "Given the numberOfBirths, " << numberOfBirths << ", and population, " << population << "\n";
    std::cout << "The Birth Rate is : " << birthRate << "%" << "\n";
    std::cout << " " << "\n";
}

void Population::getDeathRate() const
{
    std::cout << "***----getDeathRate----***" << "\n"; std::cout << " " << "\n";
    std::cout << "Given the numberOfDeaths, " << numberOfDeaths << ", and population, " << population << "\n";
    std::cout << "The Death Rate is : " << deathRate << "%" << "\n";
    std::cout << " " << "\n";
}

//*****************************************************
// Definition of the Population class's mutator functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void Population::setPopulation(double &p)
{
    std::cout << "***----setPopulation----***" << "\n"; std::cout << " " << "\n";
    while(p<1)
    {
        std::cout << "Input validation: population can not be less than 1." << "\n";
        std::cout << "Input the population : ";
            std::cin >> p;
        std::cout << " " << "\n";
    }
    population = p;
    birthRate = 100 *(numberOfBirths / population);
    deathRate = 100 *(numberOfDeaths / population);
    std::cout << " " << "\n";
}

void Population::setNumberOfBirths(double &nob)
{
    std::cout << "***----setNumberOfBirths----***" << "\n"; std::cout << " " << "\n";
    while(nob<0)
    {
        std::cout << "Input validation: numberOfBirths can not be negative." << "\n";
        std::cout << "Input the numberOfBirths : ";
            std::cin >> nob;
        std::cout << " " << "\n";
    }
    numberOfBirths = nob;
    birthRate = 100 * (numberOfBirths / population);
    std::cout << " " << "\n";
}

void Population::setNumberOfDeaths(double &nod)
{
    std::cout << "***----setNumberOfDeaths----***" << "\n"; std::cout << " " << "\n";
    while(nod<0)
    {
        std::cout << "Input validation: numberOfDeaths can not be negative." << "\n";
        std::cout << "Input the numberOfDeaths : ";
            std::cin >> nod;
        std::cout << " " << "\n";
    }
    numberOfDeaths = nod;
    deathRate = 100 *(numberOfDeaths / population);
    std::cout << " " << "\n";
}

//*****************************************************
// Definition of Circle Class's costructor. 
//*****************************************************

Circle::Circle(double &r)
{
    PI = 3.14159;
    while(r<0)
    {
        std::cout << "Input validation: radius can not be negative." << "\n";
        std::cout << "Input the radius : ";
            std::cin >> r;
        std::cout << " " << "\n";
    }
    radius = r;
}

//*****************************************************
// Definition of the Circle class's accessor functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void Circle::getRadius() const
{
    std::cout << "***----getRadius----***" << "\n"; std::cout << " " << "\n";
    std::cout << "Radius : " << radius << "\n";
    std::cout << " " << "\n";
}

void Circle::getArea() const
{
    std::cout << "***----getArea----***" << "\n"; std::cout << " " << "\n";
    std::cout << "Area : " << (PI * radius * radius) << "\n";
    std::cout << " " << "\n";
}

void Circle::getDiameter() const
{
    std::cout << "***----getDiameter----***" << "\n"; std::cout << " " << "\n";
    std::cout << "Diameter : " << (2 * radius) << "\n";
    std::cout << " " << "\n";
}

void Circle::getCircumference() const
{
    std::cout << "***----getCircumference----***" << "\n"; std::cout << " " << "\n";
    std::cout << "Circumference : " << (2 * PI * radius) << "\n";
    std::cout << " " << "\n";
}

//*****************************************************
// Definition of the Circle class's mutator functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void Circle::setRadius(double &r)
{
    std::cout << "***----setRadius----***" << "\n"; std::cout << " " << "\n";

    while(r<0)
    {
        std::cout << "Input validation: radius can not be negative." << "\n";
        std::cout << "Input the radius : ";
            std::cin >> r;
        std::cout << " " << "\n";
    }
    radius = r;
}

//*****************************************************
// Definition of TestScores Class's costructor. 
//*****************************************************

TestScores::TestScores(int &ts1, int &ts2, int &ts3)
{ 
    while(ts1 <0 || ts1 >100 )
    {
        std::cout << "Do not accept values less than 0 or greater than 100 for test scores." << "\n";
        std::cout << "Input the score for test 1 : ";
            std::cin >> ts1;
        std::cout << " " << "\n";
    }
    testScore1 = ts1;

    while(ts2 <0 || ts2 >100 )
    {
        std::cout << "Do not accept values less than 0 or greater than 100 for test scores." << "\n";
        std::cout << "Input the score for test 2 : ";
            std::cin >> ts2;
        std::cout << " " << "\n";
    }
    testScore2 = ts2;

    while(ts3 <0 || ts3 >100 )
    {
        std::cout << "Do not accept values less than 0 or greater than 100 for test scores." << "\n";
        std::cout << "Input the score for test 3 : ";
            std::cin >> ts3;
        std::cout << " " << "\n";
    }
    testScore3 = ts3;

    averageTestScores();
}

//*****************************************************
// Definition of the TestScores class's accessor functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void TestScores::getTestScores1() const 
{
    std::cout << "***----getTestScores1----***" << "\n"; std::cout << " " << "\n";
    std::cout << "TestScores1: " << testScore1 << "\n";
    std::cout << " " << "\n";
}

void TestScores::getTestScores2() const 
{
    std::cout << "***----getTestScores2----***" << "\n"; std::cout << " " << "\n";
    std::cout << "TestScores2: " << testScore2 << "\n";
    std::cout << " " << "\n";
}

void TestScores::getTestScores3() const 
{
    std::cout << "***----getTestScores3----***" << "\n"; std::cout << " " << "\n";
    std::cout << "TestScores3: " << testScore3 << "\n";
    std::cout << " " << "\n";
}

//*****************************************************
// Definition of the TestScores class's mutator functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void TestScores::setTestScores1() 
{
    std::cout << "***----setTestScores1----***" << "\n"; std::cout << " " << "\n";

    std::cout << "Input the score for test 1 : ";
        std::cin >> testScore1;

    while(testScore1 <0 || testScore1 >100 )
    {
        std::cout << "Do not accept values less than 0 or greater than 100 for test scores." << "\n";
        std::cout << "Input the score for test 1 : ";
            std::cin >> testScore1;
        std::cout << " " << "\n";
    }

    averageTestScores();
}

void TestScores::setTestScores2() 
{
    std::cout << "***----setTestScores2----***" << "\n"; std::cout << " " << "\n";

    std::cout << "Input the score for test 2 : ";
        std::cin >> testScore2;

    while(testScore2 <0 || testScore2 >100 )
    {
        std::cout << "Do not accept values less than 0 or greater than 100 for test scores." << "\n";
        std::cout << "Input the score for test 2 : ";
            std::cin >> testScore2;
        std::cout << " " << "\n";
    }

    averageTestScores();
}

void TestScores::setTestScores3() 
{
    std::cout << "***----setTestScores3----***" << "\n"; std::cout << " " << "\n";

    std::cout << "Input the score for test 3 : ";
        std::cin >> testScore3;

    while(testScore3 <0 || testScore3 >100 )
    {
        std::cout << "Do not accept values less than 0 or greater than 100 for test scores." << "\n";
        std::cout << "Input the score for test 3 : ";
            std::cin >> testScore3;
        std::cout << " " << "\n";
    }

    averageTestScores();
}

void TestScores::averageTestScores() // a member function that returns the average of the test scores.
{
    std::cout << "***----averageTestScores----***" << "\n"; std::cout << " " << "\n";
    averageTestScore = (testScore1 + testScore2 + testScore3 ) * 0.333333333333;
    std::cout << "Test Score Average : " << averageTestScore << "\n";
}

//*****************************************************
// Definition of Inventory Class's costructor. 
//*****************************************************

Inventory::Inventory(int &iN, int &q, double &c)
{ 
    while(iN <0)
    {
        std::cout << "Do not accept negative values for item number, quantity, or cost." << "\n";
        std::cout << "Input the item Number : ";
            std::cin >> iN;
        std::cout << " " << "\n";
    }
    itemNumber = iN;

    while(q <0)
    {
        std::cout << "Do not accept negative values for item number, quantity, or cost." << "\n";
        std::cout << "Input the quantity : ";
            std::cin >> q;
        std::cout << " " << "\n";
    }
    quantity = q;

    while(c <0)
    {
        std::cout << "Do not accept negative values for item number, quantity, or cost." << "\n";
        std::cout << "Input the cost : ";
            std::cin >> c;
        std::cout << " " << "\n";
    }
    cost = c;

    setTotalCost();
}

//*****************************************************
// Definition of the Inventory class's accessor functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void Inventory::getItemNumber() const // Returns the value in itemNumber.
{
    std::cout << "***----getItemNumber----***" << "\n"; std::cout << " " << "\n";
    std::cout << "itemNumber: " << itemNumber << "\n";
    std::cout << " " << "\n";
}

void Inventory::getQuantity() const // Returns the value in quantity.
{
    std::cout << "***----getQuantity----***" << "\n"; std::cout << " " << "\n";
    std::cout << "quantity: " << quantity << "\n";
    std::cout << " " << "\n";
}

void Inventory::getCost() const // Returns the value in cost.
{
    std::cout << "***----getCost----***" << "\n"; std::cout << " " << "\n";
    std::cout << "cost: " << cost << "\n";
    std::cout << " " << "\n";
}

void Inventory::getTotalCost() const // Returns the value in totalCost.
{
    std::cout << "***----getTotalCost----***" << "\n"; std::cout << " " << "\n";
    std::cout << "Total Cost: " << totalCost << "\n";
    std::cout << " " << "\n";
}

//*****************************************************
// Definition of the RetailItem class's mutator functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void Inventory::setItemNumber(int &iN) // Accepts an integer argument that is copied to the itemNumber member variable.
{
    std::cout << "***----setItemNumber----***" << "\n"; std::cout << " " << "\n";
    while(iN <0)
    {
        std::cout << "Do not accept negative values for item number, quantity, or cost." << "\n";
        std::cout << "Input the item Number : ";
            std::cin >> iN;
        std::cout << " " << "\n";
    }
    itemNumber = iN;
}

void Inventory::setQuantity(int &q) // Accepts an integer argument that is copied to the quantity member variable.
{
    std::cout << "***----setQuantity----***" << "\n"; std::cout << " " << "\n";
    while(q <0)
    {
        std::cout << "Do not accept negative values for item number, quantity, or cost." << "\n";
        std::cout << "Input the quantity : ";
            std::cin >> q;
        std::cout << " " << "\n";
    }
    quantity = q;
}

void Inventory::setCost(double &c) // Accepts a double argument that is copied to the cost member variable.
{
    std::cout << "***----setCost----***" << "\n"; std::cout << " " << "\n";
    while(c <0)
    {
        std::cout << "Do not accept negative values for item number, quantity, or cost." << "\n";
        std::cout << "Input the cost : ";
            std::cin >> c;
        std::cout << " " << "\n";
    }
    cost = c;
}

void Inventory::setTotalCost() // Calculates the total inventory cost for the item ( quantity times cost) and stores the result in totalCost.
{
    std::cout << "***----setTotalCost----***" << "\n"; std::cout << " " << "\n";
    totalCost = quantity * cost;
}

//*****************************************************
// Definition of RetailItem Class's costructor. 
//*****************************************************

RetailItem::RetailItem(std::string &d, int &uOH, double &p)
{   
    description = d;

    while(uOH <0)
    {
        std::cout << "Input validation: units currently in inventory can not be negative." << "\n";
        std::cout << "For the " << d << ", input the Units on Hand : ";
            std::cin >> uOH;
        std::cout << " " << "\n";
    }
        unitsOnHand = uOH;

    while(p <0)
    {
        std::cout << "Input validation: price can not be negative." << "\n";
        std::cout << "For the " << d << ", input the price : ";
            std::cin >> p;
        std::cout << " " << "\n";
    }
        price = p;
}

//*****************************************************
// Definition of the RetailItem class's accessor functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void RetailItem::getRetailItemDescription() const
{
    std::cout << "***----getRetailItemDescription----***" << "\n"; std::cout << " " << "\n";

    std::cout << "Description: " << description << "\n";
    std::cout << " " << "\n";
}

void RetailItem::getRetailItemUnitsOnHand() const
{
    std::cout << "***----getRetailItemUnitsOnHand----***" << "\n"; std::cout << " " << "\n";

    std::cout << "Units On Hand: " << unitsOnHand << "\n";
    std::cout << " " << "\n";
}

void RetailItem::getRetailItemPrice() const
{
    std::cout << "***----getRetailItemPrice----***" << "\n"; std::cout << " " << "\n";

    std::cout << "Price: " << price << "\n";
    std::cout << " " << "\n";
}

//*****************************************************
// Definition of the RetailItem class's mutator functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void RetailItem::setRetailItemDescription(std::string &d)
{
    std::cout << "***----setRetailItemDescription----***" << "\n"; std::cout << " " << "\n";
    description = d;
}

void RetailItem::setRetailItemUnitsOnHand(int &uOH)
{
    std::cout << "***----setRetailItemUnitsOnHand----***" << "\n"; std::cout << " " << "\n";
    while(uOH <0)
    {
        std::cout << "Input validation: units currently in inventory can not be negative." << "\n";
        std::cout << "For the " << description << ", input the Units on Hand : ";
            std::cin >> uOH;
        std::cout << " " << "\n";
    }
        unitsOnHand = uOH;
}

void RetailItem::setRetailItemPrice(double &p)
{
    std::cout << "***----setRetailItemPrice----***" << "\n"; std::cout << " " << "\n";
    while(p <0)
    {
        std::cout << "Input validation: price can not be negative." << "\n";
        std::cout << "For the " << description << ", input the price : ";
            std::cin >> p;
        std::cout << " " << "\n";
    }
        price = p;
}

//*****************************************************
// Definition of the Personal Information  class's accessor functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void PersonalInformation::getPersonalInformationName() const
{
    std::cout << "***----getPersonalInformationName----***" << "\n"; std::cout << " " << "\n";

    std::cout << "Name: " << name << "\n";
    std::cout << " " << "\n";
}

void PersonalInformation::getPersonalInformationAddress() const
{
    std::cout << "***----getPersonalInformationAddress----***" << "\n"; std::cout << " " << "\n";

    std::cout << "Address: " << address << "\n";
    std::cout << " " << "\n";
}

void PersonalInformation::getPersonalInformationAge() const
{
    std::cout << "***----getPersonalInformationAge----***" << "\n"; std::cout << " " << "\n";

    std::cout << "Age: " << age << "\n";
    std::cout << " " << "\n";
}

void PersonalInformation::getPersonalInformationPhoneNumber() const
{
    std::cout << "***----getPersonalInformationPhoneNumber----***" << "\n"; std::cout << " " << "\n";

    std::cout << "Phone Number: " << phoneNumber << "\n";
    std::cout << " " << "\n";
}

//*****************************************************
// Definition of the Personal Information class's mutator functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void PersonalInformation::setPersonalInformationName(std::string &n)
{
    std::cout << "***----setPersonalInformationName----***" << "\n"; std::cout << " " << "\n";
    name = n;
}

void PersonalInformation::setPersonalInformationAddress(std::string &addr)
{
    std::cout << "***----setPersonalInformationAddress----***" << "\n"; std::cout << " " << "\n";
    address = addr;
}

void PersonalInformation::setPersonalInformationAge(int &a)
{
    std::cout << "***----setPersonalInformationAge----***" << "\n"; std::cout << " " << "\n";
    age = a;
}

void PersonalInformation::setPersonalInformationPhoneNumber(std::string &pN)
{
    std::cout << "***----setPersonalInformationPhoneNumber----***" << "\n"; std::cout << " " << "\n";
    phoneNumber = pN;
}

//*****************************************************
// Definition of the Car class's accessor functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void Car::getCarYearModel() const
{
    std::cout << "***----getCarYearModel----***" << "\n"; std::cout << " " << "\n";

    std::cout << "The Car's year model is : " << yearModel << "\n";
    std::cout << " " << "\n";
}

void Car::getCarMake() const
{
    std::cout << "***----getCarMake----***" << "\n"; std::cout << " " << "\n";

    std::cout << "The Car's make is : " << make << "\n";
    std::cout << " " << "\n";
}

void Car::getCarSpeed() const
{
    std::cout << "***----getCarSpeed----***" << "\n"; std::cout << " " << "\n";

    std::cout << "The Car's speed is : " << speed << "\n";
    std::cout << " " << "\n";
}

//*****************************************************
// Definition of the Car class's mutator functions. 
// These functions store values in these member variables 
//*****************************************************

void Car::accelerateCar()
{
    std::cout << "***----accelerateCar----***" << "\n"; std::cout << " " << "\n";
    speed += 5;
}

void Car::brakeCar()
{
    std::cout << "***----brakeCar----***" << "\n"; std::cout << " " << "\n";
    speed -= 5;
}

//*****************************************************
// Definition of the Employee class's accessor functions. 
// These functions return and display the values in these member variables.
//*****************************************************

void Employee::getEmployeeName() const
{
    std::cout << "***----getEmployeeName----***" << "\n"; std::cout << " " << "\n";

    std::cout << "The Employee's name is : " << name << "\n";
    std::cout << " " << "\n";
}

void Employee::getEmployeeID() const
{
    std::cout << "***----getEmployeeID----***" << "\n"; std::cout << " " << "\n";

    std::cout << "The Employee's ID Number is : " << idNumber << "\n";
    std::cout << " " << "\n";
}

void Employee::getEmployeeDepartment() const
{
    std::cout << "***----getEmployeeDepartment----***" << "\n"; std::cout << " " << "\n";

    std::cout << "The Employee's department is : " << department << "\n";
    std::cout << " " << "\n";
}

void Employee::getEmployeePosition() const
{
    std::cout << "***----getEmployeePosition----***" << "\n"; std::cout << " " << "\n";

    std::cout << "The Employee's position is : " << position << "\n";
    std::cout << " " << "\n";
}

//*****************************************************
// Definition of the Employee class's mutator functions. 
// These functions store values in these member variables 
//*****************************************************

void Employee::setEmployeeName(std::string &n)
{
    std::cout << "***----setEmployeeName----***" << "\n"; std::cout << " " << "\n";
    name = n;
}

void Employee::setEmployeeID(int &id)
{
    std::cout << "***----setEmployeeID----***" << "\n"; std::cout << " " << "\n";
    idNumber = id;
}

void Employee::setEmployeeDepartment(std::string &dep)
{
    std::cout << "***----setEmployeeDepartment----***" << "\n"; std::cout << " " << "\n";
    department = dep;
}

void Employee::setEmployeePosition(std::string &pos)
{
    std::cout << "***----setEmployeePosition----***" << "\n"; std::cout << " " << "\n";
    position = pos;
}

//*****************************************************
// Definition of setMonthDayYear overloaded functions. 
// These functions set the month day and year respectively based on the amount of arguments passed. 
//*****************************************************
        
void Date::setMonthDayYear(int &month, int &day, int &year)
{ 
    month = 01; 
    day = 01; 
    year = 0001; 
}
        
void Date::setMonthDayYear(int &month, int &day, int &year, int &m)
{ 
    while(m < 1 || m > 12)
    {
        std::cout << "Input Validation: Do not accept values for the month greater than 12 or less than 1." << '\n';
        std::cout << "Input a new value for the month : ";
            std::cin >> m;
    }
    month = m;
    day = 01; 
    year = 0001; 
}

void Date::setMonthDayYear(int &month, int &day, int &year, int &m, int &d)
{ 
    while(m < 1 || m > 12)
    {
        std::cout << "Input Validation: Do not accept values for the month greater than 12 or less than 1." << '\n';
        std::cout << "Input a new value for the month : ";
            std::cin >> m;
    }
    month = m; 

    while(d < 1 || d > 31)
    {
        std::cout << "Input Validation: Do not accept values for the day greater than 31 or less than 1." << '\n';
        std::cout << "Input a new value for the day : ";
            std::cin >> d;
    }
    day = d; 

    year = 0001; 
}

void Date::setMonthDayYear(int &month, int &day, int &year, int &m, int &d, int &y)
{ 
    while(m < 1 || m > 12)
    {
        std::cout << "Input Validation: Do not accept values for the month greater than 12 or less than 1." << '\n';
        std::cout << "Input a new value for the month : ";
            std::cin >> m;
    }
    month = m; 

    while(d < 1 || d > 31)
    {
        std::cout << "Input Validation: Do not accept values for the day greater than 31 or less than 1." << '\n';
        std::cout << "Input a new value for the day : ";
            std::cin >> d;
    }
    day = d; 

    year = y; 
}

//*****************************************************
// Definition of Date Class's overloaded costructors. 
// These costructors set the month, day and year based on arugments passed.
//*****************************************************
Date::Date()
{ setMonthDayYear(month, day, year); }
        
Date::Date(int &m)
{ setMonthDayYear(month, day, year, m); }

Date::Date(int &m, int &d)
{ setMonthDayYear(month, day, year, m, d); }

Date::Date(int &m, int &d, int &y)
{ setMonthDayYear(month, day, year, m, d, y); }

//*****************************************************
// Definition of getDateFormat1 fucntions. 
// These functions display the date in different formats 
//*****************************************************

void Date::getDateFormat1(const int &month, const int &day, const int &year) const // retrieves the data in this format 12/25/2014
{
    std::cout << "***----getDateFormat1----***" << "\n"; std::cout << " " << "\n";

    std::cout << "DateFormat1 : " << month << '/' << day << '/' << year << "\n";
} 

void Date::getDateFormat2(const int &month, const int &day, const int &year) const // retrieves the data in this format December 25, 2014
{
    std::cout << "***----getDateFormat2----***" << "\n"; std::cout << " " << "\n";

    std::cout << "DateFormat2 : ";

    switch (month-1)
    {
        case January:
            std::cout << "January";
            break;
        case February:
            std::cout << "February";
            break;
        case March:
            std::cout << "March";
            break;
        case April:
            std::cout << "April";
            break;
        case May:
            std::cout << "May";
            break;
        case June:
            std::cout << "June";
            break;
        case July:
            std::cout << "July";
            break;
        case August:
            std::cout << "August";
            break;
        case September:
            std::cout << "September";
            break;
        case October:
            std::cout << "October";
            break;
        case November:
            std::cout << "November";
            break;
        case December:
            std::cout << "December";
            break;
        
        default:
            break;
    }

    std::cout << " " << day << ", " << year << "\n";
}

void Date::getDateFormat3(const int &month, const int &day, const int &year) const // retrieves the data in this format 25 December 2014
{
    std::cout << "***----getDateFormat3----***" << "\n"; std::cout << " " << "\n";

    std::cout << "DateFormat3 : " << day << " ";

    switch (month-1)
    {
        case January:
            std::cout << "January";
            break;
        case February:
            std::cout << "February";
            break;
        case March:
            std::cout << "March";
            break;
        case April:
            std::cout << "April";
            break;
        case May:
            std::cout << "May";
            break;
        case June:
            std::cout << "June";
            break;
        case July:
            std::cout << "July";
            break;
        case August:
            std::cout << "August";
            break;
        case September:
            std::cout << "September";
            break;
        case October:
            std::cout << "October";
            break;
        case November:
            std::cout << "November";
            break;
        case December:
            std::cout << "December";
            break;
        
        default:
            break;
    }

    std::cout << " " << year << " " << "\n";
}

//*****************************************************
// Definition of set date fucntions
// These function update one specfic member varible of the Date class
//*****************************************************

void Date::setMonth(int &month, int &m) // updates the month member variable 
{
    std::cout << "***----setMonth----***" << "\n"; std::cout << " " << "\n";
    
    while(m < 1 || m > 12)
    {
        std::cout << "Input Validation: Do not accept values for the month greater than 12 or less than 1." << '\n';
        std::cout << "Input a new value for the month : ";
            std::cin >> m;
    }

    month = m;
}

void Date::setDay(int &day, int &d) // updates the month member variable 
{
    std::cout << "***----setDay----***" << "\n"; std::cout << " " << "\n";

    while(d < 1 || d > 31)
    {
        std::cout << "Input Validation: Do not accept values for the day greater than 31 or less than 1." << '\n';
        std::cout << "Input a new value for the day : ";
            std::cin >> d;
    }
    day = d; 
}

void Date::setYear(int &year, int &y) // updates the month member variable 
{
    std::cout << "***----setYear----***" << "\n"; std::cout << " " << "\n";

    year = y;
}

//*****************************************************
// Definition of function displayProgramMenu. 
// This function displays the program's menu on the screen. 
//*****************************************************

void displayProgramMenu()
{
    std::cout << "***----displayProgramMenu----***" << "\n"; std::cout << " " << "\n";

    std::cout << "User, choice a program to run." << "\n";
        std::cout << "A) Starting Out With C++ Chapter 11 Structured Data - 1. Date" << "\n";
        std::cout << "B) Starting Out With C++ Chapter 11 Structured Data - 2. Employee Class" << "\n";
        std::cout << "C) Starting Out With C++ Chapter 13 Introduction to Classes - 3. Car Class" << "\n";
        std::cout << "D)  Starting Out With C++ Chapter 13 Introduction to Classes - 4. Personal Information Class" << "\n";
        std::cout << "E) --- EXIT ---" << "\n";
        std::cout << "F) Starting Out With C++ Chapter 13 Introduction to Classes - 5. Retail Item Class" << "\n";
        std::cout << "G) Starting Out With C++ Chapter 13 Introduction to Classes - 6. Inventory Class" << "\n";
        std::cout << "H) Starting Out With C++ Chapter 13 Introduction to Classes - 7. TestScores Class " << "\n";
        std::cout << "I) Starting Out With C++ Chapter 13 Introduction to Classes - 8. Circle Class " << "\n";
        std::cout << "J) Starting Out With C++ Chapter 13 Introduction to Classes - 9. Population " << "\n";
        std::cout << "K) Starting Out With C++ Chapter 13 Introduction to Classes - 10. Number Array Class " << "\n";
        std::cout << "L) Starting Out With C++ Chapter 13 Introduction to Classes - 11. Payroll" << "\n";
        //std::cout << "M) " << "\n";
        //std::cout << "N) " << "\n";
        //std::cout << "O) " << "\n";
        //std::cout << "P) " << "\n";
}

//*****************************************************
// Definition of function inputValidation functions. 
// These functions return a postive number. 
//*****************************************************

int inputValidation_postiveInteger(int &integer)
{
    std::cin >> integer;

    while( integer<0  )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "Input again : ";
            std::cin >> integer;
    }
    return integer;
}

int inputValidation_postiveInteger(int *integer)
{
    std::cin >> *integer;

    while( *integer<0  )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "Input again : ";
            std::cin >> *integer;
    }
    return *integer;
}

double inputValidation_postiveDouble(double &decimal)
{
    std::cin >> decimal;

    while( decimal<0  )
    {
        std::cin.clear();
        std::cout << "Input Validation: Do not accept negative values." << "\n";
        std::cout << "Input again : ";
            std::cin >> decimal;
    }
    return decimal;
}

double inputValidation_postiveInteger_array(double postiveInteger_array[], const int &ele)
{
	std::cin >> postiveInteger_array[ele];

    while( postiveInteger_array[ele] < 0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "Input again : ";
            std::cin >> postiveInteger_array[ele];
    }
    return postiveInteger_array[ele];
}

int inputValidation_postiveInteger_array2D(int MonkeyBusiness[][5], const int row_ele, const int column_ele)
{
    std::cin >> MonkeyBusiness[row_ele][column_ele];

    while( MonkeyBusiness[row_ele][column_ele] < 0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer" << "\n";
        std::cout << "Input again : ";
            std::cin >> MonkeyBusiness[row_ele][column_ele];
    }
    return MonkeyBusiness[row_ele][column_ele];
}

// end


//*****************************************************
// Definition of  Class's costructor. 
//*****************************************************

//*****************************************************
// Definition of the  class's accessor functions. 
// These functions return and display the values in these member variables.
//*****************************************************

//*****************************************************
// Definition of the  class's mutator functions. 
// These functions return and display the values in these member variables.
//*****************************************************