/*
Random Number Guessing Game
Write a program that generates a random number and asks the user to guess what the number is. 

If the user’s guess is higher than the random number, the program should display “Too high, try again.” 

If the user’s guess is lower than the random number, the program should display “Too low, try again.” 

The program should use a loop that repeats until the user correctly guesses the random number.
*/

#include <iostream>

int main(){
    
    int random{0}, guess{0}, range{0}, couter{0};

    std::cout << "Welcome to Random Number Guessing Game." << "\n";
    std::cout << "Starting from 0, please select the max integer value of a random number: "; std::cin >> range;
    random = rand() % range; // range 0 to ....

    std::cout << " \n";
    std::cout << "For the range of 0 to " << range << ": Please enter a number as your first guess: "; std::cin >> guess;
    couter = 1;

    // The program should use a loop that repeats until the user correctly guesses the random number.
    while(guess != random){
        
        // If the user’s guess is higher than the random number, the program should display “Too high, try again.” 
        if(guess>random){
            std::cout << "Too high, try again." << "\n";
            std::cout << " \n";
            std::cout << "Please enter your guess: "; std::cin >> guess;
            couter += couter;
        }

        // If the user’s guess is lower than the random number, the program should display “Too low, try again.” 
        if(guess<random){
            std::cout << "Too low, try again." << "\n";
            std::cout << " \n";
            std::cout << "Please enter your guess: "; std::cin >> guess;
            couter += couter;

        } 
    }

    std::cout << " \n";
    std::cout << "Great guess!, Game Over." << "\n";
    std::cout << "Total guesses: " << couter-1 << "\n";

    return 0;
}
