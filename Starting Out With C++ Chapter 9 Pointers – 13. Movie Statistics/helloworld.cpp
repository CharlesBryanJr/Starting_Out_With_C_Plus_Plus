/*
Starting Out With C++ Chapter 9 Pointers – 13. Movie Statistics
Write a program that can be used to gather statistical data about the number of movies college students see in a month. 
The program should perform the following steps:
A) Ask the user how many students were surveyed. 
An array of integers with this many elements should then be dynamically allocated.
B) Allow the user to enter the number of movies each student saw into the array.
C) Calculate and display the average, median, and mode of the values entered. 
(Use the functions you wrote in Problems 8 and 9 to calculate the median and mode.)
Input Validation: Do not accept negative numbers for input.
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
        std::cout << "User, how many students were surveyed. : ";
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
        std::cout << "User, for student " << ele+1 << ", input the number of movies they saw : ";
            inputValidation_postiveInteger_ptr(ptr_array_mf,sizeofarray,ele);
    }
}

void ModeFunction(const int * const ptr_array_mf, const int &sizeofarray, int &ele, int &mode)
{
    std::cout << "---ModeFunction---" << "\n"; std::cout << " " << "\n";

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
        
        std::cout << "Student " << largestIndex+1 << ", with the value of " << *(ptr_array_mf+largestIndex) << ", was the mode, (the value that occurs the most often) with " << largest << " occurences." << "\n";
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

}

void MedianFunction(const int * const ptr_array_mf, const int &sizeofarray, int &ele)
{
    std::cout << "---MedianFunction---" << "\n"; std::cout << " " << "\n";

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

void ReverseArray(int * const ptr_array, const int &sizeofarray, int &ele)
{
    std::cout << "---ReverseArray---" << "\n"; std::cout << " " << "\n";

    std::cout << "Current array"<< "\n";
    for(ele=0;ele<sizeofarray;++ele)
    {
        std::cout << *(ptr_array+ele) << "\n";
    }

    int *ptr_ReverseArray{nullptr};
        ptr_ReverseArray = new int[sizeofarray];

    int reverse_ele;        

    for( ele=sizeofarray-1; ele>=0; --ele )
    {
        reverse_ele = (sizeofarray-1)-ele;  // last element of array - iterator
        *(ptr_ReverseArray+reverse_ele) = *(ptr_array+ele);
    }
    std::cout << " " << "\n";

    std::cout << "Reversed array"<< "\n";
    for(ele=0;ele<sizeofarray;++ele)
    {
        std::cout << *(ptr_ReverseArray+ele) << "\n";
    }

    delete[] ptr_ReverseArray;
    ptr_ReverseArray = nullptr;
    std::cout << " " << "\n";
}

void ArrayExpander(int * const ptr_array_ae, const int &sizeofarray, int &ele)
{
    std::cout << "---ArrayExpander---" << "\n"; std::cout << " " << "\n";

    std::cout << "Current array"<< "\n";
    for(ele=0;ele<sizeofarray;++ele)
    {
        std::cout << *(ptr_array_ae+ele) << "\n";
    }
    std::cout << " " << "\n";

    int n;
    std::cout << "User, what multiple should I expand this array by? : ";
        inputValidation_postiveInteger(n);

    int *ptr_ArrayExpander{nullptr};
        ptr_ArrayExpander = new int[n*sizeofarray];
    
    /*
    for(ele=0; ele<sizeofarray; ++ele)
    {
        *(ptr_ArrayExpander+ele) = *(ptr_array_ae+ele);
    }
    
    std::cout << "Expanded array with 0s at the end."<< "\n";
    for(ele=0; ele<n*sizeofarray; ++ele)
    {
        std::cout << *(ptr_ArrayExpander+ele) << "\n";
    }
    */

    
    std::cout << " " << "\n";
    int it{0};
    for(ele=0; ele<(n*sizeofarray); ++ele)
    {
        *(ptr_ArrayExpander+it) = *(ptr_array_ae+ele);
        it += n;
    }
    
    std::cout << "Expanded array with 0s inbetween."<< "\n";
    for(ele=0; ele<n*sizeofarray; ++ele)
    {
        std::cout << *(ptr_ArrayExpander+ele) << "\n";
    }
    

    delete[] ptr_ArrayExpander;
    ptr_ArrayExpander = nullptr;
    std::cout << " " << "\n";
}

void ElementShifter(int * const ptr_array_es, const int &sizeofarray, int &ele)
{
    std::cout << "---ElementShifter---" << "\n"; std::cout << " " << "\n";

    std::cout << "Current array"<< "\n";
    for(ele=0;ele<sizeofarray;++ele)
    {
        std::cout << *(ptr_array_es+ele) << "\n";
    }
    std::cout << " " << "\n";

    int n,
        it;
    std::cout << "User, how many elements should I shift over? : ";
        inputValidation_postiveInteger(n);
        it = n;

    int *ptr_ElementShifter{nullptr};
        ptr_ElementShifter = new int[sizeofarray+n];

    for(ele=0; ele<(sizeofarray+n); ++ele)
    {
        *(ptr_ElementShifter+ele) = 0;
    }

    for(ele=0; ele<(sizeofarray+n); ++ele)
    {
        *(ptr_ElementShifter+it) = *(ptr_array_es+ele);
        it += 1;
    }
    
    std::cout << "This array was shifted over " << n << " elements." << "\n";
    std::cout << "For example, element 0, " << *(ptr_array_es+0) << ", was shifted over " << n << " element/s in the new array." << "\n";

    for(ele=0; ele<(sizeofarray+n); ++ele)
    {
        std::cout << *(ptr_ElementShifter+ele) << "\n";
    }

    delete[] ptr_ElementShifter;
    ptr_ElementShifter = nullptr;
    std::cout << " " << "\n";
}

int main()
{
	char letter;
    int ele,
        sizeofarray,
        mode,
        sum{0},
        average;

	while(letter != 'n')
	{
        std::cout << "User, how many students were surveyed. : ";
            inputValidation_postiveInteger(sizeofarray);
        
        int *ptr_array{nullptr}; 
            ptr_array = new int[sizeofarray];
        
        initailize_ptr_array(ptr_array,sizeofarray,ele);

        ModeFunction(ptr_array,sizeofarray,ele,mode);

        selectionSort_ptr(ptr_array,sizeofarray,ele);

        MedianFunction(ptr_array,sizeofarray,ele);

        for(ele=0;ele<sizeofarray;++ele)
        {
            sum += *(ptr_array+ele);
        }

        average = sum/sizeofarray;

        std::cout << "The student's on average saw " << average << " movies." << "\n";
        
        delete[] ptr_array;
        ptr_array = nullptr;

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
			inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}