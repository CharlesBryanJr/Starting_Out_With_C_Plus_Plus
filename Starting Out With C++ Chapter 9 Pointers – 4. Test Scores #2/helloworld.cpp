/*
Starting Out With C++ Chapter 9 Pointers – 4. Test Scores #2

Modify the program of Programming Challenge 2 to allow the user to enter name-score pairs. 
For each student taking a test, the user types the student’s name followed by the student’s integer test score. 
Modify the sorting function so it takes an array holding the student names and an array holding the student test scores. 
When the sorted list of scores is displayed, each student’s name should be displayed along with his or her score. 
In stepping through the arrays, use pointers rather than array subscripts. 

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

void GET_student_names(std::string *pointer_names_gsn, const int &sizeOF_TestScores, int &ele)
{
    std::cout << "---GET_student_names---" << "\n"; std::cout << " " << "\n";

    for(ele=0;ele<sizeOF_TestScores;++ele)
    {
        std::cout << "Input the name for student " << ele+1 << ", : ";
            std::cin >> *(pointer_names_gsn+ele);
    }
}

void inputValidation_postiveTestScores(int *pointer_TestScores_ivpts, int &ele)
{
    std::cin >> *(pointer_TestScores_ivpts+ele);

    while( *(pointer_TestScores_ivpts+ele)<0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "User, input the number of test scores. : ";
            std::cin >> *(pointer_TestScores_ivpts+ele);
    }
}

void initialize_TestScores(int *pointer_TestScores_its, std::string *pointer_names_its, const int &sizeOF_TestScores, int &ele)
{
    std::cout << "---initialize_TestScores---" << "\n"; std::cout << " " << "\n";

    for(ele=0;ele<sizeOF_TestScores;++ele)
    {
        std::cout << "For student " << *(pointer_names_its+ele) << ", input the test score : ";
            inputValidation_postiveTestScores(pointer_TestScores_its,ele);
    }
}

void selectionSort(int *pointer_TestScores_ss, std::string *pointer_names_ss, const int &sizeOF_TestScores, int &ele)
{
    std::cout << "---selectionSort---" << "\n"; std::cout << " " << "\n";
    int maxValue,
        maxIndex;
    std::string maxName;
        
    for(ele=0;ele<(sizeOF_TestScores-1);++ele)
    {
        maxValue = *(pointer_TestScores_ss+ele);
        maxIndex = ele;
        maxName = *(pointer_names_ss+ele);

        for(int it = ele+1; it<sizeOF_TestScores; ++it)
        {
            if(*(pointer_TestScores_ss+it)>maxValue)
            {
                maxValue = *(pointer_TestScores_ss+it);
                maxIndex = it;
                maxName = *(pointer_names_ss+it);
            }
        }

        *(pointer_TestScores_ss+maxIndex) = *(pointer_TestScores_ss+ele);
        *(pointer_TestScores_ss+ele) = maxValue;
        *(pointer_names_ss+maxIndex) = *(pointer_names_ss+ele);
        *(pointer_names_ss+ele) = maxName;
    }

    std::cout << "Below is a sorted list of test scores from highest to lowest."  << "\n";
    for(ele=0;ele<sizeOF_TestScores;++ele)
    {
        std::cout << *(pointer_TestScores_ss+ele) << " : " << *(pointer_names_ss+ele) << "\n";
    }
}

void calculateLowest_TestScores(int *pointer_TestScores_clts, std::string *pointer_names_clts, int *ptr_lowest_TestScores, const int &sizeOF_TestScores, int &ele)
{
    std::cout << "---calculateLowest_TestScores---" << "\n"; std::cout << " " << "\n";
    int sum{0},
        lowest_ele = 0;
    *ptr_lowest_TestScores = *(pointer_TestScores_clts+0);

    for(ele=0;ele<sizeOF_TestScores;++ele)
    {
        if( *(pointer_TestScores_clts+ele) < *ptr_lowest_TestScores)
        {
            *ptr_lowest_TestScores = *(pointer_TestScores_clts+ele);
            lowest_ele = ele;
        }
    }

    std::cout << *(pointer_names_clts+lowest_ele) << " had the lowest score of the " << sizeOF_TestScores << " test scores, : "  << *ptr_lowest_TestScores << "\n";
    std::cout << *(pointer_names_clts+lowest_ele) << " had the lowest score of the " << sizeOF_TestScores << " test scores, : "  << *(pointer_TestScores_clts+lowest_ele) << "\n";
    std::cout << " " << "\n";
}

void calculate_TestScores(const int * const pointer_TestScores_cts, const int * const ptr_lowest, const int &sizeOF_TestScores, int &ele)
{
    std::cout << "---calculate_TestScores---" << "\n"; std::cout << " " << "\n";
    int sum;
        
    for(ele=0;ele<sizeOF_TestScores;++ele)
    {
        sum += *(pointer_TestScores_cts+ele);
    }

    int average = (sum-*ptr_lowest) / (sizeOF_TestScores-1);

    std::cout << "The avearge score, not included the lowest, " << *ptr_lowest << ", of the " << sizeOF_TestScores-1 << " test scores was : " << average << "\n";
    std::cout << " " << "\n";
}

int main()
{
	char letter;
    int ele,
        sizeOF_TestScores;
    int names[sizeOF_TestScores];
    
	while(letter != 'n')
	{
        // "User, how many elements should I dynamically allocate for the array of integers? : ";
        std::cout << "User, input the number of students. : ";
            inputValidation_postive_sizeOF_TestScores(sizeOF_TestScores);
        
        std::string *ptr_names{nullptr}; // create pointer of array of names
                ptr_names = new std::string[sizeOF_TestScores]; // assign dynamically allocated memory to pointer
        
        GET_student_names(ptr_names, sizeOF_TestScores, ele);
        
        int *ptr_TestScores{nullptr}; // create pointer for array of test scores
            ptr_TestScores = new int[sizeOF_TestScores]; // assign dynamically allocated memory to pointer

        int *ptr_lowest{nullptr}; // create pointer
            ptr_lowest = new int; // assign dynamically allocated memory to pointer

        initialize_TestScores(ptr_TestScores,ptr_names,sizeOF_TestScores,ele);
        selectionSort(ptr_TestScores,ptr_names,sizeOF_TestScores,ele);
        calculateLowest_TestScores(ptr_TestScores,ptr_names,ptr_lowest,sizeOF_TestScores,ele);
        calculate_TestScores(ptr_TestScores,ptr_lowest,sizeOF_TestScores,ele);

        delete[] ptr_TestScores; // delete dynamically allocated memory assigned to this pointer
        ptr_TestScores = nullptr; // re point the pointer back to nullptr
        delete ptr_lowest;
        ptr_TestScores = nullptr;
        delete[] ptr_names;
        ptr_names = nullptr;

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
			inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}

