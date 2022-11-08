/*
Starting Out With C++ Chapter 9 Pointers – Algorithm Workbench

// array[index] == *( ptr_array + index ) == &array[ 0 + index ]

*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>

int main(){

    /*
    Starting Out With C++ Chapter 9 Pointers – Algorithm Workbench
    24. Look at the following code.
    double value = 29.7;
    double *ptr = &value;
    Write a cout statement that uses the ptr variable to display the contents of the value variable.
    */
    std::cout << "---------" << std::endl;
    double value = 29.7;
    std::cout << &value << std::endl;
    double *ptr = &value;
    std::cout << *ptr << std::endl;

    /*
    25. Look at the following array definition.
    int set[10];
    Write a statement using pointer notation that stores the value 99 in set[7];
    */
    std::cout << "---------" << std::endl;
    int set[10]{1,2,3,4,5,6,7,8,9,10};
    int *ptr_set{nullptr};
        ptr_set = set; // &set[0]

    std::cout << set << "\n"; // &set[0]
        std::cout << "---------" << std::endl;

    for(int ele{0};ele<10;++ele)
    {
        // pointers
        std::cout << "-----pointers----" << std::endl;
        std::cout << (ptr_set+ele) << "\n";  // ptr_set == &set[0]
        std::cout << *(ptr_set+ele) << "\n";

        // references
        std::cout << "-----references----" << std::endl;
        std::cout << &set[ele] << "\n";
        std::cout << set[ele] << "\n";
    }

    std::cout << "----update element 7-----" << std::endl;
        ptr_set[7] = 99; // ptr_set[7] == set[7]

    for(int ele{0};ele<10;++ele)
    {
        // pointers
        std::cout << "-----pointers----" << std::endl;
        std::cout << (ptr_set+ele) << "\n";
        std::cout << *(ptr_set+ele) << "\n";

        // references
        std::cout << "-----references----" << std::endl;
        std::cout << &set[ele] << "\n";
        std::cout << set[ele] << "\n";
    }


    /*
    26. Write code that dynamically allocates an array of 20 integers, then uses a loop to allow
    the user to enter values for each element of the array.
    */
    std::cout << "---------" << std::endl;
    int sizeof_array26{20};
    int array26[sizeof_array26];

    int *ptr_array26{nullptr}; 
        ptr_array26 = new int[sizeof_array26];

    for(int ele=0;ele<sizeof_array26;++ele)
    {
        std::cout << "User, for element " << ele << ", input an integer : ";
            //std::cin >> ptr_array26[ele];
            //std::cin >> ptr_array26[ 0 + ele ];
            std::cin >> *(ptr_array26+ele);
    }  

    for(int ele=0;ele<sizeof_array26;++ele)
    {
        std::cout << "For element " << ele << ", you chose : " << *(ptr_array26+ele) << '\n';
    } 
    
    delete[] ptr_array26;
    ptr_array26 = nullptr;

    /*
    27. Assume that tempNumbers is a pointer that points to a dynamically allocated array.
    Write code that releases the memory used by the array.
    delete[] tempNumbers;
    tempNumbers = nullptr;

    */
    std::cout << "-----27----" << std::endl;

    /*
    28. Look at the following function definition.
    void getNumber(int &n)
    {
    cout << "Enter a number: ";
    cin >> n;
    }

    In this function, the parameter n is a reference variable. 
    Rewrite the function so that n is a pointer.

    void getNumber(int *n)
    {
        cout << "Enter a number: ";
        cin >> n;
    }

    */
    std::cout << "----28-----" << std::endl;
    
    /*
    29. Write the definition of ptr, a pointer to a constant int .
    const int a;
    */
    std::cout << "----29-----" << std::endl;
    const int a{1};
    const int *ptr29{&a};
    //ptr29 = &a;

    /*
    30. Write the definition of ptr, a constant pointer to an int .

    */
    std::cout << "-----30----" << std::endl;
    int b{1};
    int * const ptr30{&b};
    //ptr30 = &b;
    

    return 0;
}
