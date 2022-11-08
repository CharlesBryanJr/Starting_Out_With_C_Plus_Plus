/*
18. Paint Job Estimator
A painting company has determined that 
for every 110 square feet of wall space, 
one gallon of paint 
and eight hours of labor will be required.

The company charges $25.00 per hour for labor. 

Write a modular program that allows the user to 
enter the number of rooms that are to be painted 
and the price of the paint per gallon. 

It should also ask for the square feet of wall space in each room. 

It should then display the following data:
• The number of gallons of paint required
• The hours of labor required
• The cost of the paint
• The labor charges
• The total cost of the paint job
Input validation: Do not accept a value less than 1 for the number of rooms. 
Input validation: Do not accept a value less than $10.00 for the price of paint. 
Input validation: Do not accept a negative value for square footage of wall space.
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

double inputValidation_wall_space(double &wall_space)
{
    while( !(std::cin >> wall_space) || (wall_space<0) )
    {
        std::cout << "Input validation: Do not accept a negative value for square footage of wall space. : ";
        std::cin.clear();
    }
    return wall_space;
}

double inputValidation_number_of_rooms(double &number_of_rooms)
{
    while( !(std::cin >> number_of_rooms) || (number_of_rooms<1) )
    {
        std::cout << "Input validation: Do not accept a value less than 1 for the number of rooms. : ";
        std::cin.clear();
    }
    return number_of_rooms;
}

double inputValidation_price_of_paint(double &price_of_paint)
{
    while( !(std::cin >> price_of_paint) || (price_of_paint<10.00) )
    {
        std::cout << "Input validation: Do not accept a value less than $10.00 for the price of paint. : ";
        std::cin.clear();
    }
    return price_of_paint;
}

void input_PaintJobEstimator( double &total_wall_space, 
                              double &price_of_paint, 
                              double &labor_charges_perHour)
{
    char letter;
    double wall_space_per_room,
           number_of_rooms;

    std::cout << "---input_PaintJobEstimator---" << "\n"; std::cout << " " << "\n";

    std::cout << "Input the number of rooms that are to be painted : ";
        inputValidation_number_of_rooms(number_of_rooms);
        for(int room{0}; room<number_of_rooms; room++)
        {
            std::cout << "For room " << room+1 << ", input the square feet of wall space : ";
                inputValidation_postiveInteger(wall_space_per_room);
            total_wall_space += wall_space_per_room;
        }

    std::cout << "Input the price of the paint per gallon. : ";
        inputValidation_price_of_paint(price_of_paint);

    std::cout << "Company A is the default painiting company at a rate of $25.00 per hour for labor." << "\n";
        std::cout << "To keep Company A on the job input 'y', to choose a different company input 'n' : ";
            inputValidation_y_or_n(letter);
        if(letter == 'y') 
	    {
            labor_charges_perHour = 25;
        }
        else // letter == 'n'
        {
            std::cout << "Input the price of labor for the new company : ";
                inputValidation_postiveInteger(labor_charges_perHour);
        }
}

void caluclate_PaintJobEstimator( double &total_wall_space, 
                                  double &price_of_paint, 
                                  double &labor_charges_perHour)
{
    std::cout << "---caluclate_PaintJobEstimator---" << "\n"; std::cout << " " << "\n";

    // 110 square feet of wall space == one gallon of paint == and eight hours of labor will be required.
    double number_of_gallons_of_paint = total_wall_space/110;
        std::cout << "The number of gallons of paint required : " << number_of_gallons_of_paint << '\n';

    double hours_of_labor = total_wall_space/8;
        std::cout << "The hours of labor required : " << hours_of_labor <<  "\n";

    double cost_of_paint = number_of_gallons_of_paint*price_of_paint;
        std::cout << "The cost of the paint " << cost_of_paint << "\n";

    double total_cost = cost_of_paint + hours_of_labor*labor_charges_perHour;
        std::cout << "The total cost of the paint job : " << total_cost << "\n";
    
    std::cout << " " << "\n";
}

int main()
{
	char letter;
    double total_wall_space,
           price_of_paint,
           labor_charges_perHour;

	while(letter != 'n')
	{
        input_PaintJobEstimator(total_wall_space, price_of_paint, labor_charges_perHour);
        caluclate_PaintJobEstimator(total_wall_space, price_of_paint, labor_charges_perHour);
        
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}