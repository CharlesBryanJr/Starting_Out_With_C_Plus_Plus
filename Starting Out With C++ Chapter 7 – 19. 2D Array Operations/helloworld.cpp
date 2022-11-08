/*
Starting Out With C++ Chapter 7 – 19. 2D Array Operations
Write a program that creates a two-dimensional array initialized with test data. 
Use any data type you wish. 
The program should have the following functions:

• getTotal. This function should accept a two-dimensional array as its argument and return the total of all the values in the array.

• getAverage. This function should accept a two-dimensional array as its argument and return the average of all the values in the array.

• getRowTotal. This function should accept a two-dimensional array as its first argument and an integer as its second argument. 
The second argument should be the subscript of a row in the array. 
The function should return the total of the values in the specified row.

• getColumnTotal. This function should accept a two-dimensional array as its first argument and an integer as its second argument. 
The second argument should be the subscript of a column in the array. 
The function should return the total of the values in the specified column.

• getHighestInRow. This function should accept a two-dimensional array as its first argument and an integer as its second argument. 
The second argument should be the subscript of a row in the array. 
The function should return the highest value in the specified row of the array.

• getLowestInRow. This function should accept a two-dimensional array as its first argument and an integer as its second argument. 
The second argument should be the subscript of a row in the array. 
The function should return the lowest value in the specified row of the array.

Demonstrate each of the functions in this program.
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

int getTotal(int data_array[][5], int row_ele, int column_ele)
{
    std::cout << "---getTotal---" << "\n";
    int sum{0};

    for(row_ele=0;row_ele<5;++row_ele)
    {
        for(column_ele=0;column_ele<5;++column_ele)
        {
            sum += data_array[row_ele][column_ele];
        }
    }
    return sum;
}

int getAverage(int data_array[][5], int row_ele, int column_ele)
{
    std::cout << "---getAverage---" << "\n";
    int sum,
        average;

    average = getTotal(data_array,row_ele,column_ele)/25;
    return average;
}

int getRowTotal(int data_array[][5], int row ,int row_ele, int column_ele)
{
    std::cout << "---getRowTotal---" << "\n";
    int sum;

    for(row_ele=0;row_ele<5;++row_ele)
    {
        for(column_ele=0;column_ele<5;++column_ele)
        {
            if(row_ele == row)
            {
                sum += data_array[row_ele][column_ele];
            }  
        }
    }

    return sum;
}

int getColumnTotal(int data_array[][5], int column ,int row_ele, int column_ele)
{
    std::cout << "---getColumnTotal---" << "\n";
    int sum;

    for(row_ele=0;row_ele<5;++row_ele)
    {
        for(column_ele=0;column_ele<5;++column_ele)
        {
            if(column_ele == column)
            {
                sum += data_array[row_ele][column_ele];
            }  
        }
    }
    return sum;
}

int getHighestInRow(int data_array[][5], int row ,int row_ele, int column_ele)
{
    std::cout << "---getHighestInRow---" << "\n";
    int largest{data_array[row][0]};

    for(column_ele=0;column_ele<5;++column_ele)
    {
        if(data_array[row][column_ele] > largest)
        {
            largest = data_array[row][column_ele];
        }  
    }
    
    return largest;
}

int getLowestInRow(int data_array[][5], int row ,int row_ele, int column_ele)
{
    std::cout << "---getLowestInRow---" << "\n";
    int lowest{data_array[row][0]};

    for(column_ele=0;column_ele<5;++column_ele)
    {
        if(data_array[row][column_ele] < lowest)
        {
            lowest = data_array[row][column_ele];
        }  
    }
    
    return lowest;
}

int main()
{
	char letter;
    int row_ele,
        column_ele,
        row,
        column;
    int data_array[5][5]{1,2,3,4,5,
                         6,7,8,9,10,
                         11,12,13,14,15,
                         16,17,18,19,20,
                         21,22,23,24,25};

	while(letter != 'n')
	{
        std::cout << getTotal(data_array,row_ele,column_ele) << "\n";
        std::cout << getAverage(data_array,row_ele,column_ele) << "\n";

        std::cout << "User, input a value for a row : "; 
            std::cin >> row;
            std::cout << getRowTotal(data_array,row,row_ele,column_ele) << "\n";

        std::cout << "User, input a value for a column : "; 
            std::cin >> column;
            std::cout << getColumnTotal(data_array,column,row_ele,column_ele) << "\n";

        std::cout << getHighestInRow(data_array,row,row_ele,column_ele) << "\n";
        std::cout << getLowestInRow(data_array,row,row_ele,column_ele) << "\n";

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}

