/*
Group Project
25. Travel Expenses
This program should be designed and written by a team of students. 
Here are some suggestions:

• One student should design function main, which will call the other functions in the program. 

The remainder of the functions will be designed by other members of the team.

• The requirements of the program should be analyzed so each student is given about the same workload.

• The parameters and return types of each function should be decided in advance.
• Stubs and drivers should be used to test and debug the program.
• The program can be implemented as a multifile program, or all the functions can be cut and pasted into the main file.
Here is the assignment: Write a program that calculates and displays the total travel expenses of a businessperson on a trip. 

The program should have functions that ask for and return the following:
• The total number of days spent on the trip
• The time of departure on the first day of the trip, and the time of arrival back home on the last day of the trip
• The amount of any round-trip airfare
• The amount of any car rentals
• Miles driven, if a private vehicle was used. Calculate the vehicle expense as $0.27 per mile driven
• Parking fees (The company allows up to $6 per day. Anything in excess of this must be paid by the employee.)
• Taxi fees, if a taxi was used anytime during the trip (The company allows up to $10 per day, for each day a taxi was used. Anything in excess of this must be paid by the employee.)
• Conference or seminar registration fees
• Hotel expenses (The company allows up to $90 per night for lodging. 
Anything in excess of this must be paid by the employee.)
• The amount of each meal eaten. 

On the first day of the trip, 
breakfast is allowed as an expense if the time of departure is before 7 a.m. 
Lunch is allowed if the timeof departure is before 12 noon. 
Dinner is allowed on the first day if the time of departure is before 6 p.m. 

On the last day of the trip, 
breakfast is allowed if the time of arrival is after 8 a.m. 
Lunch is allowed if the time of arrival is after 1 p.m.
Dinner is allowed on the last day if the time of arrival is after 7 p.m. 

The program should only ask for the amounts of allowable meals. 
(The company allows up to $9 for breakfast, $12 for lunch, and $16 for dinner. 
Anything in excess of this must be paid by the employee.)

The program should calculate and display 
the total expenses incurred by the businessperson, 
the total allowable expenses for the trip, 
the excess that must be reimbursed by the businessperson, if any, 
and the amount saved by the businessperson if the expenses were under the total allowed.

Input Validation: Do not accept negative numbers for any dollar amount or for miles driven in a private vehicle. 
Input Validation: Do not accept numbers less than 1 for the number of days.
Input Validation: Only accept valid times for the time of departure and the time of arrival.
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

// Input Validation: Do not accept negative numbers for any dollar amount or for miles driven in a private vehicle. 
double inputValidation_postiveInteger(double &postiveInteger)
{
    while( !(std::cin >> postiveInteger) || (postiveInteger<0) )
    {
        std::cout << "Input Validation: Must be a postive integer : ";
        std::cin.clear();
    }
    return postiveInteger;
}

// Input Validation: Do not accept numbers less than 1 for the number of days.
double inputValidation_number_of_days(double &number_of_days)
{
    while( !(std::cin >> number_of_days) || (number_of_days<1) )
    {
        std::cout << "Input Validation: Must be a postive integer : ";
        std::cin.clear();
    }
    return number_of_days;
}

// Input Validation: Only accept valid times for the time of departure and the time of arrival.
double inputValidation_valid_times(double &valid_times)
{
    while( !(std::cin >> valid_times) || (valid_times<0) || (valid_times>24) )
    {
        std::cout << "Input Validation: Time is on a 24 hour clock, please input an hour between 0 - 24 : ";
        std::cin.clear();
    }
    return valid_times;
}

double inputValidation_private_vehicle(double &private_vehicle)
{
    while( !(std::cin >> private_vehicle) || (private_vehicle<0) || (private_vehicle>1) )
    {
        std::cout << "Input Validation: must enter 1 or 0 : " << '\n';
        std::cout << "If a private_vehicle used, input '1': ";
        std::cin.clear();
    }
    return private_vehicle;
}

void get_and_store_tripInfo(double &number_of_days, 
                            double &time_of_departure, 
                            double &time_of_arrival,
                            double &airfare_cost,
                            double &car_rental_cost,
                            double &private_vehicle,
                            double &miles_driven,
                            double &parking_fees,
                            double &employee_parking_fees,
                            double &taxi_fees,
                            double &employee_taxi_fees,
                            double &registration_fees,
                            double &hotel_fees,
                            double &total_meal_expenses) 
{
    std::cout << "---get_tripInfo---" << "\n";
    std::cout << " " << "\n";

    std::cout << "• The total number of days spent on the trip : ";
        inputValidation_number_of_days(number_of_days);

    std::cout << "• The time of departure on the first day of the trip." << "\n";
        std::cout << "Time is on a 24 hour clock, please input an hour between 0 - 24 : ";
        inputValidation_valid_times(time_of_departure);
        
    std::cout << "• the time of arrival back home on the last day of the trip." << "\n";
        std::cout << "Time is on a 24 hour clock, please input an hour between 0 - 24 : ";
        inputValidation_valid_times(time_of_arrival);

    std::cout << "• The amount of any round-trip airfare : ";
        inputValidation_postiveInteger(airfare_cost);

    std::cout << "• The amount of any car rentals : ";
        inputValidation_postiveInteger(car_rental_cost);

    std::cout << "If a private_vehicle used, input '1': ";
        inputValidation_private_vehicle(private_vehicle);

    std::cout << "• miles driven, if a private vehicle was used. "; // Calculate the vehicle expense as $0.27 per mile driven
        inputValidation_postiveInteger(miles_driven);

    std::cout << "• Parking fees : "; // (The company allows up to $6 per day. Anything in excess of this must be paid by the employee.)
        inputValidation_postiveInteger(parking_fees); 

    std::cout << "• Taxi fees, if a taxi was used anytime during the trip : "; // (The company allows up to $10 per day, for each day a taxi was used. Anything in excess of this must be paid by the employee.)
        inputValidation_postiveInteger(taxi_fees);
        
    std::cout << "• Conference or seminar registration fees : ";	
        inputValidation_postiveInteger(registration_fees);

    std::cout << "• Hotel expenses : " ; // (The company allows up to $90 per night for lodging.
        inputValidation_postiveInteger(hotel_fees);
}

void time_of_departure_meals(double &time_of_departure, double &total_meal_expenses)
{
    double breakfast,
           lunch,
           dinner;

    if(time_of_departure < 7)
    {
        std::cout << "breakfast is allowed as an expense if the time of departure is before 7 a.m." << "\n";
            std::cout << "breakfast cost : ";
            total_meal_expenses += inputValidation_postiveInteger(breakfast);
    }
    if(time_of_departure < 12)
    {
        std::cout << "Lunch is allowed if the time of departure is before 12 noon." << "\n";
            std::cout << "Lunch cost : ";
            total_meal_expenses += inputValidation_postiveInteger(lunch);

    }
    if(time_of_departure < 18)
    {
        std::cout << "Dinner is allowed on the first day if the time of departure is before 6 p.m." << "\n";
            std::cout << "dinner cost : ";
            total_meal_expenses += inputValidation_postiveInteger(dinner);
    }
}

void time_of_arrival_meals(double &time_of_arrival, double &total_meal_expenses)
{
    double breakfast,
           lunch,
           dinner;

    if(time_of_arrival < 8)
    {
        std::cout << "breakfast is allowed if the time of arrival is after 8 a.m." << "\n";
            std::cout << "breakfast cost : ";
            total_meal_expenses += inputValidation_postiveInteger(breakfast);
    }
    if(time_of_arrival < 13)
    {
        std::cout << "Lunch is allowed if the time of arrival is after 1 p.m." << "\n";
            std::cout << "Lunch cost : ";
            total_meal_expenses += inputValidation_postiveInteger(lunch);
    }
    if(time_of_arrival < 19)
    {
        std::cout << "Dinner is allowed on the last day if the time of arrival is after 7 p.m." << "\n";
            std::cout << "dinner cost : ";
            total_meal_expenses += inputValidation_postiveInteger(dinner);
    }
}

void private_vehicle_cost(double &private_vehicle, double &miles_driven)
{
    if(private_vehicle == 1)
    {
        private_vehicle = miles_driven * 0.27; // Calculate the vehicle expense as $0.27 per mile driven
    } 
}

void cal_parking_fees(double &number_of_days, double &parking_fees, double &employee_parking_fees)
{
    if(parking_fees > (6*number_of_days) ) // (The company allows up to $6 per day. Anything in excess of this must be paid by the employee.)
    {
        employee_parking_fees = parking_fees - (6*number_of_days);
        if(employee_parking_fees < 0 )
        {
            employee_parking_fees = 0;
        }
    }
}

void cal_taxi_fees(double &number_of_days, double &taxi_fees, double &employee_taxi_fees)
{
    if(taxi_fees > (10*number_of_days) ) // (The company allows up to $10 per day, for each day a taxi was used. Anything in excess of this must be paid by the employee.)
    {
        employee_taxi_fees = taxi_fees - (10*number_of_days);
        if(employee_taxi_fees < 0 )
        {
            employee_taxi_fees = 0;
        }
    }
}

void cal_hotel_fees(double &number_of_days, double &hotel_fees, double &employee_hotel_fees)
{
    if(hotel_fees > (90*number_of_days) ) // (The company allows up to $90 per night for lodging.
    {
        employee_hotel_fees = hotel_fees - (90*number_of_days);
        if(employee_hotel_fees < 0 )
        {
            employee_hotel_fees = 0;
        }
    }
}

double calculate_and_display_trip_expenses( double &number_of_days, 
                                            double &time_of_departure, 
                                            double &time_of_arrival,
                                            double &airfare_cost,
                                            double &car_rental_cost,
                                            double &private_vehicle,
                                            double &miles_driven,
                                            double &parking_fees,
                                            double &employee_parking_fees,
                                            double &taxi_fees,
                                            double &employee_taxi_fees,
                                            double &registration_fees,
                                            double &hotel_fees,
                                            double &employee_hotel_fees,
                                            double &total_meal_expenses,
                                            double &empolyee_total_expenses,
                                            double &company_total_expenses)
{
    std::cout << "---calculate_and_display_trip_expenses---" << "\n";
    std::cout << " " << "\n";

    time_of_arrival_meals(time_of_arrival, total_meal_expenses);
    time_of_departure_meals(time_of_departure, total_meal_expenses);   
    cal_parking_fees(number_of_days, parking_fees, employee_parking_fees);
    private_vehicle_cost(private_vehicle, miles_driven);
    cal_taxi_fees(number_of_days, taxi_fees, employee_taxi_fees);
    cal_hotel_fees(number_of_days, hotel_fees, employee_hotel_fees);

    std::cout << " " << "\n";
    empolyee_total_expenses = employee_parking_fees + employee_taxi_fees + employee_hotel_fees; 
        if (empolyee_total_expenses<0)
        {
            empolyee_total_expenses = 0;
            std::cout << empolyee_total_expenses << '\n';
        }

    company_total_expenses = airfare_cost + parking_fees + taxi_fees + registration_fees + hotel_fees + total_meal_expenses + private_vehicle; 
        std::cout << company_total_expenses << '\n';

    return empolyee_total_expenses + company_total_expenses;
}

int main()
{
	char letter;

    double  empolyee_total_expenses,
            compmany_total_expenses,
            total_allowable_expenses,
            excess_expenses,
            saved_expenses,
            number_of_days,
            time_of_departure,
            time_of_arrival,
            airfare_cost,
            car_rental_cost,
            miles_driven,
            parking_fees,
            employee_parking_fees,
            taxi_fees,
            employee_taxi_fees,
            registration_fees,
            hotel_fees,
            employee_hotel_fees,
            number_meals,
            meal_expenses,
            company_total_expenses,
            total_meal_expenses{0},
            private_vehicle,
            total;

	while(letter != 'n')
	{
		
        get_and_store_tripInfo( number_of_days, 
                                time_of_departure, 
                                time_of_arrival,
                                airfare_cost,
                                car_rental_cost,
                                private_vehicle,
                                miles_driven,
                                parking_fees,
                                employee_parking_fees,
                                taxi_fees,
                                employee_taxi_fees,
                                registration_fees,
                                hotel_fees,
                                total_meal_expenses );

        total = calculate_and_display_trip_expenses(number_of_days, 
                                            time_of_departure, 
                                            time_of_arrival,
                                            airfare_cost,
                                            car_rental_cost,
                                            private_vehicle,
                                            miles_driven,
                                            parking_fees,
                                            employee_parking_fees,
                                            taxi_fees,
                                            employee_taxi_fees,
                                            registration_fees,
                                            hotel_fees,
                                            employee_hotel_fees,
                                            total_meal_expenses,
                                            empolyee_total_expenses,
                                            company_total_expenses );

        std::cout << " " << "\n";
        std::cout << "The total amount including empolyee_total_expenses is : " << total <<  "\n";

        std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}