/*
Starting Out With C++ Chapter 7 – 4. Larger Than n

In a program, write a function that accepts three arguments: an array, the size of the array, and a number n. 
Assume that the array contains integers. 
The function should display all of the numbers in the array that are greater than the number n .
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

double inputValidation_postiveInteger(double &ref_number)
{
    while( !(std::cin >> ref_number) || (ref_number<0) )
    {
        std::cout << "Input Validation: Must be a postive integer : ";
        std::cin.clear();
    }
    return ref_number;
}

double inputValidation_postiveInteger_array(double postiveInteger_array[], int ele)
{
    std::cin >> postiveInteger_array[ele];

    while( postiveInteger_array[ele] < 0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer" << "\n";
        std::cout << "For month " << ele+1 << ", input the amout of rainfall : ";
            std::cin >> postiveInteger_array[ele];
    }
    return postiveInteger_array[ele];
}

void LargerThan_n(int array1[], const int SIZEof_array1, int ele, const int n)
{
    std::cout << "---LargerThan_n---" << "\n"; std::cout << " " << "\n";
    for(ele=0;ele<SIZEof_array1;++ele)
    {
        if(array1[ele]>n)
        {
            std::cout << "Element " << ele << ", which corresponds to " << array1[ele] << ", is larger than " << n << "\n";
        }
    }
}

int main()
{
	char letter;
    int ele,
        SIZEof_array1,
        n;
    int array1[SIZEof_array1];

	while(letter != 'n')
	{
        LargerThan_n(array1, SIZEof_array1, ele, n);
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}