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

#ifndef solver_H
#define solver_H

/*
*****************************************************

for every empty square,
loop through the possible_numbers array (0 to 9 - inclusive)
and insert the current number

    check if the number will,
    immediately lead to an invalid solution
        if invalid, increment and insert, 
        the next number in possible_numbers array

        if potenially valid, continue to the next empty square
    
    if we have tried every number, 
    in our possible_numbers array,
    and we did not find a number,
    that did not immediately lead to an invalid solution,
    then we know that one of the, 
    previously inserted numbers,
    is incorrect,
    and we need to backtrack,

    we back track to the last square,
    we inserted a value,
    at that square we increment and insert, 
    the next number in possible_numbers array
        tried every number, 
        in our possible_numbers array,
        and we did not find a number,
        that did not immediately lead to an invalid solution,
        then we know that one of the, 
        previously inserted numbers,
        is incorrect,
        and we need to backtrack,
    
    then we continue to the next square

*****************************************************
*/
class Sudoku_Solver
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        std::vector<std::vector<int> > board; // sudoku board

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            Sudoku_Solver(std::vector<std::vector<int> > grid)
            { board = grid; }

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            bool is_valid_postion(int current_row, int current_col, int value);

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            std::vector<std::vector<int> > solve_sudoku();
            bool solve_partial_sudoku(int row, int col);
            bool try_digits_at_postion(int row, int col);

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Sudoku_Solver(){}
            
};

// end

#endif