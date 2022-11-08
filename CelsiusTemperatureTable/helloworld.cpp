/*
Celsius Temperature Table
The formula for converting a temperature from Fahrenheit to Celsius is c = (5/9)*(F-32);

where F is the Fahrenheit temperature and C is the Celsius temperature. 

Write a function named celsius that accepts a Fahrenheit temperature as an argument. 

The function should return the temperature, converted to Celsius. 

Demonstrate the function by calling it in a loop that displays a table of the Fahrenheit temperatures 0 through 20 and their Celsius equivalents.
*/

#include <iostream>

double celsius(double F){
    double c;
    std::cout << " " << "\n"; std::cout << "--- celsius() ---" << "\n"; std::cout << " " << "\n";
    std::cout << "This formula for converting a temperature from Fahrenheit to Celsius is c = (5/9)*(F-32)" << "\n";
    std::cout << "Where F is the Fahrenheit temperature and C is the Celsius temperature." << "\n"; 
    c = 0.55555555555*(F-32);
    std::cout << "For Fahrenheit temp: " << F << " the converting temperature in Celsius is: " << c << "\n";
    return c;
}

int main(){
    for(int i{0}; i<21; ++i){
        celsius(i);
    }
    return 0;
}