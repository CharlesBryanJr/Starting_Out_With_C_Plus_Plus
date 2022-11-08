/*
Present Value
Suppose you want to deposit a certain amount of money into a savings account and then leave it alone to draw interest for the next 10 years.
At the end of 10 years you would like to have $10,000 in the account. 

How much do you need to deposit today to make that happen? 
You can use the following formula, which is known as the present value formula, to find out:
P = F / (1+r)^n;

The terms in the formula are as follows:
• P is the present value, or the amount that you need to deposit today.
• F is the future value that you want in the account.
• r is the annual interest rate .
• t is the number of years that you plan to let the money sit in the account.

Write a program that has a function named presentValue that performs this calculation. 
The function should accept the future value, annual interest rate, and number of years as arguments. 
It should return the present value, which is the amount that you need to deposit today. 

Demonstrate the function in a program that lets the user experiment with different values for the formula’s terms.
*/

#include <iostream>
#include <cmath>

int presentValue(int F, int air, int yrs){
    std::cout << "--- presentValue() ---" << "\n"; std::cout << " " << "\n";
    std::cout << "P is the present value, or the amount that you need to deposit today." << "\n"; 
    std::cout << "• F is the future value that you want in the account. (In this case, F is $10,000.)" << "\n"; 
    std::cout << "• r is the annual interest rate : " << air << "\n"; 
    std::cout << "• n is the number of years that you plan to let the money sit in the account : " << "\n"; std::cout << " " << "\n";
    std::cout << "the present value, or the amount that you need to deposit today is : " << F / pow(1 + air, yrs) << "\n";
    air *= .01; 
    return F / pow((1 + air), yrs);
}

int main(){
    int F, air, yrs;
    std::cout << "Input the value for F: "; std::cin >> F;
    std::cout << "Input the value for r: "; std::cin >> air;
    std::cout << "Input the value for n: "; std::cin >> yrs;
    presentValue(F,air,yrs); std::cout << " " << "\n";
    return 0;
}
