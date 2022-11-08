/*
Distance Traveled
The distance a vehicle travels can be calculated as follows:
distance = speed * time

For example, if a train travels 40 miles per hour for 3 hours, the distance traveled is 120 miles.

Write a program that asks the user for the speed of a vehicle (in miles per hour) and how many hours it has traveled. 

The program should then use a loop to display the distance the vehicle has traveled for each hour of that time period. 

Input Validation: Do not accept a negative number for speed and do not accept any value less than 1 for time traveled.
*/
#include <iostream>

int main(){
    double distance{0}; double speed{0}; double time{0};

    std::cout << "Input the speed of a vehicle (in miles per hour). ";
    std::cin >> speed; 
    while(speed<0){
        std::cout << "Input Validation: Do not accept a negative number for speed." << "\n";
        std::cout << "Input the speed of a vehicle (in miles per hour). ";
        std::cin >> speed; 
    }
    
    std::cout << "Input how many hours it has traveled. ";
    std::cin >> time;
    while(time<1){
        std::cout << "Input Validation: Do not accept any value less than 1 for time traveled." << "\n";
        std::cout << "Input how many hours it has traveled. ";
        std::cin >> time;
    }

    std::cout << "\n";

    for(unsigned int i{0}; i < time; ++i){
        distance = speed*i;
        std::cout << "For hour: " << i << " the distance traveled is: " << distance << '\n';
    }

    return 0;
}






