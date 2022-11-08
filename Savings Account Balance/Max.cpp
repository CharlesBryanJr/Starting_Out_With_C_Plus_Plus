#include <iostream>

// Write a program that asks the user to enter two numbers. 
// The program should use the conditional operator to determine which number is the smaller and which is the larger.

unsigned int n1;
unsigned int n2;

int main(){

    std::cout << "Please enter number 1: " << "\n";
    std::cin >> n1;

    std::cout << "Please enter number 2: " << "\n";
    std::cin >> n2;

    if(n1>n2){
        std::cout << n1 << "\n";
    }
    else{
        std::cout << n2 << "\n";
    }

    return 0;
} 