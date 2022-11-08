/*
Pennies for Pay
Write a program that calculates how much a person would earn over a period of time if their salary is one penny the first day and two pennies the second day, and continues to double each day. 

The program should ask the user for the number of days.

Display a table showing how much the salary was for each day, and then show the total pay at the end of the period. 

The output should be displayed in a dollar amount, not the number of pennies.

Input Validation: Do not accept a number less than 1 for the number of days worked.
*/

#include <iostream>
#include <iomanip>

int number_of_days{0}; double pennies{0}; double salary{0.01};

int main(){
    std::cout << "Enter the number of days worked: ";
    std::cin >> number_of_days;

    while(number_of_days<1){
        std::cout << "Input Validation: Do not accept a number less than 1 for the number of days worked." << "\n";
        std::cout << "Enter the number of days worked: ";
        std::cin >> number_of_days;
    }
   
    for (int days{0}; days < number_of_days; ++days){
        salary = salary*2;
        std::cout << "The number of days worked: " << std::setw(2) << days << " and the total dollar amount: " << salary << '\n';
    }

    return 0;
}






