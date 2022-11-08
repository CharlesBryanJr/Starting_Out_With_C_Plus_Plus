/*
Starting Out With C++ Chapter 8 – 4. Charge Account Validation Modification

Modify the program you wrote for Problem 1 (Charge Account Validation) so it performs a binary search to locate valid account numbers.

Use the selection sort algorithm to sort the array before the binary search is performed.

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

void selectionSort(std::vector<int> &account_numbers)
{
    int index_startScan, // starting element of elements left to be sorted
        minIndex, // index that stores the minimum value of the elements left to be sorted
        minValue; // minimum value of the elements left to be sorted

    for (index_startScan = 0; index_startScan < (account_numbers.size() - 1); ++index_startScan)
    {
        // assign the starting element, of elements left to be sorted, 
        // to the index, that stores the minimum value of the elements left to be sorted. 
        minIndex = index_startScan;

        // assign the value stored inside the starting element, of elements left to be sorted, 
        // to the varaible that stores the minimum value of the elements left to be sorted.
        minValue = account_numbers[index_startScan];

        for(int index = index_startScan + 1; index < account_numbers.size(); index++)
        {
            if (account_numbers[index] < minValue) // if we found a new minimum value
            {
                // update & store the new minimum value 
                    minValue = account_numbers[index]; 

                // update & store the index that stores the new minimum value 
                    minIndex = index;
            }
        }

        // replace the index that stores the new minimum value with the index that stores the first index that was checked. 
        account_numbers[minIndex] = account_numbers[index_startScan]; 

        // replace the first index that was checked with the index that stores the new minimum value.
        account_numbers[index_startScan] = minValue;
    }
}

void binary_search(std::vector<int> &account_numbers, int &account_number)
{
    std::cout << "---binary_search---" << "\n"; std::cout << " " << "\n";
    bool found = false; // allow us to stop the while loop if the desired value is found.
    int postion{-1}, // store the index of the desired account number
        first{0}, // first index in the array
        last = account_numbers.size()-1, // last value in the array
        middle; // middle index in the array (also the index were checking)

    while( first<=last && (found == false) )
    {
        middle = (first + last) / 2;
        if(account_numbers[middle] == account_number)
        {
            postion = middle;
            found = true;
        }
        
        if(account_numbers[middle] > account_number) // if account number exist, it exist in the front half
        {
            last = middle - 1;
        }

        if(account_numbers[middle] < account_number) // if account number exist, it exist in the back half
        {
            first = middle + 1;
        }
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
        selectionSort(account_numbers);
        GET_account_number(account_number);
        binary_search(account_numbers, account_number);

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}