#include <iostream>
/*
Write a program that uses nested loops to collect data and calculate the average rainfall over a period of years. 
The program should first ask for the number of years. 
The outer loop will iterate once for each year. 
The inner loop will iterate twelve times, once for each month. 
Each iteration of the inner loop will ask the user for the inches of rainfall for that month.
After all iterations, the program should display the number of months, the total inches of rainfall, and the average rainfall per month for the entire period.
Input Validation: Do not accept a number less than 1 for the number of years. 
Input Validation: Do not accept negative numbers for the monthly rainfall.
*/

int main(){
    int years{0}; int rainfall{0}; double t_rainfall{0.0}; int t_months{0}; double avg_rainfall{0.0};

    //The program should first ask for the number of years. 
    std::cout << "Input the number of years: ";
    std::cin >> years;
    std::cout << "\n";

    //Input Validation: Do not accept a number less than 1 for the number of years. 
    if(years<1){
        std::cout << "Input Validation: Do not accept a number less than 1 for the number of years." << "\n";
        std::cout << "Input the number of years: ";
        std::cin >> years;
    }

    // The outer loop will iterate once for each year. 
    for (int i{0}; i < years; ++i){
        //The inner loop will iterate twelve times, once for each month. 
        for(int it{0}; it<12; ++it){
            //Each iteration of the inner loop will ask the user for the inches of rainfall for that month.
            std::cout << "Input the amount of rainfall for month " << it << ": ";
            std::cin >> rainfall; 

            //Input Validation: Do not accept negative numbers for the monthly rainfall.
            if(rainfall<0){
                std::cout << "Input Validation: Do not accept negative numbers for the monthly rainfall." << "\n";
                std::cout << "Input the amount of rainfall for month " << it << ": ";
                std::cin >> rainfall; 
            }

            t_rainfall = t_rainfall+rainfall;
            std::cout << "\n";
        }
        std::cout << "\n";
    }
    t_months = years*12;
    avg_rainfall =t_rainfall/t_months;
    //avg_rainfall = 100*avg_rainfall;

    //After all iterations, the program should display the number of months, the total inches of rainfall, and the average rainfall per month for the entire period.
    std::cout << "Number of months: " << t_months << "\n";
    std::cout << "total inches of rainfall: " << t_rainfall << "\n";
    std::cout << "average rainfall per month: " << avg_rainfall << "\n";

    std::cout << "\n";
    return 0;
}






