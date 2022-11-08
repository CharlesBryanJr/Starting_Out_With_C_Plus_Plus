/*
Starting Out With C++ Chapter 11 Structured Data - 15. Multipurpose Payroll
Write a program that calculates pay for either an hourly paid worker or a salaried worker. 

Hourly paid workers are paid their hourly pay rate times the number of hours worked. 

Salaried workers are paid their regular salary plus any bonus they may have earned. 

The program should declare two structures for the following data:
Hourly Paid:
HoursWorked
HourlyRate
Salaried:
Salary
Bonus

The program should also declare a union with two members. 
Each member should be a structure variable: 
one for the hourly paid worker and another for the salaried worker.
The program should ask the user whether he or she is calculating the pay for an hourly paid worker or a salaried worker. 
Regardless of which the user selects, the appropriate members of the union will be used to store the data that will be used to calculate the pay.
Input Validation: Do not accept negative numbers. Do not accept values greater than 80 for HoursWorked.
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

int inputValidation_postiveInteger(int &integer);

    int inputValidation_postiveInteger(int *integer);

    double inputValidation_postiveInteger(double *integer);

    double inputValidation_DrinkMachineSimulator(double &coins);

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

struct CustomerAccount
{
    std::string name,
                address,
                city,
                state,
                telephoneNumber,
                lastPaymentDate;

    int zipCode,
        accountBalance;
};

    // The program should use an array of at least 10 structures.
    CustomerAccount customers[10];

    enum CustomerAccountData { name_CustomerAccountData,
                               address_CustomerAccountData,
                               city_CustomerAccountData,
                               state_CustomerAccountData,
                               telephoneNumber_CustomerAccountData,
                               lastPaymentDate_CustomerAccountData,
                               zipCode_CustomerAccountData,
                               accountBalance_CustomerAccountData };

    void getCustomerAccount(CustomerAccount customers[]);
    void displayCustomerAccount(CustomerAccount customers[]);

struct Speaker
{
    std::string name,
                telephoneNumbername,
                telephoneNumber,
                speakingTopic;

    int feeRequired;
};

    Speaker speakerBureau[14];

    enum SpeakerData {name_SpeakerData,telephoneNumber_SpeakerData,speakingTopic,feeRequired};

    void getSpeakerData(Speaker speakerBureau[]);
    void displaySpeakerData(Speaker speakerBureau[]);

struct MonthlyBudget // what the user can spend in a month
{
    int housing,
        utilities,
        householdExpenses,
        transportation,
        food,
        medical,
        insurance,
        entertainment,
        clothing,
        miscellaneous;
};

struct MonthlyExpenses // what the user spent in a month
{
    int housing,
        utilities,
        householdExpenses,
        transportation,
        food,
        medical,
        insurance,
        entertainment,
        clothing,
        miscellaneous;
};

    MonthlyBudget octoberBudget;
    MonthlyExpenses octoberExpenses;

    void getMonthlyBudget( MonthlyBudget &monthlyBudget );
    void getMonthlyExpenses( MonthlyExpenses &monthlyExpenses );
    void displayMonthlyReport( const MonthlyBudget &monthlyBudget, const MonthlyExpenses &monthlyExpenses );

struct StudentData
{
    std::string studentName;
    int Idnum; // Student ID number
    int *tests; // Pointer to an array of test scores
    double Average; // Average test score
    char grade; // Course grade
};

    enum CourseGrade { F = 0, D = 61, C = 71, B = 81, A = 91 };

    void getStudentData( StudentData *groupOfStudents, const int * const sizeOfClass, const int * constnumberOfTest );
    void displayClassData( const StudentData *groupOfStudents, const int * const sizeOfClass );

struct SoftDrinkMachine
{
    std::string drinkName;
    double drinkCost;
    int drinkQuantity;    
};
    
    void DrinkMachineSimulator(SoftDrinkMachine *soda, const int * const typesOfSoda );

struct InventoryBins
{
    int valve,
        bearing,
        bushing,
        coupling,
        flange,
        gear,
        gearHousing,
        vacuumGripper,
        cable,
        rod;
};
    InventoryBins warehouse[10];

    enum Bins
    {   valve,
        bearing,
        bushing,
        coupling,
        flange,
        gear,
        gearHousing,
        vacuumGripper,
        cable,
        rod
    };

    // AddParts: a function that increases a specific bin’s part count by a specified number.
    void addParts(InventoryBins warehouse[], const int &ele);

    // RemoveParts: a function that decreases a specific bin’s part count by a specified number.
    void removeParts(InventoryBins warehouse[], const int &ele);
    
    void runWarehouseInventory(InventoryBins warehouse[]);

struct HourlyPaid
{
    int hoursWorked,
        hourlyRate;
};

    HourlyPaid worker;

struct Salaried
{
    int salary,
        bonus;
};
    Salaried empolyee;

union MultipurposePayroll
{
    HourlyPaid hourly;
    Salaried salary;
};
    MultipurposePayroll worker_employee;

    void payroll(HourlyPaid worker, Salaried empolyee, MultipurposePayroll worker_employee);


//	*=== START MAIN FUNCTION ===*
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
            std::cout << "E) --- EXIT ---" << "\n";
            std::cout << "F) Customer Accounts" << "\n";
            std::cout << "G) Speakers' Bureau" << "\n";
            std::cout << "H) Monthly Budget/Expenses" << "\n";
            std::cout << "I) Course Grade" << "\n";
            std::cout << "J) Drink Machine Simulator" << "\n";
            std::cout << "K) Inventory Bins" << "\n";
            std::cout << "L) Multipurpose Payroll" << "\n";
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
            if(tolower(userChoice) == 'f') 
            {
                getCustomerAccount(customers);
                    displayCustomerAccount(customers);
            }
            if(tolower(userChoice) == 'g') 
            {
                getSpeakerData(speakerBureau);
                    displaySpeakerData(speakerBureau);
            }
            if(tolower(userChoice) == 'h') 
            {
                getMonthlyBudget( octoberBudget );
                    getMonthlyExpenses( octoberExpenses );
                    displayMonthlyReport( octoberBudget, octoberExpenses );
            }
            if(tolower(userChoice) == 'i') 
            {
                // It should ask the user how many test scores there are to be and how many students there are. 
                int *sizeOfClass{nullptr};
                    sizeOfClass = new int;               
                
                std::cout << "User, input the size of the class : ";
                    inputValidation_postiveInteger(*sizeOfClass);
                    std::cout << " " << "\n";

                int *numberOfTest{nullptr};
                    numberOfTest = new int;

                std::cout << "User, for a class size of " << *sizeOfClass << ", input the number of test taken : ";
                    inputValidation_postiveInteger(*numberOfTest);
                    std::cout << " " << "\n";
                
                // dynamically allocate an array of structures (size is the num of students)
                StudentData *groupOfStudents{nullptr};
                    groupOfStudents = new StudentData[*sizeOfClass];
                
                getStudentData( groupOfStudents, sizeOfClass, numberOfTest );
                    displayClassData( groupOfStudents, sizeOfClass );

                delete numberOfTest;
                    numberOfTest = nullptr;

                delete sizeOfClass;
                    sizeOfClass = nullptr;

                delete[] groupOfStudents;
                    groupOfStudents = nullptr;
            }
            if(tolower(userChoice) == 'j')
            {
                int *typesOfSoda{nullptr};
                    typesOfSoda = new int;
                
                int temp;
                
                std::cout << "User, the Drink Machine already has 5 different types of soda, how many more would you like to add : ";
                    inputValidation_postiveInteger(temp); // greater than 0
                    *typesOfSoda = 5 + temp;
                
                    SoftDrinkMachine *soda{nullptr};
                        soda = new SoftDrinkMachine[*typesOfSoda];

                            soda[0].drinkName = "Cola";
                            soda[0].drinkCost = .75;
                            soda[0].drinkQuantity = 20;

                            soda[1].drinkName = "Root Beer";
                            soda[1].drinkCost = .75;
                            soda[1].drinkQuantity = 20;

                            soda[2].drinkName = "Lemon-Lime";
                            soda[2].drinkCost = .75;
                            soda[2].drinkQuantity = 20;

                            soda[3].drinkName = "Grape Soda";
                            soda[3].drinkCost = .80;
                            soda[3].drinkQuantity = 20;

                            soda[4].drinkName = "Cream Soda";
                            soda[4].drinkCost = .80;
                            soda[4].drinkQuantity = 20;
                    
                    DrinkMachineSimulator( soda, typesOfSoda );

                delete typesOfSoda;
                    typesOfSoda = nullptr;
                
                delete[] soda;
                    soda = nullptr;
            }
            if(tolower(userChoice) == 'k') 
            {
                runWarehouseInventory(warehouse);
            }
            if(tolower(userChoice) == 'l') 
            {
                payroll( worker,  empolyee,  worker_employee);
            }


            std::cout << " " << "\n";
            std::cout << "User, choice a program to run." << "\n";
                std::cout << "A) Movie Data" << "\n";
                std::cout << "B) Corporate Sales Data" << "\n";
                std::cout << "C) Weather Statistics" << "\n";
                std::cout << "D) Soccer Scores" << "\n";
                std::cout << "E) --- EXIT ---" << "\n";
                std::cout << "F) Customer Accounts" << "\n";
                std::cout << "G) Speakers' Bureau" << "\n";
                std::cout << "H) Monthly Budget/Expenses" << "\n";
                std::cout << "I) Course Grade" << "\n";
                std::cout << "J) Drink Machine Simulator" << "\n";
                std::cout << "K) Inventory Bins" << "\n";
                std::cout << "L) Multipurpose Payroll" << "\n";
                    std::cin >> userChoice;
        }
        
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
			inputValidation_y_or_n(letter);	std::cout << " " << "\n";
    }

	return 0;
}
// *=== END MAIN FUNCTION ===*

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

int inputValidation_postiveInteger(int *integer)
{
    std::cin >> *integer;

    while( *integer<0  )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer." << "\n";
        std::cout << "Input again : ";
            std::cin >> *integer;
    }
    return *integer;
}

double inputValidation_postiveDouble(double &decimal)
{
    std::cin >> decimal;

    while( decimal<0  )
    {
        std::cin.clear();
        std::cout << "Input Validation: Do not accept negative values." << "\n";
        std::cout << "Input again : ";
            std::cin >> decimal;
    }
    return decimal;
}

double inputValidation_DrinkMachineSimulator(double &coins)
{
    std::cin >> coins;

    while( coins<0.00 || coins>1.00 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive number less than 1.00." << "\n";
        std::cout << "Input Validation: When the user enters an amount of money, do not accept negative values or values greater than $1.00." << "\n";
        std::cout << "Input again : ";
            std::cin >> coins;
    }
    return coins;
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
    std::cout << "During the month of " << lowestTemperatureMonth << ", the lowest temperature for the year occured : " << lowestTemperature << "\n";
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

void getCustomerAccount(CustomerAccount customers[])
{
    std::cout << "----getCustomerAccount----" << "\n"; std::cout << " " << "\n";

    // input starting data
    for(unsigned int ele{0}; ele<10; ++ele)
    {
        customers[ele].name = "John Doe";
        customers[ele].address = "1 Arrowhead Dr, Kansas City, MO 64129";
        customers[ele].city = "Kansas City";
        customers[ele].state = "Missouri";
        customers[ele].zipCode = 64129;
        customers[ele].accountBalance = 1;
        customers[ele].lastPaymentDate = "6/30/1997";
    }
    
    // It should let the user enter data into the array, change the contents of any element, and display all the data stored in the array.

    char newUpdate{'y'};
    int accountToUpdate,
        contentToUpdate;
    std::string serachAccounts;

    customers[0].name = "Charles Bryan";

    while( tolower(newUpdate) == 'y')
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "What customer account would you like to search for? : ";
            // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin,serachAccounts);
        
        for(unsigned int ele{0}; ele<serachAccounts.size(); ++ele)
        {
            if( serachAccounts == customers[ele].name )
            {
                std::cout << "Match found!" << "\n";
                    std::cout << " " << "\n";

                std::cout << "For customer, " << ele+1 << ", here is the account details." << "\n";
                    std::cout << "Name : " << customers[ele].name << "\n";
                    std::cout << "address : " << customers[ele].address << "\n";
                    std::cout << "city : " << customers[ele].city << "\n";
                    std::cout << "state : " << customers[ele].state << "\n";
                    std::cout << "zipCode : " << customers[ele].zipCode << "\n";
                    std::cout << "telephoneNumber : " << customers[ele].telephoneNumber << "\n";
                    std::cout << "accountBalance : " << customers[ele].accountBalance << "\n";
                    std::cout << "lastPaymentDate : " << customers[ele].lastPaymentDate << "\n";
                std::cout << " " << "\n";
            }
        }
        
        std::cout << "What customer account would you like to update? (1-10) : ";
            std::cin >> accountToUpdate;
            std::cout << " " << "\n";
        
        std::cout << "For customer, " << accountToUpdate << ", here is the account details." << "\n";
            std::cout << "Name : " << customers[accountToUpdate-1].name << "\n";
            std::cout << "address : " << customers[accountToUpdate-1].address << "\n";
            std::cout << "city : " << customers[accountToUpdate-1].city << "\n";
            std::cout << "state : " << customers[accountToUpdate-1].state << "\n";
            std::cout << "zipCode : " << customers[accountToUpdate-1].zipCode << "\n";
            std::cout << "telephoneNumber : " << customers[accountToUpdate-1].telephoneNumber << "\n";
            std::cout << "accountBalance : " << customers[accountToUpdate-1].accountBalance << "\n";
            std::cout << "lastPaymentDate : " << customers[accountToUpdate-1].lastPaymentDate << "\n";
        std::cout << " " << "\n";

        std::cout << "What would you like to update?" << "\n";
            std::cout << "1) CustomerAccountName : " << "\n";
            std::cout << "2) address : " << "\n";
            std::cout << "3) city : " << "\n";
            std::cout << "4) state : " << "\n";
            std::cout << "5) zipCode : " << "\n";
            std::cout << "6) telephoneNumber : " << "\n";
            std::cout << "7) accountBalance : " << "\n";
            std::cout << "8) lastPaymentDate : " << "\n";
        std::cin >> contentToUpdate;
            std::cout << " " << "\n";
        
        
        switch (contentToUpdate)
        {
            case name_CustomerAccountData: // std::cout << "1) Name : " << "\n";
                std::cout << "User, the current name is : " << customers[accountToUpdate-1].name << "\n";
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Input an updated name : ";
                    std::getline(std::cin,customers[accountToUpdate-1].name);
                break;

            case address_CustomerAccountData:
                std::cout << "User, the current address is : " << customers[accountToUpdate-1].address << "\n";
                std::cout << "Input an updated address : ";
                    std::cin >> customers[accountToUpdate-1].address;
                break;

            case city_CustomerAccountData:
                std::cout << "User, the current city is : " << customers[accountToUpdate-1].city << "\n";
                std::cout << "Input an updated city : ";
                    std::cin >> customers[accountToUpdate-1].city;
                break;

            case state_CustomerAccountData:
                std::cout << "User, the current state is : " << customers[accountToUpdate-1].state << "\n";
                std::cout << "Input an updated state : ";
                    std::cin >> customers[accountToUpdate-1].state;
                break;

            case zipCode_CustomerAccountData:
                std::cout << "User, the current zipCode is : " << customers[accountToUpdate-1].zipCode << "\n";
                std::cout << "Input an updated zipCode : ";
                    std::cin >> customers[accountToUpdate-1].zipCode;
                break;

            case telephoneNumber_CustomerAccountData:
                std::cout << "User, the current telephoneNumber is : " << customers[accountToUpdate-1].telephoneNumber << "\n";
                std::cout << "Input an updated telephoneNumber : ";
                    std::cin >> customers[accountToUpdate-1].telephoneNumber;
                break;

            case accountBalance_CustomerAccountData:
                std::cout << "User, the current accountBalance is : " << customers[accountToUpdate-1].accountBalance << "\n";
                std::cout << "Input an updated accountBalance : ";
                    inputValidation_postiveInteger(customers[accountToUpdate-1].accountBalance);
                break;

            case lastPaymentDate_CustomerAccountData:
                std::cout << "User, the current lastPaymentDate is : " << customers[accountToUpdate-1].lastPaymentDate << "\n";
                std::cout << "Input an updated lastPaymentDate : ";
                    std::cin >> customers[accountToUpdate-1].lastPaymentDate;
                break;

            default:
                break;
        }

        std::cout << " " << "\n";
        std::cout << "If you would like to make another update to a customer account, input 'y' : ";
            std::cin >> newUpdate;
            std::cout << " " << "\n";
    }

    std::cout << " " << "\n";
}

void displayCustomerAccount(CustomerAccount customers[])
{
    std::cout << "----displayCustomerAccount----" << "\n"; std::cout << " " << "\n";

    for(unsigned int ele{0}; ele<10; ++ele)
    {
        std::cout << "For customer, " << ele+1 << ", here is the account details." << "\n";
            std::cout << "Name : " << customers[ele].name << "\n";
            std::cout << "address : " << customers[ele].address << "\n";
            std::cout << "city : " << customers[ele].city << "\n";
            std::cout << "state : " << customers[ele].state << "\n";
            std::cout << "zipCode : " << customers[ele].zipCode << "\n";
            std::cout << "accountBalance : " << customers[ele].accountBalance << "\n";
            std::cout << "lastPaymentDate : " << customers[ele].lastPaymentDate << "\n";
        std::cout << " " << "\n";
    }
}

void getSpeakerData(Speaker speakerBureau[])
{
    std::cout << "----getSpeakerData----" << "\n"; std::cout << " " << "\n";

        // input starting data    

    for(unsigned int ele{0}; ele<14; ++ele)
    {            
        speakerBureau[ele].name = "John Doe";
        speakerBureau[ele].telephoneNumber = "000-000-0000";
        speakerBureau[ele].speakingTopic = "State of the Economy";
        speakerBureau[ele].feeRequired = 0;
    }

    char makeUpdate{'y'};
    int speakerToUpdate,
        valueToUpdate;

    while( tolower(makeUpdate == 'y') )
    {
         std::cout << "What speaker would you like to update? (1-14) : ";
            std::cin >> speakerToUpdate;
            std::cout << " " << "\n";
        
        std::cout << "For speaker, " << speakerToUpdate << ", here are the details." << "\n";
            std::cout << "Name : " << speakerBureau[speakerToUpdate-1].name << "\n";
            std::cout << "telephoneNumber : " << speakerBureau[speakerToUpdate-1].telephoneNumber << "\n";
            std::cout << "speakingTopic : " << speakerBureau[speakerToUpdate-1].speakingTopic << "\n";
            std::cout << "feeRequired : " << speakerBureau[speakerToUpdate-1].feeRequired << "\n";
            std::cout << " " << "\n";
        
        std::cout << "For speaker, " << speakerToUpdate << ", what would you like to update?" << "\n";
            std::cout << "1) SpeakerDataName " << "\n";
            std::cout << "2) telephoneNumber " << "\n";
            std::cout << "3) speakingTopic " << "\n";
            std::cout << "4) feeRequired " << "\n";
                std::cin >> valueToUpdate;
            std::cout << " " << "\n";

        switch (valueToUpdate-1)
        {
            case name_SpeakerData:
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Input an updated name : ";
                    std::getline(std::cin,speakerBureau[speakerToUpdate-1].name);
                break;
                
            case telephoneNumber_SpeakerData:
                std::cout << "Input the new telephoneNumber value : ";
                    std::cin >> speakerBureau[speakerToUpdate-1].telephoneNumber; 
                break;

            case speakingTopic:
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Input the new speakingTopic value : ";
                    std::getline(std::cin,speakerBureau[speakerToUpdate-1].speakingTopic);
                break;

            case feeRequired:
                std::cout << "Input the new feeRequired value : ";
                    inputValidation_postiveInteger(speakerBureau[speakerToUpdate-1].feeRequired);
                break;
            
            default:
                break;
        }

        std::cout << " " << "\n";
        std::cout << "Would you like to make an update to a speaker? (input 'y') : ";
            std::cin >> makeUpdate;
            std::cout << " " << "\n";
    }
}

void displaySpeakerData(Speaker speakerBureau[])
{
    std::cout << "----displaySpeakerData----" << "\n"; std::cout << " " << "\n";

    for(unsigned int ele{0}; ele<14; ++ele)
    {
        std::cout << "For speaker, " << ele+1 << ", here are the details." << "\n";

            std::cout << "Name : " << speakerBureau[ele].name << "\n";
            std::cout << "telephoneNumber : " << speakerBureau[ele].telephoneNumber << "\n";
            std::cout << "speakingTopic : " << speakerBureau[ele].speakingTopic << "\n";
            std::cout << "feeRequired : " << speakerBureau[ele].feeRequired << "\n";

        std::cout << " " << "\n";
    }
}

    void getMonthlyBudget( MonthlyBudget &monthlyBudget )
    {
        std::cout << "----getMonthlyBudget----" << "\n"; std::cout << " " << "\n";

        std::cout << "User, during a month, what is the budget for housing? : ";
            inputValidation_postiveInteger(monthlyBudget.housing);
        std::cout << " " << "\n";

        std::cout << "User, during a month, what is the budget for utilities? : ";
            inputValidation_postiveInteger(monthlyBudget.utilities);
        std::cout << " " << "\n";

        std::cout << "User, during a month, what is the budget for householdExpenses? : ";
            inputValidation_postiveInteger(monthlyBudget.householdExpenses);
        std::cout << " " << "\n";

        std::cout << "User, during a month, what is the budget for transportation? : ";
            inputValidation_postiveInteger(monthlyBudget.transportation);
        std::cout << " " << "\n";

        std::cout << "User, during a month, what is the budget for food? : ";
            inputValidation_postiveInteger(monthlyBudget.food);
        std::cout << " " << "\n";

        std::cout << "User, during a month, what is the budget for medical? : ";
            inputValidation_postiveInteger(monthlyBudget.medical);
        std::cout << " " << "\n";

        std::cout << "User, during a month, what is the budget for insurance? : ";
            inputValidation_postiveInteger(monthlyBudget.insurance);
        std::cout << " " << "\n";

        std::cout << "User, during a month, what is the budget for entertainment? : ";
            inputValidation_postiveInteger(monthlyBudget.entertainment);
        std::cout << " " << "\n";

        std::cout << "User, during a month, what is the budget for clothing? : ";
            inputValidation_postiveInteger(monthlyBudget.clothing);
        std::cout << " " << "\n";

        std::cout << "User, during a month, what is the budget for miscellaneous? : ";
            inputValidation_postiveInteger(monthlyBudget.miscellaneous);
        std::cout << " " << "\n";

        std::cout << " " << "\n";
    }

    void getMonthlyExpenses( MonthlyExpenses &monthlyExpenses )
    {
        std::cout << "----getMonthlyExpenses----" << "\n"; std::cout << " " << "\n";

        std::cout << "User, during the month, how much did you spend on housing? : ";
            inputValidation_postiveInteger(monthlyExpenses.housing);
        std::cout << " " << "\n";

        std::cout << "User, during the month, how much did you spend on utilities? : ";
            inputValidation_postiveInteger(monthlyExpenses.utilities);
        std::cout << " " << "\n";

        std::cout << "User, during the month, how much did you spend on householdExpenses? : ";
            inputValidation_postiveInteger(monthlyExpenses.householdExpenses);
        std::cout << " " << "\n";

        std::cout << "User, during the month, how much did you spend on transportation? : ";
            inputValidation_postiveInteger(monthlyExpenses.transportation);
        std::cout << " " << "\n";

        std::cout << "User, during the month, how much did you spend on food? : ";
            inputValidation_postiveInteger(monthlyExpenses.food);
        std::cout << " " << "\n";

        std::cout << "User, during the month, how much did you spend on medical? : ";
            inputValidation_postiveInteger(monthlyExpenses.medical);
        std::cout << " " << "\n";

        std::cout << "User, during the month, how much did you spend on insurance? : ";
            inputValidation_postiveInteger(monthlyExpenses.insurance);
        std::cout << " " << "\n";

        std::cout << "User, during the month, how much did you spend on entertainment? : ";
            inputValidation_postiveInteger(monthlyExpenses.entertainment);
        std::cout << " " << "\n";

        std::cout << "User, during the month, how much did you spend on clothing? : ";
            inputValidation_postiveInteger(monthlyExpenses.clothing);
        std::cout << " " << "\n";

        std::cout << "User, during the month, how much did you spend on miscellaneous? : ";
            inputValidation_postiveInteger(monthlyExpenses.miscellaneous);
        std::cout << " " << "\n";

        std::cout << " " << "\n";
    }

void displayMonthlyReport( const MonthlyBudget &monthlyBudget, const MonthlyExpenses &monthlyExpenses )
{
    std::cout << "----displayMonthlyReport----" << "\n"; std::cout << " " << "\n";

    int totalMonthlyExpenses{0},
        totalMonthlyBudget{0};
    
    totalMonthlyBudget =  monthlyBudget.housing 
                        + monthlyBudget.utilities
                        + monthlyBudget.householdExpenses
                        + monthlyBudget.transportation
                        + monthlyBudget.food
                        + monthlyBudget.medical
                        + monthlyBudget.insurance
                        + monthlyBudget.entertainment
                        + monthlyBudget.clothing
                        + monthlyBudget.miscellaneous;

    if( monthlyExpenses.housing > monthlyBudget.housing )
    {
        std::cout << "For the month, you OVER spent on housing by " << monthlyExpenses.housing - monthlyBudget.housing << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.housing;
    }

    if( monthlyExpenses.housing < monthlyBudget.housing )
    {
        std::cout << "For the month, you UNDER spent on housing by " << monthlyExpenses.housing - monthlyBudget.housing << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.housing;
    }

    if( monthlyExpenses.utilities > monthlyBudget.utilities )
    {
        std::cout << "For the month, you OVER spent on utilities by " << monthlyExpenses.utilities - monthlyBudget.utilities << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.utilities;
    }

    if( monthlyExpenses.utilities < monthlyBudget.utilities )
    {
        std::cout << "For the month, you UNDER spent on utilities by " << monthlyExpenses.utilities - monthlyBudget.utilities << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.utilities;
    }

    if( monthlyExpenses.householdExpenses > monthlyBudget.householdExpenses )
    {
        std::cout << "For the month, you OVER spent on householdExpenses by " << monthlyExpenses.householdExpenses - monthlyBudget.householdExpenses << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.householdExpenses;
    }

    if( monthlyExpenses.householdExpenses < monthlyBudget.householdExpenses )
    {
        std::cout << "For the month, you UNDER spent on householdExpenses by " << monthlyExpenses.householdExpenses - monthlyBudget.householdExpenses << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.householdExpenses;
    }

    if( monthlyExpenses.transportation > monthlyBudget.transportation )
    {
        std::cout << "For the month, you OVER spent on transportation by " << monthlyExpenses.transportation - monthlyBudget.transportation << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.transportation;
    }

    if( monthlyExpenses.transportation < monthlyBudget.transportation )
    {
        std::cout << "For the month, you UNDER spent on transportation by " << monthlyExpenses.transportation - monthlyBudget.transportation << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.transportation;
    }

    if( monthlyExpenses.food > monthlyBudget.food )
    {
        std::cout << "For the month, you OVER spent on food by " << monthlyExpenses.food - monthlyBudget.food << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.food;
    }

    if( monthlyExpenses.food < monthlyBudget.food )
    {
        std::cout << "For the month, you UNDER spent on food by " << monthlyExpenses.food - monthlyBudget.food << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.food;
    }

    if( monthlyExpenses.medical > monthlyBudget.medical )
    {
        std::cout << "For the month, you OVER spent on medical by " << monthlyExpenses.medical - monthlyBudget.medical << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.medical;
    }

    if( monthlyExpenses.medical < monthlyBudget.medical )
    {
        std::cout << "For the month, you UNDER spent on medical by " << monthlyExpenses.medical - monthlyBudget.medical << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.medical;
    }

    if( monthlyExpenses.insurance > monthlyBudget.insurance )
    {
        std::cout << "For the month, you OVER spent on medical by " << monthlyExpenses.insurance - monthlyBudget.insurance << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.insurance;
    }

    if( monthlyExpenses.insurance < monthlyBudget.insurance )
    {
        std::cout << "For the month, you UNDER spent on insurance by " << monthlyExpenses.insurance - monthlyBudget.insurance << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.insurance;
    }

    if( monthlyExpenses.entertainment > monthlyBudget.entertainment )
    {
        std::cout << "For the month, you OVER spent on entertainment by " << monthlyExpenses.entertainment - monthlyBudget.entertainment << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.entertainment;
    }

    if( monthlyExpenses.entertainment < monthlyBudget.entertainment )
    {
        std::cout << "For the month, you UNDER spent on entertainment by " << monthlyExpenses.entertainment - monthlyBudget.entertainment << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.entertainment;
    }

    if( monthlyExpenses.clothing > monthlyBudget.clothing )
    {
        std::cout << "For the month, you OVER spent on clothing by " << monthlyExpenses.clothing - monthlyBudget.clothing << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.clothing;
    }

    if( monthlyExpenses.clothing < monthlyBudget.clothing )
    {
        std::cout << "For the month, you UNDER spent on clothing by " << monthlyExpenses.clothing - monthlyBudget.clothing << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.clothing;
    }

    if( monthlyExpenses.miscellaneous > monthlyBudget.miscellaneous )
    {
        std::cout << "For the month, you OVER spent on miscellaneous by " << monthlyExpenses.miscellaneous - monthlyBudget.miscellaneous << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.miscellaneous;
    }

    if( monthlyExpenses.miscellaneous < monthlyBudget.miscellaneous )
    {
        std::cout << "For the month, you UNDER spent on miscellaneous by " << monthlyExpenses.miscellaneous - monthlyBudget.miscellaneous << " dollars." << "\n";
        totalMonthlyExpenses += monthlyExpenses.miscellaneous;
    }

    std::cout << " " << "\n";
    std::cout << "User, you spent " << totalMonthlyExpenses << " this month." << "\n";

    if( totalMonthlyExpenses > totalMonthlyBudget )
    {
        std::cout << "For the month, you OVER spent by " << totalMonthlyExpenses - totalMonthlyBudget << " dollars." << "\n";
    }

    if( totalMonthlyExpenses < totalMonthlyBudget )
    {
        std::cout << "For the month, you UNDER spent by " << totalMonthlyExpenses - totalMonthlyBudget << " dollars." << "\n";
    }
    
    std::cout << " " << "\n";
}

void getStudentData( StudentData *groupOfStudents, const int * const sizeOfClass, const int * const numberOfTest )
{
    std::cout << "----getStudentData----" << "\n"; std::cout << " " << "\n";

    int totalTestScore{0};

    const int RANGE{100};

    for(int ele{0}; ele<*sizeOfClass; ++ele)
    {
        totalTestScore = 0;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "For student " << ele+1 << ", input a name." << "\n";
            std::getline( std::cin,groupOfStudents[ele].studentName );

        groupOfStudents[ele].Idnum = rand() % RANGE; // will genereate a random number between 0 and RANGE
            std::cout << "For student " << groupOfStudents[ele].studentName << ", here is their randomly generated Student ID number : " << groupOfStudents[ele].Idnum << "\n";
        
        // make each student's tests member point to a dynamically allocated array that will hold the test scores
            (groupOfStudents + ele)->tests = new int[*numberOfTest];

            for(int index{0}; index<(*numberOfTest); ++index)
            {
                std::cout << "For student " << groupOfStudents[ele].Idnum << ", " << groupOfStudents[ele].studentName << ", input the score for test " << index+1 << " : ";
                    // inputValidation_postiveInteger( groupOfStudents[ele].tests );
                    std::cin >> (*(groupOfStudents + ele)).tests[index];
                    totalTestScore += (*(groupOfStudents + ele)).tests[index];
            }
        
        groupOfStudents[ele].grade = totalTestScore / *numberOfTest;

        std::cout << "For student " << ele+1 << ", " << groupOfStudents[ele].studentName << ", here is their test score avarage : " << totalTestScore / *numberOfTest << "\n";
    }
}

void displayClassData( const StudentData *groupOfStudents, const int * const sizeOfClass )
{
    std::cout << "----displayClassData----" << "\n"; std::cout << " " << "\n";

    for(int ele{0}; ele<(*sizeOfClass); ++ele)
    {
        if( groupOfStudents[ele].grade > A ) // A is an enumator that is set at 91
        {
            std::cout << "Student " << groupOfStudents[ele].Idnum << ", " << groupOfStudents[ele].studentName << ", recived an A for the class." << "\n";
        }

        else if( groupOfStudents[ele].grade > B && groupOfStudents[ele].grade < A  ) 
        {
            std::cout << "Student " << groupOfStudents[ele].Idnum << ", " << groupOfStudents[ele].studentName << ", recived an B for the class." << "\n";
        }

        else if( groupOfStudents[ele].grade > C && groupOfStudents[ele].grade < B )
        {
            std::cout << "Student " << groupOfStudents[ele].Idnum << ", " << groupOfStudents[ele].studentName << ", recived an C for the class." << "\n";
        }

        else if( groupOfStudents[ele].grade > D && groupOfStudents[ele].grade < C )
        {
            std::cout << "Student " << groupOfStudents[ele].Idnum << ", " << groupOfStudents[ele].studentName << ", recived an D for the class." << "\n";
        }

        else
        {
            std::cout << "Student " << groupOfStudents[ele].Idnum << ", " << groupOfStudents[ele].studentName << ", recived an F for the class." << "\n";
        }
        std::cout << " " << "\n";
    }

    std::cout << " " << "\n";
}

void DrinkMachineSimulator(SoftDrinkMachine *soda, const int * const typesOfSoda )
{
    std::cout << "----DrinkMachineSimulator----" << "\n"; std::cout << " " << "\n";
    double earnedCoins{0}; // store the amount of coins the machine earns

    for(int ele{5}; ele<(*typesOfSoda); ++ele)
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "For drink " << ele+1 << ", input a name." << "\n";
            std::getline( std::cin,soda[ele].drinkName );
        
        std::cout << "For drink " << soda[ele].drinkName << ", input a cost : ";
            inputValidation_postiveDouble(soda[ele].drinkCost);
        
        std::cout << "For drink " << soda[ele].drinkName << ", input a quantity : ";
            inputValidation_postiveInteger(soda[ele].drinkQuantity);
        
        std::cout << " " << "\n";
    }
    
    char anotherDrink{'y'};
    std::string drinkChoice;
    double coins{0};

    while( tolower(anotherDrink) == 'y')
    {
        // A list of drinks is displayed on the screen. 
        std::cout << "----Display Drinks----" << "\n"; std::cout << " " << "\n";
        for(int ele{0}; ele<(*typesOfSoda); ++ele)
        {
            std::cout << "For drink " << soda[ele].drinkName << ", here are the details." << "\n";
            
            std::cout << "Cost : " << soda[ele].drinkCost << "\n";
            
            std::cout << "Quantity : " << soda[ele].drinkQuantity << "\n";
            std::cout << " " << "\n";
        }

        std::cout << "Input coins into the machine!" << "\n";
        std::cout << "How much was entered?" << "\n";
            inputValidation_DrinkMachineSimulator(coins);
            std::cout << " " << "\n";

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Input the name of the drink would you like to pick : " << "\n";
            std::getline( std::cin,drinkChoice );
            std::cout << " " << "\n";
        
        bool foundDrink{false};
        
        for(int ele{0}; ele<(*typesOfSoda); ++ele)
        {
            if( drinkChoice == soda[ele].drinkName ) // find the drink the user choose
            {
                foundDrink = true;

                if( soda[ele].drinkQuantity == 0 ) // none left
                {
                    std::cout << "Unfortunately, " << soda[ele].drinkName << ", has sold out." << "\n";
                    std::cout << " " << "\n";
                }

                else // soda[ele].drinkQuantity > 0 
                {
                    if( coins > soda[ele].drinkCost )
                    {
                        std::cout << "User, you choose " << soda[ele].drinkName << ", at a price of " << soda[ele].drinkCost << ", enjoy!" << "\n";
                        soda[ele].drinkQuantity -= 1;
                        coins -= soda[ele].drinkCost;
                        earnedCoins += soda[ele].drinkCost;
                        std::cout << "User, here are your coins back : " << coins << "\n";
                        std::cout << " " << "\n";
                    }

                    else // coins < soda[ele].drinkCost
                    {
                        std::cout << "User, you choose " << soda[ele].drinkName << ", at a price of " << soda[ele].drinkCost << "\n";
                        std::cout << "Since you inserted " << coins << " into the machine, this will not cover the full amount of the drink cost."  << "\n";
                        std::cout << "User, here are your coins back : " << coins << "\n";
                        std::cout << " " << "\n";
                    }
                }
            }
        }

        if(foundDrink == false) 
        {
            std::cout << "Unfortunately, " << drinkChoice << ", was not found." << "\n";
                std::cout << " " << "\n";
        }

        std::cout << "If you would you like to buy another drink, input 'y' : ";
            std::cin >> anotherDrink;

        std::cout << " " << "\n";
    }

    std::cout << "The drink machine has earneded : " << earnedCoins << "\n";

    std::cout << " " << "\n";
}

// AddParts: a function that increases a specific bin’s part count by a specified number.
void addParts(InventoryBins warehouse[], const int &ele)
{
    std::cout << "----addParts----" << "\n"; std::cout << " " << "\n";
    int whichPart,
        addHowMany;

    std::cout << "What part would you like to add to ? : " << "\n";
        std::cout << "1) valve " << "\n";
        std::cout << "2) bearing " << "\n";
        std::cout << "3) bushing " << "\n";
        std::cout << "4) coupling " << "\n";
        std::cout << "5) flange " << "\n";
        std::cout << "6) gear " << "\n";
        std::cout << "7) gearHousing " << "\n";
        std::cout << "8) vacuumGripper " << "\n";
        std::cout << "9) cable " << "\n";
        std::cout << "10) rod " << "\n";
            inputValidation_postiveInteger(whichPart);
             std::cout << " " << "\n";
        
    std::cout << "How many would you like to add? : ";
        inputValidation_postiveInteger(addHowMany);
         std::cout << " " << "\n";

        switch (whichPart-1)
        {
            case valve: // case 0:
                if(warehouse[ele].valve + addHowMany >30)
                {
                    std::cout << "This bin can only hold 30 parts." << "\n";
                    std::cout << "Only " << 30 - warehouse[ele].valve << ", valves can be added." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else // warehouse[ele].valve + addHowMany <30
                {
                    warehouse[ele].valve += addHowMany;
                }
                break;
            
            case bearing:
                if(warehouse[ele].bearing + addHowMany >30)
                {
                    std::cout << "This bin can only hold 30 parts." << "\n";
                    std::cout << "Only " << 30 - warehouse[ele].bearing << ", bearing can be added." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else 
                {
                    warehouse[ele].bearing += addHowMany;
                }
                break;

            case bushing:
                if(warehouse[ele].bushing + addHowMany >30)
                {
                    std::cout << "This bin can only hold 30 parts." << "\n";
                    std::cout << "Only " << 30 - warehouse[ele].bushing << ", bushing can be added." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else 
                {
                    warehouse[ele].bushing += addHowMany;
                }
                break;

            case coupling:
                if(warehouse[ele].coupling + addHowMany >30)
                {
                    std::cout << "This bin can only hold 30 parts." << "\n";
                    std::cout << "Only " << 30 - warehouse[ele].coupling << ", coupling can be added." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else 
                {
                    warehouse[ele].coupling += addHowMany;
                }
                break;

            case flange:
                if(warehouse[ele].flange + addHowMany >30)
                {
                    std::cout << "This bin can only hold 30 parts." << "\n";
                    std::cout << "Only " << 30 - warehouse[ele].flange << ", flanges can be added." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else 
                {
                    warehouse[ele].flange += addHowMany;
                }
                break;

            case gear:
                if(warehouse[ele].gear + addHowMany >30)
                {
                    std::cout << "This bin can only hold 30 parts." << "\n";
                    std::cout << "Only " << 30 - warehouse[ele].gear << ", gears can be added." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else 
                {
                    warehouse[ele].gear += addHowMany;
                }
                break;

            case gearHousing:
                if(warehouse[ele].gearHousing + addHowMany >30)
                {
                    std::cout << "This bin can only hold 30 parts." << "\n";
                    std::cout << "Only " << 30 - warehouse[ele].gearHousing << ", gearHousings can be added." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else 
                {
                    warehouse[ele].gearHousing += addHowMany;
                }
                break;

            case vacuumGripper:
                if(warehouse[ele].vacuumGripper + addHowMany >30)
                {
                    std::cout << "This bin can only hold 30 parts." << "\n";
                    std::cout << "Only " << 30 - warehouse[ele].vacuumGripper << ", vacuumGrippers can be added." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else 
                {
                    warehouse[ele].vacuumGripper += addHowMany;
                }
                break;

            case cable:
                if(warehouse[ele].cable + addHowMany >30)
                {
                    std::cout << "This bin can only hold 30 parts." << "\n";
                    std::cout << "Only " << 30 - warehouse[ele].cable << ", cables can be added." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else 
                {
                    warehouse[ele].cable += addHowMany;
                }
                break;

            case rod:
                if(warehouse[ele].rod + addHowMany >30)
                {
                    std::cout << "This bin can only hold 30 parts." << "\n";
                    std::cout << "Only " << 30 - warehouse[ele].rod << ", rods can be added." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else 
                {
                    warehouse[ele].rod += addHowMany;
                }
                break;

            default:
                break;
        }

    std::cout << " " << "\n";
}

// RemoveParts: a function that decreases a specific bin’s part count by a specified number.
void removeParts(InventoryBins warehouse[], const int &ele)
{
    std::cout << "----removeParts----" << "\n"; std::cout << " " << "\n";
    int whichPart,
        removeHowMany;

    std::cout << "What part would you like to add to ? : " << "\n";
        std::cout << "1) valve " << "\n";
        std::cout << "2) bearing " << "\n";
        std::cout << "3) bushing " << "\n";
        std::cout << "4) coupling " << "\n";
        std::cout << "5) flange " << "\n";
        std::cout << "6) gear " << "\n";
        std::cout << "7) gearHousing " << "\n";
        std::cout << "8) vacuumGripper " << "\n";
        std::cout << "9) cable " << "\n";
        std::cout << "10) rod " << "\n";
            inputValidation_postiveInteger(whichPart);
             std::cout << " " << "\n";
        
    std::cout << "How many would you like to remove? : ";
        inputValidation_postiveInteger(removeHowMany);
         std::cout << " " << "\n";

        switch (whichPart-1)
        {
            case valve:
                if(warehouse[ele].valve - removeHowMany < 0 )
                {
                    std::cout << "This bin can not hold less than 0 parts." << "\n";
                    std::cout << "This bin can only subtract " << warehouse[ele].valve << ", valves." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else // warehouse[ele].valve + removeHowMany < 0
                {
                    warehouse[ele].valve -= removeHowMany;
                }
                break;
            
            case bearing:
                if(warehouse[ele].bearing - removeHowMany < 0 )
                {
                    std::cout << "This bin can not hold less than 0 parts." << "\n";
                    std::cout << "This bin can only subtract " << warehouse[ele].bearing << ", bearings." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else 
                {
                    warehouse[ele].bearing -= removeHowMany;
                }
                break;

            case bushing:
                if(warehouse[ele].bushing - removeHowMany < 0 )
                {
                    std::cout << "This bin can not hold less than 0 parts." << "\n";
                    std::cout << "This bin can only subtract " << warehouse[ele].bushing << ", bushings." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else 
                {
                    warehouse[ele].bushing -= removeHowMany;
                }
                break;

            case coupling:
                if(warehouse[ele].coupling - removeHowMany < 0 )
                {
                    std::cout << "This bin can not hold less than 0 parts." << "\n";
                    std::cout << "This bin can only subtract " << warehouse[ele].coupling << ", couplings." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else 
                {
                    warehouse[ele].coupling -= removeHowMany;
                }
                break;

            case flange:
                if(warehouse[ele].flange - removeHowMany < 0 )
                {
                    std::cout << "This bin can not hold less than 0 parts." << "\n";
                    std::cout << "This bin can only subtract " << warehouse[ele].flange << ", flanges." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else 
                {
                    warehouse[ele].flange -= removeHowMany;
                }
                break;

            case gear:
                if(warehouse[ele].gear - removeHowMany < 0 )
                {
                    std::cout << "This bin can not hold less than 0 parts." << "\n";
                    std::cout << "This bin can only subtract " << warehouse[ele].gear << ", gears." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else 
                {
                    warehouse[ele].gear -= removeHowMany;
                }
                break;

            case gearHousing:
                if(warehouse[ele].gearHousing - removeHowMany < 0 )
                {
                    std::cout << "This bin can not hold less than 0 parts." << "\n";
                    std::cout << "This bin can only subtract " << warehouse[ele].gearHousing << ", gearHousing." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else 
                {
                    warehouse[ele].gearHousing -= removeHowMany;
                }
                break;

            case vacuumGripper:
                if(warehouse[ele].vacuumGripper - removeHowMany < 0 )
                {
                    std::cout << "This bin can not hold less than 0 parts." << "\n";
                    std::cout << "This bin can only subtract " << warehouse[ele].vacuumGripper << ", vacuumGrippers." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else 
                {
                    warehouse[ele].vacuumGripper -= removeHowMany;
                }
                break;

            case cable:
                if(warehouse[ele].cable - removeHowMany < 0 )
                {
                    std::cout << "This bin can not hold less than 0 parts." << "\n";
                    std::cout << "This bin can only subtract " << warehouse[ele].cable << ", cables." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else 
                {
                    warehouse[ele].cable -= removeHowMany;
                }
                break;

            case rod:
                if(warehouse[ele].rod - removeHowMany < 0 )
                {
                    std::cout << "This bin can not hold less than 0 parts." << "\n";
                    std::cout << "This bin can only subtract " << warehouse[ele].rod << ", rods." << "\n";
                    std::cout << "Request denied." << "\n";
                }
                else 
                {
                    warehouse[ele].rod -= removeHowMany;
                }
                break;

            default:
                break;
        }

    std::cout << " " << "\n";
}

void runWarehouseInventory(InventoryBins warehouse[])
{
    std::cout << "----runWarehouseInventory----" << "\n"; std::cout << " " << "\n";

    char addOrRemove{'y'};
    std::string addOrRemoveParts;
    int binNumber;
    bool binFound{false};

    // The program should have an array of 10 bins, initialized with the following data:
    for(unsigned int ele{0}; ele<10; ++ele)
    {
        warehouse[ele].valve = 10;
        warehouse[ele].bearing = 11-ele;
        warehouse[ele].bushing = 12-ele;
        warehouse[ele].coupling = 13-ele;
        warehouse[ele].flange = 14-ele;
        warehouse[ele].gear = 15-ele;
        warehouse[ele].gearHousing = 16-ele;
        warehouse[ele].vacuumGripper = 17-ele;
        warehouse[ele].cable = 18-ele;
        warehouse[ele].rod = 19-ele;
    }

    while(tolower(addOrRemove) == 'y')
    {
        std::cout << "----displayInventoryBins----" << "\n"; std::cout << " " << "\n";

        for(unsigned int ele{0}; ele<10; ++ele)
        {
            std::cout << "For inventory bin " << ele+1 << ", here are the quantities." << "\n";
                std::cout << "valve : " << warehouse[ele].valve << "\n";
                std::cout << "Bearing : " << warehouse[ele].bearing << "\n";
                std::cout << "bushing : " << warehouse[ele].bushing << "\n";
                std::cout << "coupling : " << warehouse[ele].coupling << "\n";
                std::cout << "flange : " << warehouse[ele].flange << "\n";
                std::cout << "gear : " << warehouse[ele].gear << "\n";
                std::cout << "gearHousing : " << warehouse[ele].gearHousing << "\n";
                std::cout << "vacuumGripper : " << warehouse[ele].vacuumGripper << "\n";
                std::cout << "cable : " << warehouse[ele].cable << "\n";
                std::cout << "rod : " << warehouse[ele].rod << "\n";
                    std::cout << " " << "\n";
        }

        binFound = false;

        std::cout << "What bin would you like to add or remove from? (1-10) : "; // 0-9
            inputValidation_postiveInteger(binNumber);
            std::cout << " " << "\n";

        for(unsigned int ele{0}; ele<10; ++ele)
        {
            if( ele == (binNumber-1) )
            {
                binFound = true;
                
                std::cout << "For inventory bin " << ele+1 << ", here are the quantities." << "\n";
                    std::cout << "valve : " << warehouse[ele].valve << "\n";
                    std::cout << "Bearing : " << warehouse[ele].bearing << "\n";
                    std::cout << "bushing : " << warehouse[ele].bushing << "\n";
                    std::cout << "coupling : " << warehouse[ele].coupling << "\n";
                    std::cout << "flange : " << warehouse[ele].flange << "\n";
                    std::cout << "gear : " << warehouse[ele].gear << "\n";
                    std::cout << "gearHousing : " << warehouse[ele].gearHousing << "\n";
                    std::cout << "vacuumGripper : " << warehouse[ele].vacuumGripper << "\n";
                    std::cout << "cable : " << warehouse[ele].cable << "\n";
                    std::cout << "rod : " << warehouse[ele].rod << "\n";
                        std::cout << " " << "\n";
                
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Would you like to add or remove ? : " << "\n";
                    std::getline( std::cin,addOrRemoveParts );
            

                if( addOrRemoveParts == "add" )
                {
                    addParts(warehouse, ele);
                }
                else if( addOrRemoveParts == "remove" )
                {
                    removeParts(warehouse, ele);
                }

                std::cout << " " << "\n";
            }
        }

        if( binFound == false)
        {
            std::cout << "Unfortunately, this warehouse does not have that bin number." << "\n";
                std::cout << " " << "\n";
        }

        std::cout << "Would you like to add or remove another part from a bin? input 'y' : ";
            std::cin >> addOrRemove;
    }
    
    std::cout << " " << "\n";
}

void payroll(HourlyPaid worker, Salaried empolyee, MultipurposePayroll worker_employee)
{
    std::cout << "----payroll----" << "\n"; std::cout << " " << "\n";

    std::string personnel;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "User, are you calculating the pay for an hourly paid worker or a salaried employee. ( hourly or salaried )" << "\n";
            std::getline( std::cin,personnel );
            std::cout << " " << "\n";
    

    if( personnel == "hourly" )
    {
        std::cout << "Input the hours worked : ";
            inputValidation_postiveInteger(worker_employee.hourly.hoursWorked);
        std::cout << " " << "\n";
        
        std::cout << "Input the hourly rate : ";
            inputValidation_postiveInteger(worker_employee.hourly.hourlyRate);
        std::cout << " " << "\n";

        std::cout << "For this payroll period, this worker earned : " << (worker_employee.hourly.hoursWorked * worker_employee.hourly.hourlyRate) << "\n";
        std::cout << " " << "\n";
    }
    else if ( personnel == "salaried" )
    {
        std::cout << " " << "\n";
        std::cout << "Input the salary for this employee : ";
            inputValidation_postiveInteger(worker_employee.salary.salary);
        std::cout << " " << "\n";
        
        std::cout << "Input the bonus : ";
            inputValidation_postiveInteger(worker_employee.salary.bonus);
        std::cout << " " << "\n";

        std::cout << "For this payroll period, this worker earned : " << (worker_employee.salary.salary + worker_employee.salary.bonus) << "\n";
        std::cout << " " << "\n";
    }
    else // personnel != "hourly" and personnel != "salaried"
    {
        std::cout << "User, we do not have this type of personnel on the payroll." << "\n";
        std::cout << " " << "\n";
    }


    std::cout << " " << "\n";
}

// end