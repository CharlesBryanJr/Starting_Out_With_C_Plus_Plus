/*
Starting Out With C++ Chapter 8 – 2. Lottery Winners
A lottery ticket buyer purchases 10 tickets a week, always playing the same 10 5-digit “lucky” combinations. 
Write a program that initializes an array or a vector with these numbers 
and then lets the player enter this week’s winning 5-digit number.
The program should perform a linear search through the list of the player’s numbers
and report whether or not one of the tickets is a winner this week. 
Here are the numbers:
13579 26791 26792 33445 55555
62483 77777 79422 85647 93121
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

void initialize_lotteryNumbers(std::vector<int> &lotteryTickets, 
                               const int lotteryNumbers_array[], 
                               const int sizeOF_lotteryNumbers_array,
                               int &ele)
{
    std::cout << "---initialize_lotteryNumbers---" << "\n"; std::cout << " " << "\n";

    for(ele=0;ele<sizeOF_lotteryNumbers_array;++ele)
    {
        lotteryTickets.push_back(lotteryNumbers_array[ele]);
    }
}

void get_lotteryNumbers(int &lotteryNumbers)
{
    std::cout << "---get_lotteryNumbers---" << "\n"; std::cout << " " << "\n";

    std::cout << "User, input the this week's winning 5-digit number : ";
        std::cin >> lotteryNumbers;

    std::cout << " " << "\n";
}

void check_lotteryTickets(const std::vector<int> &lotteryTickets, 
                          int &ele,
                          const int &lotteryNumbers)
{
    std::cout << "---check_lotteryTickets---" << "\n"; std::cout << " " << "\n";
    //bool found{false};
    int postion{-1}; 
    ele = 0;

    while(ele<lotteryTickets.size() && postion == -1)
    {
        if(lotteryTickets[ele] == lotteryNumbers)
        {
            postion = ele;
            //found = true;
        }
        ++ele;
    }

    if(postion != -1) // or found == true 
    {
        std::cout << "YOU WIN!" << "\n";
        std::cout << "Ticket number " << postion+1 << ", was the winning ticket." << "\n";
    }
    else // postion == -1 or found == false
    {
        std::cout << "Better luck next time." << "\n";
    }

    std::cout << " " << "\n";
}

int main()
{
	char letter;
    int ele,
        sizeOF_lotteryTickets_array{10},
        lotteryNumbers; // wining lotto numbers
    int lotteryTickets_array[sizeOF_lotteryTickets_array]{13579, 26791, 26792, 33445, 55555,
                                                          62483, 77777, 79422, 85647, 93121};
    std::vector<int> lotteryTickets;

	while(letter != 'n')
	{
        initialize_lotteryNumbers(lotteryTickets, 
                                  lotteryTickets_array, 
                                  sizeOF_lotteryTickets_array,
                                  ele);

        get_lotteryNumbers(lotteryNumbers);

        check_lotteryTickets(lotteryTickets,
                             ele,
                             lotteryNumbers);
        
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}

