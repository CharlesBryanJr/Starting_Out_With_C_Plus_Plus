/*
Starting Out With C++ Chapter 9 Pointers – 8. Mode Function
In statistics, the mode of a set of values is the value that occurs most often or with the greatest frequency. 

Write a function that accepts as arguments the following:
A) An array of integers
B) An integer that indicates the number of elements in the array

The function should determine the mode of the array. 
That is, it should determine which value in the array occurs most often. 
The mode is the value the function should return. 
If the array has no mode (none of the values occur more than once), the function should return −1. 
(Assume the array will always contain nonnegative values.)

Demonstrate your pointer prowess by using pointer notation instead of array notation in this function.
}
*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>

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

void inputValidation_postiveInteger(int &ref_number)
{
    std::cin >> ref_number;

    while( ref_number<0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "User, input the amount of values in the array : ";
            std::cin >> ref_number;
    }
}

void inputValidation_postiveInteger_ptr(int * const ptr_array_ivpip, const int &sizeofarray, const int &ele)
{
    std::cin >> *(ptr_array_ivpip+ele);

    while( *(ptr_array_ivpip+ele) < 0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "User, for element " << ele+1 << ", input the value : ";
            std::cin >> *(ptr_array_ivpip+ele);
    }
}

void initailize_ptr_array(int * const ptr_array_mf, const int sizeofarray, int &ele)
{
    std::cout << "---initailize_ptr_array---" << "\n"; std::cout << " " << "\n";

    for(ele=0;ele<sizeofarray;++ele)
    {
        std::cout << "User, for element " << ele+1 << ", input the value : ";
            inputValidation_postiveInteger_ptr(ptr_array_mf,sizeofarray,ele);
    }
}

void ModeFunction(const int * const ptr_array_mf, const int &sizeofarray, int &ele, int &mode)
{
    std::cout << "---ModeFunction---" << "\n"; std::cout << " " << "\n";

    std::cout << "For the array shown below."<< "\n";
    for(ele=0;ele<sizeofarray;++ele)
    {
        std::cout << *(ptr_array_mf+ele) << "\n";
    }

    int *mode_ptr_array{nullptr};
        mode_ptr_array = new int[sizeofarray];

    for(ele=0;ele<sizeofarray;++ele) 
    {
        mode = 0; //reset mode

        for(int it=0;it<sizeofarray;++it)
        {
            if( *(ptr_array_mf+ele) == *(ptr_array_mf+it) )
            {
                mode += 1; // how many times did the value occur?
            }
        }
        *(mode_ptr_array+ele) = mode; // store the occurences of the values stored inside of the ptr_array_mf 
    }

    int largest = *(mode_ptr_array+0); //  assign largest to value stored inside of element zero

    for(ele=0;ele<sizeofarray;++ele)
    {
        if( *(mode_ptr_array+ele) > largest )
        {
            largest = *(mode_ptr_array+ele);
        }
    }

    int largestIndex = 0;

    if( largest > 1) // if a mode exist
    {
        for(ele=0;ele<sizeofarray;++ele) // 
        {
            if( *(mode_ptr_array+ele) == largest )
            {
                largestIndex = ele;
            }
        }
        
        std::cout << "Element " << largestIndex << ", with the value of " << *(ptr_array_mf+largestIndex) << ", was the mode, (the value that occurs the most often) with " << largest << " occurences." << "\n";
    }

    else // mode does not exist
    {
        std::cout << "This data set, does not have a mode (value that occurs the most often)." << "\n";
    }

    std::cout << " " << "\n";

    delete[] mode_ptr_array;
    mode_ptr_array = nullptr;

}

int main()
{
	char letter;
    int ele,
        sizeofarray,
        mode;

	while(letter != 'n')
	{
        std::cout << "User, input the amount of values in the array : ";
            inputValidation_postiveInteger(sizeofarray);
        
        int *ptr_array{nullptr}; 
            ptr_array = new int[sizeofarray];
        
        initailize_ptr_array(ptr_array,sizeofarray,ele);

        ModeFunction(ptr_array,sizeofarray,ele,mode);
        
        delete[] ptr_array;
        ptr_array = nullptr;

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
			inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}