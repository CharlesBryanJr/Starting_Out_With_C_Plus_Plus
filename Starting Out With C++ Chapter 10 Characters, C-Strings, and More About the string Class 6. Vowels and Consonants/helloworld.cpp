/*
Starting Out With C++ Chapter 10 Characters, C-Strings, and More About the string Class 6. Vowels and Consonants
Write a function that accepts a pointer to a C-string as its argument. 
The function should count the number of vowels appearing in the string and return that number.

Write another function that accepts a pointer to a C-string as its argument. 
This function should count the number of consonants appearing in the string and return that number.

Demonstrate these two functions in a program that performs the following steps:
1. The user is asked to enter a string.

2. The program displays the following menu:
	A) Count the number of vowels in the string
	B) Count the number of consonants in the string
	C) Count both the vowels and consonants in the string
	D) Enter another string
	E) Exit the program

3. The program performs the operation selected by the user and repeats until the user selects E to exit the program.
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

int WordCounter( const char * const ptr_CstringArray, const int &sizeOf_CstringArray, int &ele )
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
    return WordCount;
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

    std::cout << "The words in this string have an Average Number of Letters of " << AverageNumberOfLetters << "\n";
    std::cout << " " << "\n";
}

void SentenceCapitalizer( char * const ptr_CstringArray, const int &sizeOf_CstringArray, int &ele )
{
    std::cout << "----SentenceCapitalizer----" << "\n"; std::cout << " " << "\n";
    
    bool firstWord{false}; // Is it a guarentee that the first word capitalized?
    for(ele = 0; ele<(sizeOf_CstringArray-1); ++ele) // ele 1000 == '\0' 
    {
        if(firstWord == false)
        {
            if( *(ptr_CstringArray+ele) != ' ')
            {
                *(ptr_CstringArray+ele) = toupper( *(ptr_CstringArray+ele) );
                firstWord = true;
            }
        }
    }

    ele = 0;
    while( *(ptr_CstringArray+ele) != '\0' )
    {
        if( *(ptr_CstringArray+ele) == '.' && *(ptr_CstringArray+ele+1) == ' ' )
        {
            *(ptr_CstringArray+ele+2) = toupper( *(ptr_CstringArray+ele+2) );
        }
        ++ele;
    }

    ele = 0;
    while( *(ptr_CstringArray+ele) != '\0' )
    {
        std::cout << *(ptr_CstringArray+ele);
        ++ele;
    }

    std::cout << " " << "\n";
}

void VowelCounter( const char * const ptr_CstringArray, const int &sizeOf_CstringArray, int &ele )
{
    std::cout << "----VowelCounter----" << "\n"; std::cout << " " << "\n";

    int VowelCount{0};

    ele = 0;
    while( *(ptr_CstringArray+ele) != '\0' )
    {
        // vowels are 'a', 'e', 'i', 'o' and 'u'.
        if( tolower(*(ptr_CstringArray+ele)) == 'a' || 
            tolower(*(ptr_CstringArray+ele)) == 'e' ||
            tolower(*(ptr_CstringArray+ele)) == 'i' ||
            tolower(*(ptr_CstringArray+ele)) == 'o' ||
            tolower(*(ptr_CstringArray+ele)) == 'u' ) 
        {
            ++VowelCount;
        }

        ++ele;
    }

    std::cout << "This string has " << VowelCount << " vowels." << "\n";
    std::cout << " " << "\n";
}

void ConsonantsCounter( const char * const ptr_CstringArray, const int &sizeOf_CstringArray, int &ele )
{
    std::cout << "----ConsonantsCounter----" << "\n"; std::cout << " " << "\n";

    int ConsonantsCount{0};
    ele = 0;
    while( *(ptr_CstringArray+ele) != '\0' )
    {
        if( tolower(*(ptr_CstringArray+ele)) == 'b' || 
            tolower(*(ptr_CstringArray+ele)) == 'c' ||
            tolower(*(ptr_CstringArray+ele)) == 'd' ||
            tolower(*(ptr_CstringArray+ele)) == 'f' ||
            tolower(*(ptr_CstringArray+ele)) == 'g' ||
            tolower(*(ptr_CstringArray+ele)) == 'j' || 
            tolower(*(ptr_CstringArray+ele)) == 'k' ||
            tolower(*(ptr_CstringArray+ele)) == 'l' ||
            tolower(*(ptr_CstringArray+ele)) == 'm' ||
            tolower(*(ptr_CstringArray+ele)) == 'n' ||
            tolower(*(ptr_CstringArray+ele)) == 'p' || 
            tolower(*(ptr_CstringArray+ele)) == 'q' ||
            tolower(*(ptr_CstringArray+ele)) == 's' ||
            tolower(*(ptr_CstringArray+ele)) == 't' ||
            tolower(*(ptr_CstringArray+ele)) == 'v' ||
            tolower(*(ptr_CstringArray+ele)) == 'x' ||
            tolower(*(ptr_CstringArray+ele)) == 'z' || 
            tolower(*(ptr_CstringArray+ele)) == 'h' ||
            tolower(*(ptr_CstringArray+ele)) == 'r' ||
            tolower(*(ptr_CstringArray+ele)) == 'w' ||
            tolower(*(ptr_CstringArray+ele)) == 'y'  ) 
        {
            ++ConsonantsCount;
        }

        ++ele;
    }

    std::cout << "This string has " << ConsonantsCount << " consonants." << "\n";
    std::cout << " " << "\n";
}

int main()
{
    char letter,
         userChoice;

    int ele,
        sizeOf_CstringArray{1001};
    
    char *ptr_stringObject_nowCstringArray[sizeOf_CstringArray];
    std::string mystring;
    
    char *ptr_CstringArray{nullptr};
        ptr_CstringArray = new char[sizeOf_CstringArray];

	while(letter != 'n')
	{
        std::cout << "User, input a string." << "\n";
            std::cin.getline(ptr_CstringArray,sizeOf_CstringArray); std::cout << " " << "\n";
            
        std::cout << "A) Count the number of vowels in the string." << "\n";
        std::cout << "B) Count the number of consonants in the string." << "\n";
        std::cout << "C) Count both the vowels and consonants in the string." << "\n";
        std::cout << "D) Enter another string." << "\n";
        std::cout << "Z) Run everything." << "\n";
        std::cout << "E) Exit the program." << "\n";
            std::cin >> userChoice;

        while(tolower(userChoice) != 'e')
        {
            if(tolower(userChoice) == 'd') // Enter another string.
            {
                std::cout << "User, input a string." << "\n";
                    std::cin >> mystring;
                    std::strcpy(*ptr_stringObject_nowCstringArray, mystring.c_str());
                
                std::cout << "A) Count the number of vowels in the string." << "\n";
                std::cout << "B) Count the number of consonants in the string." << "\n";
                std::cout << "C) Count both the vowels and consonants in the string." << "\n";
                std::cout << "D) Enter another string." << "\n";
                std::cout << "Z) Run everything." << "\n";
                std::cout << "E) Exit the program." << "\n";
                    std::cin >> userChoice;
            }
            if(tolower(userChoice) == 'b') // Count the number of consonants in the string.
            {
                ConsonantsCounter(ptr_CstringArray,sizeOf_CstringArray,ele);
            }
            if(tolower(userChoice) == 'c') // Count both the vowels and consonants in the string.
            {
                VowelCounter(ptr_CstringArray,sizeOf_CstringArray,ele);
                ConsonantsCounter(ptr_CstringArray,sizeOf_CstringArray,ele);
            }
            if(tolower(userChoice) == 'a') // Count the number of vowels in the string.
            {
                VowelCounter(ptr_CstringArray,sizeOf_CstringArray,ele);
            }
            if(tolower(userChoice) == 'z') // run everything
            {
                characterCounter(ptr_CstringArray,ele);
                
                BackwardString(ptr_CstringArray,sizeOf_CstringArray,ele);
                
                WordCounter(ptr_CstringArray,sizeOf_CstringArray,ele);

                AverageNumberOfLetters(ptr_CstringArray,sizeOf_CstringArray,ele);

                SentenceCapitalizer(ptr_CstringArray,sizeOf_CstringArray,ele);

                VowelCounter(ptr_CstringArray,sizeOf_CstringArray,ele);

                ConsonantsCounter(ptr_CstringArray,sizeOf_CstringArray,ele);
            }
            
            std::cout << "A) Count the number of vowels in the string." << "\n";
            std::cout << "B) Count the number of consonants in the string." << "\n";
            std::cout << "C) Count both the vowels and consonants in the string." << "\n";
            std::cout << "D) Enter another string." << "\n";
            std::cout << "Z) Run everything." << "\n";
            std::cout << "E) Exit the program." << "\n";
                std::cin >> userChoice;
        }

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
			inputValidation_y_or_n(letter);	std::cout << " " << "\n";
    }

    delete[] ptr_CstringArray;
        ptr_CstringArray = nullptr;
	
	return 0;
}