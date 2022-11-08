/*
16. Population
In a population, the birth rate is the percentage increase of the population due to births, and the death rate is the percentage decrease of the population due to deaths. 

Write a program that displays the size of a population for any number of years. 

The program should ask for the following data:
• The starting size of a population
• The annual birth rate
• The annual death rate
• The number of years to display

Write a function that calculates the size of the population for a year. 
The formula is N = P + BP − DP
where N is the new population size, 
P is the previous population size, 
B is the birth rate,
and D is the death rate.

Input Validation: Do not accept numbers less than 2 for the starting size. 
Input Validation: Do not accept negative numbers for birth rate or death rate. 
Input Validation: Do not accept numbers less than 1 for the number of years.
*/

#include <iostream>

char inputValidation_y_or_n(char &ref_letter)
{
    std::cin >> ref_letter;

    while (!(ref_letter == 'y' || ref_letter == 'n'))
    {
        std::cout << "ERROR: a 'y' or an 'n' must be entered: ";
        std::cin.clear();
        std::cin >> ref_letter;
    }
    return ref_letter;
}

// Input Validation: Do not accept numbers less than 2 for the starting size. 
double inputValidation_startingSize(double &ref_number)
{
    while( !(std::cin >> ref_number) || (ref_number<2) )
    {
        std::cout << "Input Validation: Do not accept numbers less than 2 for the starting size. : ";
        std::cin.clear();
    }
    return ref_number;
}

double inputValidation_postiveInteger(double &ref_number)
{
    while( !(std::cin >> ref_number) || (ref_number<0) )
    {
        std::cout << "Input Validation: Must be a postive integer : ";
        std::cin.clear();
    }
    return ref_number;
}

double inputValidation_number_of_years(double &ref_number)
{
    while( !(std::cin >> ref_number) || (ref_number<1) )
    {
        std::cout << "Input Validation: Do not accept numbers less than 1 for the number of years. : ";
        std::cin.clear();
    }
    return ref_number;
}

void cal_size_of_population( double population_startingSize, 
                             double annual_birth_rate, 
                             double annual_death_rate, 
                             double number_of_years )
{
    double population_newSize{population_startingSize};

    std::cout << "Using the formula N = P + BP - DP, the new population size is :  " << "\n";
    std::cout << "where N is the new population size" << "\n";
    std::cout << "P is the previous population size"  << "\n";
    std::cout << "B is the birth rate"  << "\n";
    std::cout << "and D is the death rate."  << "\n";
    std::cout << " " << "\n";

    for(int year{0}; year<number_of_years; year++)
    {
        population_newSize = population_newSize + (0.01*annual_birth_rate*population_newSize) - (0.01*annual_death_rate*population_newSize);
        std::cout << "The size of the new population for year " << year+1 << " is : " << population_newSize << "\n";
        std::cout << " " << "\n";
    }
}

int main()
{
	char letter;

    double  population_startingSize, 
            annual_birth_rate, 
            annual_death_rate, 
            number_of_years;

	while(letter != 'n')
	{
        std::cout << "• The starting size of a population : "; 
            inputValidation_startingSize(population_startingSize);
        std::cout << "• The annual birth rate : "; 
            inputValidation_postiveInteger(annual_birth_rate);
        std::cout << "• The annual death rate : "; 
            inputValidation_postiveInteger(annual_death_rate);
        std::cout << "• The number of years to display : "; 
            inputValidation_number_of_years(number_of_years);
        
        cal_size_of_population( population_startingSize, 
                                annual_birth_rate, 
                                annual_death_rate, 
                                number_of_years );
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}