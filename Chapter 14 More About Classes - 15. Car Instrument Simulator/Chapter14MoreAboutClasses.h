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
#include <ctime>
#include <cmath>
#include <stdlib.h> 

#ifndef Chapter14MoreAboutClasses_H
#define Chapter14MoreAboutClasses_H

/*
*****************************************************
Chapter 14 More About Classes - 15. Car Instrument Simulator
For this assignment you will design a set of classes that work together to simulate a car’s fuel gauge and odometer. 
The classes you will design are:

• The FuelGauge Class: This class will simulate a fuel gauge. 
Its responsibilities are
– To know the car’s current amount of fuel, in gallons.
– To report the car’s current amount of fuel, in gallons.
– To be able to increment the amount of fuel by 1 gallon. This simulates putting fuel in the car. (The car can hold a maximum of 15 gallons.)
– To be able to decrement the amount of fuel by 1 gallon, if the amount of fuel is greater than 0 gallons. This simulates burning fuel as the car runs.

• The Odometer Class: This class will simulate the car’s odometer. 
Its responsibilities are:
– To know the car’s current mileage.
– To report the car’s current mileage.
– To be able to increment the current mileage by 1 mile. 

The maximum mileage the odometer can store is 999,999 miles. 
When this amount is exceeded, the odometer resets the current mileage to 0.
– To be able to work with a FuelGauge object. 
It should decrease the FuelGauge object’s current amount of fuel by 1 gallon for every 24 miles traveled. 
(The car’s fuel economy is 24 miles per gallon.)

Demonstrate the classes by creating instances of each. 
Simulate filling the car up with fuel, and then run a loop that increments the odometer until the car runs out of fuel.
During each loop iteration, print the car’s current mileage and amount of fuel.
*****************************************************
*/

class FuelGauge // This class will simulate a fuel gauge.
{
    private:

        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing
            int fuelAmount; // – To know the car’s current amount of fuel, in gallons.
            int maxFuelAmount; 

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
	        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
	        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            FuelGauge() // default constructor
                {
                    fuelAmount = 0;
                    maxFuelAmount = 15;
                }

                FuelGauge( int &mFuelAmount )
                {
                    fuelAmount = 0;
                    while( mFuelAmount < 1 )
                    {
                        std::cout << "Error: Max Fuel Amount must be greater than 0." << "\n";
                        std::cout << "Input Max Fuel Amount : ";
                            std::cin >> mFuelAmount;
                            std::cout << " " << "\n";
                    }
                    maxFuelAmount = mFuelAmount;
                }

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                int getFuelAmount() const { return fuelAmount; } // – To report the car’s current amount of fuel, in gallons.
                int getMaxFuelAmount() const { return maxFuelAmount; } // – To report the car’s max amount of fuel, in gallons.

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed.

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.	

                // – To be able to increment the amount of fuel by 1 gallon. This simulates putting fuel in the car. (The car can hold a maximum of 15 gallons.)
                FuelGauge& operator ++ () 
                { 
                    ++fuelAmount; 
                    if( fuelAmount > maxFuelAmount )
                    {
                        std::cout << "ERROR: The car can hold a maximum of " << maxFuelAmount << " gallons." << "\n";
                        fuelAmount = maxFuelAmount;
                        std::cout << "fuelAmount : " << fuelAmount << "\n";
                    }
                    return *this; 
                }

                FuelGauge& operator ++ ( int ) 
                { 
                    ++fuelAmount; 
                    if( fuelAmount > maxFuelAmount )
                    {
                        std::cout << "ERROR: The car can hold a maximum of " << maxFuelAmount << " gallons." << "\n";
                        fuelAmount = maxFuelAmount;
                        std::cout << "fuelAmount : " << fuelAmount << "\n";
                    }
                    return *this; 
                }

                // – To be able to decrement the amount of fuel by 1 gallon, if the amount of fuel is greater than 0 gallons. This simulates burning fuel as the car runs.
                FuelGauge& operator -- () 
                { 
                    --fuelAmount; 
                    if( fuelAmount == -1 )
                    {
                        std::cout << "ERROR: The fuel amount can not be negative." << "\n";
                        fuelAmount = 0;
                        std::cout << "fuelAmount : " << fuelAmount << "\n";
                    }
                    return *this; 
                }

                FuelGauge& operator -- ( int )
                { 
                    --fuelAmount; 
                    if( fuelAmount == -1 )
                    {
                        std::cout << "ERROR: The fuel amount can not be negative." << "\n";
                        fuelAmount = 0;
                        std::cout << "fuelAmount : " << fuelAmount << "\n";
                    }
                    return *this; 
                }

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            ~FuelGauge(){}				
            
};

class Odometer // This class will simulate the car’s odometer.
{
    private:

        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing
            int currentMileage;
            int milesPerGallon;

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
	        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
	        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            Odometer() // default constructor
                {
                    currentMileage = 0;
                    milesPerGallon = 24;
                }
                
                Odometer( int &mPerGallon ) 
                {
                    currentMileage = 0;
                    while( mPerGallon < 1 )
                    {
                        std::cout << "Error: milesPerGallon must be greater than 0." << "\n";
                        std::cout << "Input milesPerGallon : ";
                            std::cin >> mPerGallon;
                            std::cout << " " << "\n";
                    }
                    milesPerGallon = mPerGallon; 
                }

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                int getCurrentMileage() const { return currentMileage; }

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed.
                // It should decrease the FuelGauge object’s current amount of fuel by 1 gallon for every 24 miles traveled. 
                // (The car’s fuel economy is 24 miles per gallon.)
                void incrementOdometer()
                { 
                    ++currentMileage;
                    if( currentMileage == 1000000 )
                    {
                        std::cout << "Resets the current mileage to 0." << '\n';
                        currentMileage = 0;
                        std::cout << "currentMileage : " << currentMileage << '\n';
                    }
                }

                void runCar( FuelGauge &fGauge )
                {
                    int carMaxMiles;
                    carMaxMiles = fGauge.getMaxFuelAmount() * milesPerGallon;

                    for( unsigned int i{0}; i<carMaxMiles; ++i)
                    {
                        incrementOdometer();
                        std::cout << "currentMileage : " << currentMileage << "\n"; 
                        if( i % milesPerGallon == 0 )
                        {
                            --fGauge;
                        }
                        std::cout << "getFuelAmount : " << fGauge.getFuelAmount() << "\n";
                        std::cout << " " << "\n";
                    }
                }

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.	

                // The maximum mileage the odometer can store is 999,999 miles. 
                // When this amount is exceeded, the odometer resets the current mileage to 0.

                Odometer& operator ++ () 
                { 
                    ++currentMileage;
                    if( currentMileage == 1000000 )
                    {
                        std::cout << "Resets the current mileage to 0." << '\n';
                        currentMileage = 0;
                        std::cout << "currentMileage : " << currentMileage << '\n';
                    }
                    return *this; 
                }

                Odometer& operator ++ ( int ) 
                { 
                    ++currentMileage;
                    if( currentMileage == 1000000 )
                    {
                        std::cout << "Resets the current mileage to 0." << '\n';
                        currentMileage = 0;
                        std::cout << "currentMileage : " << currentMileage << '\n';
                    }
                    return *this; 
                }

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            ~Odometer(){}				
            
};

/*
*****************************************************
Chapter 14 More About Classes - 14. Parking Ticket Simulator
For this assignment you will design a set of classes that work together to simulate a police officer issuing a parking ticket. 
The classes you should design are:

• The ParkedCar Class: This class should simulate a parked car. The class’s responsibilities are:
– To know the car's make, model, color, license number, and the number of minutes that the car has been parked

• The ParkingMeter Class: This class should simulate a parking meter. 
The class’s only responsibility is:
– To know the number of minutes of parking time that has been purchased

• The ParkingTicket Class: This class should simulate a parking ticket. 
The class’s responsibilities are:
– To report the make, model, color, and license number of the illegally parked car
– To report the amount of the fine, which is $25 for the first hour or part of an hour that the car is illegally parked, plus $10 for every additional hour or part ofan hour that the car is illegally parked
– To report the name and badge number of the police officer issuing the ticket

• The PoliceOfficer Class: This class should simulate a police officer inspecting parked cars. 
The class’s responsibilities are:
– To know the police officer’s name and badge number
– To examine a ParkedCar object and a ParkingMeter object, and determine whether the car's time has expired
– To issue a parking ticket (generate a ParkingTicket object) if the car’s time has expired

Write a program that demonstrates how these classes collaborate.
*****************************************************
*/

class ParkedCar
{
    private:

        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing
            std::string carMake;
            std::string carModel;
            std::string carColor;
            int licenseNumber;
            int minutesParked;

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
            // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
            // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            ParkedCar() // default constructor
                {
                    carMake = "Honda Accord";
                    carModel = "2022";
                    carColor = "Black";
                    licenseNumber = 1;
                    minutesParked = 1;
                }

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                std::string getCarMake() const { return carMake; }
                std::string getCarModel() const { return carModel; }
                std::string getCarColor() const { return carColor; }
                int getLicenseNumber() const { return licenseNumber; }
                int getMinutesParked() const { return minutesParked; }

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed.
                void setCarMake( std::string &cMake ){ carMake = cMake; }
                void setCarModel( std::string &cModel ){ carModel = cModel; }
                void setCarColor( std::string &cColor ){ carColor = cColor; }
                void setLicenseNumber( int &lNumber ){ licenseNumber = lNumber; }
                void setMinutesParked( int &mParked )
                {
                    while( mParked < 1 )
                    {
                        std::cout << "Input Validation: Minutes parked can not be less than 1." << "\n";
                        std::cout << "Input Minutes Parked : ";
                            std::cin >> mParked;
                        std::cout << " " << "\n";
                    }
                    minutesParked = mParked;
                }

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            ~ParkedCar(){}				
};

class ParkingMeter
{
    private:

        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing
            int purchasedParkingTime;

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
	        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
	        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            ParkingMeter() // default constructor
                {
                    purchasedParkingTime = 1;
                }

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                int getPurchasedParkingTime() const
                { return purchasedParkingTime; }

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed.
                void setPurchasedParkingTime( int &pParkingTime )
                { 
                    while( pParkingTime < 1 )
                    {
                        std::cout << "Input Validation: Purchased parking time can not be less than 1." << "\n";
                        std::cout << "Input Purchased Parking Time : ";
                            std::cin >> pParkingTime;
                        std::cout << " " << "\n";
                    }
                    purchasedParkingTime = pParkingTime; 
                }

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            ~ParkingMeter(){}				
            
};

class PoliceOfficer;

class ParkingTicket
{
    private:

        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing
            double fineAmount;

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
	        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
	        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            ParkingTicket() // default constructor
                {
                    fineAmount = 0;
                }

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                void reportIllegallyParkedCar( const ParkedCar &pCar ) const;
                void reportFineAmount( const ParkedCar &pCar, const ParkingMeter &pMeter );
                void reportPoliceOfficer( const PoliceOfficer &pOfficer ) const;

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed.
                void updateFineAmount( const ParkedCar &pCar, const ParkingMeter &pMeter );

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            ~ParkingTicket(){}				
            
};

class PoliceOfficer
{
    private:

        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing
            std::string policeOfficerName;
            int policeOfficerBadgeNumber;

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
	        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
	        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            PoliceOfficer() // default constructor
                {
                    policeOfficerName = "James Bond";
                    policeOfficerBadgeNumber = 007;
                }

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                std::string getPoliceOfficerName() const { return policeOfficerName; }
                int getPoliceOfficerBadgeNumber() const { return policeOfficerBadgeNumber; }

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed.
                void setPoliceOfficer();
                void examineParkedCar( const ParkedCar &pCar, const ParkingMeter &pMeter, ParkingTicket &pTicket );
                void issueParkedCarTicket( const ParkedCar &pCar, const ParkingMeter &pMeter, ParkingTicket &pTicket );

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            ~PoliceOfficer(){}				
            
};

/*
*****************************************************
Chapter 14 More About Classes - 10. Corporate Sales
A corporation has six divisions, each responsible for sales to different geographic locations. 
Design a DivSales class that keeps sales data for a division, with the following members:
• An array with four elements for holding four quarters of sales figures for the division.
• A private static variable for holding the total corporate sales for all divisions for the entire year.
• A member function that takes four arguments, each assumed to be the sales for a quarter. 
The value of the arguments should be copied into the array that holds the sales data. 
The total of the four arguments should be added to the static variable that holds the total yearly corporate sales.
• A function that takes an integer argument within the range of 0–3. 
The argument is to be used as a subscript into the division quarterly sales array. 
The function should return the value of the array element with that subscript.
Write a program that creates an array of six DivSales objects. 
The program should ask the user to enter the sales for four quarters for each division. 
After the data are entered, the program should display a table showing the division sales for each quarter.
The program should then display the total corporate sales for the year.
Input Validation: Only accept positive values for quarterly sales figures.
*****************************************************
*/

class DivSales
{
    private:

        // ***--- attributes or member variables ---***
            // What private data is the class responsible of storing
            double quarterlySales[4]; // • An array with four elements for holding four quarters of sales figures for the division.
            static double totalCorporateSales; // • A private static variable for holding the total corporate sales for all divisions for the entire year.

        // ***--- methods or member functions ---***
            // What private actions is the class responsible of executing 
            void subtractTotalCorporateSales();
            void addTotalCorporateSales();

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
	            // Useful for initializing private member variables or executing private member functions
	            DivSales() // default constructor
                {
                    for(unsigned i{0}; i<4; ++i)
                    {
                        quarterlySales[i] = 0;
                    }
                }

                DivSales( double &qs1, double &qs2, double &qs3, double &qs4 );

            // ***--- copy costructors ---***
	            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
				// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
	            // Write public accessor functions that return the values in the member variables.
                double getQuarterlySales( int &salesQuarter ) const { return quarterlySales[salesQuarter]; }
                double getTotalCorporateSales() const { return totalCorporateSales; }

            // ***--- mutator or setter  ---***
	            // Write public mutator functions to store values in the member variables.
	            // Update other member variables if needed.
                void setQuarterlySales( double &qs1, double &qs2, double &qs3, double &qs4 ); // • A member function that takes four arguments, each assumed to be the sales for a quarter. 

			// ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.		

			// ***--- destructors ---***
	            // Useful to free memory that was dynamically allocated by the class object
	            ~DivSales(){}				
            
};

double DivSales::totalCorporateSales = 0;

/*
*****************************************************
Chapter 14 More About Classes - 9. FeetInches Modification
Modify the FeetInches class discussed in this chapter so it overloads the following
operators:
<=
>=
!=
Demonstrate the class’s capabilities in a simple program.
class FeetInches; // Forward Declaration

std::ostream &operator << (std::ostream &, const FeetInches &);
std::istream &operator >> (std::istream &, FeetInches &);

// The FeetInches class holds distances or measurements expressed in feet and inches.
class FeetInches
{
    private:
        int feet; // To hold a number of feet
        int inches; // To hold a number of inches
        void simplify(); // Defined in FeetInches.cpp
    public:
        // Constructor
        FeetInches(int f = 0, int i = 0)
        { feet = f;
        inches = i;
        simplify(); }

        // Mutator functions
        void setFeet(int f)
        { feet = f; }

        void setInches(int i)
        { inches = i; simplify(); }

        // Accessor functions
        int getFeet() const
        { return feet; }

        int getInches() const
        { return inches; }

        // Overloaded operator functions
        FeetInches operator + (const FeetInches &); // Overloaded +
        FeetInches operator - (const FeetInches &); // Overloaded −

        // Friends
        friend std::ostream &operator << (std::ostream &, const FeetInches &);
        friend std::istream &operator >> (std::istream &, FeetInches &);
};
*****************************************************
*/


/*
*****************************************************
Chapter 14 More About Classes - 8. Date Class Modification
Modify the Date class in Programming Challenge 1 of Chapter 13 . 
The new version should have the following overloaded operators:
++ Prefix and postfix increment operators. 
These operators should increment the object's day member.
−− Prefix and postfix decrement operators. 
These operators should decrement the object's day member.
− Subtraction operator. 
If one Date object is subtracted from another, the operator should give the number of days between the two dates. 
For example, if April 10, 2014 is subtracted from April 18, 2014, the result will be 8.

<< cout’s stream insertion operator. 
This operator should cause the date to be displayed in the form April 18, 2014

>> cin’s stream extraction operator. 
This operator should prompt the user for a date to be stored in a Date object.

The class should detect the following conditions and handle them accordingly:
• When a date is set to the last day of the month and incremented, it should become the first day of the following month.
• When a date is set to December 31 and incremented, it should become January 1 of the following year.
• When a day is set to the first day of the month and decremented, it should become the last day of the previous month.
• When a date is set to January 1 and decremented, it should become December 31 of the previous year.
Demonstrate the class’s capabilities in a simple program.
Input Validation: The overloaded >> operator should not accept invalid dates. 
For example, the date 13/45/2014 should not be accepted.
*****************************************************
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
            
            // ***--- operator functions ---***
	            // redefine the way a particular operator works with an object
	            // Update other member variables if needed.	
                Date& operator ++ () { ++day; updateDay(day); return *this; };
                void operator ++ ( int ){ ++day; updateDay(day); };

                Date& operator -- (){ --day; updateDay(day); return *this; };
                void operator -- ( int ){ --day; updateDay(day); };

                int operator - ( Date &right )
                {
                    int difference;

                    if( day > right.day )
                    {
                        difference = day - right.day;
                    }
                    else // right.day > day 
                    {
                        difference = right.day - day;
                    }
                    return difference;
                }

                Date& operator << ( Date &right  )
                {
                    right.displayDateFormat2();
                    return *this;
                }

                Date& operator >> ( Date &right  )
                {
                    std::cout << "User, input day : ";
                        std::cin >> right.day;
                    std::cout << "User, input month : ";
                        std::cin >> right.month;
                    std::cout << "User, input year : ";
                        std::cin >> right.year;
                    return *this;
                }

            // --- destructors ---
            // Useful to free memory that was dynamically allocated by the class object
            ~Date(){};
};

/*
*****************************************************
// Chapter 14 More About Classes - 4. NumDays Class

Design a class called NumDays. 
The class’s purpose is to store a value that represents a number of work hours and convert it to a number of days. 
For example, 8 hours would be converted to 1 day, 12 hours would be converted to 1.5 days, and 18 hours would be converted to 2.25 days. 

The class should have a constructor that accepts a number of hours, as well as member functions for storing and retrieving the hours and days.

The class should also have the following overloaded operators:

+ Addition operator. 
When two NumDays objects are added together, the overloaded + operator should return the sum of the two objects’ hours members.

− Subtraction operator. 
When one NumDays object is subtracted from another, the overloaded − operator should return the difference of the two objects’ hours members.

++ Prefix and postfix increment operators. 
These operators should increment the number of hours stored in the object. 
When incremented, the number of days should be automatically recalculated.

−− Prefix and postfix decrement operators. 
These operators should decrement the number of hours stored in the object. 
When decremented, the number of days should be automatically recalculated.
*****************************************************
*/

class NumDays
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        int workHours;
        int workDays;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            NumDays(){ workHours = 0; updateNumberOfWorkDays(); } // default constructor

            NumDays(int &wH)
            {
                while( wH <0 )
                {
                    std::cout << "Input validation: Do not accept negative values for the number of hours worked." << "\n";
                    std::cout << "Input the work hours : ";
                        std::cin >> wH;
                    std::cout << " " << "\n";
                }
                workHours = wH;
                updateNumberOfWorkDays();
            }

            // ***--- copy costructors ---***
            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
			// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            int getNumberOfWorkHours() const { return workHours; }
            int getNumberOfWorkDays() const { return workDays; }

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void setNumberOfWorkHours(int &wH)
            { 
                while( wH <0 )
                {
                    std::cout << "Input validation: Do not accept negative values for the number of hours worked." << "\n";
                    std::cout << "Input the work hours : ";
                        std::cin >> wH;
                    std::cout << " " << "\n";
                }
                workHours = wH;  
                updateNumberOfWorkDays();
            }

            void updateNumberOfWorkDays(){ workDays = workHours / 8; }

			// ***--- operator functions ---***
            // redefine the way a particular operator works with an object
            // Update other member variables if needed.	
	
            // When two NumDays objects are added together, the overloaded + operator should return the sum of the two objects’ hours members.
            int operator + (const NumDays &right) // + Addition operator.
            {
                return workHours + right.workHours;
            }

            // When one NumDays object is subtracted from another, the overloaded − operator should return the difference of the two objects’ hours members.
            int operator - (const NumDays &right) // - Subtraction operator.
            {
                return workHours - right.workHours;
            }

            // These operators should increment the number of hours stored in the object. 
            // When incremented, the number of days should be automatically recalculated.
            NumDays& operator ++ () // ++ Prefix increment operators.
            { 
                ++workHours; 
                updateNumberOfWorkDays(); 
                return *this; 
            } 
            
            NumDays operator ++ ( int ) // ++ Postfix increment operators.
            {
                ++workHours;
                updateNumberOfWorkDays();
                return *this;
            }

            // These operators should decrement the number of hours stored in the object. 
            // When decremented, the number of days should be automatically recalculated.
            NumDays& operator -- () // −− Prefix decrement operators. 
            { 
                --workHours; 
                updateNumberOfWorkDays(); 
                return *this; 
            } 

            NumDays operator -- ( int ) // -- Postfix decrement operators.
            {
                --workHours;
                updateNumberOfWorkDays();
                return *this;
            }

			// ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~NumDays(){}				
            
};

/*
*****************************************************
Chapter 14 More About Classes - 5. Time Off
Design a class named TimeOff. 
The purpose of the class is to track an employee’s sick leave, vacation, and unpaid time off. 
It should have, as members, the following instances of the NumDays class described in Programming Challenge 4:

maxSickDays A NumDays object that records the maximum number of days of sick leave the employee may take.
sickTaken A NumDays object that records the number of days of sick leave the employee has already taken.
maxVacation A NumDays object that records the maximum number of days of paid vacation the employee may take.
vacTaken A NumDays object that records the number of days of paid vacation the employee has already taken.
maxUnpaid A NumDays object that records the maximum number of days of unpaid vacation the employee may take.
unpaidTaken A NumDays object that records the number of days of unpaid leave the employee has taken.

Additionally, the class should have members for holding the employee’s name and identification number. 
It should have an appropriate constructor and member functions for storing and retrieving data in any of the member objects.

Input Validation: Company policy states that an employee may not accumulate more than 240 hours of paid vacation. 
The class should not allow the maxVacation object to store a value greater than this amount.
*****************************************************
*/

class TimeOff
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        NumDays maxSickDays; // A NumDays object that records the maximum number of days of sick leave the employee may take.
        NumDays sickTaken; // A NumDays object that records the number of days of sick leave the employee has already taken.
        NumDays maxVacation; // A NumDays object that records the maximum number of days of paid vacation the employee may take.
        NumDays vacationTaken; // A NumDays object that records the number of days of paid vacation the employee has already taken.
        NumDays maxUnpaid; // A NumDays object that records the maximum number of days of unpaid vacation the employee may take.
        NumDays unpaidTaken; // A NumDays object that records the number of days of unpaid leave the employee has taken.

        std::string employeeName;
        int employeeId;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            TimeOff(); // default constructor
            TimeOff( std::string &eN, int &eId, int &msD, int &sT, int &mV, int &vT, int &mU, int &uT );

            // ***--- copy costructors ---***
            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
			// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            int getMaxSickDays() const { return maxSickDays.getNumberOfWorkDays(); }
            int getSickTakenDays() const { return sickTaken.getNumberOfWorkDays(); }
            int getMaxVacationDays() const { return maxVacation.getNumberOfWorkDays(); }
            int getVacationTakenDays() const { return vacationTaken.getNumberOfWorkDays(); }
            int getMaxUnpaidDays() const { return maxUnpaid.getNumberOfWorkDays(); }
            int getUnpaidTakenDays() const { return unpaidTaken.getNumberOfWorkDays(); }
            std::string getEmployeeName() const { return employeeName; }
            int setEmployeeId() const { return employeeId; }

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void setMaxSickDays(int &msD);
            void setSickTaken(int &sT);
            void setMaxVacation(int &mV);
            void setVacationTaken(int &vT);
            void setMaxUnpaid(int &mU);
            void setUnpaidTaken(int &uT);
            void setEmployeeName( std::string eN ){ employeeName = eN; }
            void setEmployeeId( int &eId ){ employeeId = eId; }

			// ***--- operator functions ---***
            // redefine the way a particular operator works with an object
            // Update other member variables if needed.		

			// ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~TimeOff(){}				
            
};

/*
*****************************************************
Chapter 14 More About Classes - 3. Day of the Year Modification

Modify the DayOfYear class, written in Programming Challenge 2, to add a constructor that takes two parameters: 
a string object representing a month and an integer in the range 0 through 31 representing the day of the month. 

The constructor should then initialize the integer member of the class to represent the day specified by the month and day of month parameters. 

The constructor should terminate the program with an appropriate error message if the number entered for a day is outside the range of days for the month given.

Add the following overloaded operators:
++ prefix and postfix increment operators. 
These operators should modify the DayOfYear object so that it represents the next day. 
If the day is already the end of the year, the new value of the object will represent the first day of the year.

−− prefix and postfix decrement operators. 
These operators should modify the DayOfYear object so that it represents the previous day. 
If the day is already the first day of the year, the new value of the object will represent the last day of the year.
*****************************************************
*/


/*
*****************************************************
Chapter 14 More About Classes - 2. Day of the Year

Assuming that a year has 365 days, write a class named DayOfYear that takes an integer 
representing a day of the year and translates it to a string consisting of the month followed by day of the month. 

For example,
Day 2 would be January 2 .
Day 32 would be February 1 .
Day 365 would be December 31.
The constructor for the class should take as parameter an integer representing the day
of the year, and the class should have a member function print() that prints the day in the month–day format. 

The class should have an integer member variable to repre-
sent the day and should have static member variables holding string objects that can
be used to assist in the translation from the integer format to the month-day format.

Test your class by inputting various integers representing days and printing out their representation in the month–day format.
*****************************************************
*/

class DayOfYear
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        int dayNumber;
        std::string day;
        std::string month;
        static std::string months[13];
        static std::string daysOfMonth[32];
        std::string monthDayFormat;
        bool foundDay; // switch on or off

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            DayOfYear() // default constructor
            {
                dayNumber = 1;
                foundDay = false; // switch off
            }

            DayOfYear(int &doty)
            {
                while(doty<0)
                {
                    std::cout << "Input validation: Day of the Year must be postive." << "\n";
                    std::cout << "Input the Day of the Year :";
                        std::cin >> doty;
                    std::cout << " " << "\n";
                }
                dayNumber = doty;
                foundDay = false; // switch off
            }

            DayOfYear(std::string &m, int &dayOfMonth);

            // ***--- copy costructors ---***
            // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
			// ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            int getDayNumber() const { return dayNumber; }
            std::string getDayOfYear() const { return monthDayFormat; }
            std::string getMonthNames( int &mN ) const { return months[mN]; }

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void monthDayCountValidation(std::string &m, int &dayOfMonth, const int &monthMaxDays);
            void translationDayOfYear(const int &startOfMonth, const int &monthNumber);
            void print();

            // ***--- operator functions ---***
            // redefine the way a particular operator works with an object
            // Update other member variables if needed.	
            DayOfYear& operator ++ (){ ++dayNumber; return *this; }
            DayOfYear& operator -- (){ --dayNumber; return *this; }

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~DayOfYear(){}
};

std::string DayOfYear::months[13]
{"zero", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

std::string DayOfYear::daysOfMonth[32]
{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", 
"11", "12", "13", "14", "15", "16", "17", "18", "19", "20", 
"21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};

/*
*****************************************************
Chapter 14 More About Classes - 1. Numbers Class
Design a class Numbers that can be used to translate whole dollar amounts in the range 0 through 9999 into an English description of the number. 

For example, the number 713 would be translated into the string seven hundred thirteen, and 8203 would be translated into eight thousand two hundred three. 
The class should have a single integer member variable:
int number; 
and a static array of string objects that specify how to translate key dollar amounts into the desired format. 
For example, you might use static strings such as
string lessThan20[20] = {"zero", "one", ..., "eighteen", "nineteen"};
string hundred = "hundred";
string thousand = "thousand";

The class should have a constructor that accepts a nonnegative integer and uses it to initialize the Numbers object. 
It should have a member function print() that prints the English description of the Numbers object. 
Demonstrate the class by writing a main program that asks the user to enter a number in the proper range and then prints out its English description. 
*****************************************************
*/

/*
*****************************************************
Chapter 14 More About Classes - 7. Month Class
Design a class named Month. 
The class should have the following private members:
• name A string object that holds the name of a month, such as “January,” “February,” etc.

• monthNumber An integer variable that holds the number of the month. 
For example, January would be 1, February would be 2, etc.  
Valid values for this variable are 1 through 12.

In addition, provide the following member functions:
• A default constructor that sets monthNumber to 1 and name to “January.”
• A constructor that accepts the name of the month as an argument. 
It should set name to the value passed as the argument and set monthNumber to the correct value.
• A constructor that accepts the number of the month as an argument. 
It should set monthNumber to the value passed as the argument and set name to the correct month name.
• Appropriate set and get functions for the name and monthNumber member variables.
• Prefix and postfix overloaded ++ operator functions that increment monthNumber and set name to the name of next month. 
If monthNumber is set to 12 when these functions execute, they should set monthNumber to 1 and name to “January.”
• Prefix and postfix overloaded −− operator functions that decrement monthNumber and set name to the name of previous month. 
If monthNumber is set to 1 when these functions execute, they should set monthNumber to 12 and name to “December.”

Also, you should overload cout’s << operator and cin’s >> operator to work with the Month class. 
Demonstrate the class in a program.
*****************************************************
*/

class Month
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        std::string name; // holds the name of a month
        int monthNumber; // holds the number of the month
        bool monthFound{false};
        //static std::string months[13];

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
                // Useful for initializing private member variables or executing private member functions
                
                // • A default constructor that sets monthNumber to 1 and name to “January.”
                Month(){ name = "January"; monthNumber = 1; }
                
                // • A constructor that accepts the name of the month as an argument. 
                Month( std::string &n ); // It should set name to the value passed as the argument and set monthNumber to the correct value.

                // • A constructor that accepts the number of the month as an argument. 
                Month( int &mN );
                // It should set monthNumber to the value passed as the argument and set name to the correct month name.

            // ***--- copy costructors ---***
                // Useful if the class and object have a pointer member variable (otherwise use memberwise assignment)
                // ClassName(const ClassName &obj)

            // ***--- accessor or getter ---***
                // Write public accessor functions that return the values in the member variables.
                std::string getMonthName() const { return name; }
                int getMonthNumber() const { return monthNumber; }
                bool getMonthFound() const { return monthFound; }
            
            // ***--- mutator or setter  ---***
                // Write public mutator functions to store values in the member variables.
                // Update other member variables if needed.
                void setMonthName( std::string &n );
                void setMonthName( int &mN );
                void setMonthNumber( int &mN );
                void setMonthNumber( std::string &n );

			// ***--- operator functions ---***
                // redefine the way a particular operator works with an object
                // Update other member variables if needed.		
                Month& operator ++ (); // ++ Prefix increment operators.
                Month operator ++ ( int ); // ++ Postfix increment operators.
                Month& operator -- ();  // -- Prefix decrement operators.
                Month operator -- ( int );  // -- Postfix decrement operators.

			// ***--- destructors ---***
                // Useful to free memory that was dynamically allocated by the class object
                ~Month(){}				
            
};
//std::string Month::months[13]
//{"zero", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

class Numbers
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        int number;
        std::string numberEnglishTranslation;
        static std::string lessThan20[20];
        static std::string tens[10];
        static std::string hundred;
        static std::string thousand;
        static std::string million;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 
        
    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            Numbers(int &n)
            {
                while( n<0 )
                {
                    std::cout << "Input validation: Numbers class can only accept non negative numbers." << "\n";
                    std::cout << "Input a postive number : ";
                        std::cin >> n;
                    std::cout << " " << "\n";
                }
                number = n;
            };

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            int getNumber() const { return number; }
            std::string printEnglishTranslation() const { return numberEnglishTranslation; }

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void setNumber( int &n );
            void NumberToEnglishTranslation();

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Numbers(){}
            
};

std::string Numbers::lessThan20[20]{"zero", "one", "two", "three", "four", "five", "six", 
                                    "seven", "eight", "nine", "ten", "eleven",
                                    "twelve", "thirteen", "fourteen", "fifthteen", 
                                    "sixteen", "seventeen", "eightteen", "nineteen"};
std::string Numbers::tens[10]{ "zero", "ten", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety" };
std::string Numbers::hundred = "hundred";
std::string Numbers::thousand = "thousand";
std::string Numbers::million = "million";

// end

#endif