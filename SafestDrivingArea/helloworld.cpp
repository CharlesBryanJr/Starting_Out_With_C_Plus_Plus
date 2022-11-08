/*
Safest Driving Area
Write a program that determines which of five geographic regions within a major city
(north, south, east, west, and central) had the fewest reported automobile accidents last year. 

It should have the following two functions, which are called by main .

• int getNumAccidents() is passed the name of a region. 
It asks the user for the number of automobile accidents reported in that region during the last year, validates the input, then returns it. 
It should be called once for each city region.

• void findLowest() is passed the five accident totals. 
It determines which is the smallest and prints the name of the region, along with its accident figure.

Input Validation: Do not accept an accident number that is less than 0.
*/

#include <iostream>

// • int getNumAccidents() is passed the name of a region. 
int getNumAccidents(std::string city){
    std::cout << " " << "\n"; std::cout << "--- getNumAccidents ---" << "\n"; std::cout << " " << "\n";

    int automobile_accidents;

    //It asks the user for the number of automobile accidents reported in that region during the last year, validates the input, then returns it. 
    std::cout << "For " << city << ", input the number of automobile accidents reported in that region during the last year: "; std::cin >> automobile_accidents;

    //Input Validation: Do not accept an accident number that is less than 0.
    while(automobile_accidents<0){
        std::cout << " " << "\n";
        std::cout << "Input Validation: Do not accept an accident number that is less than 0." << "\n";
        std::cout << "For " << city << ", input the number of automobile accidents reported in that region during the last year: "; std::cin >> automobile_accidents;
    }

    return automobile_accidents;
}

void findLowest(int north, int south, int east, int west, int central){
    std::cout << " " << "\n"; std::cout << "--- findLowest ---" << "\n"; std::cout << " " << "\n";

    int lowest;
    
    if(north<south){
        if(north<east){
            if(north<west){
                if(north<central){
                    lowest = north;
                    std::cout << "North is the lowest: " << lowest << "\n";
                }
            }
        }
    }
    
    if(south<north){
        if(south<east){
            if(south<west){
                if(south<central){
                    lowest = south;
                    std::cout << "South is the lowest: " << lowest << "\n";
                }
            }
        }
    }


    if(east<north){
        if(east<south){
            if(east<west){
                if(east<central){
                    lowest = east;
                    std::cout << "East is the lowest: " << lowest << "\n";
                }
            }
        }
    }

    if(west<north){
        if(west<south){
            if(west<east){
                if(west<central){
                    lowest = west;
                    std::cout << "West is the lowest: " << lowest << "\n";
                }
            }
        }
    }

    if(central<north){
        if(central<south){
            if(central<east){
                if(central<west){
                    lowest = central;
                    std::cout << "Central is the lowest: " << lowest << "\n";
                }
            }
        }
    }
    
}

    
int main(){
    int n,s,e,w,c;

    //It should be called once for each city region.
    n = getNumAccidents("north");
    s = getNumAccidents("south");
    e = getNumAccidents("east");
    w = getNumAccidents("west");
    c = getNumAccidents("central");

    findLowest(n,s,e,w,c);

    std::cout << " " << "\n";
    return 0;

}