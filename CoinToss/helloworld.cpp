/*
Coin Toss
Write a function named coinToss that simulates the tossing of a coin. 

When you call the function, it should generate a random number in the range of 1 through 2. 

If the random number is 1, the function should display “heads.” 

If the random number is 2, the function should display “tails.” 

Demonstrate the function in a program that asks the user how many times the coin should be tossed and then simulates the tossing of the coin that number of times.
*/

#include <iostream>

int coinToss(){
    int random_number;

    std::cout << " " << "\n"; std::cout << "--- coinToss() ---" << "\n"; std::cout << " " << "\n";
    std::cout << "Write a function named coinToss that simulates the tossing of a coin." << "\n"; 
    std::cout << "If the random number is 1, the function should display “heads." << "\n"; 
    std::cout << "If the random number is 2, the function should display “tails." << "\n"; 

    random_number = rand() % 2 + 1;

    if(random_number == 1){
        std::cout << "random number is " << random_number << " : heads" << "\n"; 
    }
    else{
        std::cout << "random number is " << random_number << " : tails" << "\n"; 
    }
    std::cout << " ";
    return random_number;
}

int main(){
    int how_many_times;
    std::cout << "how many times the coin should be tossed? : "; std::cin >> how_many_times;
    for(int i{0}; i<how_many_times; ++i){
        coinToss();
    }
    return 0;
}