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
#include <ctime>
#include <cmath>

#include "Chapter13IntroToClasses.h"
#include "Chapter13IntroToClasses.cpp"

//*****************************************************
// Definition of function inputValidation_y_or_n function. 
// This function returns a y or n char.
//*****************************************************

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

//*****************************************************
//	*=== START MAIN FUNCTION ===*

int main()
{
    char letter,
         userChoice;

	while(letter != 'n')
	{
        displayProgramMenu();
            std::cin >> userChoice;

        while(tolower(userChoice) != 'e')
        {
            while (toupper(userChoice) < 'A' || toupper(userChoice) > 'U')
            {
                std::cout << "Please make a choice in the range of A through U: "; std::cout << " " << "\n";
                displayProgramMenu();
                    std::cin >> userChoice;
            }
            
            if(tolower(userChoice) == 'a') 
            {
                // local variables 
                int m{0},
                    d{33},
                    y{1997};

                Date Sunday;
                    Sunday.displayDateFormat1(); std::cout << " " << "\n";
                    Sunday.displayDateFormat2(); std::cout << " " << "\n";
                    Sunday.displayDateFormat3(); std::cout << " " << "\n";
                
                std::cout << " " << "\n";

                Date Monday(m);
                    Monday.displayDateFormat1(); std::cout << " " << "\n";
                    Monday.displayDateFormat2(); std::cout << " " << "\n";
                    Monday.displayDateFormat3(); std::cout << " " << "\n";
                
                std::cout << " " << "\n";
                
                Date Tuesday(m,d);
                    Tuesday.displayDateFormat1(); std::cout << " " << "\n";
                    Tuesday.displayDateFormat2(); std::cout << " " << "\n";
                    Tuesday.displayDateFormat3(); std::cout << " " << "\n";
                
                std::cout << " " << "\n";
                
                Date Wednesday(m,d,y);
                    Wednesday.displayDateFormat1(); std::cout << " " << "\n";
                    Wednesday.displayDateFormat2(); std::cout << " " << "\n";
                    Wednesday.displayDateFormat3(); std::cout << " " << "\n";
                
                m = 18;
                d = 0;
                y = 2022;

                Date Today;
                    Today.updateMonth(m);
                    Today.updateDay(d);
                    Today.updateYear(y);
                    Today.displayDateFormat1(); std::cout << " " << "\n";
                    Today.displayDateFormat2(); std::cout << " " << "\n";
                    Today.displayDateFormat3(); std::cout << " " << "\n";
            }

            if(tolower(userChoice) == 'b')
            {
                // local variables
                std::string n;
                int id;
                std::string dep;
                std::string pos;

                // Susan Meyers 47899 Accounting Vice President
                    n = "Susan Meyers";
                    id = 47899;
                    dep = "Accounting";
                    pos = "Vice President";
                    Employee VicePresident;
                        VicePresident.getEmployeeName();
                        VicePresident.getEmployeeID();
                        VicePresident.getEmployeeDepartment();
                        VicePresident.getEmployeePosition();

                        VicePresident.setEmployeeName(n);
                        VicePresident.setEmployeeID(id);
                        VicePresident.setEmployeeDepartment(dep);
                        VicePresident.setEmployeePosition(pos);

                        VicePresident.getEmployeeName();
                        VicePresident.getEmployeeID();
                        VicePresident.getEmployeeDepartment();
                        VicePresident.getEmployeePosition();

                std::cout << " " << "\n";
                // Mark Jones 39119 IT Programmer
                    n = "Mark Jones";
                    id = 39119;
                    dep = "IT";
                    pos = "Programmer";
                    Employee Programmer(n, id);
                        Programmer.getEmployeeName();
                        Programmer.getEmployeeID();
                        Programmer.getEmployeeDepartment();
                        Programmer.getEmployeePosition();

                std::cout << " " << "\n";
                // Joy Rogers 81774 Manufacturing Engineer
                    n = "Joy Rogers";
                    id = 81774;
                    dep = "Manufacturing";
                    pos = "Engineer";
                    Employee Engineer(n, id, dep, pos);
                        Engineer.getEmployeeName();
                        Engineer.getEmployeeID();
                        Engineer.getEmployeeDepartment();
                        Engineer.getEmployeePosition();
                
                std::cout << " " << "\n";
            }

            if(tolower(userChoice) == 'c')
            {
                // Demonstrate the class in a program that creates a Car object, and then calls the accelerate function five times. 
                // After each call to the accelerate function, get the current speed of the car and display it. 
                // Then, call the brake function five times.
                // After each call to the brake function, get the current speed of the car and display it.

                //local variables
                int yM{2023};
                std::string m{"Tesla Roadster"};
                int s{60}; // 1.9 secs
                int laps{12};
                
                Car TeslaRoadster(yM,m);
                    TeslaRoadster.getCarMake();
                    TeslaRoadster.getCarYearModel();
                    TeslaRoadster.getCarSpeed();

                    for(unsigned int it{0}; it<laps; ++it)
                    {
                        TeslaRoadster.accelerateCar();
                        TeslaRoadster.getCarSpeed();
                    }

                    for(unsigned int it{0}; it<laps; ++it)
                    {
                        TeslaRoadster.brakeCar();
                        TeslaRoadster.getCarSpeed();
                    }
                
                std::cout << " " << "\n";

            }
            if(tolower(userChoice) == 'd')
            {
                // Demonstrate the class by writing a program that creates three instances of it. 
                // One instance should hold your information, and the other two should hold your friends’ or family members’ information.
                std::string n; 
                std::string addr; 
                int a; 
                std::string pN;

                PersonalInformation MichaelJordan;
                    n = "Air Jordan";
                        MichaelJordan.setPersonalInformationName(n);
                    addr = "2700 Point Dr, Highland Park, IL 60035";
                        MichaelJordan.setPersonalInformationAddress(addr);
                    a = 37;
                        MichaelJordan.setPersonalInformationAge(a);
                    pN = "(800) 806-6453";
                        MichaelJordan.setPersonalInformationPhoneNumber(pN);

                        MichaelJordan.getPersonalInformationName();
                        MichaelJordan.getPersonalInformationAddress();
                        MichaelJordan.getPersonalInformationAge();
                        MichaelJordan.getPersonalInformationPhoneNumber();

                PersonalInformation TomBrady;
                    n = "TB12";
                        TomBrady.setPersonalInformationName(n);
                    addr = "333 Far away";
                        TomBrady.setPersonalInformationAddress(addr);
                    a = 45;
                        TomBrady.setPersonalInformationAge(a);
                    pN = "(800) 999-9999";
                        TomBrady.setPersonalInformationPhoneNumber(pN);

                        TomBrady.getPersonalInformationName();
                        TomBrady.getPersonalInformationAddress();
                        TomBrady.getPersonalInformationAge();
                        TomBrady.getPersonalInformationPhoneNumber();

                PersonalInformation TigerWoods;
                    n = "TW";
                        TigerWoods.setPersonalInformationName(n);
                    addr = "111 Far Far away";
                        TigerWoods.setPersonalInformationAddress(addr);
                    a = 41;
                        TigerWoods.setPersonalInformationAge(a);
                    pN = "(800)-888-3333";
                        TigerWoods.setPersonalInformationPhoneNumber(pN);

                        TigerWoods.getPersonalInformationName();
                        TigerWoods.getPersonalInformationAddress();
                        TigerWoods.getPersonalInformationAge();
                        TigerWoods.getPersonalInformationPhoneNumber();

                std::cout << " " << "\n";
            }
            if(towlower(userChoice) == 'f')
            {
                
                // Once you have written the class, write a separate program that creates three RetailItem objects and stores the following data in them.
                std::string d; // A string that holds a brief description of the item.
                int uOH; // An int that holds the number of units currently in inventory.
                double p; // A double that holds the item’s retail price.

                d = "Jacket";
                uOH = -5;
                p = -1;

                RetailItem Item1(d,uOH,p);
                    Item1.getRetailItemDescription();
                    Item1.getRetailItemUnitsOnHand();
                    Item1.getRetailItemPrice();
                    std::cout << " " << "\n";

                d = "Designer Jeans";
                uOH = 40;
                p = 34.95;
                RetailItem Item2(d,uOH,p);
                    Item2.getRetailItemDescription();
                    Item2.getRetailItemUnitsOnHand();
                    Item2.getRetailItemPrice();
                    std::cout << " " << "\n";

                d = "Shirt";
                uOH = 20;
                p = 24.95;
                RetailItem Item3(d,uOH,p);
                    Item3.getRetailItemDescription();
                    Item3.getRetailItemUnitsOnHand();
                    Item3.getRetailItemPrice();
                    std::cout << " " << "\n";
                
                d = "hoodie";
                Item1.setRetailItemDescription(d);
                    Item1.getRetailItemDescription();
                    std::cout << " " << "\n";
                
                uOH = -99;
                Item2.setRetailItemUnitsOnHand(uOH);
                    Item2.getRetailItemUnitsOnHand();
                    std::cout << " " << "\n";
                
                p = -99.99;
                Item3.setRetailItemPrice(p);
                    Item3.getRetailItemPrice();
                
                std::cout << " " << "\n";
            }
            if(towlower(userChoice) == 'g')
            {
                int iN{10101010};
                int q{13};
                double c{19.99};

                Inventory Phones;
                    Phones.getItemNumber();
                    Phones.getQuantity();
                    Phones.getCost();
                    Phones.getTotalCost();
                    std::cout << " " << "\n";
                
                Inventory Books(iN,q,c);
                    Books.getItemNumber();
                    Books.getQuantity();
                    Books.getCost();
                    Books.getTotalCost();
                    std::cout << " " << "\n";
            }
            if(towlower(userChoice) == 'h')
            {
                int ts1{777};
                int ts2{-888};
                int ts3{999};

                TestScores student1;
                    student1.getTestScores1();
                    student1.getTestScores2();
                    student1.getTestScores3();
                    student1.setTestScores1();
                    student1.setTestScores2();
                    student1.setTestScores3();
                    std::cout << " " << "\n";
                
                TestScores student2(ts1,ts2,ts3);
                    student2.getTestScores1();
                    student2.getTestScores2();
                    student2.getTestScores3();
                    student2.averageTestScores();
                    std::cout << " " << "\n";
                            
            }
            if(towlower(userChoice) == 'i')
            {
                // Write a program that demonstrates the Circle class by asking the user for the circle’s
                // radius, creating a Circle object, and then reporting the circle’s area, diameter, and circumference.
                double r{10};

                Circle PizzaPie;
                    PizzaPie.getRadius();
                    PizzaPie.getArea();
                    PizzaPie.getDiameter();
                    PizzaPie.getCircumference();
                    PizzaPie.setRadius(r);
                    PizzaPie.getRadius();
                    PizzaPie.getArea();
                    PizzaPie.getDiameter();
                    PizzaPie.getCircumference();
                    std::cout << " " << "\n";
                
                r = 47;
                Circle Clock(r);
                    Clock.getRadius();
                    Clock.getArea();
                    Clock.getDiameter();
                    Clock.getCircumference();
                    std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 'j')
            {
                // Design a Population class that stores a population, number of births, and number of deaths for a period of time. 
                // Member functions should return the birth rate and death rate. 
                // Implement the class in a program.

                Population NYC;
                    NYC.getPopulation();
                    NYC.getBirthRate();
                    NYC.getDeathRate();
                    std::cout << " " << "\n";
                
                double p = 100000;
                double nob = 8000;
                double nod = 6000;
                
                Population LA(p,nob,nod);
                    LA.getPopulation();
                    LA.getBirthRate();
                    LA.getDeathRate();
                    std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 'k')
            {
                // Starting Out With C++ Chapter 13 Introduction to Classes - 10. Number Array Class
                // Design a class that has an array of floating-point numbers. 

                int index = -1;
                float value = 99999;

                NumberArray PennyStocks;
                    PennyStocks.getArrayValues();
                    PennyStocks.getArrayLowestValue();
                    PennyStocks.getArrayHighestValue();
                    PennyStocks.getArrayAverageValue();
                    PennyStocks.setArrayValue(index,value);
                    PennyStocks.getArrayValues();
                    std::cout << " " << "\n";  

                int sizeOfArray{250};

                NumberArray DollarStore(sizeOfArray);
                    DollarStore.getArrayValues();
                    DollarStore.getArrayLowestValue();
                    DollarStore.getArrayHighestValue();
                    DollarStore.getArrayAverageValue();
                    DollarStore.setArrayValue(index,value);
                    DollarStore.getArrayValues();
                    std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 'l')
            {
                // Starting Out With C++ Chapter 13 Introduction to Classes - 11. Payroll
                // Write a program with an array of seven PayRoll objects. 
                // The program should ask the user for the number of hours each employee has worked and will then display the amount of gross pay each has earned.
                
                int PayRollArraySize{7},
                    HPR,
                    NOHW;
                
                Payroll PayRollArray[PayRollArraySize];
                    for(int index{0}; index<PayRollArraySize; ++index )
                    {
                        std::cout << "User, for object " << index+1 << "\n";
                        std::cout << "Input the hourlyPayRate : ";
                            std::cin >> HPR;
                        std::cout << "Input the numberOfHoursWorked : ";
                            std::cin >> NOHW;
                        PayRollArray[index].setTotalPay(HPR,NOHW);
                        std::cout << " " << "\n";
                    }

                    for(int index{0}; index<PayRollArraySize; ++index )
                    {
                        PayRollArray[index].getPayrollValues();
                        std::cout << " " << "\n";
                    }

                    std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 'm')
            {
                // The program should create an instance of the class and display the side that is initially facing up. 
                // Then, use a loop to toss the coin 20 times. 
                // Each time the coin is tossed, display the side that is facing up. 
                // The program should keep count of the number of times heads is facing up 
                // and the number of times tails is facing up, and display those values after the loop finishes.

                int numberOfTosses{1000},
                    tailsCount{0},
                    headsCount{0};
                
                Coin Quarter;
                    Quarter.getSideUp();

                    for(unsigned int it{0}; it<numberOfTosses; ++it) // 0-999
                    {
                        Quarter.toss();
                        Quarter.getSideUp();
                        std::cout << " " << "\n";

                        if(Quarter.getSideUp() == "heads")
                        {
                            headsCount += 1;
                        }
                        else 
                        {
                            tailsCount += 1;
                        }
                    }
                    
                    std::cout << "For " << numberOfTosses << " tosses of the coin, here are the stats." << "\n";
                    std::cout << "headsCount: " << headsCount << "\n";
                    std::cout << "tailsCount: " << tailsCount << "\n";
                    std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 'n')
            {
                /*
                //*****************************************************
                Starting Out With C++ Chapter 13 Introduction to Classes - 13. Tossing Coins for a Dollar
                For this assignment, you will create a game program using the Coin class from Programming Challenge 12. 
                The program should have three instances of the Coin class: 
                one representing a quarter, one representing a dime, and one representing a nickel.
                When the game begins, your starting balance is $0. 
                During each round of the game, the program will toss the simulated coins. 
                When a coin is tossed, the value of the coin is added to your balance if it lands heads-up. 
                For example, if the quarter lands heads-up, 25 cents is added to your balance. Nothing is added to your balance for coins that land tails-up. 
                The game is over when your balance reaches $1 or more. 
                If your balance is exactly $1, you win the game. 
                You lose if your balance exceeds $1.
                //*****************************************************
                */

               double gameBalance{0};
               const double FINALSCORE{1};
               int countTosses{3};
               std::string tossResult;

               Coin gameQuater;
               Coin gameNickel;
               Coin gameDime;

               while( gameBalance < FINALSCORE )
               {
                    tossResult = gameQuater.getSideUp();

                    if( tossResult == "heads" && gameBalance < FINALSCORE )
                    {
                        gameBalance += 0.25;
                    }

                    std::cout << "gameBalance: " << gameBalance << "\n";

                    gameQuater.toss();
                    countTosses += 1;

                    // ---

                    tossResult = gameDime.getSideUp();

                    if( tossResult == "heads" && gameBalance < FINALSCORE )
                    {
                        gameBalance += 0.10;
                    }
                    
                    std::cout << "gameBalance: " << gameBalance << "\n";

                    gameDime.toss();
                    countTosses += 1;


                    // ---

                    tossResult = gameNickel.getSideUp();

                    if( tossResult == "heads" && gameBalance < FINALSCORE )
                    {
                        gameBalance += 0.05;
                    }

                    std::cout << "gameBalance: " << gameBalance << "\n";
                    
                    gameNickel.toss();
                    countTosses += 1;
               }

               if( gameBalance == FINALSCORE )
               { 
                    std::cout << "You Win!" << "\n";
                    std::cout << "countTosses: " << countTosses << "\n"; 
               }
               else // gameBalance != FINALSCORE
               { 
                    std::cout << "You lose!" << "\n"; 
                    std::cout << "countTosses: " << countTosses << "\n"; 
               }

                std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 'o')
            {
                /*
                Starting Out With C++ Chapter 13 Introduction to Classes - 14. Fishing Game Simulation
                For this assignment, you will write a program that simulates a fishing game. 
                In this game, a six-sided die is rolled to determine what the user has caught. 
                Each possible item is worth a certain number of fishing points. 
                The points will not be displayed until the user has finished fishing, and then a message is displayed congratulating the user depending on the number of fishing points gained.

                Here are some suggestions for the game’s design:
                • Each round of the game is performed as an iteration of a loop that repeats as long as the player wants to fish for more items.
                • At the beginning of each round, the program will ask the user whether he or she wants to continue fishing.
                • The program simulates the rolling of a six-sided die (use the Die class that was demonstrated in this chapter).
                • Each item that can be caught is represented by a number generated from the die. 
                For example, 1 for “a huge fish,” 2 for “an old shoe,” 3 for “a little fish,” and so on.
                • Each item the user catches is worth a different amount of points.
                • The loop keeps a running total of the user’s fishing points.
                • After the loop has finished, the total number of fishing points is displayed, along with a message that varies depending on the number of points earned.
                */

               char continueFishing{'y'};
               int countFishingPoints{0};
               int DieSides{6};
               int a;

               int GrassCarpCount{0}, 
                    PeruvianAnchovetaCount{0}, 
                    SilverCarpCount{0}, 
                    CommonCarpCount{0}, 
                    AlaskaPollockCount{0}, 
                    NileTilapiaCount{0};
               
               Die FishingDie(DieSides);

               std::cout << "User, lets play a game of fishing." << '\n';
               std::cout << "A six-sided die is rolled to determine what the user has caught." << '\n';
               std::cout << "Each possible item is worth a certain number of fishing points." << '\n';
               std::cout << "1) Grass carp: " << '\n';
               std::cout << "2) Peruvian anchoveta : " << '\n';
               std::cout << "3) Silver carp : " << '\n';
               std::cout << "4) Common carp : " << '\n';
               std::cout << "5) Alaska pollock : " << '\n';
               std::cout << "6) NileTilapia : " << '\n';

               while( tolower(continueFishing) == 'y' )
               {
                     std::cout << "Casting line -*-*-*-*-*-*-*-* " << '\n';
                    FishingDie.roll();
                    a = FishingDie.getValue();

                    switch ( a-1 )
                    {
                        case GrassCarp:
                            countFishingPoints += 1;
                            GrassCarpCount += 1;
                            break;
                        case PeruvianAnchoveta:
                            countFishingPoints += 2;
                            PeruvianAnchovetaCount += 1;
                            break;
                        case SilverCarp:
                            countFishingPoints += 3;
                            SilverCarpCount += 1;
                            break;
                        case CommonCarp:
                            countFishingPoints += 4;
                            CommonCarpCount += 1;
                            break;
                        case AlaskaPollock:
                            countFishingPoints += 5;
                            AlaskaPollockCount += 1;
                            break;
                        case NileTilapia:
                            countFishingPoints += 6;
                            NileTilapiaCount += 1;
                            break;
                        default:
                            break;
                    }

                    std::cout << "Input 'y' if you would like to continue to fish? : ";
                        std::cin >> continueFishing;
                    std::cout << " " << "\n"; 
               }

               std::cout << "User, here are your final stats : " << "\n";
               std::cout << "1) Grass carp: " << GrassCarpCount << '\n';
               std::cout << "2) Peruvian anchoveta : " << PeruvianAnchovetaCount << '\n';
               std::cout << "3) Silver carp : " << SilverCarpCount << '\n';
               std::cout << "4) Common carp : " << CommonCarpCount << '\n';
               std::cout << "5) Alaska pollock : " << AlaskaPollockCount << '\n';
               std::cout << "6) NileTilapia : " << NileTilapiaCount << '\n';
               std::cout << " " << "\n";
               std::cout << "countFishingPoints : " << countFishingPoints << "\n";

                std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 'p')
            {
                /*
                //*****************************************************
                Starting Out With C++ Chapter 13 Introduction to Classes - 15. Mortgage Payment                
                Design a class that will determine the monthly payment on a home mortgage. 
                The monthly payment with interest compounded monthly can be calculated as follows:

                Payment = the monthly payment
                Loan = the dollar amount of the loan
                Rate = the annual interest rate
                Years = the number of years of the loan
                The class should have member functions for setting the loan amount, interest rate, and number of years of the loan. 
                It should also have member functions for returning the monthly payment amount and the total amount paid to the bank at the end of the loan period. 
                Implement the class in a complete program.
                Input Validation: Do not accept negative numbers for any of the loan values.
                //*****************************************************
                */

                MortgagePayment House;
                    House.getMonthlyPayment();
                    House.getTotalAmountPaid();
                
                double l{9829};
                double r{0.08};
                double ly{13};

                MortgagePayment LakeHouse(l,r,ly);
                    LakeHouse.getMonthlyPayment();
                    LakeHouse.getTotalAmountPaid();

                    l = 1000;
                    r = 0.01;
                    ly = 10;
                
                    LakeHouse.setLoan(l);
                    LakeHouse.setRate(r);
                    LakeHouse.setLoanYears(ly);
                    LakeHouse.getMonthlyPayment();
                    LakeHouse.getTotalAmountPaid();

                std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 'q')
            {
                /*
                //*****************************************************
                Starting Out With C++ Chapter 13 Introduction to Classes - 16. Freezing and Boiling Points
                The following table lists the freezing and boiling points of several substances.
                Substance Freezing Point Boiling Point
                Ethyl Alcohol −173 172
                Oxygen −362 −306
                Water 32 212

                Design a class that stores a temperature in a temperature member variable and has the appropriate accessor and mutator functions. 
                In addition to appropriate constructors, the class should have the following member functions:

                • isEthylFreezing . This function should return the bool value true if the temperature stored in the temperature field is at or below the freezing point of ethyl alcohol. 
                Otherwise, the function should return false .

                • isEthylBoiling . This function should return the bool value true if the temperature stored in the temperature field is at or above the boiling point of ethyl alcohol.
                Otherwise, the function should return false .

                • isOxygenFreezing . This function should return the bool value true if the temperature stored in the temperature field is at or below the freezing point of oxygen.
                Otherwise, the function should return false .

                • isOxygenBoiling . This function should return the bool value true if the temperature stored in the temperature field is at or above the boiling point of oxygen.
                Otherwise, the function should return false .

                • isWaterFreezing . This function should return the bool value true if the temperature stored in the temperature field is at or below the freezing point of water.
                Otherwise, the function should return false .

                • isWaterBoiling . This function should return the bool value true if the temperature stored in the temperature field is at or above the boiling point of water.
                Otherwise, the function should return false .

                Write a program that demonstrates the class. 
                The program should ask the user to enter a temperature and then display a list of the substances that will freeze at that temperature and those that will boil at that temperature. 
                For example, if the temperature is −20 the class should report that water will freeze and oxygen will boil at that temperature.
                //*****************************************************
                */

               int t{-20}; // local varible to hold the temperature
               char newTemp{'y'};

                PhaseChange testTemp; 

                while( newTemp == 'y' )
                {
                    std::cout << "Input a new temp : ";
                        std::cin >> t;
                        testTemp.setTemperature(t);
                    
                    if( testTemp.isEthylFreezing() )
                    {
                        std::cout << "The temperature of, " << t << ", is at or below the freezing point of ethyl alcohol." << "\n";
                        std::cout << " " << "\n";
                    }

                    if( testTemp.isEthylBoiling() )
                    {
                        std::cout << "The temperature of, " << t << ", is at or above the boiling point of ethyl alcohol." << "\n";
                        std::cout << " " << "\n";
                    }

                    if( testTemp.isOxygenFreezing() )
                    {
                        std::cout << "The temperature of, " << t << ", is at or below the freezing point of Oxygen." << "\n";
                        std::cout << " " << "\n";
                    }

                    if( testTemp.isOxygenBoiling() )
                    {
                        std::cout << "The temperature of, " << t << ", is at or above the boiling point of Oxygen." << "\n";
                        std::cout << " " << "\n";
                    }

                    if( testTemp.isWaterFreezing() )
                    {
                        std::cout << "The temperature of, " << t << ", is at or below the freezing point of Water." << "\n";
                        std::cout << " " << "\n";
                    }

                    if( testTemp.isWaterBoiling() )
                    {
                        std::cout << "The temperature of, " << t << ", is at or above the boiling point of Water." << "\n";
                        std::cout << " " << "\n";
                    }

                    std::cout << " " << "\n";  

                    std::cout << "Input 'y' if you would like to test a new temp : ";
                        std::cin >> newTemp;
                    std::cout << " " << "\n";
                }          
            }
            if(towlower(userChoice) == 'r')
            {
                /*
                //*****************************************************
                Starting Out With C++ Chapter 13 Introduction to Classes - 17. Cash Register
                Design a CashRegister class that can be used with the InventoryItem class discussed in this chapter. 
                The CashRegister class should perform the following:
                1. Ask the user for the item and quantity being purchased.
                2. Get the item’s cost from the InventoryItem object.
                3. Add a 30% profit to the cost to get the item’s unit price.
                4. Multiply the unit price times the quantity being purchased to get the purchase sub-total.
                5. Compute a 6% sales tax on the subtotal to get the purchase total.
                6. Display the purchase subtotal, tax, and total on the screen.
                7. Subtract the quantity being purchased from the onHand variable of the InventoryItem class object.

                Implement both classes in a complete program. 
                Feel free to modify the InventoryItem class in any way necessary.
                Input Validation: Do not accept a negative value for the quantity of items being purchased.
                //*******************
                */

                CashRegister Gucci;

                int CRIN;

                std::cout << "User, what item would you like to purchase? : ";
                    std::cin >> CRIN;

                Gucci.PurchaseItem(CRIN);

                std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 's')
            {
                /*
                //*****************************************************
                Starting Out With C++ Chapter 13 Introduction to Classes - 18. A Game of 21
                For this assignment, you will write a program that lets the user play against the computer in a variation of the popular blackjack card game. 
                In this variation of the game, two six-sided dice are used instead of cards. 
                The dice are rolled, and the player tries to beat the computer’s hidden total without going over 21.

                Here are some suggestions for the game’s design:
                • Each round of the game is performed as an iteration of a loop that repeats as long as the player agrees to roll the dice, and the player’s total does not exceed 21.
                • At the beginning of each round, the program will ask the users whether they want to roll the dice to accumulate points.
                • During each round, the program simulates the rolling of two six-sided dice. 
                It rolls the dice first for the computer, and then it asks the user if he or she wants to roll.
                (Use the Die class that was demonstrated in this chapter to simulate the dice).
                • The loop keeps a running total of both the computer and the user’s points.
                • The computer’s total should remain hidden until the loop has finished.
                • After the loop has finished, the computer’s total is revealed, and the player with the most points without going over 21 wins.
                //*****************************************************
                */

                const int dieSides{6};
                Die PlayerDie(dieSides);
                Die DealerDie(dieSides);

                GameOf21 playBlackJack;

                char hitMe{'y'};

                while( playBlackJack.getPlayerScore() < playBlackJack.getBLACKJACK21() &&
                       playBlackJack.getDealerScore() < playBlackJack.getBLACKJACK21() && 
                       hitMe == 'y' )
                {
                    std::cout << "Player, here is your score : " << playBlackJack.getPlayerScore() << "\n";
                    std::cout << "Player, would you like the dealer to hit you ? 'y' : ";
                        std::cin >> hitMe;
                    
                    if( hitMe == 'y' )
                    {
                        if( playBlackJack.getPlayerScore() < playBlackJack.getBLACKJACK21() )
                        {
                            playBlackJack.PlayerHitMe(PlayerDie);
                        }

                        if( playBlackJack.getDealerScore() < playBlackJack.getBLACKJACK21() )
                        {
                            playBlackJack.DealerHitMe(DealerDie);
                        }
                        
                    }
                    
                }

                std::cout << " " << "\n";  
                if( playBlackJack.getPlayerScore() > playBlackJack.getDealerScore() && playBlackJack.getPlayerScore() <= playBlackJack.getBLACKJACK21() )
                {
                    std::cout << "---GAME OVER---" << "\n"; std::cout << " " << "\n";
                    std::cout << "Player Wins!" << "\n";
                    std::cout << "PlayerScore : " << playBlackJack.getPlayerScore() << "\n";
                    std::cout << "DealerScore : " << playBlackJack.getDealerScore() << "\n";
                }

                else if( playBlackJack.getDealerScore() > playBlackJack.getBLACKJACK21() )
                {
                    std::cout << "---GAME OVER---" << "\n"; std::cout << " " << "\n";
                    std::cout << "Player Wins!" << "\n";
                    std::cout << "PlayerScore : " << playBlackJack.getPlayerScore() << "\n";
                    std::cout << "DealerScore : " << playBlackJack.getDealerScore() << "\n";
                }
                
                else if( playBlackJack.getDealerScore() > playBlackJack.getPlayerScore() && playBlackJack.getDealerScore() <= playBlackJack.getBLACKJACK21() )
                {
                    std::cout << "---GAME OVER---" << "\n"; std::cout << " " << "\n";
                    std::cout << "Dealer Wins!" << "\n";
                    std::cout << "PlayerScore : " << playBlackJack.getPlayerScore() << "\n";
                    std::cout << "DealerScore : " << playBlackJack.getDealerScore() << "\n";
                }

                else if( playBlackJack.getPlayerScore() > playBlackJack.getBLACKJACK21() )
                {
                    std::cout << "---GAME OVER---" << "\n"; std::cout << " " << "\n";
                    std::cout << "Dealer Wins!" << "\n";
                    std::cout << "PlayerScore : " << playBlackJack.getPlayerScore() << "\n";
                    std::cout << "DealerScore : " << playBlackJack.getDealerScore() << "\n";
                }

                else // playBlackJack.getPlayerScore() == playBlackJack.getDealerScore()
                {
                    std::cout << "---GAME OVER---" << "\n"; std::cout << " " << "\n";
                    std::cout << "Tie" << "\n";
                    std::cout << "PlayerScore : " << playBlackJack.getPlayerScore() << "\n";
                    std::cout << "DealerScore : " << playBlackJack.getDealerScore() << "\n";
                }

    
                std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 't')
            {
                /*
                //*****************************************************
                Starting Out With C++ Chapter 13 Introduction to Classes - 19. Trivia Game
                In this programming challenge you will create a simple trivia game for two players. 
                The program will work like this:
                • Starting with player 1, each player gets a turn at answering five trivia questions.
                (There are a total of 10 questions.) 
                When a question is displayed, four possible answers are also displayed. 
                Only one of the answers is correct, and if the player selects the correct answer he or she earns a point.
                • After answers have been selected for all of the questions, the program displays the number of points earned by each player and declares the player with the highest number of points the winner.

                In this program you will design a Question class to hold the data for a trivia question.
                The Question class should have member variables for the following data:
                • A trivia question
                • Possible answer #1
                • Possible answer #2
                • Possible answer #3
                • Possible answer #4
                • The number of the correct answer (1, 2, 3, or 4)

                The Question class should have appropriate constructor(s), accessor, and mutator functions.
                The program should create an array of 10 Question objects, one for each trivia question. 
                Make up your own trivia questions on the subject or subjects of your choice for the objects.
                //*****************************************************
                */

                Test TriviaGame;
                TriviaGame.createTest();
                TriviaGame.takeTest();
                TriviaGame.calculateLetterGrade();
                std::cout << "User, your test score was " << TriviaGame.getTestScore() << ", which corresponds to a/an " << TriviaGame.getLetterGrade() << " letter grade." << "\n";
                std::cout << " " << "\n";              
            }
            if(towlower(userChoice) == 'u')
            {
                /*
                //*****************************************************
                Starting Out With C++ Chapter 13 Introduction to Classes - 20. Patient Fees

                2. You are to write a program that computes a patient’s bill for a hospital stay. 
                The different components of the program are
                The PatientAccount class
                The Surgery class
                The Pharmacy class
                The main program

                – The PatientAccount class will keep a total of the patient’s charges. 
                It will also keep track of the number of days spent in the hospital. 
                The group must decide on the hospital’s daily rate.

                – The Surgery class will have stored within it the charges for at least five types of surgery. 
                It can update the charges variable of the PatientAccount class.

                – The Pharmacy class will have stored within it the price of at least five types of medication. 
                It can update the charges variable of the PatientAccount class.

                – Design a menu that allows the user to enter a type of surgery and a type of medication, and check the patient out of the hospital. 
                When the patient checks out, the total charges should be displayed.
                //*****************************************************
                */
                
                PatientAccount CharlesBryan;

                Surgery LegSurgery;

                // Surgery AnkleSurgery;

                Pharmacy localPharmacy;

                std::cout << " " << "\n";
                std::string tempName;
                char anotherSurgery;
                char moreMedicine;
                int surgeryNumber;
                int medicineNumber;
                int totalSurgeryCost{0};
                int totalMedicineCost{0};
                int totalCost;

                int a = 250;
                CharlesBryan.setDailyRate(a);
                
                int aa = 7;
                CharlesBryan.setLengthOfStay(aa);

                // LegSurgery

                std::string aaa{"LegSurgery 1"};
                LegSurgery.setSurgery1(aaa);
                int aaaa = 1000;
                LegSurgery.setSurgery1cost(aaaa);

                std::string aaaaa = "LegSurgery 2";
                LegSurgery.setSurgery2(aaaaa);
                int aaaaaa = 2000;
                LegSurgery.setSurgery2cost(aaaaaa);

                std::string aaaaaaa = "LegSurgery 3";
                LegSurgery.setSurgery3(aaaaaaa);
                int aaaaaaaa = 3000;
                LegSurgery.setSurgery3cost(aaaaaaaa);

                std::string aaaaaaaaa = "LegSurgery 4";
                LegSurgery.setSurgery4(aaaaaaaaa);
                int aaaaaaaaaa = 4000;
                LegSurgery.setSurgery4cost(aaaaaaaaaa);

                // localPharmacy

                std::string b = "Medication 1";
                localPharmacy.setMedication1(b);
                int bb = 100;
                localPharmacy.setMedication1cost(bb);

                std::string bbb = "Medication 2";
                localPharmacy.setMedication2(bbb);
                int bbbb = 200;
                localPharmacy.setMedication2cost(bbbb);

                std::string bbbbbb = "Medication 3";
                localPharmacy.setMedication3(bbbbbb);
                int bbbbbbb = 300;
                localPharmacy.setMedication3cost(bbbbbbb);

                std::string bbbbbbbb = "Medication 4";
                localPharmacy.setMedication4(bbbbbbbb);
                int bbbbbbbbb = 400;
                localPharmacy.setMedication4cost(bbbbbbbbb);

                std::cout << "---Checking into of the Hospital---" << "\n";
                    std::cout << " " << "\n";

                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Input the name of the Patient : "; 
                    std::getline(std::cin, tempName);
                    CharlesBryan.setPatientAccountName(tempName);
                    std::cout << " " << "\n";
                    
                char checkOut{'n'};
                while( checkOut == 'n' )
                {
                    anotherSurgery = 'n'; // reset anotherSurgery
                    std::cout << "Input 'y' if you need to add another surgery. : ";
                        std::cin >> anotherSurgery;
                        std::cout << " " << "\n";
                    
                    if( anotherSurgery == 'y' )
                    {
                        std::cout << "LegSurgery1: " << LegSurgery.getSurgery1() << "\n";
                        std::cout << "LegSurgery1Cost: " << LegSurgery.getSurgery1cost() << "\n";
                            std::cout << " " << "\n";

                        std::cout << "LegSurgery2: " << LegSurgery.getSurgery2() << "\n";
                        std::cout << "LegSurgery2Cost: " << LegSurgery.getSurgery2cost() << "\n";
                            std::cout << " " << "\n";

                        std::cout << "LegSurgery3: " << LegSurgery.getSurgery3() << "\n";
                        std::cout << "LegSurgery3Cost: " << LegSurgery.getSurgery3cost() << "\n";
                            std::cout << " " << "\n";

                        std::cout << "LegSurgery4: " << LegSurgery.getSurgery4() << "\n";
                        std::cout << "LegSurgery4Cost: " << LegSurgery.getSurgery4cost() << "\n";
                            std::cout << " " << "\n";

                        std::cout << "What surgery do you need? : ";
                            std::cin >> surgeryNumber;
                            std::cout << " " << "\n";

                        while( surgeryNumber < 1 || surgeryNumber > 4 )
                        {
                            std::cout << "Input validation: Surgery choice must be 1, 2, 3, or 4." << "\n";
                            std::cout << "What surgery do you need? : ";
                                std::cin >> surgeryNumber;
                                std::cout << " " << "\n";
                        }

                        if( surgeryNumber == 1 ) // surgery 1
                        {
                            totalSurgeryCost += LegSurgery.getSurgery1cost();
                        }

                        else if( surgeryNumber == 2 ) // surgery 2
                        {
                            totalSurgeryCost += LegSurgery.getSurgery2cost();
                        }

                        else if( surgeryNumber == 3 ) // surgery 3
                        {
                            totalSurgeryCost += LegSurgery.getSurgery3cost();
                        }

                        else if( surgeryNumber == 4 ) // surgery 4
                        {
                            totalSurgeryCost += LegSurgery.getSurgery4cost();
                        }

                    }
                    std::cout << " " << "\n";

                    moreMedicine = 'n'; // reset moreMedicine
                    std::cout << "Input 'y' if you need more medicine. : ";
                        std::cin >> moreMedicine;
                        std::cout << " " << "\n";

                    if( moreMedicine == 'y' )
                    {
                        std::cout << "Medication1: " << localPharmacy.getMedication1() << "\n";
                        std::cout << "Medication1cost: " << localPharmacy.getMedication1cost() << "\n";
                            std::cout << " " << "\n";

                        std::cout << "Medication2: " << localPharmacy.getMedication2() << "\n";
                        std::cout << "Medication2cost: " << localPharmacy.getMedication2cost() << "\n";
                            std::cout << " " << "\n";

                        std::cout << "Medication3: " << localPharmacy.getMedication3() << "\n";
                        std::cout << "Medication3cost: " << localPharmacy.getMedication3cost() << "\n";
                            std::cout << " " << "\n";

                        std::cout << "Medication4: " << localPharmacy.getMedication4() << "\n";
                        std::cout << "Medication4cost: " << localPharmacy.getMedication4cost() << "\n";
                            std::cout << " " << "\n";

                        std::cout << "What medicine do you need? : ";
                            std::cin >> medicineNumber;
                            std::cout << " " << "\n";

                        while( medicineNumber < 1 || medicineNumber > 4 )
                        {
                            std::cout << "Input validation: Medicine choice must be 1, 2, 3, or 4." << "\n";
                            std::cout << "What medicine do you need? : ";
                                std::cin >> medicineNumber;
                                std::cout << " " << "\n";
                        }

                        if( medicineNumber == 1 ) // medicine 1
                        {
                            totalMedicineCost += localPharmacy.getMedication1cost();
                        }

                        else if( medicineNumber == 2 ) // medicine 2
                        {
                            totalMedicineCost += localPharmacy.getMedication2cost();
                        }

                        else if( medicineNumber == 3 ) // medicine 3
                        {
                            totalMedicineCost += localPharmacy.getMedication3cost();
                        }

                        else if( medicineNumber == 4 ) // medicine 4
                        {
                            totalMedicineCost += localPharmacy.getMedication4cost();
                        }

                    }
                        std::cout << " " << "\n";
                    
                    std::cout << CharlesBryan.getPatientAccountName() << ", are you ready to check out? : 'y' : ";
                        std::cin >> checkOut;
                        std::cout << " " << "\n";
                }

                std::cout << "---Congrats on Checking out of the Hospital!---" << "\n";
                std::cout << " " << "\n";

                std::cout  << CharlesBryan.getPatientAccountName() << ", here is a summary of your stay." << "\n";
                std::cout << "DailyRate : " << CharlesBryan.getDailyRate()  << "\n";
                std::cout << "LengthOfStay : " << CharlesBryan.getLengthOfStay() << "\n";
                std::cout << "totalSurgeryCost : " << totalSurgeryCost << "\n";
                std::cout << "totalMedicineCost : " << totalMedicineCost << "\n";
                    std::cout << " " << "\n";

                    totalCost = ( CharlesBryan.getDailyRate() * CharlesBryan.getLengthOfStay() ) + totalSurgeryCost + totalMedicineCost;
                        CharlesBryan.setPatientExpense(totalCost);

                std::cout << "Total Cost : " << CharlesBryan.getPatientExpense() << "\n";
                    std::cout << " " << "\n";   
                   
            }
            if(towlower(userChoice) == 'v')
            {

                std::cout << " " << "\n";              
            }

            std::cout << " " << "\n";
            displayProgramMenu();
                std::cin >> userChoice;
        }
        
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
			inputValidation_y_or_n(letter);	std::cout << " " << "\n";
    }

	return 0;
}

// *=== END MAIN FUNCTION ===* 
//*****************************************************