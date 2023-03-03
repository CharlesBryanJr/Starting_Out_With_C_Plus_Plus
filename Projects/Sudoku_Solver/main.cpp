#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <cctype>
#include <cstring>
#include <string>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <stdlib.h>
#include "solver.h"
#include "solver.cpp"

//*****************************************************
// Definition of function inputValidation_y_or_n function. 
// This function returns a y or n char.
//*****************************************************

char inputValidation_y_or_n(char &letter)
{
    std::cin >> letter;
	while (tolower(letter) != 'y' && tolower(letter) != 'n')
    {
        std::cout << "ERROR: a 'y' or an 'n' must be entered: ";
        std::cin.clear();
        std::cin >> letter;
    }
    return letter;
}

//*****************************************************
//	*=== START MAIN FUNCTION ===*

int main()
{
    char letter,
         userChoice;

	while(letter != 'n')
	{
        displayProgramMenu();
            std::cin >> userChoice;

        while(tolower(userChoice) != 'e')
        {
            while (toupper(userChoice) < 'A' || toupper(userChoice) > 'Z')
            {
                std::cout << "Please make a choice in the range of A through U: "; std::cout << " " << "\n";
                displayProgramMenu();
                std::cin >> userChoice;
            }
            
            if(tolower(userChoice) == 'a') 
            {
                std::vector<std::vector<int> > board;

                Sudoku_Solver a(board);
                a.solve_sudoku();

                std::cout << " " << "\n";
            }
            std::cout << " " << "\n";
            displayProgramMenu();
            std::cin >> userChoice;
        }
        
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);	
        std::cout << " " << "\n";
    }

	return 0;
}

// *=== END MAIN FUNCTION ===* 
//*****************************************************