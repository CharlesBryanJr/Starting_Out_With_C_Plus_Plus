/*
Starting Out With C++ Chapter 10 Characters, C-Strings, and More About the string Class – 1. String Length
Write a function that returns an integer and accepts a pointer to a C-string as an argument. 
The function should count the number of characters in the string and return that number. 
Demonstrate the function in a simple program that asks the user to input a string, passes it to the function, and then displays the function’s return value.
*/

#include <iostream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <cctype>
#include <cstring>
#include <string>
#include <cstdlib>

char inputValidation_y_or_n(char &letter)
{
    std::cin >> letter;
		while (tolower(letter) != 'y' && tolower(letter) != 'n')
    {
        std::cout << "ERROR: a 'y' or an 'n' must be entered: ";
        std::cin.clear();
        std::cin >> letter;
    }
    return letter;
}

int inputValidation_postiveInteger(int &ref_number)
{
    std::cin >> ref_number;

    while( ref_number<0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "Input again : ";
            std::cin >> ref_number;
    }
    return ref_number;
}

void characterCounter(char *ptr_CstringArray, int &ele)
{
    std::cout << "---characterCounter---" << "\n"; std::cout << " " << "\n";
    int count{0}; //declare counter variable to count number of chars and return it, initialize to 0

    while( *(ptr_CstringArray+count) != '\0' )
    {
        ++count;
    }

    std::cout << "This Cstring has " << count << " characters." << "\n";
    std::cout << " " << "\n";
}

int main()
{
    char letter;
    int ele,
        CstringarraySIZE{21}; // Cstring Array size

	while(letter != 'n')
	{
        char *ptr_CstringArray = {nullptr};
            ptr_CstringArray = new char[CstringarraySIZE];
            //*(ptr_CstringArray+CstringarraySIZE) = '\0';
                    
        std::cout << "Enter a string with a maximum of 20 characters and I will show you how many characters it has!" << "\n";
            std::cin.getline(ptr_CstringArray,CstringarraySIZE);

        characterCounter(ptr_CstringArray,ele);

        delete ptr_CstringArray;
            ptr_CstringArray = nullptr;

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
			inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}
