/*
Starting Out With C++ Chapter 7 – 1. Largest/Smallest Array Values
Largest/Smallest Array Values
Write a program that lets the user enter 10 values into an array. 
The program should then display the largest and smallest values stored in the array.
*/
#include <iostream>

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

void getArray(int array1 [], int array1_size, int element)
{
    std::cout << "User, please input 10 values that will be stored in an array." << "\n";
    for(element = 0; element<array1_size; ++element)
    {
        std::cout << "For value #" << element+1 << ", input a value : "; 
            std::cin >> array1[element];
    }
}

int largest(const int array1 [], int array1_size, int element)
{
    int largest = array1[0];

    for(element = 0; element<array1_size; ++element)
    {
        if( array1[element] > largest)
        {
            largest = array1[element];
        }
    }
    return largest;
}

int smallest(const int array1 [], int array1_size, int element)
{
    int smallest = array1[0];

    for(element = 0; element<array1_size; ++element)
    {
        if( array1[element] < smallest)
        {
            smallest = array1[element];
        }
    }
    return smallest;
}

int main()
{
	char letter;
    int array1_size{10},
        element;
    int array1 [array1_size];

	while(letter != 'n')
	{
        getArray(array1,array1_size,element); std::cout << " " << "\n";

        std::cout << "The largest number in the array is : " << largest(array1,array1_size,element) << "\n"; std::cout << " " << "\n";
        std::cout << "The smallest number in the array is : " << smallest(array1,array1_size,element) << "\n"; std::cout << " " << "\n";	
        		
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}