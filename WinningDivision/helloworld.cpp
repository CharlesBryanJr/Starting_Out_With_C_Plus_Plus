/*
Winning Division
Write a program that determines which of a company’s four divisions (Northeast, Southeast, Northwest, and Southwest) had the greatest sales for a quarter. 

It should include the following two functions, which are called by main.

• double getSales() is passed the name of a division. 
It asks the user for a division’s quarterly sales figure, validates the input, then returns it. 
It should be called once for each division.

• void findHighest() is passed the four sales totals. 
It determines which is the largest and prints the name of the high grossing division, along with its sales figure.

Input Validation: Do not accept dollar amounts less than $0.00.
*/

#include <iostream>

// • double getSales() is passed the name of a division.
double getSales(std::string division){
    std::cout << " " << std::endl; std::cout << " --- getSales() --- " << std::endl;

    //It asks the user for a division’s quarterly sales figure, validates the input, then returns it. 
    double qsf{0}; 

    std::cout << "What is the " << division <<  "'s quarterly sales figure? : "; std::cin >> qsf;

    // Input Validation: Do not accept dollar amounts less than $0.00.
    while(qsf<0){
        std::cout << "Input error: quarterly sales figure must be postive." << std::endl;
        std::cout << "What is the division's quarterly sales figure? : "; std::cin >> qsf;
    }
    
    std::cout << "For division " << division << ", the quarterly sales figure is : " << qsf;

    return qsf;
}

double findHighest(double Northeast, double Southeast, double Northwest, double Southwest){
    std::cout << " " << std::endl; std::cout << " --- findHighest() --- " << std::endl;
    double first;

    // determines which of a company’s four divisions (Northeast, Southeast, Northwest, and Southwest) had the greatest sales for a quarter. 
    if(Northeast>Southeast){
        if (Northeast>Northwest){
            if(Northeast>Southwest){
                first = Northeast;
                std::cout << "Northeast: " << Northeast << std::endl;
            }
        }
    }

    if(Southeast>Northeast){
        if (Southeast>Northwest){
            if(Southeast>Southwest){
                first = Southeast;
                std::cout << "Southeast: " << Southeast << std::endl;
            }
        }
    }

    if(Northwest>Northeast){
        if (Northwest>Southeast){
            if(Northwest>Southwest){
                first = Northwest;
                std::cout << "Northwest: " << Northwest << std::endl;
            }
        }
    }

    if(Southwest>Northeast){
        if (Southwest>Southeast){
            if(Southwest>Northwest){
                first = Southwest;
                std::cout << "Southwest: " << Southwest << std::endl;
            }
        }
    }

    return first;
}

int main(){
    findHighest(getSales("NE"), getSales("SW"), getSales("NW"), getSales("SE")); std::cout << " " << std::endl; return 0;
}
