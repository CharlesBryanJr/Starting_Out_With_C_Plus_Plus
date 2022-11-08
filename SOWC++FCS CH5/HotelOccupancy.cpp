/*
Write a program that calculates the occupancy rate for a hotel. 
The program should start by asking the user how many floors the hotel has. 

A loop should then iterate once for each floor. 

In each iteration, the loop should ask the user for the number of rooms on the floor and how many of them are occupied. 

After all the iterations, the program should display how many rooms the hotel has, how many of them are occupied, how many are unoccupied, and the percentage of rooms that are occupied. 
The percentage may be calculated by dividing the number of rooms occupied by the number of rooms.

It is traditional that most hotels do not have a thirteenth floor. The loop in this program should skip the entire thirteenth iteration.

Input Validation: Do not accept a value less than 1 for the number of floors. 
Input Validation: Do not accept a number less than 10 for the number of rooms on a floor.
*/

#include <iostream>
#include <iomanip>

int main(){
    int floors{0}; int rooms{0}; int occupied{0}; int unoccupied{0}; double percentage_occupied{0.0};
    int t_rooms{0}; int t_occupied{0}; int t_unoccupied{0}; double t_percentage_occupied{0.0};

    std::cout << "How many floors does the hotel have? "; 
    std::cin >> floors;

    
    while(floors<1){
        std::cout << "Input Validation: Do not accept a value less than 1 for the number of floors." << "\n";
        std::cout << "How many floors does the hotel have? "; 
        std::cin >> floors;
    }
    
    
    for (int i{0}; i < floors; ++i){
        if(i==13){
            std::cout << "skip 13"<< "\n";
        }

        else{
            std::cout << "For floor " << i << ", input the number of rooms: "; 
            std::cin >> rooms; 

            while(rooms<10){
                std::cout << "Input Validation: Do not accept a number less than 10 for the number of rooms on a floor." << "\n";
                std::cout << "For floor " << i << ", input the number of rooms: "; 
                std::cin >> rooms; 
            }
                   
            std::cout << "For floor " << i << ", input how many of the " << rooms << " are occupied: "; 
            std::cin >> occupied; 
            
            percentage_occupied = 100*occupied/rooms;
            unoccupied = rooms - occupied;
                
            std::cout << "Floor " << i << "\n"
                << "  number of rooms: " << rooms << "\n"
                << "  occupied rooms: " << occupied << "\n"
                << "  unoccupied rooms: " << unoccupied << "\n"
                << "  percentage occupied: "  << percentage_occupied << "%" << "\n";
            
            t_rooms = t_rooms+rooms;
            t_occupied = t_occupied+occupied; 
            t_unoccupied = t_unoccupied+unoccupied;
            std::cout << "\n"; 
        }

    }
    t_percentage_occupied = 100*t_occupied/t_rooms;
    std::cout << "\n";
    std::cout << "Total Floors: " << floors << "\n"
        << "  total number of rooms: " << t_rooms << "\n"
        << "  total occupied rooms: " << t_occupied << "\n"
        << "  total unoccupied rooms: " << t_unoccupied << "\n"
        << "  total percentage occupied: " << t_percentage_occupied << "%" << "\n";
std::cout << "\n"; 
return 0;
}






