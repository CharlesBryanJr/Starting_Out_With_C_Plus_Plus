/*
Starting Out With C++ Chapter 10 Characters, C-Strings, and More About the string Class 7. Name Arranger
Write a program that asks for the user’s first, middle, and last names. 
The names should be stored in three different character arrays. 
The program should then store, in a fourth array, the name arranged in the following manner: the last name followed by a comma and a space, followed by the first name and a space, followed by the middle name. 
For example, if the user entered “ Carol Lynn Smith”, it should store “ Smith, Carol Lynn” in the fourth array. Display the contents of the fourth array on the screen.
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

void NameArranger(const char firstNameArray[], 
                 const char middleNameArray[], 
                 const char lastNameArray[], 
                 char * const ptr_CstringArray, 
                 const int &sizeOf_CstringArray, 
                 int &ele )
{
    std::cout << "---NameArranger---" << "\n"; std::cout << " " << "\n";
    int start_FirstNameArray{-1},
        start_MiddleNameArray{-1},
        end_MiddleNameArray{-1};
    

    for(ele = 0; ele < sizeOf_CstringArray; ++ele) 
    {
        if( (lastNameArray[ele] == ' ') && (lastNameArray[ele+1] == ' ') && (start_FirstNameArray == -1) )
        {
            start_FirstNameArray = ele+3;
        }
        if(firstNameArray[ele] == ' ' &&  firstNameArray[ele+1] == ' ' && (start_MiddleNameArray == -1) )
        {
            start_MiddleNameArray = ele+1;
        }
        if(middleNameArray[ele] == ' ' &&  middleNameArray[ele+1] == ' ' && (end_MiddleNameArray == -1) )
        {
            end_MiddleNameArray = ele;
        }
    }

    for(ele = 0; ele < (3*sizeOf_CstringArray); ++ele) // 
    {
        // print last name
        if( ele < start_FirstNameArray-3 ) // last char in the last name
        {
            *(ptr_CstringArray+ele) = lastNameArray[ele];
        }

        // print space
        if( ele == start_FirstNameArray -2 ) 
        {
            *(ptr_CstringArray+ele) = ' ';
        }
        
        // print ,
        if( ele == start_FirstNameArray -3 ) 
        {
            *(ptr_CstringArray+ele) = ',';
        }

        // print first name
        if( ( ele >= (start_FirstNameArray-1) ) && ( ele <= ( start_FirstNameArray + start_MiddleNameArray ) ) ) 
        {
            *(ptr_CstringArray+ele) = firstNameArray[ ele - start_FirstNameArray];
        }

        // print middle name
        if( ( ele >= ( start_FirstNameArray + start_MiddleNameArray ) ) && ( ele < start_FirstNameArray + start_MiddleNameArray + end_MiddleNameArray ) )
        {
            *(ptr_CstringArray+ele) = middleNameArray[ ele - start_FirstNameArray - start_MiddleNameArray];
        }

    }

    for(ele = 0; ele < (start_FirstNameArray + start_MiddleNameArray + end_MiddleNameArray); ++ele) 
    {
        std::cout << *(ptr_CstringArray+ele);
    }
    
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

    char firstNameArray[sizeOf_CstringArray],
         middleNameArray[sizeOf_CstringArray],
         lastNameArray[sizeOf_CstringArray];
    
    char *ptr_CstringArray{nullptr};
        ptr_CstringArray = new char[3*sizeOf_CstringArray];
        
    
	while(letter != 'n')
	{
        /*
        for(ele=0;ele<sizeOf_CstringArray;++ele)
        {
            firstNameArray[ele] = ' ';
            middleNameArray[ele] = ' ';
            lastNameArray[ele] = ' ';
        }

        for(ele=0; ele<(3*sizeOf_CstringArray); ++ele)
        {
            *(ptr_CstringArray+ele) = ' ';
        }
        
        std::cout << "Using the input of your first, middle, and last names, this program will arrange them in a particular manner." << "\n";
        std::cout << "For example, if the user entered “ Carol Lynn Smith”, it should store “ Smith, Carol Lynn” in the fourth array." << "\n";	

        std::cout << "User, input your FIRST name : ";
            std::cin >> firstNameArray;

        std::cout << "User, input your MIDDLE name : ";
            std::cin >> middleNameArray;

        std::cout << "User, input your LAST name : ";
            std::cin >> lastNameArray;

        NameArranger(firstNameArray,middleNameArray,lastNameArray,ptr_CstringArray,sizeOf_CstringArray,ele);
        */
        
        std::cout << " " << "\n";
        ptr_CstringArray = new char[sizeOf_CstringArray];

        std::cin.clear();
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