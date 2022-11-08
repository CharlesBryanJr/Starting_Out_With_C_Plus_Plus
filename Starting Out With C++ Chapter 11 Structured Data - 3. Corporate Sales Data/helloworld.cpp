/*
Starting Out With C++ Chapter 11 Structured Data - 3. Corporate Sales Data
Write a program that uses a structure to store the following data on a company division:
Division Name (such as East, West, North, or South)
First-Quarter Sales
Second-Quarter Sales
Third-Quarter Sales
Fourth-Quarter Sales
Total Annual Sales
Average Quarterly Sales

The program should use four variables of this structure. 
Each variable should represent one of the following corporate divisions: East, West, North, and South. 

The user should be asked for the four quarters’ sales figures for each division. 

Each division’s total and average sales should be calculated and stored in the appropriate member of each structure variable. 

These figures should then be displayed on the screen.
Input Validation: Do not accept negative numbers for any sales figures.
*/

#include <iostream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <cctype>
#include <cstring>
#include <string>
#include <cstdlib>
#include <limits>

char inputValidation_y_or_n(char &letter);

int inputValidation_postiveInteger(int &ref_number);

double inputValidation_postiveInteger_array(double postiveInteger_array[], const int &ele);

int inputValidation_postiveInteger_array2D(int MonkeyBusiness[][5], const int row_ele, const int column_ele);

struct MovieData
{
    std::string title;
    std::string director;
    int yearRelased;
    int runningTime; // in minutes
    int budget;
    int boxOffice;
};

    MovieData batman{ "The Dark Knight", "Christopher Nolan", 2008, 152, 185000000, 100600000 };
    MovieData jamesBond{ "No Time to die", "Cary Joji Fukunaga", 2022, 163, 250000000, 77400000 };

void displayMovieData(const MovieData &movie);

struct CorporateSalesData
{
    std::string divisionName; // (such as East, West, North, or South)
    int firstQuarterSales;
    int secondQuarterSales;
    int thirdQuarterSales;
    int fourthQuarterSales;
    int totalAnnualSales;
    int averageQuarterlySales;
};

    CorporateSalesData east { "East" };
    CorporateSalesData west { "West" };
    CorporateSalesData north { "North" };
    CorporateSalesData south { "South" };

void calculateCorporateSalesData(CorporateSalesData &division);
void displayCorporateSalesData(const CorporateSalesData &division);

int main()
{
    char letter,
         userChoice;
        
	while(letter != 'n')
	{
        std::cout << "User, choice a program to run." << "\n";
            std::cout << "A) Movie Data" << "\n";
            std::cout << "B) Corporate Sales Data" << "\n";
            std::cout << "E) Exit program" << "\n";
                std::cin >> userChoice;

        while(tolower(userChoice) != 'e')
        {
            
            if(tolower(userChoice) == 'a') 
            {
                displayMovieData(batman);
                std::cout << " " << "\n";
                displayMovieData(jamesBond);
            }
            if(tolower(userChoice) == 'b') 
            {
                calculateCorporateSalesData(east);
                    displayCorporateSalesData(east);

                calculateCorporateSalesData(west);
                    displayCorporateSalesData(west);

                calculateCorporateSalesData(north);
                    displayCorporateSalesData(north);

                calculateCorporateSalesData(south);
                    displayCorporateSalesData(south);
            }
            if(tolower(userChoice) == 'z') // run everything
            {
                displayMovieData(batman);
                    std::cout << " " << "\n";
                displayMovieData(jamesBond);

                calculateCorporateSalesData(east);
                    displayCorporateSalesData(east);

                calculateCorporateSalesData(west);
                    displayCorporateSalesData(west);

                calculateCorporateSalesData(north);
                    displayCorporateSalesData(north);
                    
                calculateCorporateSalesData(south);
                    displayCorporateSalesData(south);

            }

            std::cout << " " << "\n";
            std::cout << "User, choice a program to run." << "\n";
                std::cout << "A) Movie Data" << "\n";
                std::cout << "B) Corporate Sales Data" << "\n";
                    std::cin >> userChoice;
        }
        
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
			inputValidation_y_or_n(letter);	std::cout << " " << "\n";
    }

	return 0;
}

char inputValidation_y_or_n(char &letter)
{
    std::cin >> letter;
		while (tolower(letter) != 'y' && tolower(letter) != 'n')
    {
        std::cout << "ERROR: a 'y' or an 'n' must be entered: ";
        std::cin.clear();
        std::cin >> letter;
    }
    return letter;
}

int inputValidation_postiveInteger(int &integer)
{
    std::cin >> integer;

    while( integer<0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "Input again : ";
            std::cin >> integer;
    }
    return integer;
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

void displayMovieData(const MovieData &movie)
{
    std::cout << "----displayMovieData----" << "\n"; std::cout << " " << "\n";

    std::cout << movie.title << "\n";
    std::cout << movie.director << "\n";
    std::cout << movie.yearRelased << "\n";
    std::cout << movie.runningTime << "\n";
    std::cout << movie.budget << "\n";
    std::cout << movie.boxOffice << "\n";

    std::cout << " " << "\n";
}

void calculateCorporateSalesData(CorporateSalesData &division)
{
    std::cout << "----calculateCorporateSalesData----" << "\n"; std::cout << " " << "\n";

    std::cout << "User, input the divison data for the " << division.divisionName << " divison." << "\n";

    std::cout << "Input the First Quarter Sales data : ";
        inputValidation_postiveInteger(division.firstQuarterSales);
        std::cout << " " << "\n";

    std::cout << "Input the Second Quarter Sales data : ";
        inputValidation_postiveInteger(division.secondQuarterSales);
        std::cout << " " << "\n";
    
    std::cout << "Input the Thrird Quarter Sales data : ";
        inputValidation_postiveInteger(division.thirdQuarterSales);
        std::cout << " " << "\n";

    std::cout << "Input the Fourth Quarter Sales data : ";
        inputValidation_postiveInteger(division.fourthQuarterSales);
        std::cout << " " << "\n";

    division.totalAnnualSales = division.firstQuarterSales + division.secondQuarterSales + division.thirdQuarterSales + division.fourthQuarterSales;

    division.averageQuarterlySales = division.totalAnnualSales / 4;

    std::cout << " " << "\n";
}

void displayCorporateSalesData(const CorporateSalesData &division)
{
    std::cout << "----displayCorporateSalesData----" << "\n"; std::cout << " " << "\n";

    std::cout << "User, for the " << division.divisionName << " divison, here is the data." << "\n";

    std::cout << "totalAnnualSales : " << division.totalAnnualSales << "\n";
    std::cout << " " << "\n";

    std::cout << "averageQuarterlySales : " << division.averageQuarterlySales << "\n";
    std::cout << " " << "\n";
}