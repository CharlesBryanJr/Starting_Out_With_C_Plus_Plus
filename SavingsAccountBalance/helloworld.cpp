/*
Savings Account Balance
Write a program that calculates the balance of a savings account at the end of a period of time. 

It should ask the user for the annual interest rate, the starting balance, and the number of months that have passed since the account was established. 

A loop should then iterate once for every month, performing the following:
A) Ask the user for the amount deposited into the account during the month. 
(Do not accept negative numbers.) 
This amount should be added to the balance.

B) Ask the user for the amount withdrawn from the account during the month. 
(Do not accept negative numbers.) 
This amount should be subtracted from the balance.

C) Calculate the monthly interest. 
The monthly interest rate is the annual interest rate divided by twelve. 
Multiply the monthly interest rate by the balance, and add the result to the balance.

After the last iteration, the program should display the ending balance, the total amount of deposits, the total amount of withdrawals, and the total interest earned.
*/

#include <iostream>

double annual_interest_rate{0}, number_of_months{0}, balance{0}, month_deposit{0}, t_month_deposit{0}, month_withdraw{0}, t_month_withdraw{0}, monthly_interest{0}, t_intrest{0};

int main(){


    std::cout << "\n";
    //It should ask the user for the annual interest rate, the starting balance, and the number of months that have passed since the account was established. 
    std::cout << "Input the annual interest rate: ";
    std::cin >> annual_interest_rate;
    annual_interest_rate = annual_interest_rate/100;

    std::cout << "Input the starting balance: ";
    std::cin >> balance;

    std::cout << "Input the number of months: ";
    std::cin >> number_of_months;


    // A loop should then iterate once for every month, performing the following:
    for(int month{0}; month<number_of_months; ++month){

        // A) Ask the user for the amount deposited into the account during the month. 
        // (Do not accept negative numbers.) 
        // This amount should be added to the balance.
        std::cout << "For month: " << month << " the amount deposited was: ";
        std::cin >> month_deposit; 
        if(month_deposit<0){
            std::cout << "(Do not accept negative numbers.)" << "\n";
            std::cout << "For month: " << month << " the amount deposited was: ";
            std::cin >> month_deposit; 
        }
        t_month_deposit += month_deposit;
        balance = balance + month_deposit;


        //B) Ask the user for the amount withdrawn from the account during the month. 
        //(Do not accept negative numbers.) 
        //This amount should be subtracted from the balance.
        std::cout << "For month: " << month << " the amount withdrawn was: ";
        std::cin >> month_withdraw; 
        if(month_withdraw<0){
            std::cout << "(Do not accept negative numbers.)" << "\n";
            std::cout << "For month: " << month << " the amount withdrawn was: ";
            std::cin >> month_withdraw; 
        }
        t_month_withdraw += month_withdraw;
        balance = balance - month_withdraw;


        // C) Calculate the monthly interest. 
        // The monthly interest rate is the annual interest rate divided by twelve.
        // Multiply the monthly interest rate by the balance, and add the result to the balance.
        monthly_interest = annual_interest_rate/12;
        t_intrest = t_intrest + monthly_interest*balance;
        balance = balance + monthly_interest*balance;
        
        std::cout << "\n";
    }

    std::cout << "Final balance: " << balance << std::endl;
    std::cout << "Total amount of deposits: " << t_month_deposit << std::endl;
    std::cout << "Total amount of withdrawals: " << t_month_withdraw << std::endl;
    std::cout << "Total interest earned: " << t_intrest << std::endl;

    return 0;
}
