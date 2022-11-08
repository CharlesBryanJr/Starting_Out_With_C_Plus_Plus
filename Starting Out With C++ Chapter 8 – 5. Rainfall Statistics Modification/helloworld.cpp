/*
Starting Out With C++ Chapter 8 – 5. Rainfall Statistics Modification
Modify the Rainfall Statistics program you wrote for Programming Challenge 2 of Chapter 7. 
The program should display a list of months, sorted in order of rainfall, from highest to lowest.

Starting Out With C++ Chapter 7 – 2. Rainfall Statistics
Write a program that lets the user enter the total rainfall for each of 12 months into an array of doubles. 
The program should calculate and display the total rainfall for the year, the average monthly rainfall, and the months with the highest and lowest amounts.
Input Validation: Do not accept negative numbers for monthly rainfall figures.
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

double inputValidation_postiveInteger_array(double rainfall_perMonth[], int ele)
{
    std::cin >> rainfall_perMonth[ele];

    while( rainfall_perMonth[ele] < 0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer" << "\n";
        std::cout << "For month " << ele+1 << ", input the amout of rainfall : ";
            std::cin >> rainfall_perMonth[ele];
    }
    return rainfall_perMonth[ele];
}

void getRainfall_perMonth(double rainfall_perMonth[], const int rainfall_stats_SIZE)
{
    std::cout << "---getRainfall_perMonth---" << "\n"; std::cout << " " << "\n";
    std::cout << "enter the total rainfall for each of 12 months." << "\n";
    int ele;

    for(int ele{0}; ele<rainfall_stats_SIZE; ++ele)
    {
        std::cout << "For month " << ele+1 << ", input the amout of rainfall : ";
            inputValidation_postiveInteger_array(rainfall_perMonth, ele);
    }

    std::cout << " " << "\n";
}

void calculate_Rainfall_stats(const double rainfall_perMonth[], const int rainfall_stats_SIZE, int &total_rainfall, int &avg_rainfall)
{
    std::cout << "---calculate_Rainfall_stats---" << "\n"; std::cout << " " << "\n";

    for(int ele{0}; ele<rainfall_stats_SIZE; ++ele)
    {
        total_rainfall += rainfall_perMonth[ele];
    }
    std::cout << "The total rainfall for the year was : "  << total_rainfall << '\n';
        std::cout << " " << "\n";

    avg_rainfall = total_rainfall /rainfall_stats_SIZE;
        std::cout << "The average rainfall for a single month was : "  << avg_rainfall << '\n';

    std::cout << " " << "\n";
}

void highest_Rainfall_month(const double rainfall_perMonth[], const int rainfall_stats_SIZE, int &highest_rainfall_perMonth)
{
    std::cout << "---highest_Rainfall_month---" << "\n"; std::cout << " " << "\n";
    highest_rainfall_perMonth = rainfall_perMonth[0];

    for(int ele{0}; ele<rainfall_stats_SIZE; ++ele)
    {
        if( rainfall_perMonth[ele] > highest_rainfall_perMonth)
        {
            highest_rainfall_perMonth = rainfall_perMonth[ele];
        }
    }
    std::cout << "The highest rainfall for a single month was : "  << highest_rainfall_perMonth << '\n';

    std::cout << " " << "\n";
}

void lowest_Rainfall_month(const double rainfall_perMonth[], const int rainfall_stats_SIZE, int &smallest_rainfall_perMonth)
{
    std::cout << "---lowest_Rainfall_month---" << "\n"; std::cout << " " << "\n";
    smallest_rainfall_perMonth = rainfall_perMonth[0];

    for(int ele{0}; ele<rainfall_stats_SIZE; ++ele)
    {
        if( rainfall_perMonth[ele] < smallest_rainfall_perMonth )
        {
            smallest_rainfall_perMonth = rainfall_perMonth[ele];
        }
    }
    std::cout << "The smallest rainfall for a single month was : "  << smallest_rainfall_perMonth << '\n';

    std::cout << " " << "\n";
}

void selection_sort(double rainfall_perMonth[], const int &rainfall_stats_SIZE, std::vector<double> &rainfall_per_Month)
{
    std::cout << "---selection_sort---" << "\n"; std::cout << " " << "\n";
    int minIndex,
        minValue,
        startSort;
    
    for(int startSort{0}; startSort<rainfall_stats_SIZE; ++startSort)
    {
        minIndex = startSort;
        minValue = rainfall_perMonth[startSort];

        for(int ele = (startSort+1); ele<rainfall_stats_SIZE; ++ele)
        {
            if(rainfall_perMonth[ele] < minValue)
            {
                minValue = rainfall_perMonth[ele];
                minIndex = ele;
            }
        }
        rainfall_per_Month.push_back(minIndex);
        rainfall_perMonth[minIndex] = rainfall_perMonth[startSort];
        rainfall_perMonth[startSort] = minValue;
    }
    
    std::cout << "Here are the list of months, sorted by rainfall, from highest to lowest." << "\n";
        for(int element{rainfall_stats_SIZE-1}; element>=0; --element)
        {
            std::cout << "For month " << rainfall_per_Month[element] << ", the rainfall was : " << rainfall_perMonth[element] << "\n";
        }

    std::cout << "Here are the list of months, sorted by rainfall, from lowest to highest." << "\n";
        for(int element{0}; element,rainfall_stats_SIZE; ++element)
        {
            std::cout << "For month " << rainfall_per_Month[element] << ", the rainfall was : " << rainfall_perMonth[element] << "\n";
        }

    std::cout << " " << "\n";
}

int main()
{
	char letter;
    int rainfall_stats_SIZE{12},
        total_rainfall{0},
        avg_rainfall{0},
        highest_rainfall_perMonth{0},
        smallest_rainfall_perMonth,
        ele;
    double rainfall_perMonth[rainfall_stats_SIZE];
    std::vector<double> rainfall_per_Month;

	while(letter != 'n')
	{
        getRainfall_perMonth(rainfall_perMonth, rainfall_stats_SIZE);
        selection_sort(rainfall_perMonth,rainfall_stats_SIZE,rainfall_per_Month);
        calculate_Rainfall_stats(rainfall_perMonth, rainfall_stats_SIZE, total_rainfall, avg_rainfall);
        highest_Rainfall_month(rainfall_perMonth, rainfall_stats_SIZE, highest_rainfall_perMonth);
        lowest_Rainfall_month(rainfall_perMonth, rainfall_stats_SIZE, smallest_rainfall_perMonth);
        
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}