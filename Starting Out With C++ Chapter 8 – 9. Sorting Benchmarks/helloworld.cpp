/*
Starting Out With C++ Chapter 8 – 9. Sorting Benchmarks
Write a program that uses two identical arrays of at least 20 integers. 
It should call a function that uses the bubble sort algorithm to sort one of the arrays in ascending order. 
The function should keep a count of the number of exchanges it makes. 
The program then should call a function that uses the selection sort algorithm to sort the other array. 
It should also keep count of the number of exchanges it makes. 
Display these values on the screen.
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

int inputValidation_postiveInteger(int &ref_number)
{
    std::cin >> ref_number;

    while( ref_number<0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "Input again : ";
            std::cin >> ref_number;
    }
    return ref_number;
}

double inputValidation_postiveInteger_array(double postiveInteger_array[], const int &ele)
{
	std::cin >> postiveInteger_array[ele];

    while( postiveInteger_array[ele] < 0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "Input again : ";
            std::cin >> postiveInteger_array[ele];
    }
    return postiveInteger_array[ele];
}

int inputValidation_postiveInteger_array2D(int MonkeyBusiness[][5], const int row_ele, const int column_ele)
{
    std::cin >> MonkeyBusiness[row_ele][column_ele];

    while( MonkeyBusiness[row_ele][column_ele] < 0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer" << "\n";
        std::cout << "Input again : ";
            std::cin >> MonkeyBusiness[row_ele][column_ele];
    }
    return MonkeyBusiness[row_ele][column_ele];
}

void initialize_lotteryNumbers(std::vector<int> &lotteryTickets, 
                               const int lotteryNumbers_array[], 
                               const int sizeOF_lotteryNumbers_array,
                               int &ele)
{
    std::cout << "---initialize_lotteryNumbers---" << "\n"; std::cout << " " << "\n";

    for(ele=0;ele<sizeOF_lotteryNumbers_array;++ele)
    {
        lotteryTickets.push_back(lotteryNumbers_array[ele]);
    }
}

void get_lotteryNumbers(int &lotteryNumbers)
{
    std::cout << "---get_lotteryNumbers---" << "\n"; std::cout << " " << "\n";

    std::cout << "User, input the this week's winning 5-digit number : ";
        std::cin >> lotteryNumbers;

    std::cout << " " << "\n";
}

void linearSearch_lotteryTickets(const std::vector<int> &lotteryTickets, 
                                 int &ele,
                                 const int &lotteryNumbers,
                                 int &sum_linearSearch)
{
    std::cout << "---linearSearch_lotteryTickets---" << "\n"; std::cout << " " << "\n";
    bool found{false};
    int position{-1};
    ele = 0;

    while(ele<lotteryTickets.size() && found == false) // position == -1
    {
        if(lotteryTickets[ele] == lotteryNumbers)
        {
            position = ele;
            found = true;
        }
        ++ele;
        sum_linearSearch += 1;
    }

	if( found == true ) // position != -1
    {
        std::cout << "YOU WIN!" << "\n";
        std::cout << "Ticket number " << position+1 << ", was the winning ticket." << "\n";
    }
    else // found == false or position == -1 or
    {
        std::cout << "Better luck next time." << "\n";
    }

    std::cout << " " << "\n";
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(std::vector<int> &lotteryTickets, int &sum_selectionSort)
{
    std::cout << "---selectionSort---" << "\n"; std::cout << " " << "\n";
    int min_index;
    int min_value;

    for (int start_index = 0; start_index < (lotteryTickets.size() - 1); start_index++)
    {
        min_index = start_index;
        min_value = lotteryTickets[start_index];

        for (int index = start_index + 1; index < lotteryTickets.size(); index++)
        {
            if (lotteryTickets[index] < min_value)
            {
                min_value = lotteryTickets[index];
                min_index = index;
                sum_selectionSort += 1;
            }
        }
        swap(lotteryTickets[min_index], lotteryTickets[start_index]);
    }
}

void binarySearch_lotteryTickets(const std::vector<int> &lotteryTickets, const int &lotteryNumbers, int &sum_binarySearch)
{
    std::cout << "---binarySearch_lotteryTickets---" << "\n"; std::cout << " " << "\n";
    bool found{false};
    int position{-1},
        first{0}, // first element of the vector
        last = lotteryTickets.size()-1, // last element of the vector
        middle{0}; // middle element of the vector
        
    while( first<=last && found == false ) // postion == -1
    {
        middle = (first + last) / 2; // Calculate midpoint
        if (lotteryTickets[middle] == lotteryNumbers) // If value is found at mid
        {
            position = middle;
            found = true;
        }
        else if (lotteryTickets[middle] > lotteryNumbers) // If value is in lower half
        {
            last = middle - 1;
        }
        else // lotteryTickets[middle] < lotteryNumbers (If value is in upper half)
        {
            first = middle + 1; // If value is in upper half
        }
        sum_binarySearch += 1;
    }

    if( found == true ) // position != -1
    {
        std::cout << "YOU WIN!" << "\n";
        std::cout << "Ticket number " << position+1 << ", was the winning ticket." << "\n";
    }
    else // found == false or position == -1 
    {
        std::cout << "Better luck next time." << "\n";
    }

    std::cout << " " << "\n";
}

void bubbleSort(int lotteryTickets_array[], const int sizeOF_lotteryTickets_array,int &ele, int &sum_bubbleSort)
{
    std::cout << "---bubbleSort---" << "\n"; std::cout << " " << "\n";
    bool swaping;
    int temp;
    do
    {
        swaping = false;
        for (int count = 0; count < (sizeOF_lotteryTickets_array - 1); count++)
        {
            if (lotteryTickets_array[count] > lotteryTickets_array[count + 1])
            {
                temp = lotteryTickets_array[count];
                lotteryTickets_array[count] = lotteryTickets_array[count + 1];
                lotteryTickets_array[count + 1] = temp;
                swaping = true;
                sum_bubbleSort += 1;
            }
        }
    } while (swaping);
}

int main()
{
	char letter;
    int ele,
        sizeOF_lotteryTickets_array{30},
        lotteryNumbers, // wining lotto numbers
        sum_linearSearch{0},
        sum_binarySearch{0},
        sum_bubbleSort{0},
        sum_selectionSort{0};
    int lotteryTickets_array[sizeOF_lotteryTickets_array]{13579, 26791, 26792, 33445, 55555,
                                                          62483, 77777, 79422, 85641, 93121,
                                                          22483, 77727, 79422, 85642, 93021,
                                                          32583, 77777, 79422, 85643, 92121,
                                                          82493, 77377, 79422, 85648, 93141,
                                                          12483, 17777, 79522, 85697, 11111};
    std::vector<int> lotteryTickets;

	while(letter != 'n')
	{
        initialize_lotteryNumbers(lotteryTickets, 
                                  lotteryTickets_array, 
                                  sizeOF_lotteryTickets_array,
                                  ele);

        get_lotteryNumbers(lotteryNumbers);

        linearSearch_lotteryTickets(lotteryTickets, ele, lotteryNumbers, sum_linearSearch);

        selectionSort(lotteryTickets, sum_selectionSort);

        binarySearch_lotteryTickets(lotteryTickets, lotteryNumbers, sum_binarySearch);

        std::cout << "The number of comparisons the linearSearch made was : " << sum_linearSearch << "\n";
        std::cout << "The number of comparisons the binarySearch made was : " << sum_binarySearch << "\n";

        bubbleSort(lotteryTickets_array,sizeOF_lotteryTickets_array,ele, sum_bubbleSort);

        std::cout << "The number of exchanges the bubbleSort made was : " << sum_bubbleSort << "\n";
        std::cout << "The number of exchanges the selectionSort made was : " << sum_selectionSort << "\n";

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}



