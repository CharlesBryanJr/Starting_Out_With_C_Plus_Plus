/*
Starting Out With C++ Chapter 9 Pointers – 9. Median Function
In statistics, when a set of values is sorted in ascending or descending order, its median is the middle value. 
If the set contains an even number of values, the median is the mean, or average, of the two middle values. 
Write a function that accepts as arguments
the following:
A) An array of integers
B) An integer that indicates the number of elements in the array
The function should determine the median of the array. This value should be returned as a double. 
(Assume the values in the array are already sorted.)
Demonstrate your pointer prowess by using pointer notation instead of array notation in this function.
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

void initailize_ptr_array(int * const ptr_array_mf, const int &sizeofarray, int &ele)
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

void selectionSort_ptr(int * const ptr_array_ssp, const int &sizeofarray, int &ele)
{
    std::cout << "---selectionSort_ptr---" << "\n"; std::cout << " " << "\n";

    int minValue,
        minIndex;

    for(ele=0;ele<(sizeofarray-1);++ele)
    {
        minValue = *(ptr_array_ssp+ele);
        minIndex = ele;
        
        for(int it=ele+1;it<sizeofarray;++it)
        {
            if( *(ptr_array_ssp+it) < minValue )
            {
                minValue = *(ptr_array_ssp+it);
                minIndex = it;
            }
        }

        *(ptr_array_ssp+minIndex) = *(ptr_array_ssp+ele);
        *(ptr_array_ssp+ele) = minValue;
    }

    for(ele=0;ele<sizeofarray;++ele)
    {
        std::cout << *(ptr_array_ssp+ele) << "\n";
    }

}

void MedianFunction(const int * const ptr_array_mf, const int &sizeofarray, int &ele)
{
    std::cout << "---MedianFunction---" << "\n"; std::cout << " " << "\n";

    std::cout << "For the array shown below."<< "\n";
    for(ele=0;ele<sizeofarray;++ele)
    {
        std::cout << *(ptr_array_mf+ele) << "\n";
    }
    std::cout << " " << "\n";

    int median;
    
    if( sizeofarray % 2 == 0 ) // if disabile by 2 evenly then we have an even amount of numbers array
    {
        median = ( *(ptr_array_mf+(sizeofarray/2)) + *(ptr_array_mf+(sizeofarray/2)-1) ) /2;
        std::cout << "Since the array set contains an even number of values, the median is the mean, or average, of the two middle values : " << median << "\n";
    }

    else // odd amount of numbers array
    {
       median = sizeofarray /2; 
       std::cout << "Since the array set contains an odd number of values, the median is the middle value : " << *(ptr_array_mf+median) << "\n";
    }
    std::cout << " " << "\n";
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

        selectionSort_ptr(ptr_array,sizeofarray,ele);

        MedianFunction(ptr_array,sizeofarray,ele);
        
        delete[] ptr_array;
        ptr_array = nullptr;

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
			inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}