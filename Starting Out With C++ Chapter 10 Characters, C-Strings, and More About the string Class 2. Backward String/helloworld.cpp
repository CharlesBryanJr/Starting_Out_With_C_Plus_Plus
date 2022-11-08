/*
Starting Out With C++ Chapter 10 Characters, C-Strings, and More About the string Class 2. Backward String
Write a function that accepts a pointer to a C-string as an argument and displays its contents backward. 
For instance, if the string argument is “ Gravity” the function should display “ ytivarG”. 
Demonstrate the function in a program that asks the user to input a string and then passes it to the function.
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

void BackwardString( const char * const ptr_Cstring, const int &sizeOF_ptr_Cstring, int &ele )
{
    std::cout << "----BackwardString----" << "\n"; std::cout << " " << "\n";	

    if ( *(ptr_Cstring+0) == ' ' ) 
    {
        std::cout << " ";
    }
    
    ele = sizeOF_ptr_Cstring-1; // subtract one for the null character '\0'

    while( ele >= 0 ) // because the last charcter might be an actual character.
    {
        std::cout << *(ptr_Cstring+ele);
        --ele;
    }
    std::cout << " " << "\n";			
}

int main()
{
    char letter;
    int ele;
    int sizeOF_ptr_Cstring{1001};

	while(letter != 'n')
	{
		std::cout << "Starting Out With C++ Chapter 10 Characters, C-Strings, and More About the string Class 2. Backward String" << "\n";
        std::cout << "Write a function that accepts a pointer to a C-string as an argument and displays its contents backward." << "\n";
        std::cout << "For instance, if the string argument is “ Gravity” the function should display “ ytivarG”." << "\n";
        std::cout << "Demonstrate the function in a program that asks the user to input a string and then passes it to the function." << "\n";

        char *ptr_Cstring{nullptr};
            ptr_Cstring = new char[sizeOF_ptr_Cstring];

        std::cout << "User, input a string to be reversed/inverted/printed backwards. : " << "\n";
            std::cin.getline(ptr_Cstring,sizeOF_ptr_Cstring);
        
        BackwardString(ptr_Cstring,sizeOF_ptr_Cstring,ele);

        delete[] ptr_Cstring;
            ptr_Cstring = nullptr;

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
			inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}