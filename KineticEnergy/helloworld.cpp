/*
Kinetic Energy
In physics, an object that is in motion is said to have kinetic energy. 

The following formula can be used to determine a moving object’s kinetic energy: KE = 0.5 * m * v * v;

The variables in the formula are as follows: KE is the kinetic energy, m is the object’s mass in kilograms, and v is the object’s velocity, in meters per second.

Write a function named kineticEnergy that accepts an object’s mass (in kilograms) and velocity (in meters per second) as arguments. 

The function should return the amount of kinetic energy that the object has. 

Demonstrate the function by calling it in a program that asks the user to enter values for mass and velocity.
*/

#include <iostream>

double kineticEnergy(double m, double v){
    std::cout << " " << "\n"; std::cout << "--- kineticEnergy() ---" << "\n"; std::cout << " " << "\n";
    double KE;
    std::cout << "In physics, an object that is in motion is said to have kinetic energy." << "\n";
    std::cout << "This function will calculate the amount of kinetic energy that the object has using this formula: KE = 0.5 * m * v * v " << "\n";
    std::cout << "KE is the kinetic energy" << "\n"; 
    std::cout << "m is the object's mass in kilograms: " << m << "\n";
    std::cout << "v is the object's velocity, in meters per second: " << v << "\n";
    //The following formula can be used to determine a moving object’s kinetic energy: KE = 0.5 * m * v * v;
    KE = 0.5 * m * v * v;
    std::cout << "this object has this amount of kinetic energy: " << KE << "\n"; std::cout << " ";
    //The function should return the amount of kinetic energy that the object has. 
    return KE; 
}

int main(){
    double mass, velocity;
    // Demonstrate the function by calling it in a program that asks the user to enter values for mass and velocity.
    std::cout << "User, please input the value of for mass: "; std::cin >> mass;
    std::cout << "User, please input the value of for velocity: "; std::cin >> velocity;
    kineticEnergy(mass,velocity);
    return 0;
}