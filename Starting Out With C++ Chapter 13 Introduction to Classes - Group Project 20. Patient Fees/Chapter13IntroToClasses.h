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

#ifndef Chapter13IntroToClasses_H
#define Chapter13IntroToClasses_H

/*
//*****************************************************
Starting Out With C++ Chapter 13 Introduction to Classes - 20. Patient Fees

1. This program should be designed and written by a team of students. Here are some suggestions:
– One or more students may work on a single class.
– The requirements of the program should be analyzed so each student is given about the same workload.
– The parameters and return types of each function and class member function should be decided in advance.
– The program will be best implemented as a multi-file program.

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

class PatientAccount
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        std::string patientAccountName;
        double patientExpense; // total of the patient’s charges. 
        int lengthOfStay; //  the number of days spent in the hospital. 
        int dailyRate; // hospital’s daily rate.

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            PatientAccount(){ patientAccountName = "John Doe"; patientExpense = 0; lengthOfStay = 0; dailyRate = 0; }

            PatientAccount( std::string &pAN, double &pE, int &lofS, int &dR )
            { patientAccountName = pAN; patientExpense = pE; lengthOfStay = lofS; dailyRate = dR; }

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            double getPatientExpense() const { return patientExpense; } 
            int getLengthOfStay() const { return lengthOfStay; }
            int getDailyRate() const { return dailyRate; }
            std::string getPatientAccountName() const { return patientAccountName; }

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void setPatientExpense( const double &pE ){  patientExpense = pE; }
            void setLengthOfStay( const int &lofS ){ lengthOfStay = lofS; }
            void setDailyRate( const int &dR ){ dailyRate = dR; }
            void setPatientAccountName( const std::string &pAN ){ patientAccountName = pAN; }

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~PatientAccount(){}
            
};

class Surgery
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        std::string surgery1;
            int surgery1cost;

        std::string surgery2;
            int surgery2cost;

        std::string surgery3;
            int surgery3cost;

        std::string surgery4;
            int surgery4cost;
        
        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            Surgery()
            {
                surgery1 = " "; surgery1cost = 0;
                surgery2 = " "; surgery2cost = 0;
                surgery3 = " "; surgery3cost = 0;
                surgery4 = " "; surgery4cost = 0;
            }

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            std::string getSurgery1() const { return surgery1; }
            int getSurgery1cost() const { return surgery1cost; }

            std::string getSurgery2() const { return surgery2; }
            int getSurgery2cost() const { return surgery2cost; }

            std::string getSurgery3() const { return surgery3; }
            int getSurgery3cost() const { return surgery3cost; }

            std::string getSurgery4() const { return surgery4; }
            int getSurgery4cost() const { return surgery4cost; }

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void setSurgery1( const std::string &s1 ){ surgery1 = s1; }
            void setSurgery1cost( const int &s1c ){ surgery1cost = s1c; }

            void setSurgery2( const std::string &s2 ){ surgery2 = s2; }
            void setSurgery2cost( const int &s2c ){ surgery2cost = s2c; }

            void setSurgery3( const std::string &s3 ){ surgery3 = s3; }
            void setSurgery3cost( const int &s3c ){ surgery3cost = s3c; }

            void setSurgery4( const std::string &s4 ){ surgery4 = s4; }
            void setSurgery4cost( const int &s4c ){ surgery4cost = s4c; }
            
            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Surgery(){}
            
};

class Pharmacy
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        std::string medication1;
            int medication1cost;

        std::string medication2;
            int medication2cost;

        std::string medication3;
            int medication3cost;

        std::string medication4;
            int medication4cost;
        
        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            Pharmacy()
            {
                medication1 = " "; medication1cost = 0;
                medication2 = " "; medication2cost = 0;
                medication3 = " "; medication3cost = 0;
                medication4 = " "; medication4cost = 0;
            }

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            std::string getMedication1() const { return medication1; }
            int getMedication1cost() const { return medication1cost; }

            std::string getMedication2() const { return medication2; }
            int getMedication2cost() const { return medication2cost; }

            std::string getMedication3() const { return medication3; }
            int getMedication3cost() const { return medication3cost; }

            std::string getMedication4() const { return medication4; }
            int getMedication4cost() const { return medication4cost; }

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void setMedication1( const std::string &m1 ){ medication1 = m1; }
            void setMedication1cost( const int &m1c ){ medication1cost = m1c; }

            void setMedication2( const std::string &m2 ){ medication2 = m2; }
            void setMedication2cost( const int &m2c ){ medication2cost = m2c; }

            void setMedication3( const std::string &m3 ){ medication3 = m3; }
            void setMedication3cost( const int &m3c ){ medication3cost = m3c; }

            void setMedication4( const std::string &m4 ){ medication4 = m4; }
            void setMedication4cost( const int &m4c ){ medication4cost = m4c; }
 
            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Pharmacy(){}
            
};

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

class Question
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        std::string triviaQuestion;
        std::string triviaAnswer1;
        std::string triviaAnswer2;
        std::string triviaAnswer3;
        std::string triviaAnswer4;
        int correctAnswer;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            Question()
            { triviaQuestion = " "; triviaAnswer1 = " "; triviaAnswer2 = " "; triviaAnswer3 = " "; triviaAnswer4 = " "; correctAnswer = 1; }

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            std::string getTriviaQuestion(){ return triviaQuestion; }
            std::string getTriviaAnswer1(){ return triviaAnswer1; }
            std::string getTriviaAnswer2(){ return triviaAnswer2; }
            std::string getTriviaAnswer3(){ return triviaAnswer3; }
            std::string getTriviaAnswer4(){ return triviaAnswer4; }
            int getCorrectAnswer(){ return correctAnswer; }

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void setTriviaQuestion( std::string &tQ ){ triviaQuestion = tQ; }
            void setTriviaAnswer1( std::string &tA1 ){ triviaAnswer1 = tA1; }
            void setTriviaAnswer2( std::string &tA2 ){ triviaAnswer2 = tA2; }
            void setTriviaAnswer3( std::string &tA3 ){ triviaAnswer3 = tA3; }
            void setTriviaAnswer4( std::string &tA4 ){ triviaAnswer4 = tA4; }
            void setCorrectAnswer( int &cA );

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Question(){}
            
};

class Test
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        int numberOfQuestions;
        int testScore;
        char letterGrade;
        Question *ptr_question;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 
        void createQuestionArray()
        {
            std::cout << "***----createQuestionArray----***" << "\n"; std::cout << " " << "\n";
            ptr_question = new Question[numberOfQuestions];
        }

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            Test()
            { numberOfQuestions = 1; letterGrade = 'A'; testScore = 0; }

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            int getNumberOfQuestions(){ return numberOfQuestions; }
            int getTestScore(){ return testScore; }
            char getLetterGrade(){ return letterGrade; }

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void setNumberOfQuestions( int &noq ){ numberOfQuestions = noq; }
            void setLetterGrade( int &lG ){ letterGrade = lG; }
            void createTest();
            void takeTest();
            void calculateLetterGrade();

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Test(){ delete[] ptr_question; ptr_question = nullptr; }
            
};

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

class Die;

class GameOf21
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        int PlayerScore;
        int DealerScore;
        const int BLACKJACK21 = 21;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            GameOf21(){ PlayerScore = 0; DealerScore = 0; }

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            int getPlayerScore(){ return PlayerScore; }
            int getDealerScore(){ return DealerScore; }
            int getBLACKJACK21(){ return BLACKJACK21; }

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void PlayerHitMe(Die &ObjectPlayerDie);
            void DealerHitMe(Die &ObjectDealerDie);

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~GameOf21(){}
            
};

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
//*****************************************************
*/

class CashRegister
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        int CashRegisterItemNumber; // An int that holds the item’s item number.
        int CashRegisterQuantity; // An int for holding the quantity of the items on hand.
        double unitPrice; // double for holding the wholesale per-unit cost of the item
        double CashRegisterTotalCost; // A double for holding the total inventory cost of the item (calculateed as quantity times cost ).
        double profitMargin;
        double purchaseSubTotal;
        double salesTaxRate;
        double salesTax;
        double purchaseTotal;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            CashRegister()
            { 
                CashRegisterItemNumber = 0; 
                CashRegisterQuantity = 0; 
                unitPrice = 0; 
                profitMargin = 0.30; 
                purchaseSubTotal = 0; 
                salesTaxRate = 0.06;
            };

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            
            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void PurchaseItem(int &CRIN);

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~CashRegister(){}
            
};


                /*
                //*****************************************************
                Starting Out With C++ Chapter 13 Introduction to Classes - 16. Freezing and Boiling Points

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
                //*******************
                */

class PhaseChange
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        const int EthylAlcoholFreezingPoint = -173;
        const int EthylAlcoholBoilingPoint = 172;

        const int OxygenFreezingPoint = -362;
        const int OxygenBoilingPoint = -306;

        const int WaterFreezingPoint = 32;
        const int WaterBoilingPoint = 212;

        int temperature;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            PhaseChange(){ temperature = 0; }

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            bool isEthylFreezing();
            bool isEthylBoiling();
            bool isOxygenFreezing();
            bool isOxygenBoiling();
            bool isWaterFreezing();
            bool isWaterBoiling();
            
            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void setTemperature(int &t);

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~PhaseChange(){}
            
};

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

class MortgagePayment
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        double monthlyPayment, // Payment = the monthly payment
                loan, // Loan = the dollar amount of the loan
                rate, // Rate = the annual interest rate
                years; // Years = the number of years of the loan

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            MortgagePayment();

            MortgagePayment(double &l, double &r, double &ly);

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            double getMonthlyPayment();
            double getTotalAmountPaid();

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void setLoan(double &l);
            void setRate(double &r);
            void setLoanYears(double &ly);

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~MortgagePayment(){}
            
};

/*
//*****************************************************
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
//*****************************************************
*/

class Die
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        int sides; // Number of sides
        int value; // The die's value

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            Die(const int &numSides);

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            int getSides(); // Returns the number of sides
            int getValue(); // Returns the die's value

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            int roll(); // Rolls the die

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Die(){}
            
};

/*
//*****************************************************
Starting Out With C++ Chapter 13 Introduction to Classes - 12. Coin Toss Simulator
Write a class named Coin. The Coin class should have the following member variable:
• A string named sideUp. The sideUp member variable will hold either “heads” or
“tails” indicating the side of the coin that is facing up.
The Coin class should have the following member functions:
• A default constructor that randomly determines the side of the coin that is facing up
(“heads” or “tails”) and initializes the sideUp member variable accordingly.
• A void member function named toss that simulates the tossing of the coin. When
the toss member function is called, it randomly determines the side of the coin that
is facing up (“heads” or “tails”) and sets the sideUp member variable accordingly.
• A member function named getSideUp that returns the value of the sideUp member
variable.
Write a program that demonstrates the Coin class. The program should create an
instance of the class and display the side that is initially facing up. Then, use a loop
to toss the coin 20 times. Each time the coin is tossed, display the side that is facing
up. The program should keep count of the number of times heads is facing up and the
number of times tails is facing up, and display those values after the loop finishes.
//*****************************************************
*/

class Coin
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        std::string sideUp; // The sideUp member variable will hold either “heads” or “tails” indicating the side of the coin that is facing up.

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            Coin(); // • A default constructor that randomly determines the side of the coin that is facing up (“heads” or “tails”) and initializes the sideUp member variable accordingly.

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            std::string getSideUp(); // • A member function named getSideUp that returns the value of the sideUp member variable.

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void toss(); // • A void member function named toss that simulates the tossing of the coin.

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Coin(){}
            
};

/*
//*****************************************************
Starting Out With C++ Chapter 13 Introduction to Classes - 11. Payroll
Design a PayRoll class that has data members for an employee’s hourly pay rate, number of hours worked, and total pay for the week. 
Write a program with an array of seven PayRoll objects. 
The program should ask the user for the number of hours each employee has worked and will then display the amount of gross pay each has earned.
Input Validation: Do not accept values greater than 60 for the number of hours worked.
//*****************************************************
*/

class Payroll
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        int hourlyPayRate,
            numberOfHoursWorked,
            totalPay;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            Payroll();

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            void getPayrollValues(); // • Retrieve a number from any element of the array

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void setTotalPay(int &HPR, int &NOHW); 

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Payroll(){}
            
};


/*
//*****************************************************
Starting Out With C++ Chapter 13 Introduction to Classes - 10. Number Array Class
Design a class that has an array of floating-point numbers. 
The constructor should accept an integer argument and dynamically allocate the array to hold that many numbers. 
The destructor should free the memory held by the array. 
In addition, there should be member functions to perform the following operations:
• Store a number in any element of the array
• Retrieve a number from any element of the array
• Return the highest value stored in the array
• Return the lowest value stored in the array
• Return the average of all the numbers stored in the array
Demonstrate the class in a program.
//*****************************************************
*/

class NumberArray
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        int sizeOF_floatArray;
        float *floatArray{nullptr}; // Design a class that has an array of floating-point numbers. 

        int highestValue,
            lowestValue,
            sumValues,
            averageValue;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            NumberArray(); 
            NumberArray(int &sizeOfArray); // The constructor should accept an integer argument and dynamically allocate the array to hold that many numbers. 

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            void getArrayValue(int &index); // • Retrieve a number from any element of the array
            void getArrayValues(); // • Retrieve all the values in the array
            void getArrayHighestValue(); // • Return the highest value stored in the array
            void getArrayLowestValue(); // • Return the lowest value stored in the array
            void getArrayAverageValue(); // • Return the average of all the numbers stored in the array

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void setArrayValue(int &index, float &value); // • Store a number in any element of the array

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~NumberArray()
            { delete[] floatArray; floatArray = nullptr; }
            
};

/*
//*****************************************************
Starting Out With C++ Chapter 13 Introduction to Classes - 9. Population
In a population, the birth rate and death rate are calculated as follows:
Birth Rate = Number of Births ÷ Population
Death Rate = Number of Deaths ÷ Population

For example, in a population of 100,000 that has 8,000 births and 6,000 deaths per
year, the birth rate and death rate are:
Birth Rate = 8,000 ÷ 100,000 = 0.08
Death Rate = 6,000 ÷ 100,000 = 0.06

Design a Population class that stores a population, number of births, and number of deaths for a period of time. 
Member functions should return the birth rate and death rate. 
Implement the class in a program.

Input Validation: Do not accept population figures less than 1, or birth or death numbers less than 0.
//*****************************************************
*/

class Population
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        double population; 
        double numberOfBirths;
        double numberOfDeaths;
        double birthRate;
        double deathRate;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions

            Population();

            Population(double &p, double &nob, double &nod);

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            void getPopulation() const;
            void getBirthRate() const;
            void getDeathRate() const;

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables. 
            void setPopulation(double &p);
            void setNumberOfBirths(double &nob);
            void setNumberOfDeaths(double &nod);

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Population(){}
            
};

/*
//*****************************************************
Starting Out With C++ Chapter 13 Introduction to Classes - 8. Circle Class
• radius: a double
• pi: a double initialized with the value 3.14159

The class should have the following member functions:
• Default Constructor. A default constructor that sets radius to 0.0.
• Constructor. Accepts the radius of the circle as an argument.
• setRadius. A mutator function for the radius variable.
• getRadius. An accessor function for the radius variable.
• getArea. Returns the area of the circle, which is calculated as area = pi * radius * radius
• getDiameter. Returns the diameter of the circle, which is calculated as diameter = radius * 2
• getCircumference. Returns the circumference of the circle, which is calculated as circumference = 2 * pi * radius
//*****************************************************
*/

class Circle
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        double radius; 
        double PI;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions

            Circle() 
            { radius = 0.00; PI = 3.14159; }

            Circle(double &r);

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            void getRadius() const;
            void getArea() const;
            void getDiameter() const;
            void getCircumference() const;

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            void setRadius(double &r);

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Circle(){}
            
};

/*
//*****************************************************
Starting Out With C++ Chapter 13 Introduction to Classes - 7. TestScores Class
Design a TestScores class that has member variables to hold three test scores. 
The class should have a constructor, accessor, and mutator functions for the test score fields and a member function that returns the average of the test scores. 
Demonstrate the class by writing a separate program that creates an instance of the class. 
The program should ask the user to enter three test scores, which are stored in the TestScores object. 
Then the program should display the average of the scores, as reported by the TestScores object.
//*****************************************************
*/

class TestScores
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing

        int testScore1; // An int that holds the score for test 1
        int testScore2; // An int that holds the score for test 2
        int testScore3; // An int that holds the score for test 3
        int averageTestScore;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions

            TestScores() 
            { testScore1 = 0; testScore2 = 0; testScore3 = 0; }

            TestScores(int &ts1, int &ts2, int &ts3);

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            void getTestScores1() const;
            void getTestScores2() const;
            void getTestScores3() const;

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            void setTestScores1();
            void setTestScores2();
            void setTestScores3(); 
            void averageTestScores(); // a member function that returns the average of the test scores.

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~TestScores(){}
            
};

/*
//*****************************************************
Starting Out With C++ Chapter 13 Introduction to Classes - 6. Inventory Class
Design an Inventory class that can hold information and calculate data for items in a retail store’s inventory. 
The class should have the following private member variables:

itemNumber An int that holds the item’s item number.
quantity An int for holding the quantity of the items on hand.
cost A double for holding the wholesale per-unit cost of the item
totalCost A double for holding the total inventory cost of the item (calculated as quantity times cost ).

Default Constructor Sets all the member variables to 0.
Constructor #2 Accepts an item’s number, cost, and quantity as arguments.
The function should copy these values to the appropriate member variables and then call the setTotalCost function.

setItemNumber Accepts an integer argument that is copied to the itemNumber member variable.
setQuantity Accepts an integer argument that is copied to the quantity member variable.
setCost Accepts a double argument that is copied to the cost member variable.
setTotalCost Calculates the total inventory cost for the item ( quantity times cost) and stores the result in totalCost.
getItemNumber Returns the value in itemNumber.
getQuantity Returns the value in quantity.
getCost Returns the value in cost.
getTotalCost Returns the value in totalCost.
Input Validation: Do not accept negative values for item number, quantity, or cost.
//*****************************************************
*/

class Inventory
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing

        int itemNumber; // An int that holds the item’s item number.
        int quantity; // An int for holding the quantity of the items on hand.
        double cost; // double for holding the wholesale per-unit cost of the item
        double totalCost; // A double for holding the total inventory cost of the item (calculated as quantity times cost ).

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 


        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions

            Inventory() 
            { itemNumber = 0; quantity = 0; cost = 0.00; totalCost = 0.00; }

            Inventory(int &iN, int &q, double &c);

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            void getItemNumber() const; // Returns the value in itemNumber.
            int getQuantity() const; // Returns the value in quantity.
            double getCost() const; // Returns the value in cost.
            void getTotalCost() const; // Returns the value in totalCost.

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            void setItemNumber(int &iN); // Accepts an integer argument that is copied to the itemNumber member variable.
            void setQuantity(int &q); // Accepts an integer argument that is copied to the quantity member variable.
            void setCost(double &c); // Accepts a double argument that is copied to the cost member variable.
            void setTotalCost(); // Calculates the total inventory cost for the item ( quantity times cost) and stores the result in totalCost.

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Inventory(){}
            
};

/*
//*****************************************************
Starting Out With C++ Chapter 13 Introduction to Classes - 5. Retail Item Class
Write a class named RetailItem that holds data about an item in a retail store. 

The class should have the following member variables:
• description . A string that holds a brief description of the item.
• unitsOnHand . An int that holds the number of units currently in inventory.
• price . A double that holds the item’s retail price.

Write a constructor that accepts arguments for each member variable, 
appropriate mutator functions that store values in these member variables, 
and accessor functions.
that return the values in these member variables. 
//*****************************************************
*/

class RetailItem
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing

        std::string description; // A string that holds a brief description of the item.
        int unitsOnHand; // An int that holds the number of units currently in inventory.
        double price; // A double that holds the item’s retail price.

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 


        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions

            RetailItem() 
            {   
                description = "";
                unitsOnHand = 0;
                price = 0.00;
            }

            RetailItem(std::string &d, int &uOH, double &p);

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables. 
            void getRetailItemDescription() const;
            void getRetailItemUnitsOnHand() const;
            void getRetailItemPrice() const;

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            void setRetailItemDescription(std::string &d);
            void setRetailItemUnitsOnHand(int &uOH);
            void setRetailItemPrice(double &p);

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~RetailItem(){}
            
};

/*
//*****************************************************
Starting Out With C++ Chapter 13 Introduction to Classes - 4. Personal Information Class

Design a class that holds the following personal data: name, address, age, and phone number. 
Write appropriate accessor and mutator functions.
//*****************************************************
*/

class PersonalInformation
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing

        std::string name; 
        std::string address; 
        int age; 
        std::string phoneNumber;

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 


        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions

            PersonalInformation() 
            {   
                name = "John Doe";
                address = "1 Arrowhead Drive";
                age = 25;
                phoneNumber = "111-111-1111";
            }

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables. 
            void getPersonalInformationName() const;
            void getPersonalInformationAddress() const;
            void getPersonalInformationAge() const;
            void getPersonalInformationPhoneNumber() const;

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            void setPersonalInformationName(std::string &n);
            void setPersonalInformationAddress(std::string &addr);
            void setPersonalInformationAge(int &a);
            void setPersonalInformationPhoneNumber(std::string &pN);

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~PersonalInformation(){}
            
};

/*
//*****************************************************
Starting Out With C++ Chapter 13 Introduction to Classes - 3. Car Class
Write a class named Car that has the following member variables:
• yearModel . An int that holds the car’s year model.
• make . A string that holds the make of the car.
• speed . An int that holds the car’s current speed.

In addition, the class should have the following constructor and other member functions.

• Constructor. The constructor should accept the car’s year model and make as arguments. 
These values should be assigned to the object’s yearModel and make member variables. 
The constructor should also assign 0 to the speed member variables.
• Accessor. Appropriate accessor functions to get the values stored in an object’s yearModel, make, and speed member variables.
• accelerate . The accelerate function should add 5 to the speed member variable each time it is called.
• brake . The brake function should subtract 5 from the speed member variable each time it is called.
//*****************************************************
*/

class Car
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing

        int yearModel; // • yearModel . An int that holds the car’s year model.
        std::string make; // • make . A string that holds the make of the car.
        int speed; // • speed . An int that holds the car’s current speed.

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 


        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            
            Car(int &yM, std::string &m) // • Constructor. The constructor should accept the car’s year model and make as arguments. 
            {   
                yearModel = yM;
                make = m;
                speed = 0;
            }

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables. 
            void getCarYearModel() const;
            void getCarMake() const;
            void getCarSpeed() const;

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            void accelerateCar();
            void brakeCar();

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Car(){}
            
};

/*
//*****************************************************
Class specification : Employee Class
Write a class named Employee that has the following member variables:
• name. A string that holds the employee’s name.
• idNumber. An int variable that holds the employee’s ID number.
• department. A string that holds the name of the department where the employee works.
• position. A string that holds the employee’s job title.

The class should have the following constructors:
• A constructor that accepts the following values as arguments and assigns them to the appropriate member variables: 
employee’s name, employee’s ID number, department, and position.

• A constructor that accepts the following values as arguments and assigns them to the appropriate member variables: employee’s name and ID number. 
The department and position fields should be assigned an empty string ( "" ).

• A default constructor that assigns empty strings ( "") to the name, department, and position member variables, and 0 to the idNumber member variable.
//*****************************************************
*/

class Employee
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing

        std::string name; // • name. A string that holds the employee’s name.
        int idNumber; // • idNumber. An int variable that holds the employee’s ID number.
        std::string department; // • department. A string that holds the name of the department where the employee works.
        std::string position; // • position. A string that holds the employee’s job title.

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 


        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions

            // • A default constructor that assigns empty strings ( "") to the name, department, and position member variables, and 0 to the idNumber member variable.
            Employee()
            { name = ""; idNumber = 0; department = ""; position = ""; }

            // • A constructor that accepts the following values as arguments and assigns them to the appropriate member variables: employee’s name and ID number. 
            // The department and position fields should be assigned an empty string ( "" ).
            Employee(std::string &n, int &id)
            { name = n; idNumber = id; department = ""; position = ""; }

            // • A constructor that accepts the following values as arguments and assigns them to the appropriate member variables: 
            // employee’s name, employee’s ID number, department, and position.
            Employee(std::string &n, int &id, std::string &dep, std::string &pos)
            { name = n; idNumber = id; department = dep; position = pos; }

            // ***--- accessor or getter ---***
            // Write appropriate accessor functions that return the values in these member variables. 
            void getEmployeeName() const;
            void getEmployeeID() const;
            void getEmployeeDepartment() const;
            void getEmployeePosition() const;

            // ***--- mutator or setter  ---***
            // Write appropriate mutator functions that store values in these member variables 
            void setEmployeeName(std::string &n);
            void setEmployeeID(int &id);
            void setEmployeeDepartment(std::string &dep);
            void setEmployeePosition(std::string &pos);
            
            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~Employee(){}
            
};

/*
//*****************************************************
Class specification : Date
The Date class stores a date in three integers: month, day, and year.
The Date class can print the date in three forms:
12/25/2014
December 25, 2014
25 December 2014
Input Validation: Do not accept values for the day greater than 31 or less than 1. 
Input Validation: Do not accept values for the month greater than 12 or less than 1.
//*****************************************************
*/

class Date
{
    private:

        // attributes or member variables 
        // What private data is the class responsible of storing
        int month;
        int day;
        int year;

        // methods or member functions 
        // What private actions is the class responsible of executing 

        void setMonthDayYear(int &month, int &day, int &year);

        void setMonthDayYear(int &month, int &day, int &year, int &m);

        void setMonthDayYear(int &month, int &day, int &year, int &m, int &d);

        void setMonthDayYear(int &month, int &day, int &year, int &m, int &d, int &y);

    public:
        
        // attributes or member variables 
        // What public data is the class responsible of storing 


        // methods or member functions 
        // What public actions is the class responsible of executing 

            // costructors
            // Useful for initializing private member variables or executing private member functions
            Date();
    
            Date(int &m);

            Date(int &m, int &d);

            Date(int &m, int &d, int &y);
    
            // --- accessor or getter ---

            void getDateFormat1(const int &month, const int &day, const int &year) const; // retrieves the data in this format 12/25/2014

                void displayDateFormat1() 
                {  getDateFormat1(month, day, year); }
            
            void getDateFormat2(const int &month, const int &day, const int &year) const; // retrieves the data in this format December 25, 2014
                
                void displayDateFormat2()
                {  getDateFormat2(month, day, year); }

            void getDateFormat3(const int &month, const int &day, const int &year) const; // retrieves the data in this format 25 December 2014

                void displayDateFormat3()
                {  getDateFormat3(month, day, year); }
            
            // --- mutator or setter  ---
            
            void setMonth(int &month, int &m); // updates the month member variable 

                void updateMonth(int &m)
                { setMonth(month, m); }
            
            void setDay(int &day, int &d); // updates the day member variable 

                void updateDay(int &d)
                { setDay(day, d); }
            
            void setYear(int &year, int &y); // updates the year member variable 

                void updateYear(int &y)
                { setYear(year, y); }
            
            // --- destructors ---
            // Useful to free memory that was dynamically allocated by the class object
            ~Date(){};
            
            
};

#endif