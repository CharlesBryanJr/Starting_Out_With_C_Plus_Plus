/*
Starting Out With C++ Chapter 10 Characters, C-Strings, and More About the string Class 3. Word Counter

Write a function that accepts a pointer to a C-string as an argument and returns the number of words contained in the string. 
For instance, if the string argument is “Four score and seven years ago” the function should return the number 6. 
Demonstrate the function in a program that asks the user to input a string and then passes it to the function. 
The number of words in the string should be displayed on the screen. Optional

Exercise: Write an overloaded version of this function that accepts a string class object as its argument.
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

double inputValidation_postiveInteger_array(double postiveInteger_array[], const int &ele)
{
	std::cin >> postiveInteger_array[ele];

    while( postiveInteger_array[ele] < 0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "Input again : ";
            std::cin >> postiveInteger_array[ele];
    }
    return postiveInteger_array[ele];
}

int inputValidation_postiveInteger_array2D(int MonkeyBusiness[][5], const int row_ele, const int column_ele)
{
    std::cin >> MonkeyBusiness[row_ele][column_ele];

    while( MonkeyBusiness[row_ele][column_ele] < 0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer" << "\n";
        std::cout << "Input again : ";
            std::cin >> MonkeyBusiness[row_ele][column_ele];
    }
    return MonkeyBusiness[row_ele][column_ele];
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

void WordCounter(const char * const CstringArray, const int &sizeOf_CstringArray, int &ele )
{
    std::cout << "----WordCounter----" << "\n"; std::cout << " " << "\n";

    int WordCount{1}; // count the last word

    ele = 0;
    while( *(CstringArray+ele) != '\0' )
    {
        if( *(CstringArray+ele) == ' ' )
        {
            ++WordCount;
        }

        ++ele;
    }

    std::cout << "This string has " << WordCount << " words." << "\n";
    std::cout << " " << "\n";
}

int main()
{
    char letter;
    int ele,
        sizeOf_CstringArray{1000};

	while(letter != 'n')
	{
		std::cout << "Starting Out With C++ Chapter 10 Characters, C-Strings, and More About the string Class 3. Word Counter" << "\n";
            std::cout << "Write a function that accepts a pointer to a C-string as an argument and returns the number of words contained in the string." << "\n";
            std::cout << "For instance, if the string argument is “Four score and seven years ago” the function should return the number 6." << "\n";
            std::cout << "Demonstrate the function in a program that asks the user to input a string and then passes it to the function." << "\n";
                std::cout << " " << "\n";
            std::cout << "The number of words in the string should be displayed on the screen. Optional" << "\n";
                std::cout << " " << "\n";
            std::cout << "Exercise: Write an overloaded version of this function that accepts a string class object as its argument." << "\n";
        
        char *ptr_CstringArray{nullptr};
            ptr_CstringArray = new char[sizeOf_CstringArray];

        std::cout << "User, input a string and this program will count the amount of words." << "\n";
            std::cin.getline(ptr_CstringArray,sizeOf_CstringArray);
        
        characterCounter(ptr_CstringArray,ele);
        
        BackwardString(ptr_CstringArray,sizeOf_CstringArray,ele);
        
        WordCounter(ptr_CstringArray,sizeOf_CstringArray,ele);

        delete[] ptr_CstringArray;
            ptr_CstringArray = nullptr;

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
			inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}