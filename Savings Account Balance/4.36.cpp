#include <iostream>

// Write an if statement that prints the message “The number is valid” if the variable grade is within the range 0 through 100.

int main(){
    int grade{33};

    if(grade >= 0 && grade <= 100){
        std::cout << "The number is valid" << "\n";
    }

    return 0;
} 