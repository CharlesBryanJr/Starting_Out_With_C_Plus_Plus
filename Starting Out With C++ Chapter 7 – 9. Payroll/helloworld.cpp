/*
Starting Out With C++ Chapter 7 – 9. Payroll
Write a program that uses the following arrays:
• empId: an array of seven long integers to hold employee identification numbers. 
The array should be initialized with the following numbers:
5658845 4520125 7895122 8777541 8451277 1302850 7580489
• hours: an array of seven integers to hold the number of hours worked by each employee
• payRate: an array of seven doubles to hold each employee’s hourly pay rate
• wages: an array of seven doubles to hold each employee’s gross wages

The program should relate the data in each array through the subscripts. 

For example, the number in element 0 of the hours array should be the number of hours worked by the employee whose identification number is stored in element 0 of the empId array.

That same employee’s pay rate should be stored in element 0 of the payRate array.

The program should display each employee number and ask the user to enter that employee’s hours and pay rate. 

It should then calculate the gross wages for that employee (hours times pay rate) and store them in the wages array. 

After the data has been entered for all the employees, the program should display each employee’s identification number and gross wages.

Input Validation: Do not accept negative values for hours or numbers less than 15.00 for pay rate.
*/
#include <iostream>
#include <iomanip>
#include <vector>
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

int inputValidation_postiveInteger_hours(const long int empId[], int hours[], const int ele)
{
	std::cin >> hours[ele];

    while( hours[ele] < 0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Do not accept negative values for hours." << "\n";
        std::cout << "For employee " << empId[ele] << ", input the employee's hours : ";
            std::cin >> hours[ele];
    }
    return hours[ele];
}

double inputValidation__payRate(const long int empId[], double payRate[], int ele)
{
    std::cin >> payRate[ele];

    while( payRate[ele] < 15 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Do not accept negative values for hours or numbers less than 15.00 for pay rate." << "\n";
        std::cout << "For employee " << empId[ele] << ", input the employee's pay rate : ";
            std::cin >> payRate[ele];
    }
    return payRate[ele];
}

void GET_employeeData(const long int empId[], int hours[], double payRate[], int SIZEof_arrays, int ele)
{
    std::cout << "---GET_employee_data---" << "\n"; std::cout << " " << "\n";
    
    for(ele=0;ele<SIZEof_arrays;++ele)
    {
        std::cout << "For employee " << empId[ele] << ", input the employee's hours : ";
            inputValidation_postiveInteger_hours(empId,hours,ele);
        
        std::cout << "For employee " << empId[ele] << ", input the employee's pay rate : ";
            inputValidation__payRate(empId,payRate,ele);
        
        std::cout << " " << "\n";
    }
    std::cout << " " << "\n";
}

void calculate_and_display_employeeData(const long int empId[], int hours[], double payRate[], double wages[], int SIZEof_arrays, int ele)
{
    std::cout << "---calculate_and_display_employeeData---" << "\n"; std::cout << " " << "\n";
    
    for(ele=0;ele<SIZEof_arrays;++ele)
    {
        wages[ele] =  hours[ele] * payRate[ele];
    }
    
    for(ele=0;ele<SIZEof_arrays;++ele)
    {
        std::cout << "For employee " << empId[ele] << ", employee's wages : " << wages[ele] <<  "\n";
        std::cout << " " << "\n";
    }
}

int main()
{
	char letter;
    int ele,
        SIZEof_arrays{7};

    long int empId[SIZEof_arrays] {5658845,4520125,7895122,8777541,8451277,1302850,7580489};
    int hours[SIZEof_arrays];
    double payRate[SIZEof_arrays];
    double wages[SIZEof_arrays];

	while(letter != 'n')
	{
        GET_employeeData(empId, hours, payRate, SIZEof_arrays, ele);
        calculate_and_display_employeeData(empId, hours, payRate, wages, SIZEof_arrays, ele);

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}