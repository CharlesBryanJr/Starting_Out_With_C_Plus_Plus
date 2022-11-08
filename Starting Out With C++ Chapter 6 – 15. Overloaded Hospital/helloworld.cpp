/*
15. Overloaded Hospital
Write a program that computes and displays the charges for a patient’s hospital stay.

First, the program should ask if the patient was admitted as an in-patient or an out patient. 

If the patient was an in-patient, the following data should be entered:

• The number of days spent in the hospital
• The daily rate
• Hospital medication charges
• Charges for hospital services (lab tests, etc.)

The program should ask for the following data if the patient was an out-patient:
• Charges for hospital services (lab tests, etc.)
• Hospital medication charges

The program should use two overloaded functions to calculate the total charges. 
One of the functions should accept arguments for the in-patient data, while the other function accepts arguments for out-patient information. 

Both functions should return the total charges.

Input Validation: Do not accept negative numbers for any data.
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

bool get_hospital_stay_charges( double &ref_number_of_days, 
                                double &ref_daily_rate, 
                                double &ref_hospital_medication_charges, 
                                double &ref_hospital_services_charges) //ref included
{
    bool in_or_out_patient;

    std::cout << "Was the patient was admitted as an in-patient or an out patient?" << "\n";
    std::cout << "Input 'true' for in-patient or Input 'false' for out patient? : "; std::cin >> std::boolalpha >> in_or_out_patient;

    if( in_or_out_patient == true ) // in-patient
    {
        std::cout << "The number of days spent in the hospital : ";
            inputValidation_postiveInteger(ref_number_of_days);
        std::cout << "The daily rate : ";
            inputValidation_postiveInteger(ref_daily_rate);
        std::cout << "Hospital medication charges : ";
            inputValidation_postiveInteger(ref_hospital_medication_charges);
        std::cout << "Charges for hospital services (lab tests, etc.) : ";
            inputValidation_postiveInteger(ref_hospital_services_charges);
    }

    else // out_patient
    {
        std::cout << "Hospital medication charges : ";
            inputValidation_postiveInteger(ref_hospital_medication_charges);
        std::cout << "Charges for hospital services (lab tests, etc.) : ";
            inputValidation_postiveInteger(ref_hospital_services_charges);
    }

    return in_or_out_patient;
}

double calculate_the_total_charges( double &number_of_days,
                                    double &daily_rate,
                                    double &hospital_medication_charges, 
                                    double &hospital_services_charges)
{
    return (number_of_days*daily_rate) + hospital_medication_charges + hospital_services_charges;
}

double calculate_the_total_charges(double &hospital_medication_charges, double &hospital_services_charges)
{
    return hospital_medication_charges + hospital_services_charges;
}

int main()
{
	char letter;
    double  number_of_days, 
            daily_rate, 
            hospital_medication_charges, 
            hospital_services_charges;

    while(letter != 'n')
	{
        if( get_hospital_stay_charges(number_of_days, daily_rate, hospital_medication_charges, hospital_services_charges) == true )
        {
            std::cout << "The total charges for an IN patient : " 
                << calculate_the_total_charges(number_of_days, daily_rate, hospital_medication_charges, hospital_services_charges) << "\n";
        }

        else 
        {
            std::cout << "The total charges for an OUT patient : " 
                << calculate_the_total_charges(hospital_medication_charges, hospital_services_charges) << "\n";
        }

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}