#include <iostream>
/*
Population
Write a program that will predict the size of a population of organisms. 
//The program should ask the user for the starting number of organisms, their average daily population increase (as a percentage), and the number of days they will multiply. 
//A loop should display the size of the population for each day.
//Input Validation: Do not accept a number less than 2 for the starting size of the population. 
//Input Validation: Do not accept a negative number for average daily population increase. 
//Input Validation: Do not accept a number less than 1 for the number of days they will multiply. 
*/

int main(){
    //The program should ask the user for the starting number of organisms, their average daily population increase (as a percentage), and the number of days they will multiply. 
    double population{0}; double t_population{0}; double population_increase{0}; int number_of_days{0};

    std::cout << "Input the starting number of organisms: ";
    std::cin >> population;
    //Input Validation: Do not accept a number less than 2 for the starting size of the population. 
    if(population<2){
        std::cout << "Input Validation: Do not accept a number less than 2 for the starting size of the population." << '\n';
        std::cout << "Input the starting number of organisms: ";
        std::cin >> population_increase;
    }

    std::cout << "Input the average daily population increase (as a percentage): ";
    std::cin >> population_increase;
    //Input Validation: Do not accept a negative number for average daily population increase. 
    if(population<2){
        std::cout << "Input Validation: Do not accept a negative number for average daily population increase." << '\n';
        std::cout << "Input the average daily population increase (as a percentage): ";
        std::cin >> population_increase;
    }
    population_increase = population_increase/100;

    std::cout << "Input the number of days they will multiply: ";
    std::cin >> number_of_days;
    //Input Validation: Do not accept a number less than 1 for the number of days they will multiply. 
    if(number_of_days<1){
        std::cout << "Input Validation: Do not accept a number less than 1 for the number of days they will multiply." << '\n';
        std::cout << "Input the number of days they will multiply: ";
        std::cin >> number_of_days;
    }

    //A loop should display the size of the population for each day.
    for (int i{0}; i < number_of_days; ++i){
        population = population + population*population_increase;
        std::cout << "On day " << i << " the size of the population was: " << population << '\n';
    }

    return 0;
}






