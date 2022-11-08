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

            void getDateFormat1(const int &month, const int &day, const int &year); // retrieves the data in this format 12/25/2014

                void displayDateFormat1()
                {  getDateFormat1(month, day, year); }
            
            void getDateFormat2(const int &month, const int &day, const int &year); // retrieves the data in this format December 25, 2014
                
                void displayDateFormat2()
                {  getDateFormat2(month, day, year); }

            void getDateFormat3(const int &month, const int &day, const int &year); // retrieves the data in this format 25 December 2014

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
            ~Date();
            
            
};

#endif
