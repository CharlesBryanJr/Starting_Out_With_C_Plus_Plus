/*
Starting Out With C++ Chapter 7 – 5. Monkey Business
A local zoo wants to keep track of how many pounds of food each of its three monkeys eats each day during a typical week. 

Write a program that stores this information in a two-dimensional 3 × 5 array, where each row represents a different monkey and each column represents a different day of the week. 

The program should first have the user input the data for each monkey. 

Then it should create a report that includes the following information:
• Average amount of food eaten per day by the whole family of monkeys.
• The least amount of food eaten during the week by any one monkey.
• The greatest amount of food eaten during the week by any one monkey.

Input Validation: Do not accept negative numbers for pounds of food eaten.
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

int inputValidation_postiveInteger_array2D(int MonkeyBusiness[][5], int row_ele, int colmun_ele)
{
    std::cout << "For day " << colmun_ele+1 << ", how many pounds of food did monkey " << row_ele+1 << ", eat? : ";
    std::cin >> MonkeyBusiness[row_ele][colmun_ele];

    while( MonkeyBusiness[row_ele][colmun_ele] < 0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer" << "\n";
        std::cout << "For day " << colmun_ele+1 << ", how many pounds of food did monkey " << row_ele+1 << ", eat? : ";
            std::cin >> MonkeyBusiness[row_ele][colmun_ele];
    }
    return MonkeyBusiness[row_ele][colmun_ele];
}

void GET_monkeyData(int MonkeyBusiness[][5], const int SIZEof_MonkeyBusiness_rows, const int SIZEof_MonkeyBusiness_columns, int row_ele, int colmun_ele)
{
    std::cout << "---GET_monkeyData---" << "\n"; std::cout << " " << "\n";

    for(row_ele=0;row_ele<SIZEof_MonkeyBusiness_rows;++row_ele)
    {
        for(colmun_ele=0;colmun_ele<SIZEof_MonkeyBusiness_columns;++colmun_ele)
        {
            inputValidation_postiveInteger_array2D(MonkeyBusiness,row_ele,colmun_ele);
        }
    }
    std::cout << " " << "\n";
}

void Average_monkeyData(const int MonkeyBusiness[][5], const int SIZEof_MonkeyBusiness_rows, const int SIZEof_MonkeyBusiness_columns, int row_ele, int colmun_ele, int &average)
{
    std::cout << "---Average_monkeyData---" << "\n"; std::cout << " " << "\n";
    int total;

    for(row_ele=0;row_ele<SIZEof_MonkeyBusiness_rows;++row_ele)
    {
        for(colmun_ele=0;colmun_ele<SIZEof_MonkeyBusiness_columns;++colmun_ele)
        {
            total += MonkeyBusiness[row_ele][colmun_ele];
        }
    }
    average = total / (SIZEof_MonkeyBusiness_rows * SIZEof_MonkeyBusiness_columns);
    std::cout << "The Average amount of food eaten per day by the whole family of monkeys was : " << average << '\n';
}

void LEAST_food(const int MonkeyBusiness[][5], const int SIZEof_MonkeyBusiness_rows, const int SIZEof_MonkeyBusiness_columns, int row_ele, int colmun_ele, int &LEAST)
{
    std::cout << "---LEAST_food---" << "\n"; std::cout << " " << "\n";
    LEAST = MonkeyBusiness[0][0];
    int r_ele,
        c_ele;

    for(row_ele=0;row_ele<SIZEof_MonkeyBusiness_rows;++row_ele)
    {
        for(colmun_ele=0;colmun_ele<SIZEof_MonkeyBusiness_columns;++colmun_ele)
        {
            if(MonkeyBusiness[row_ele][colmun_ele]<LEAST)
            {
                LEAST = MonkeyBusiness[row_ele][colmun_ele];
            }
        }
    }

    for(row_ele=0;row_ele<SIZEof_MonkeyBusiness_rows;++row_ele)
    {
        for(colmun_ele=0;colmun_ele<SIZEof_MonkeyBusiness_columns;++colmun_ele)
        {
            if(MonkeyBusiness[row_ele][colmun_ele] == LEAST)
            {
                r_ele = row_ele;
                c_ele = colmun_ele;
            }
        }
    }

    std::cout << "Monkey " << r_ele+1 << ", on day " << c_ele+1 << " ate the LEAST amount of food during the week : " << LEAST << '\n';
}

void MOST_food(const int MonkeyBusiness[][5], const int SIZEof_MonkeyBusiness_rows, const int SIZEof_MonkeyBusiness_columns, int row_ele, int colmun_ele, int &MOST)
{
    std::cout << "---MOST_food---" << "\n"; std::cout << " " << "\n";
    MOST = MonkeyBusiness[0][0];
    int r_ele,
        c_ele;

    for(row_ele=0;row_ele<SIZEof_MonkeyBusiness_rows;++row_ele)
    {
        for(colmun_ele=0;colmun_ele<SIZEof_MonkeyBusiness_columns;++colmun_ele)
        {
            if(MonkeyBusiness[row_ele][colmun_ele]>MOST)
            {
                MOST = MonkeyBusiness[row_ele][colmun_ele];
            }
        }
    }

    for(row_ele=0;row_ele<SIZEof_MonkeyBusiness_rows;++row_ele)
    {
        for(colmun_ele=0;colmun_ele<SIZEof_MonkeyBusiness_columns;++colmun_ele)
        {
            if(MonkeyBusiness[row_ele][colmun_ele] == MOST)
            {
                r_ele = row_ele;
                c_ele = colmun_ele;
            }
        }
    }

    std::cout << "Monkey " << r_ele+1 << ", on day " << c_ele+1 << " ate the MOST amount of food during the week : " << MOST << '\n';
}

int main()
{
	char letter;
    int row_ele,
        colmun_ele,
        SIZEof_MonkeyBusiness_rows{3},
        SIZEof_MonkeyBusiness_columns{5},
        average,
        LEAST,
        MOST;
    int MonkeyBusiness[SIZEof_MonkeyBusiness_rows][5];


	while(letter != 'n')
	{
        GET_monkeyData(MonkeyBusiness, SIZEof_MonkeyBusiness_rows, SIZEof_MonkeyBusiness_columns, row_ele, colmun_ele); std::cout << " " << "\n";
        Average_monkeyData(MonkeyBusiness, SIZEof_MonkeyBusiness_rows, SIZEof_MonkeyBusiness_columns, row_ele, colmun_ele, average); std::cout << " " << "\n";
        LEAST_food(MonkeyBusiness, SIZEof_MonkeyBusiness_rows, SIZEof_MonkeyBusiness_columns, row_ele, colmun_ele, LEAST); std::cout << " " << "\n";
        MOST_food(MonkeyBusiness, SIZEof_MonkeyBusiness_rows, SIZEof_MonkeyBusiness_columns, row_ele, colmun_ele, MOST); std::cout << " " << "\n";
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}