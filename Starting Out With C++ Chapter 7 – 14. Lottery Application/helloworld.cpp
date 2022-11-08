/*
Starting Out With C++ Chapter 7 – 14. Lottery Application
Write a program that simulates a lottery. 
The program should have an array of five integers named lottery  and should generate a random number in the range of 0 through 9 for each element in the array. 

The user should enter five digits, which should be stored in an integer array named user. 

The program is to compare the corresponding elements in the two arrays and keep a count of the digits that match. 

For example, the following shows the lottery array and the user array with sample numbers stored in each. 

There are two matching digits (elements 2 and 4).
lottery array: 7 4 9 1 3
user array: 4 2 9 7 3

The program should display the random numbers stored in the lottery array and the number of matching digits. 

If all of the digits match, display a message proclaiming the user as a grand prize winner.
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

int inputValidation_postiveInteger_array(int user[], const int &ele)
{
	std::cout << "User for number " << ele+1 << ", input an integer from 0 - 9, : ";
        std::cin >> user[ele];

    while( (user[ele] < 0) || (user[ele] > 9) )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be an integer from 0 - 9." << "\n";
	    std::cout << "User for number " << ele+1 << ", input an integer from 0 - 9, : ";
            std::cin >> user[ele];
    }
    return user[ele];
}

void GET_user_lottery_application(int user[], const int &SIZEofarray, int &ele)
{
    std::cout << "--- GET_user_lottery_application --- " << "\n"; std::cout << " " << "\n";

    for(ele=0;ele<SIZEofarray;++ele)
    {
        inputValidation_postiveInteger_array(user, ele);
    }
    std::cout << " " << "\n";
}

void GET_lottery_numbers(int lottery[], const int &SIZEofarray, int &ele)
{
    std::cout << "--- GET_lottery_numbers --- " << "\n"; std::cout << " " << "\n";

    for(ele=0;ele<SIZEofarray;++ele)
    {
        lottery[ele] = rand() % 9 + 1;
    }
    std::cout << " " << "\n";
}

void lottery_application(int lottery[], const int user[], const int &SIZEofarray, int &ele)
{
    std::cout << "--- lottery_application --- " << "\n"; std::cout << " " << "\n";
    int score{0};

    for(ele=0;ele<SIZEofarray;++ele)
    {
        std::cout << "For number " << ele+1 << "," << "\n";
        std::cout << "User, you guessed : " << user[ele] << "\n";
        std::cout << "The lottery number was : " << lottery[ele] << "\n";
        std::cout << " " << "\n";
        
        if( user[ele] == lottery[ele] )
        {
            score += 1;
        }
    }

    if(score == 5)
    {
        std::cout << "---grand prize winner---" << "\n";
    }
    else
    {
        std::cout << "User, you correctly guessed " << score << " numbers out of " << SIZEofarray << "\n";
    }

    std::cout << " " << "\n";
}

int main()
{
	char letter;
    int ele,
        SIZEofarray{5};
    int lottery[SIZEofarray],
        user[SIZEofarray];

	while(letter != 'n')
	{
        GET_user_lottery_application(user,SIZEofarray,ele);
        GET_lottery_numbers(lottery,SIZEofarray,ele);
        lottery_application(lottery,user,SIZEofarray,ele);

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}

