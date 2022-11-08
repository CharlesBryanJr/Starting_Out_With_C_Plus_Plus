/*
Starting Out With C++ Chapter 9 Pointers – 6. Case Study Modification #1
Modify Program 9-19 (the United Cause case study program) so it can be used with any set of donations.
The program should dynamically allocate the donations array and ask the user to input its values.
*/

// This program shows the donations made to the United Cause
// by the employees of CK Graphics, Inc. It displays
// the donations in order from lowest to highest
// and in the original order they were received.
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>

void inputValidation(int *ptr_amount, int &count)
{
    std::cin >> *(ptr_amount+count);

    while ( *(ptr_amount+count) < 0)
    {
        std::cin.clear();
        std::cout << "Input Validation." << '\n';
        std::cout << "For donation " << count << ", input the amount donationed : ";
            std::cin >> *(ptr_amount+count);
    }
   
}
/*
//***********************************************************
// Definition of function showArray. *
// This function displays the contents of arr. size is the *
// number of elements. *
//***********************************************************
void showArray(int * const ptr_showArray, int size)
{
    for (int count = 0; count < size; count++)
    {
        std::cout << arr[count] << " ";
        std::cout << std::endl;  
    }
}
*/

//***************************************************************
// Definition of function showArrPtr. *
// This function displays the contents of the array pointed to *
// by arr. size is the number of elements. *
//***************************************************************
void showArrPtr(int *arr, int size)
{
    for (int count = 0; count < size; count++)
    {
        std::cout << *(arr+count) << " ";
        std::cout << std::endl;
    }
}

//****************************************************************
// Definition of function arrSelectSort. *
// This function performs an ascending order selection sort on *
// arr, which is an array of pointers. Each element of array *
// points to an element of a second array. After the sort, *
// arr will point to the elements of the second array in *
// ascending order. *
//****************************************************************

void arrSelectSort(int *arr, int size)
{
    int startScan, 
        minIndex;
    int minValue;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = *(arr+startScan);

        for(int index = startScan + 1; index < size; index++)
        {
            if (*(arr+index) < minValue)
            {
                minValue = *(arr+index);
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minValue;
    }        
}

int main()
{
    int NUM_DONATIONS;

    std::cout << "User, how many donations were made? : ";
        std::cin >> NUM_DONATIONS;

    /*
    const int NUM_DONATIONS = 15; // Number of donations
    // An array containing the donation amounts.
    int donations[NUM_DONATIONS] = {5, 100, 5, 25, 10,
                                    5, 25, 5, 5, 100,
                                    10, 15, 10, 5, 10};

    // An array of pointers to int.
    int *arrPtr[NUM_DONATIONS] = {nullptr, nullptr, nullptr, nullptr, nullptr,
                                  nullptr, nullptr, nullptr, nullptr, nullptr,
                                  nullptr, nullptr, nullptr, nullptr, nullptr};
    // Each element of arrPtr is a pointer to int.
    // Make each element point to an element in the donations array.
    */

    int *arrPtr_donations{nullptr};
    arrPtr_donations = new int[NUM_DONATIONS];

    for (int count = 0; count < NUM_DONATIONS; count++)
    {
        // arrPtr[count] = &donations[count];
        std::cout <<"For donation " << count << ", input the amount donationed : ";
            std::cin >> *(arrPtr_donations+count);
            //inputValidation(arrPtr_donations,count);
    }

    // Sort the elements of the array of pointers.
    arrSelectSort(arrPtr_donations, NUM_DONATIONS);

    // Display the donations using the array of pointers. This
    // will display them in sorted order.
    std::cout << "The donations, sorted in ascending order are: \n";
    showArrPtr(arrPtr_donations, NUM_DONATIONS);

    /*
    // Display the donations in their original order.
    std::cout << "The donations, in their original order are: \n";
    showArray(donations, NUM_DONATIONS);
    */
   
    return 0;
}