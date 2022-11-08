/*
Starting Out With C++ Chapter 9 Pointers – 3. Drop Lowest Score

Modify Problem 2 above so the lowest test score is dropped. 

This score should not be included in the calculation of the average.

Starting Out With C++ Chapter 9 Pointers – 2. Test Scores #1
Write a program that dynamically allocates an array large enough to hold a user defined number of test scores. 
Once all the scores are entered, the array should be passed to a function that sorts them in ascending order. 
Another function should be called that calculates the average score. 
The program should display the sorted list of scores and averages with appropriate headings. 
Use pointer notation rather than array notation whenever possible.
Input Validation: Do not accept negative numbers for test scores.
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

void inputValidation_postive_sizeOF_TestScores(int &ref_number)
{
    std::cin >> ref_number;

    while( ref_number<0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "User, input the number of test scores. : ";
            std::cin >> ref_number;
    }
}

void inputValidation_postiveTestScores(int *pointer_TestScores_ivpts, int &ele)
{
    std::cin >> pointer_TestScores_ivpts[ele];

    while( pointer_TestScores_ivpts[ele]<0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "User, input the number of test scores. : ";
            std::cin >> pointer_TestScores_ivpts[ele];
    }
}

void initialize_TestScores(int *pointer_TestScores_its, const int &sizeOF_TestScores, int &ele)
{
    std::cout << "---initialize_TestScores---" << "\n"; std::cout << " " << "\n";

    for(ele=0;ele<sizeOF_TestScores;++ele)
    {
        std::cout << "For test " << ele << ", input the test score : ";
            inputValidation_postiveTestScores(pointer_TestScores_its,ele);
    }
}

void selectionSort(int *pointer_TestScores_ss, const int &sizeOF_TestScores, int &ele)
{
    std::cout << "---selectionSort---" << "\n"; std::cout << " " << "\n";
    int maxValue,
        maxIndex;
        
    for(ele=0;ele<(sizeOF_TestScores-1);++ele)
    {
        maxValue = pointer_TestScores_ss[ele];
        maxIndex = ele;

        for(int it = ele+1; it<sizeOF_TestScores; ++it)
        {
            if(pointer_TestScores_ss[it]>maxValue)
            {
                maxValue = pointer_TestScores_ss[it];
                maxIndex = it;
            }
        }

        pointer_TestScores_ss[maxIndex] = pointer_TestScores_ss[ele];
        pointer_TestScores_ss[ele] = maxValue;
    }

    std::cout << "Below is a sorted list of test scores from highest to lowest."  << "\n";
    for(ele=0;ele<sizeOF_TestScores;++ele)
    {
        std::cout << pointer_TestScores_ss[ele] << "\n";
    }
}

void calculateLowest_TestScores(int *pointer_TestScores_clts, int *ptr_lowest_TestScores, const int &sizeOF_TestScores, int &ele)
{
    std::cout << "---calculateLowest_TestScores---" << "\n"; std::cout << " " << "\n";
    int sum{0};
    *ptr_lowest_TestScores = pointer_TestScores_clts[0];

    for(ele=0;ele<sizeOF_TestScores;++ele)
    {
        if( pointer_TestScores_clts[ele] < *ptr_lowest_TestScores)
        {
            *ptr_lowest_TestScores = pointer_TestScores_clts[ele];
        }
    }

    std::cout << "The lowest score of the " << sizeOF_TestScores << " test scores was : "  << *ptr_lowest_TestScores << "\n";
    std::cout << " " << "\n";
}

void calculate_TestScores(int *pointer_TestScores_cts, int *ptr_lowest, const int &sizeOF_TestScores, int &ele)
{
    std::cout << "---calculate_TestScores---" << "\n"; std::cout << " " << "\n";
    int sum;
        
    for(ele=0;ele<sizeOF_TestScores;++ele)
    {
        sum += pointer_TestScores_cts[ele];
    }

    int average = (sum-*ptr_lowest) / (sizeOF_TestScores-1);

    std::cout << "The avearge score, not included the lowest, " << *ptr_lowest << ", of the " << sizeOF_TestScores-1 << " test scores was : "  << average << "\n";
    std::cout << " " << "\n";
}

int main()
{
	char letter;
    int ele,
        sizeOF_TestScores;
    
	while(letter != 'n')
	{
        // std::cout << "User, how many elements should I dynamically allocate for the array of integers? : ";
        std::cout << "User, input the number of test scores. : ";
            inputValidation_postive_sizeOF_TestScores(sizeOF_TestScores);
        
        int *ptr_TestScores{nullptr}; // create pointer
            ptr_TestScores = new int[sizeOF_TestScores]; // assign dynamically allocated memory to pointer
        
        int *ptr_lowest{nullptr}; // create pointer
            ptr_lowest = new int; // assign dynamically allocated memory to pointer

        initialize_TestScores(ptr_TestScores,sizeOF_TestScores,ele);
        selectionSort(ptr_TestScores,sizeOF_TestScores,ele);
        calculateLowest_TestScores(ptr_TestScores,ptr_lowest,sizeOF_TestScores,ele);
        calculate_TestScores(ptr_TestScores,ptr_lowest,sizeOF_TestScores,ele);

        delete[] ptr_TestScores; // delete dynamically allocated memory assigned to this pointer
        ptr_TestScores = nullptr; // re point the pointer back to nullptr
        delete ptr_lowest;
        ptr_TestScores = nullptr;

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
			inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}