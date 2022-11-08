/*
1. Charge Account Validation
Write a program that lets the user enter a charge account number. 
The program should determine if the number is valid by checking for it in the following list:
5658845 4520125 7895122 8777541 8451277 1302850
8080152 4562555 5552012 5050552 7825877 1250255
1005231 6545231 3852085 7576651 7881200 4581002
The list of numbers above should be initialized in a single-dimensional array. 
A simple linear search should be used to locate the number entered by the user. 
If the user enters a number that is in the array, the program should display a message saying that the number is valid. 
If the user enters a number that is not in the array, the program should display a message indicating that the number is invalid.
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

void initialize_account_numbers(std::vector<int> &account_numbers, 
                                const int account_numbers_array[], 
                                const int &sizeOF_account_numbers, 
                                int &index)
{
    std::cout << "---initialize_account_numbers---" << "\n"; std::cout << " " << "\n";
    for(index=0;index<sizeOF_account_numbers;++index)
    {
        account_numbers.push_back(account_numbers_array[index]);
    }
}

void GET_account_number(int &account_number)
{
    std::cout << "---GET_account_number---" << "\n"; std::cout << " " << "\n";

    std::cout << "User, input an account number : ";
        std::cin >> account_number;

    std::cout << " " << "\n";
}

void linear_search(std::vector<int> &account_numbers, int &index, int &account_number)
{
    std::cout << "---linear_search---" << "\n"; std::cout << " " << "\n";
    bool found = false; // allow us to stop the while loop if the desired value is found.
    index = 0;
    int postion{-1}; // store the index of the desired account number

    while( index<account_numbers.size() && (found == false) )
    {
        if(account_numbers[index] == account_number)
        {
            postion = index;
            found = true;
        }
        ++index;
    }

    if(found) // found==true
    {
        std::cout << "number is valid, found in postion : " << postion+1 << '\n';
    }
    else //found == false
    {
        std::cout << "number is invalid." << '\n';
    }

    std::cout << " " << "\n";
}

int main()
{
	char letter;
    int index,
        sizeOF_account_numbers{18},
        account_number;
    int account_numbers_array[sizeOF_account_numbers]{5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
                                                      8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                                                      1005231, 6545231, 3852085, 7576651, 7881200, 4581002};
    std::vector<int> account_numbers;

	while(letter != 'n')
	{
        initialize_account_numbers(account_numbers, account_numbers_array, sizeOF_account_numbers, index);
        GET_account_number(account_number);
        linear_search(account_numbers, index, account_number);

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}

