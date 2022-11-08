#include <iostream>
// Write a program that asks the user for a positive integer value. 
// The program should use a loop to get the sum of all the integers from 1 up to the number entered. 
// For example, if the user enters 50, the loop will find the sum of 1, 2, 3, 4, ... 50.
// Input Validation: Do not accept a negative starting number.

int main(){
    // Write a program that asks the user for a positive integer value. 
    int p_it{0};
    std::cout << "enter a positive integer" << '\n';
    std::cin >> p_it;

    if(p_it<0){
        std::cout << "Input Validation: Do not accept a negative starting number." << '\n';
    }
    else{
        // The program should use a loop to get the sum of all the integers from 1 up to the number entered. 
        unsigned int sum{0};
        unsigned int n2;
        for (int i{0}; i < p_it; ++i){
            sum=+i;
        }
        std::cout << sum << '\n';
    }
    return 0;
}




