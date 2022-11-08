/*
13. Days Out
Write a program that calculates the average number of days a company’s employees are absent. 
The program should have the following functions:

• A function called by main that asks the user for the number of employees in the company. 
This value should be returned as an int. 
(The function accepts no arguments.)

• A function called by main that accepts one argument: the number of employees in the company. 
The function should ask the user to enter the number of days each employee missed during the past year.
The total of these days should be returned as an int .

• A function called by main that takes two arguments: the number of employees in the company and the total number of days absent for all employees during the year.
The function should return, as a double, the average number of days absent. 
(This function does not perform screen output and does not ask the user for input.)

Input Validation: Do not accept a number less than 1 for the number of employees. 
Input Validation: Do not accept a negative number for the days any employee missed.
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

int inputValidation_postiveInteger(int &ref_number)
{
    while( !(std::cin >> ref_number) || (ref_number<1) )
    {
        std::cout << "Input Validation: Must be a postive integer : ";
        std::cin.clear();
    }
    return ref_number;
}

int number_of_employees()
{
    int employees_count;
    std::cout << "Input the number of employees in the company : ";
    inputValidation_postiveInteger(employees_count);
    return employees_count;
}

int employee_missed_days(int number_of_employees)
{
    int missed_days_count{0}, 
        total_missed_days_count{0};

    for(int employees{0}; employees<number_of_employees; employees++)
    {
        std::cout << "Input the number of days employee " << employees << ", missed during the past year : "; 
        inputValidation_postiveInteger(missed_days_count);
        total_missed_days_count += missed_days_count;
    }
    return total_missed_days_count;
}

double average_number_of_days_absent(int number_of_employees, int employee_missed_days)
{
    return employee_missed_days / number_of_employees;
}

int main()
{
	char letter;
    double  var_number_of_employees{0},
            var_employee_missed_days{0},
            var_average_number_of_days_absent{0};

	 while(letter != 'n')
	{
        var_number_of_employees = number_of_employees(); 
        var_employee_missed_days = employee_missed_days(var_number_of_employees); 
        var_average_number_of_days_absent = average_number_of_days_absent(var_number_of_employees, var_employee_missed_days);
            std::cout << "The average_number_of_days_absent is : " << var_average_number_of_days_absent << "\n";
        
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}