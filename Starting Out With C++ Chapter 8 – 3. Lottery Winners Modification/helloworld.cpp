/*
Starting Out With C++ Chapter 8 – 3. Lottery Winners Modification
Modify the program you wrote for Programming Challenge 2 (Lottery Winners) so it performs a binary search instead of a linear search.

A lottery ticket buyer purchases 10 tickets a week, always playing the same 10 5-digit
“lucky” combinations. Write a program that initializes an array or a vector with
these numbers and then lets the player enter this week’s winning 5-digit number.
The program should perform a linear search through the list of the player’s numbers
and report whether or not one of the tickets is a winner this week. Here are the
numbers:
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

void binarySearch_lotteryTickets(const std::vector<int> &lotteryTickets, 
                                 const int &lotteryNumbers)
{
    std::cout << "---binarySearch_lotteryTickets---" << "\n"; std::cout << " " << "\n";
    bool found{false};
    int position{-1},
        first{0}, // first element of the vector
        last = lotteryTickets.size()-1, // last element of the vector
        middle; // middle element of the vector

    while( first<=last && found == false ) // postion == -1
    {
        middle = (first + last) / 2; // Calculate midpoint
        if (lotteryTickets[middle] == lotteryNumbers) // If value is found at mid
        {
            position = middle;
            found = true;
        }
        else if (lotteryTickets[middle] > lotteryNumbers) // If value is in lower half
        {
            last = middle - 1;
        }
        else // lotteryTickets[middle] < lotteryNumbers (If value is in upper half)
        {
            first = middle + 1; // If value is in upper half
        }
    }

    if( found == true ) // position != -1
    {
        std::cout << "YOU WIN!" << "\n";
        std::cout << "Ticket number " << position+1 << ", was the winning ticket." << "\n";
    }
    else // found == false or position == -1 
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

        binarySearch_lotteryTickets(lotteryTickets,
                                    lotteryNumbers);
        
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}