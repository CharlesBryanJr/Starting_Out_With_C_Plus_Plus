#include <iostream>

// Write nested if statements that perform the following tests: 
// If amount1 is greater than 10 and amount2 is less than 100, display the greater of the two.

int main(){
    unsigned int amount1{33};
    unsigned int amount2{50};

    if(amount1>10 && amount2<100){
        if(amount1>amount2){
            std::cout << amount1 << "\n";
        }
        else{
            std::cout << amount2 << "\n";
        }
    }
    return 0;
} 