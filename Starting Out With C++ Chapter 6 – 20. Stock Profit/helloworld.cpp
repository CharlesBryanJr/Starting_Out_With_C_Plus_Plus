/*
20. Stock Profit
The profit from the sale of a stock can be calculated as follows:
Profit  (( NS  SP )  SC )  (( NS  PP )  PC )

where NS is the number of shares, 
SP is the sale price per share, 
SC is the sale commission paid, 
PP is the purchase price per share, 
and PC is the purchase commission paid.

If the calculation yields a positive value, then the sale of the stock resulted in a profit.
If the calculation yields a negative number, then the sale resulted in a loss.

Write a function that accepts as arguments 
the number of shares, 
the purchase price per share, 
the purchase commission paid, 
the sale price per share, 
and the sale commission paid. 

The function should return the profit (or loss) from the sale of stock.
Demonstrate the function in a program that asks the user to enter the necessary data and displays the amount of the profit or loss.
*/
#include <iostream>

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

double inputValidation_postiveInteger(double &ref_number)
{
    while( !(std::cin >> ref_number) || (ref_number<0) )
    {
        std::cout << "Input Validation: Must be a postive integer : ";
        std::cin.clear();
    }
    return ref_number;
}

double stockProfit( double &sale_of_the_stock, 
                    double &number_of_shares, 
                    double &purchase_price_per_share, 
                    double &purchase_commission_paid, 
                    double &sale_price_per_share, 
                    double &sale_commission_paid,
                    double &profit_or_loss )
{
    std::cout << "---stockProfit---" << "\n"; std::cout << " " << "\n";

    std::cout << "Input NS, the number of shares : ";
        inputValidation_postiveInteger(number_of_shares);

    std::cout << "Input SP, the sale price per share : ";
        inputValidation_postiveInteger(sale_price_per_share);

    std::cout << "Input SC, the sale commission paid : ";
        inputValidation_postiveInteger(sale_commission_paid);

    std::cout << "Input PP, the purchase price per share : ";
        inputValidation_postiveInteger(purchase_price_per_share);

    std::cout << "Input PC, the purchase commission paid : ";
        inputValidation_postiveInteger(purchase_commission_paid);
    
    profit_or_loss = ( (number_of_shares * sale_price_per_share) - sale_commission_paid ) 
                    - ( (number_of_shares * purchase_price_per_share) + purchase_commission_paid );

    return profit_or_loss;
}

int main()
{
	char letter;
    std::string result;
    double  sale_of_the_stock,
            number_of_shares, 
            purchase_price_per_share, 
            purchase_commission_paid, 
            sale_price_per_share, 
            sale_commission_paid,
            profit_or_loss;

	 while(letter != 'n')
	{
        profit_or_loss = stockProfit(   sale_of_the_stock,
                                        number_of_shares, 
                                        purchase_price_per_share, 
                                        purchase_commission_paid, 
                                        sale_price_per_share, 
                                        sale_commission_paid,
                                        profit_or_loss );

        result = (profit_or_loss>0) ? "PROFIT" : "LOSS";
        std::cout << result << "\n";
        std::cout << "The profit or loss from the sale of stock is : " << profit_or_loss << "\n";
        
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}