/*
Starting Out With C++ Chapter 11 Structured Data - 6. Soccer Scores
Write a program that stores the following data about a soccer player in a structure:
Player’s Name
Player’s Number
Points Scored by Player

The program should keep an array of 12 of these structures. 
Each element is for a different player on a team. 
When the program runs it should ask the user to enter the data for each player. 
It should then show a table that lists each player’s number, name, and points scored. 
The program should also calculate and display the total points earned by the team. 
The number and name of the player who has earned the most points should also be displayed.
Input Validation: Do not accept negative values for players’ numbers or points scored.
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

int inputValidation_temps(int &integer);

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

struct WeatherData
{
    std::string monthName;

    int totalRainfall,
        highTemperature,
        lowTemperature,
        averageTemperature;
};
    
    WeatherData months[12];

    enum Months{ JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER };

    void getWeatherData(WeatherData months[]);
    void WeatherStatistics(WeatherData months[]);

struct SoccerPlayer
{
    std::string PlayerName;
    int PlayerNumber;
    int PlayerPointsScored;
};

    SoccerPlayer soccerTeam[12];

    void getSoccerTeamData(SoccerPlayer soccerTeam[]);
    void displaySoccerTeamData(SoccerPlayer soccerTeam[]);

int main()
{
    char letter,
         userChoice;
        
	while(letter != 'n')
	{
        std::cout << "User, choice a program to run." << "\n";
            std::cout << "A) Movie Data" << "\n";
            std::cout << "B) Corporate Sales Data" << "\n";
            std::cout << "C) Weather Statistics" << "\n";
            std::cout << "D) Soccer Scores" << "\n";
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
            if(tolower(userChoice) == 'c') 
            {
                getWeatherData(months);
                WeatherStatistics(months);
            }
            if(tolower(userChoice) == 'd') 
            {
                getSoccerTeamData(soccerTeam);
                    displaySoccerTeamData(soccerTeam);
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
                
                getWeatherData(months);
                    WeatherStatistics(months);

                getSoccerTeamData(soccerTeam);
                    displaySoccerTeamData(soccerTeam);
            }

            std::cout << " " << "\n";
            std::cout << "User, choice a program to run." << "\n";
                std::cout << "A) Movie Data" << "\n";
                std::cout << "B) Corporate Sales Data" << "\n";
                std::cout << "C) Weather Statistics" << "\n";
                std::cout << "D) Soccer Scores" << "\n";
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

    while( integer<0  )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "Input again : ";
            std::cin >> integer;
    }
    return integer;
}

int inputValidation_temps(int &integer)
{
    std::cin >> integer;

    while( integer<-100 || integer>140 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Only accept temperatures within the range between -100 and +140 degrees Fahrenheit." << "\n";
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
        //std::cin >> division.firstQuarterSales;

    std::cout << "Input the Second Quarter Sales data : ";
        inputValidation_postiveInteger(division.secondQuarterSales);
        //std::cin >> division.secondQuarterSales;
    
    std::cout << "Input the Thrird Quarter Sales data : ";
        inputValidation_postiveInteger(division.thirdQuarterSales);
        //std::cin >> division.thirdQuarterSales;

    std::cout << "Input the Fourth Quarter Sales data : ";
        inputValidation_postiveInteger(division.fourthQuarterSales);
        //std::cin >> division.fourthQuarterSales;

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

void getWeatherData(WeatherData months[])
{
    std::cout << "----getWeatherData----" << "\n"; std::cout << " " << "\n";

    for(unsigned int ele{JANUARY}; ele<DECEMBER; ++ele) // Using an enum values to Step Through an Array’s Elements
    {
        std::cout << "User, for month " << static_cast<Months>(ele) << " input data." << "\n";
        std::cout << "Input Total Rainfall : ";
            inputValidation_postiveInteger(months[ele].totalRainfall);

        std::cout << "Input High Temperature : ";
            inputValidation_temps(months[ele].highTemperature);

        std::cout << "Input Low Temperature : ";
            inputValidation_temps(months[ele].lowTemperature);

        months[ele].averageTemperature = ( months[ele].highTemperature / months[ele].lowTemperature );

        std::cout << " " << "\n";
    }

    std::cout << " " << "\n";
}

void WeatherStatistics(WeatherData months[])
{
    std::cout << "----WeatherStatistics----" << "\n"; std::cout << " " << "\n";

    int averageMonthlyRainfall,
        yearTotalRainfall{0},
        highestTemperature{months[JANUARY].highTemperature},
        lowestTemperature{months[JANUARY].lowTemperature},
        averageOF_averageMonthlyRainfall{0},
        index;
    
    std::string highestTemperatureMonth{"JANUARY"},
                lowestTemperatureMonth{"JANUARY"};

    for(unsigned int ele{JANUARY}; ele<DECEMBER; ++ele) // Using an enum values to Step Through an Array’s Elements
    {
        yearTotalRainfall +=  months[ele].totalRainfall;
        averageOF_averageMonthlyRainfall += months[ele].averageTemperature;

        // if the current month had a higher temp than highestTemperature... update highestTemperature
        if( months[ele].highTemperature > highestTemperature ) 
        {
            highestTemperature = months[ele].highTemperature;
            index = ele;

            switch (ele)
            {
                case JANUARY:
                    highestTemperatureMonth = "JANUARY";
                    break;
                case FEBRUARY:
                    highestTemperatureMonth = "FEBRUARY";
                    break;
                case MARCH:
                    highestTemperatureMonth = "MARCH";
                    break;
                case APRIL:
                    highestTemperatureMonth = "APRIL";
                    break;
                case MAY:
                    highestTemperatureMonth = "MAY";
                    break;
                case JUNE:
                    highestTemperatureMonth = "JUNE";
                    break;
                case JULY:
                    highestTemperatureMonth = "JULY";
                    break;
                case AUGUST:
                    highestTemperatureMonth = "AUGUST";
                    break;
                case SEPTEMBER:
                    highestTemperatureMonth = "SEPTEMBER";
                    break;
                case OCTOBER:
                    highestTemperatureMonth = "OCTOBER";
                    break;
                case NOVEMBER:
                    highestTemperatureMonth = "NOVEMBER";
                    break;
                case DECEMBER:
                    highestTemperatureMonth = "DECEMBER";
                    break;
                default:
                    break;
            }
        }

        // if the current month had a lower temp than lowestTemperature... update highestTempelowestTemperaturerature
        if( months[ele].lowTemperature < lowestTemperature ) 
        {
            lowestTemperature = months[ele].lowTemperature;

            switch (ele)
            {
                case JANUARY:
                    lowestTemperatureMonth = "JANUARY";
                    break;
                case FEBRUARY:
                    lowestTemperatureMonth = "FEBRUARY";
                    break;
                case MARCH:
                    lowestTemperatureMonth = "MARCH";
                    break;
                case APRIL:
                    lowestTemperatureMonth = "APRIL";
                    break;
                case MAY:
                    lowestTemperatureMonth = "MAY";
                    break;
                case JUNE:
                    lowestTemperatureMonth = "JUNE";
                    break;
                case JULY:
                    lowestTemperatureMonth = "JULY";
                    break;
                case AUGUST:
                    highestTemperatureMonth = "AUGUST";
                    break;
                case SEPTEMBER:
                    lowestTemperatureMonth = "SEPTEMBER";
                    break;
                case OCTOBER:
                    lowestTemperatureMonth = "OCTOBER";
                    break;
                case NOVEMBER:
                    lowestTemperatureMonth = "NOVEMBER";
                    break;
                case DECEMBER:
                    lowestTemperatureMonth = "DECEMBER";
                    break;
                default:
                    break;
            }
        }
    }

    //the total rainfall for the year, 
    std::cout << "the total rainfall for the year : " << yearTotalRainfall << "\n";
        std::cout << " " << "\n";

    // the average monthly rainfall, 
    averageMonthlyRainfall = yearTotalRainfall / 12;
        std::cout << "the average monthly rainfall : " << averageOF_averageMonthlyRainfall/12 << "\n";
        std::cout << " " << "\n";

    //the highest and lowest temperatures for the year (and the months they occurred in),
    std::cout << "During the month of " << highestTemperatureMonth << ", the highest temperature for the year occured : " << highestTemperature << "\n";
        std::cout << " " << "\n";
    std::cout << "During the month of " << lowestTemperatureMonth << ", the highest temperature for the year occured : " << lowestTemperature << "\n";
        std::cout << " " << "\n";

    // and the average of all the monthly average temperatures.
    std::cout << "the average of all the monthly average temperatures was : " << (averageOF_averageMonthlyRainfall / 12) << "\n";
        std::cout << " " << "\n";
}

void getSoccerTeamData(SoccerPlayer soccerTeam[])
{
    std::cout << "----getSoccerTeamData----" << "\n"; std::cout << " " << "\n";

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // When the program runs it should ask the user to enter the data for each player.
    for(unsigned int ele{0}; ele<12; ++ele)
    {
        std::cout << "User, for player " << ele+1 << " input data." << "\n";
            std::cout << "Input the player's name : "; 
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin,soccerTeam[ele].PlayerName);

            std::cout << "Input the player's number : ";
                inputValidation_postiveInteger(soccerTeam[ele].PlayerNumber); 
            
            std::cout << "Input the Points Scored by the Player : ";
                inputValidation_postiveInteger(soccerTeam[ele].PlayerPointsScored);
        
        std::cout << " " << "\n";
    }
    std::cout << " " << "\n";
}

void displaySoccerTeamData(SoccerPlayer soccerTeam[])
{
    std::cout << "----displaySoccerTeamData----" << "\n"; std::cout << " " << "\n";
    int mostGoals{soccerTeam[0].PlayerPointsScored},
        mostGoalsPlayer,
        totalGoals{0};
    
    // It should then show a table that lists each player’s number, name, and points scored.
    for(unsigned int ele{0}; ele<12; ++ele)
    {
        std::cout << "Player " << soccerTeam[ele].PlayerNumber << ", " << soccerTeam[ele].PlayerName << ", scored " << soccerTeam[ele].PlayerPointsScored << " goals." << "\n";
        std::cout << " " << "\n";

        totalGoals += soccerTeam[ele].PlayerPointsScored;

        if( soccerTeam[ele].PlayerPointsScored > mostGoals )
        {
            mostGoals = soccerTeam[ele].PlayerPointsScored;
            mostGoalsPlayer = ele;
        }
    }

    // The program should also calculate and display the total points earned by the team. 
    std::cout << "The team scored  " << totalGoals << " goals." << "\n";
    
    // The number and name of the player who has earned the most points should also be displayed.
    std::cout << "Player " << soccerTeam[mostGoalsPlayer].PlayerNumber << ", " << soccerTeam[mostGoalsPlayer].PlayerName << ", scored the most goals : " << mostGoals << "\n";

    std::cout << " " << "\n";
}