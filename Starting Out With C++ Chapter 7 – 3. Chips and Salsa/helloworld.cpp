/*
Starting Out With C++ Chapter 7 – 3. Chips and Salsa

Write a program that lets a maker of chips and salsa keep track of sales for five different types of salsa: mild, medium, sweet, hot, and zesty.

The program should use two parallel 5-element arrays: 
an array of strings that holds the five salsa names 
and 
an array of integers that holds the number of jars sold during the past month for each salsa type. 

The salsa names should be stored using an initialization list at the time the name array is created. 

The program should prompt the user to enter the number of jars sold for each type. 

Once this sales data has been entered, the program should produce a report that displays 
sales for each salsa type, 
total sales, 
and the names of the highest selling and lowest selling products.

Input Validation: Do not accept negative values for number of jars sold.
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

double inputValidation_postiveInteger_array(const std::string salsa_names[], int jars_sold_per_salsa[], int ele)
{
    std::cin >> jars_sold_per_salsa[ele];

    while( jars_sold_per_salsa[ele] < 0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer" << "\n";
        std::cout << "For salsa " << salsa_names[ele] << ", input the number of jars sold during the past month : ";
            std::cin >> jars_sold_per_salsa[ele];
    }
    return jars_sold_per_salsa[ele];
}

void GET_jars_sold_per_salsa(const std::string salsa_names[], int jars_sold_per_salsa[], const int sizeOF_salsa_names, int ele)
{
    std::cout << "---GET_jars_sold_per_salsa---" << "\n"; std::cout << " " << "\n";

    for(ele = 0; ele<sizeOF_salsa_names; ++ele)
    {
        std::cout << "For salsa " << salsa_names[ele] << ", input the number of jars sold during the past month : ";
            inputValidation_postiveInteger_array(salsa_names,jars_sold_per_salsa,ele);
    }
    std::cout << " " << "\n";
}

void TOTAL_salsaJars_sold(const int jars_sold_per_salsa[], const int sizeOF_salsa_names, int ele)
{
    std::cout << "---TOTAL_salsaJars_sold---" << "\n"; std::cout << " " << "\n";
    int total;

    for(ele=0;ele<sizeOF_salsa_names;++ele)
    {
        total += jars_sold_per_salsa[ele];
    }

    std::cout << "The TOTAL sold salsa jars in the past month is : " << total << "\n";
    std::cout << " " << "\n";
}

void MOST_salsaJars_sold(const std::string salsa_names[], const int jars_sold_per_salsa[], const int sizeOF_salsa_names, int ele)
{
    std::cout << "---MOST_salsaJars_sold---" << "\n"; std::cout << " " << "\n";
    int most_sold{jars_sold_per_salsa[0]};
    std::string MOST_sold_salsa_name;

    for(ele=0; ele<sizeOF_salsa_names; ++ele)
    {
        if(jars_sold_per_salsa[ele]>most_sold)
        {
            most_sold = jars_sold_per_salsa[ele];
        }
    }

    for(ele=0; ele<sizeOF_salsa_names; ++ele)
    {
        if(most_sold == jars_sold_per_salsa[ele])
        {
            MOST_sold_salsa_name = salsa_names[ele];
        }
    }

    std::cout << MOST_sold_salsa_name << " was the MOST sold salsa jars in the past month is : " << most_sold << "\n";
    std::cout << " " << "\n";
}

void LEAST_salsaJars_sold(const std::string salsa_names[], const int jars_sold_per_salsa[], const int sizeOF_salsa_names, int ele)
{
    std::cout << "---LEAST_salsaJars_sold---" << "\n"; std::cout << " " << "\n";
    int LEAST_sold{jars_sold_per_salsa[0]};
    std::string LEAST_sold_salsa_name;

    for(ele=0; ele<sizeOF_salsa_names; ++ele)
    {
        if(jars_sold_per_salsa[ele]<LEAST_sold)
        {
            LEAST_sold = jars_sold_per_salsa[ele];
        }
    }

    for(ele=0; ele<sizeOF_salsa_names; ++ele)
    {
        if(LEAST_sold == jars_sold_per_salsa[ele])
        {
            LEAST_sold_salsa_name = salsa_names[ele];
        }
    }

    std::cout << LEAST_sold_salsa_name << " was the LEAST sold salsa jars in the past month is : " << LEAST_sold << "\n";
    std::cout << " " << "\n";
}

void REPORT_salsa(const std::string salsa_names[], const int jars_sold_per_salsa[], const int sizeOF_salsa_names, int ele)
{
    std::cout << "---REPORT_salsa---" << "\n"; std::cout << " " << "\n";

    for(ele = 0; ele<sizeOF_salsa_names; ++ele)
    {
        std::cout << " The number of jars sold during the past month for " << salsa_names[ele] << " salsa was : " << jars_sold_per_salsa[ele] << "\n";
        std::cout << " " << "\n";
    }

    std::cout << " " << "\n";
}

int main()
{
	char letter;
    int ele,
        sizeOF_salsa_names{5};
    std::string salsa_names[sizeOF_salsa_names] = {"mild", "medium", "sweet", "hot", "zesty"};
    int jars_sold_per_salsa[sizeOF_salsa_names];

	while(letter != 'n')
	{
        GET_jars_sold_per_salsa(salsa_names, jars_sold_per_salsa, sizeOF_salsa_names, ele);
        REPORT_salsa(salsa_names, jars_sold_per_salsa, sizeOF_salsa_names, ele);
        TOTAL_salsaJars_sold(jars_sold_per_salsa, sizeOF_salsa_names, ele);
        MOST_salsaJars_sold(salsa_names, jars_sold_per_salsa, sizeOF_salsa_names, ele);
        LEAST_salsaJars_sold(salsa_names, jars_sold_per_salsa, sizeOF_salsa_names, ele);

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}