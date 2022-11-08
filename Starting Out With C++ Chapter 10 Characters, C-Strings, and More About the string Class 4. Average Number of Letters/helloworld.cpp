/*
Starting Out With C++ Chapter 10 Characters, C-Strings, and More About the string Class 4. Average Number of Letters

Modify the program you wrote for Problem 3 (Word Counter), so it also displays the average number of letters in each word.
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

int characterCounter( const char *ptr_CstringArray, int &ele )
{
    std::cout << "---characterCounter---" << "\n"; std::cout << " " << "\n";
    int count{0}; //declare counter variable to count number of chars and return it, initialize to 0

    while( *(ptr_CstringArray+count) != '\0' )
    {
        ++count;
    }

    std::cout << "This Cstring has " << count << " characters." << "\n";
    std::cout << " " << "\n";

    return count;
}

void BackwardString( const char * const ptr_CstringArray, const int &sizeOF_ptr_Cstring, int &ele )
{
    std::cout << "----BackwardString----" << "\n"; std::cout << " " << "\n";	

    if ( *(ptr_CstringArray+0) == ' ' ) 
    {
        std::cout << " ";
    }
    
    ele = sizeOF_ptr_Cstring-1; // subtract one for the null character '\0'

    while( ele >= 0 ) // because the last charcter might be an actual character.
    {
        std::cout << *(ptr_CstringArray+ele);
        --ele;
    }
    std::cout << " " << "\n";			
}

void WordCounter( const char * const ptr_CstringArray, const int &sizeOf_CstringArray, int &ele )
{
    std::cout << "----WordCounter Cstring Array----" << "\n"; std::cout << " " << "\n";

    int WordCount{1}; // count the last word

    ele = 0;
    while( *(ptr_CstringArray+ele) != '\0' )
    {
        if( *(ptr_CstringArray+ele) == ' ' )
        {
            ++WordCount;
        }

        ++ele;
    }

    std::cout << "This string has " << WordCount << " words." << "\n";
    std::cout << " " << "\n";
}

void AverageNumberOfLetters( const char * const ptr_CstringArray, const int &sizeOf_CstringArray, int &ele )
{
    std::cout << "----AverageNumberOfLetters----" << "\n"; std::cout << " " << "\n";

    int WordCount{1}, // count the last word
        AverageNumberOfLetters;

    ele = 0;
    while( *(ptr_CstringArray+ele) != '\0' )
    {
        if( *(ptr_CstringArray+ele) == ' ' )
        {
            ++WordCount;
        }
        ++ele;
    }

    int nonLetterCount{0};
    ele = 0;
    while( *(ptr_CstringArray+ele) != '\0' )
    {
        if( *(ptr_CstringArray+ele) == '.' || *(ptr_CstringArray+ele) == ',' )
        {
            ++nonLetterCount;
        }

        ++ele;
    }

    AverageNumberOfLetters = (characterCounter(ptr_CstringArray,ele) - nonLetterCount - WordCount-1) / WordCount;

    std::cout << "The words in this string has an average Number of Letters of " << AverageNumberOfLetters << "\n";
    std::cout << " " << "\n";
}

int main()
{
    char letter;
    int ele,
        sizeOf_CstringArray{1000};

	while(letter != 'n')
	{
        char *ptr_CstringArray{nullptr};
            ptr_CstringArray = new char[sizeOf_CstringArray];

        std::cout << "User, input a string and this program will count the amount of words." << "\n";
            std::cin.getline(ptr_CstringArray,sizeOf_CstringArray);
        
        characterCounter(ptr_CstringArray,ele);
        
        BackwardString(ptr_CstringArray,sizeOf_CstringArray,ele);
        
        WordCounter(ptr_CstringArray,sizeOf_CstringArray,ele);

        AverageNumberOfLetters(ptr_CstringArray,sizeOf_CstringArray,ele);

        delete[] ptr_CstringArray;
            ptr_CstringArray = nullptr;

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
			inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}