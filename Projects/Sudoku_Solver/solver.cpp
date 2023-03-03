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


//*****************************************************
// Definition of the Sudoku_Solver class's accessor functions. 
// These functions return and display the values in these member variables.
//*****************************************************

bool Sudoku_Solver::is_valid_postion(int current_row, int current_col, int value){
    int num;
    
    for(int col = 0; col < board[current_row].size(); ++col){
        num = board[current_row][col];
        if(num == value)
        { return false; }
    }

    for(int row = 0; row < board.size(); ++row){
        num = board[row][current_col];
        if(num == value)
        { return false; }
    }

    int subgrid_row_start = current_row / (3 * 3);
    int subgrid_col_start = current_col / (3 * 3);

    for(int row = 0; row < 3; ++row){
        for(int col = 0; col < 3; ++col){
            int row_to_check = subgrid_row_start + row;
            int col_to_check = subgrid_col_start + col;
            int num = board[row_to_check][col_to_check];

            if(num == value)
            { return false; }
        }
    }

    return true;
}

//*****************************************************
// Definition of the Sudoku_Solver class's mutator functions. 
// These functions return and display the values in these member variables.
// Update other member variables if needed.	
//*****************************************************
std::vector<std::vector<int> > Sudoku_Solver::solve_sudoku(){
    solve_partial_sudoku(0, 0);
    return board;
}

bool Sudoku_Solver::solve_partial_sudoku(int row, int col){
    int current_row = row;
    int current_col = col;

    if(current_col == board[current_row].size()){
        current_row++;
        current_col = 0;

        if(current_row == board[current_row].size())
        { return true; }
    }

    if(board[current_row][current_col] == 0){
        return try_digits_at_postion(current_row, current_col);
    }

    return solve_partial_sudoku(current_row, current_col + 1);
}

bool Sudoku_Solver::try_digits_at_postion(int row, int col)
{
    for(int num = 1; num <= 9; ++num){
        if(is_valid_postion(row, col, num)){
            board[row][col] = num;
        }
        if(solve_partial_sudoku(row, col + 1)){
            return true;
        }
    }

    board[row][col] = 0;
    return false;
}


//*****************************************************
// Definition of function displayProgramMenu. 
// This function displays the program's menu on the screen. 
//*****************************************************

void displayProgramMenu()
{
    std::cout << "***----displayProgramMenu----***" << "\n"; std::cout << " " << "\n";

    std::cout << "User, choice a program to run." << "\n";
    std::cout << "A)  Sudoku Solver" << "\n";
    std::cout << "E) --- EXIT ---" << "\n";
}

// end
