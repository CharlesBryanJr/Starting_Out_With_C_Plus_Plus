#include <iostream>

// Write an if statement that prints the message “The number is valid” if the variable temperature is within the range −50 through 150.
int main(){
    int temperature{33};

    if(temperature >= -50 && temperature <= 150){
        std::cout << "The number is valid" << "\n";
    }

    return 0;
} 