/*
Falling Distance
When an object is falling because of gravity, the following formula can be used to determine the distance the object falls in a specific time period: d = 0.5 * g * t * t;

The variables in the formula are as follows: d is the distance in meters, g is 9.8, and t is the amount of time, in seconds, that the object has been falling.

Write a function named fallingDistance that accepts an object’s falling time (in seconds) as an argument. 

The function should return the distance, in meters, that the object has fallen during that time interval. 

Write a program that demonstrates the function by calling it in a loop that passes the values 1 through 10 as arguments and displays the return value.
*/

#include <iostream>


// Write a function named fallingDistance that accepts an object’s falling time (in seconds) as an argument. 
void fallingDistance(double t){
    double d, g{9.8};
    std::cout << " " << "\n"; std::cout << "--- fallingDistance ---" << "\n"; std::cout << " " << "\n";
    std::cout << "This function will calculate the distance the object falls in a specific time period using this formula: d = 0.5 * g * t * t " << "\n";
    std::cout << "g is " << g << "\n";  
    std::cout << "t is the amount of time, in seconds: " << t << "\n"; 
    d = 0.5 * g * t * t;
    std::cout << "during, that time interval: " << t <<  ", the distance, in meters, that the object has fell: " << d << "\n";
}

int main(){
    for(int i{1}; i<11; ++i){
        fallingDistance(i);
    }
    return 0;
}