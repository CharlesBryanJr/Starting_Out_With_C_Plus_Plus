/*
Starting Out With C++ Chapter 9 Pointers – 1. Array Allocator
Write a function that dynamically allocates an array of integers. 
The function should accept an integer argument indicating the number of elements to allocate. 
The function should return a pointer to the array.
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

int *ArrayAllocator(int array[], const int &sizeOF_array, int &ele)
{
    std::cout << "---ArrayAllocator---" << "\n"; std::cout << " " << "\n";

    for(ele=0;ele<sizeOF_array;++ele)
    {
        array[ele] = ele;
    }

    // dynamically allocates memory on the heap for a array the size of "sizeOF_array1"
    int *ptr_array{nullptr};
        //ptr_array = new int[sizeOF_array];
        ptr_array = array; //&array[0];

        for(ele=0;ele<sizeOF_array;++ele)
        {
            std::cout << "-------array notation-------" << "\n";
            //ptr_array[ele] = array[ele];
            std::cout << &ptr_array[ele] << "\n";
            std::cout << ptr_array[ele] << "\n";

            std::cout << "-------pointer notation-------" << "\n";
            std::cout << (ptr_array+ele) << "\n";
            std::cout << *(ptr_array+ele) << "\n";
        }

   std::cout << " " << "\n";
   return ptr_array;
}

void *ArrayAllocator2(int *ptr_passed, int array[], const int &sizeOF_array, int &ele)
{
    std::cout << "---ArrayAllocator2---" << "\n"; std::cout << " " << "\n";

    for(ele=0;ele<sizeOF_array;++ele)
    {
        array[ele] += ele;
    }

    ptr_passed = array;

        for(ele=0;ele<sizeOF_array;++ele)
        {
            std::cout << "-------array notation-------" << "\n";
            //ptr_passed[ele] = array[ele];
            std::cout << &ptr_passed[ele] << "\n";
            std::cout << ptr_passed[ele] << "\n";

            std::cout << "-------pointer notation-------" << "\n";
            std::cout << (ptr_passed+ele) << "\n";
            std::cout << *(ptr_passed+ele) << "\n";
        }

   std::cout << " " << "\n";
}

int main()
{
	char letter;
    int ele,
        sizeOF_array{100};
    int array[sizeOF_array]; std::cout << &array << "\n";
    //pointers
    int *ptr_returned{nullptr};
    int *ptr_passed{nullptr};
        ptr_passed = array; // the name of an array serves as the first address of the array. &array[0];
    
	while(letter != 'n')
	{
        std::cout << "User, how many address should I dynamically allocate for the array of integers? : ";
            std::cin >> sizeOF_array;
        
        ptr_returned = ArrayAllocator(array,sizeOF_array,ele); // passing an array and creating & returning a pointer
            std::cout << ptr_returned << "\n";
        
        ArrayAllocator2(ptr_passed,array,sizeOF_array,ele); // passing a pointer 
            std::cout << ptr_passed << "\n";
                std::cout << &ptr_passed[1] << "\n"; //array notation
                std::cout << (ptr_passed+1) << "\n"; //pointer notation

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		    inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	return 0;
}