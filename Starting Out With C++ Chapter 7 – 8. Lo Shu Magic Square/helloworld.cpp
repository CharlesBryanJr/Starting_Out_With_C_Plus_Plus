/*
Starting Out With C++ Chapter 7 – 8. Lo Shu Magic Square
The Lo Shu Magic Square is a grid with 3 rows and 3 columns shown in Figure 7-19 .
The Lo Shu Magic Square has the following properties:
• The grid contains the numbers 1 through 9 exactly.
• The sum of each row, each column, and each diagonal all add up to the same number. 
This is shown in Figure 7-20 .

In a program you can simulate a magic square using a two-dimensional array. 

Write a function that accepts a two-dimensional array as an argument, and determines whether the array is a Lo Shu Magic Square. 
Test the function in a program.
*/
#include <iostream>
#include <iomanip>
#include <vector>
char inputValidation_y_or_n(char &letter)
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

/*
int inputValidation_postiveInteger_array2D(int Magic_Square[][3], const int row_ele, const int colmun_ele)
{
    std::cin >> Magic_Square[row_ele][colmun_ele];

    while( Magic_Square[row_ele][colmun_ele] < 0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer" << "\n";
        std::cout << "For row element " << row_ele+1 << ", column element " << colmun_ele+1 << ", input a value : ";
            std::cin >> Magic_Square[row_ele][colmun_ele];
    }
    return Magic_Square[row_ele][colmun_ele];
}
*/

void GET_Magic_Square(int Magic_Square[][3], 
                      const int SIZEof_Magic_Square_rows, 
                      const int SIZEof_Magic_Square_columns, 
                      int row_ele, 
                      int column_ele)
{
    std::cout << "---GET_Magic_Square---" << "\n"; std::cout << " " << "\n";

    for(row_ele=0;row_ele<SIZEof_Magic_Square_rows;++row_ele)
    {
        for(column_ele=0;column_ele<SIZEof_Magic_Square_columns;++column_ele)
        {
            std::cout << "For row element " << row_ele+1 << ", column element " << column_ele+1 << ", input a value : ";
                std::cin >> Magic_Square[row_ele][column_ele];
                // inputValidation_postiveInteger_array2D(Magic_Square, row_ele, column_ele);
        }
    }
    std::cout << " " << "\n";
}

void IS_Magic_Square( int Magic_Square[][3], 
                      const int SIZEof_Magic_Square_rows, 
                      const int SIZEof_Magic_Square_columns, 
                      int row_ele, 
                      int column_ele)
{
    std::cout << "---IS_Magic_Square---" << "\n"; std::cout << " " << "\n";
    int row0{0},
        row1{0},
        row2{0},
        column0{0},
        column1{0},
        column2{0},
        diagonal_1{0},
        diagonal_2{0};

    for(row_ele=0;row_ele<SIZEof_Magic_Square_rows;++row_ele)
    {
        for(column_ele=0;column_ele<SIZEof_Magic_Square_columns;++column_ele)
        {
            if(row_ele==0)
            {
                row0 += Magic_Square[0][column_ele]; // row0 = row0 + Magic_Square[row_ele][column_ele];
            }
            
            if(row_ele==1)
            {
                row1 += Magic_Square[row_ele][column_ele];
            }
            
            if(row_ele==2)
            {
                row2 += Magic_Square[row_ele][column_ele];
            }
            
            if(column_ele==0)
            {
                column0 += Magic_Square[row_ele][0]; // column0 = column0 + Magic_Square[row_ele][column_ele];
            }

            if(column_ele==1)
            {
                column1 += Magic_Square[row_ele][column_ele];
            }

            if(column_ele==2)
            {
                column2 += Magic_Square[row_ele][column_ele];
            }

            if(row_ele == column_ele)
            {
                diagonal_1 += Magic_Square[row_ele][column_ele];
            }

            if(row_ele==0 && column_ele==2)
            {
                diagonal_2 += Magic_Square[row_ele][column_ele];
            }

            if(row_ele==1 && column_ele==1)
            {
                diagonal_2 += Magic_Square[row_ele][column_ele];
            }

            if(row_ele==2 && column_ele==0)
            {
                diagonal_2 += Magic_Square[row_ele][column_ele];
            }

        }
    }

    std::cout << "row0 : " << row0 << "\n";
    std::cout << "row1 : " << row1 << "\n";
    std::cout << "row2 : " << row2 << "\n";
    std::cout << "column0 : " << column0 << "\n";
    std::cout << "column1 : " << column1 << "\n";
    std::cout << "column2 : " << column2 << "\n";
    std::cout << "diagonal_1 : " << diagonal_1 << "\n";
    std::cout << "diagonal_2 : " << diagonal_2 << "\n";
    std::cout << " " << "\n";

    if(    (row0 == row1) 
        && (row0 == row2) 
        && (column0 == column1) 
        && (column0 == column2)
        && (diagonal_1 == diagonal_2)
        && (row0 == column0) 
        && (row0 == diagonal_1) )
    {
        std::cout << " IS MAGIC SQUARE " << "\n";
    }
    
    else 
    {
        std::cout << " NOT MAGIC SQUARE " << "\n";
    }
}

int main()
{
	char letter;
    int row_ele,
        r_ele,
        column_ele,
        c_ele,
        SIZEof_Magic_Square_rows{3},
        SIZEof_Magic_Square_columns{3};
    int Magic_Square[SIZEof_Magic_Square_rows][3];


	while(letter != 'n')
	{
        GET_Magic_Square(Magic_Square, SIZEof_Magic_Square_rows, SIZEof_Magic_Square_columns, row_ele, column_ele);
        IS_Magic_Square(Magic_Square, SIZEof_Magic_Square_rows, SIZEof_Magic_Square_columns, row_ele, column_ele);
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}