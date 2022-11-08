/*
The Greatest and Least of These

Write a program with a loop that lets the user enter a series of integers. 

The user should enter −99 to signal the end of the series. 

After all the numbers have been entered, the program should display the largest and smallest numbers entered.

*/
#include <iostream>

int main(){
    int integer{0}; int old_integer{0}; int largest{0}; int smallest{0};

    std::cout << "This program will find the greastest integer and least integer of the inputed integers." << "\n";
    std::cout << "Input 99 at any time to stop the program." << "\n";
    std::cout << "Input an integer: ";
    std::cin >> integer;

    while(integer != -99){
        if(integer>largest){
            largest = integer;
        }

        if(integer<smallest){
            smallest = integer;
        }
        
        std::cout << "Input an integer: ";
        std::cin >> integer;
    }
    
    //After all the numbers have been entered, the program should display the largest and smallest numbers entered.
    std::cout << "The largest number entered was: " << largest << "\n";
    std::cout << "The smallest number entered was: " << smallest << "\n";

    return 0;
}






