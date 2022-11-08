/*
10. Future Value
Suppose you have a certain amount of money in a savings account that earns compound monthly interest, and you want to calculate the amount that you will have after a specific number of months. 

The formula, which is known as the future value formula, is:
F = P x (1 + i)^t

The terms in the formula are as follows:
• F is the future value of the account after the specified time period.
• P is the present value of the account.
• i is the monthly interest rate .
• t is the number of months .

Write a program that prompts the user to enter the account’s present value, monthly
interest rate, and the number of months that the money will be left in the account. The
program should pass these values to a function named futureValue that returns the
future value of the account, after the specified number of months. The program should
display the account’s future value.
*/
#include <iostream>

/********************************************************
 ********************************************************/
double inputValidation_positiveIntegers(double num)
{
    while(!(std::cin >> num) || num < 0)
    {
        std::cout << "Error. An integer above 0 must be entered: ";
        std::cin.clear();
    }
    return num;
}

/********************************************************
 * Definition of inputValidate function:
 * This function checks for either a 'y' or an 'n'
 ********************************************************/
char inputValidation_y_or_n(char letter)
{
    std::cin >> letter;

    while (!(letter == 'y' || letter == 'n'))
    {
        std::cout << "ERROR: a 'y' or an 'n' must be entered: ";
        std::cin.clear();
        std::cin >> letter;
    }
    return letter;
}

/********************************************************
 * Definition of futureValue function:
 * The futureValue function calculates the present
 * value using this formula: 
 * present_value * pow((1 + monthly_interest_rate), number_of_months);
 * accepting the present_value,monthly_interest_rate, 
 * and number_of_months as arguments.
 ********************************************************/
double futureValue(double present_value, double monthly_interest_rate, double number_of_months)
{    
    return present_value * monthly_interest_rate * number_of_months;
}


int main()
{
    double present_value,
           future_value,
           monthly_interest_rate,
           number_of_months;

    char run_program_again;

    while(run_program_again != 'n')
    {
        std::cout << "Enter account's present value  : ";
        present_value = inputValidation_positiveIntegers(present_value);

        std::cout << "Enter monthly interest rate    : ";
        monthly_interest_rate = inputValidation_positiveIntegers(monthly_interest_rate);

        std::cout << "Enter number of months         : ";
        number_of_months = inputValidation_positiveIntegers(number_of_months);

        future_value = futureValue(present_value, monthly_interest_rate, number_of_months);
        std::cout << "Future value is: $" << future_value << std::endl << std::endl;

        std::cout << "Would you like to make another calculation? (y/n): ";
        run_program_again = inputValidation_y_or_n(run_program_again);

        std::cout << std::endl;

    };

    return 0;
}
