/*
Markup
Write a program that asks the user to enter an item’s wholesale cost and its markup percentage. 

It should then display the item’s retail price. 

For example: If an item’s wholesale cost is 5.00 and its markup percentage is 100%, then the item’s retail price is 10.00.

If an item’s wholesale cost is 5.00 and its markup percentage is 50%, then the item’s retail price is 7.50.

The program should have a function named calculateRetail that receives the wholesale cost and the markup percentage as arguments and returns the retail price of the item.

Input Validation: Do not accept negative values for either the wholesale cost of the item or the markup percentage.
*/

#include <iostream>
std::string item;

double calculateRetail(double wholesale, double markup){
    double retailprice{0};

    std::cout << "enter the name of the item: "; std::cin >> item;

    while(wholesale<0){
        std::cout << "Input Validation: Do not accept negative values for either the wholesale cost of the item or the markup percentage." << std::endl;
        std::cout << "for " << item << " enter the wholesale cost: "; std::cin >> wholesale;
    }

    while(markup<0){
        std::cout << "Input Validation: Do not accept negative values for either the wholesale cost of the item or the markup percentage." << std::endl;
        std::cout << "for " << item << " enter the markup price: "; std::cin >> markup;
    }

    retailprice = wholesale + (wholesale * markup * 0.01);

    return retailprice;
}

int main(){

    double result{calculateRetail(5,8)};

    std::cout << "The retail price of " << item << " is: " << result << std::endl;
  
    return 0;
}
