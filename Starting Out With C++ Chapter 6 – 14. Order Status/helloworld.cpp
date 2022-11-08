/*
14. Order Status
The Middletown Wholesale Copper Wire Company sells spools of copper wiring for $100 each. 
Write a program that displays the status of an order. 
The program should have a function that asks for the following data:
• The number of spools ordered.
• The number of spools in stock.
• Whether there are special shipping and handling charges.
(Shipping and handling is normally $10 per spool.) 
If there are special charges, the program should ask for the special charges per spool.

The gathered data should be passed as arguments to another function that displays
• The number of spools ready to ship from current stock.
• The number of spools on backorder (if the number ordered is greater than what is in stock).
• Subtotal of the portion ready to ship (the number of spools ready to ship times $100).
• Total shipping and handling charges on the portion ready to ship.
• Total of the order ready to ship.

The shipping and handling parameter in the second function should have the default argument 10.00.

Input Validation: Do not accept numbers less than 1 for spools ordered. 
Input Validation: Do not accept a number less than 0 for spools in stock or shipping and handling charges.
*/
#include <iostream>

char inputValidation_y_or_n(char &ref_letter)
{
    std::cin >> ref_letter;

    while (!(ref_letter == 'y' || ref_letter == 'n'))
    {
        std::cout << "ERROR: a 'y' or an 'n' must be entered: ";
        std::cin.clear();
        std::cin >> ref_letter;
    }
    
    return ref_letter;
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

void order_status( double &spools_ordered, 
                     double &spools_in_stock, 
                     double &Shipping_and_Handling_charges_per_spool,
                     double &special_Shipping_and_Handling_charges_per_spool, 
                     double &special_charges_per_spool )
{           
    std::cout << "Input the number of spools ordered : ";
        inputValidation_postiveInteger(spools_ordered);

    std::cout << "Input the number of spools in stock : ";
        inputValidation_postiveInteger(spools_in_stock);

    std::cout << "Shipping and handling charges are normally $" << Shipping_and_Handling_charges_per_spool << " per spool." << "\n";

    std::cout << "Input special shipping and handling charges : "; 
        inputValidation_postiveInteger(special_Shipping_and_Handling_charges_per_spool);

    std::cout << "Input, special charges per spool : ";
        inputValidation_postiveInteger(special_charges_per_spool);
}

void order_display( double &spools_ordered, 
                    double &spools_in_stock, 
                    double &Shipping_and_Handling_charges_per_spool,
                    double &special_Shipping_and_Handling_charges_per_spool, 
                    double &special_charges_per_spool )
{
    double  backorder_spools_count{0},
            Subtotal_ready_to_ship{0},
            shipping_and_handling_charges_ready_to_ship{0},
            special_charges_per_spool_ready_to_ship{0},
            total_ready_to_ship{0};

    std::cout << "The number of spools ready to ship from current stock : " << spools_in_stock << "\n";

    if(spools_ordered > spools_in_stock)
    {
        backorder_spools_count = spools_ordered - spools_in_stock;
            std::cout << "The number of spools on backorder : " << backorder_spools_count << "\n";
        
        Subtotal_ready_to_ship = 100 * spools_in_stock ;
            std::cout << "Subtotal of the portion ready to ship : " << Subtotal_ready_to_ship <<  "\n";

        shipping_and_handling_charges_ready_to_ship = spools_in_stock * (Shipping_and_Handling_charges_per_spool+special_Shipping_and_Handling_charges_per_spool);
            std::cout << "Total shipping and handling charges on the portion ready to ship : " << shipping_and_handling_charges_ready_to_ship <<  "\n";
    
        special_charges_per_spool_ready_to_ship =  spools_in_stock * special_charges_per_spool;
            std::cout << "Total special charges per spool on the portion ready to ship : " << special_charges_per_spool_ready_to_ship <<  "\n";

        total_ready_to_ship = Subtotal_ready_to_ship + shipping_and_handling_charges_ready_to_ship + special_charges_per_spool_ready_to_ship;
            std::cout << "Total of the order ready to ship : " << total_ready_to_ship <<  "\n";
    }

    else // spools_in_stock > spools_ordered 
    {
        Subtotal_ready_to_ship = 100 * spools_ordered ;
            std::cout << "Subtotal of the portion ready to ship : " << Subtotal_ready_to_ship <<  "\n";

        shipping_and_handling_charges_ready_to_ship = spools_ordered * (Shipping_and_Handling_charges_per_spool+special_Shipping_and_Handling_charges_per_spool);
            std::cout << "Total shipping and handling charges on the portion ready to ship : " << shipping_and_handling_charges_ready_to_ship <<  "\n";
    
        special_charges_per_spool_ready_to_ship =  spools_ordered * special_charges_per_spool;
            std::cout << "Total special charges per spool on the portion ready to ship : " << special_charges_per_spool_ready_to_ship <<  "\n";

        total_ready_to_ship = Subtotal_ready_to_ship + shipping_and_handling_charges_ready_to_ship + special_charges_per_spool_ready_to_ship;
            std::cout << "Total of the order ready to ship : " << total_ready_to_ship <<  "\n";

    }

    std::cout << " " << "\n";
}

int main()
{
	char letter;

    double spools_ordered{0},
           spools_in_stock{0},
           Shipping_and_Handling_charges_per_spool{10},
           special_Shipping_and_Handling_charges_per_spool{0},
           special_charges_per_spool{0};

    std::cout << spools_ordered << "  " <<  &spools_ordered << "\n";
    std::cout << spools_in_stock << "  " << &spools_in_stock << "\n";
    std::cout << Shipping_and_Handling_charges_per_spool << "  " << &Shipping_and_Handling_charges_per_spool << "\n";
    std::cout << special_Shipping_and_Handling_charges_per_spool << "  " << &special_Shipping_and_Handling_charges_per_spool << "\n";
    std::cout << special_charges_per_spool << "  " << &special_charges_per_spool << "\n";

	 while(letter != 'n')
	{
        order_status(spools_ordered, 
                     spools_in_stock, 
                     Shipping_and_Handling_charges_per_spool,
                     special_Shipping_and_Handling_charges_per_spool, 
                     special_charges_per_spool );
        
        std::cout << " " << "\n";
        
        order_display(spools_ordered, 
                     spools_in_stock, 
                     Shipping_and_Handling_charges_per_spool,
                     special_Shipping_and_Handling_charges_per_spool, 
                     special_charges_per_spool );

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		    inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }

    std::cout << "  " << spools_ordered << "  " << &spools_ordered << "\n";
    std::cout << "  " << spools_in_stock << "  " << &spools_in_stock << "\n";
    std::cout << "  " << Shipping_and_Handling_charges_per_spool << "  " << &Shipping_and_Handling_charges_per_spool << "\n";
    std::cout << "  " << Shipping_and_Handling_charges_per_spool << "  " << &special_Shipping_and_Handling_charges_per_spool << "\n";
    std::cout << "  " << special_charges_per_spool << "  " << &special_charges_per_spool << "\n";
	
	return 0;
}