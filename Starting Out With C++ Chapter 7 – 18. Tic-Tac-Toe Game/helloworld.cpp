/*
Starting Out With C++ Chapter 7 – 18. Tic-Tac-Toe Game
Write a program that allows two players to play a game of tic-tac-toe. 
Use a two dimensional char array with three rows and three columns as the game board. 
Each element of the array should be initialized with an asterisk (*). 
The program should run a loop that
• Displays the contents of the board array
• Allows player 1 to select a location on the board for an X. 

The program should ask the user to enter the row and column number.
• Allows player 2 to select a location on the board for an O. 
The program should ask the user to enter the row and column number.

• Determines whether a player has won, or a tie has occurred. 
If a player has won, the program should declare that player the winner and end. 
If a tie has occurred, the program should say so and end.

Player 1 wins when there are three Xs in a row on the game board. 
The Xs can appear in a row, in a column, or diagonally across the board. 
A tie occurs when all of the locations on the board are full, but there is no winner.
*/

#include <iostream>
#include <iomanip>
#include <vector>
char inputValidation_y_or_n( char &letter)
{
    std::cin >> letter;

    while ( !(letter == 'y' || letter == 'n') )
    {
        std::cout << "ERROR: a 'y' or an 'n' must be entered: ";
        std::cin.clear();
        std::cin >> letter;
    }
    return letter;
}

int inputValidation_row(int &row, const int row_ele)
{
    while( !(std::cin >> row) || (row<0) || (row>3) )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "Player " << row_ele+1 << ", select a row on the board for an X : ";
            std::cin >> row;
    }
    return row;
}

int inputValidation_colmun(int &column, const int row_ele)
{
    while( !(std::cin >> column) || (column<0) || (column>3) )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "Player " << row_ele+1 << ", select a column on the board for an X : ";
            std::cin >> column;
    }
    return column;
}

int inputValidation_postiveInteger_array2D(char game_board[3][3], const int row_ele, const int colmun_ele)
{
    std::cin >> game_board[row_ele][colmun_ele];

    while( game_board[row_ele][colmun_ele] < 0 || game_board[row_ele][colmun_ele] > 3 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer" << "\n";
        std::cout << "For day " << colmun_ele+1 << ", how many pounds of food did monkey " << row_ele+1 << ", eat? : ";
            std::cin >> game_board[row_ele][colmun_ele];
    }
    return game_board[row_ele][colmun_ele];
}

void display_game_board(char game_board[][3], int &row_ele, int &colmun_ele)
{
    for(row_ele = 0; row_ele<3; ++row_ele)
    {
        for(colmun_ele = 0; colmun_ele<3; ++colmun_ele)
        {
            std::cout << game_board[row_ele][colmun_ele] << " ";
        }
        std::cout << " " << "\n";
    }
}

void Tic_Tac_Toe(char game_board[][3], int &row_ele, int &column_ele)
{
    std::cout << "---Tic_Tac_Toe---" << "\n"; std::cout << " " << "\n";
    int row, 
        column;

    display_game_board(game_board,row_ele,column_ele);

    for(row_ele = 0; row_ele<3; ++row_ele)
    {
        for(column_ele = 0; column_ele<3; ++column_ele)
        {
            std::cout << "Player " << row_ele+1 << ", select a location on the board for an X." << "\n";

            std::cout << "Player " << row_ele+1 << ", select a row on the board for an X : ";
                inputValidation_row(row,row_ele);

            std::cout << "Player " << row_ele+1 << ", select a column on the board for an X : ";
                inputValidation_colmun(column, row_ele);

            std::cout << "Player " << row_ele+1 << ", you selected row " << row << ", column " << column << ", to add an X." << "\n";
        }
        std::cout << " " << "\n";
        display_game_board(game_board,row_ele,column_ele);
    }

    std::cout << " " << "\n";
}

int main()
{
	char letter;
    int row_ele, 
        column_ele;
    char game_board[3][3]{'*','*','*','*','*','*','*','*','*'};

	while(letter != 'n')
	{
        Tic_Tac_Toe(game_board, row_ele, column_ele);
        
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}
