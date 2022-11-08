/*
Payroll Report
Write a program that displays a weekly payroll report. 

A loop in the program should ask the user for the employee number, gross pay, state tax, federal tax, and FICA with-holdings. 

The loop will terminate when 0 is entered for the employee number. 

After the data is entered, the program should display totals for gross pay, state tax, federal tax, FICA withholdings, and net pay.

Input Validation: Do not accept negative numbers for any of the items entered. 
Input Validation: Do not accept values for state, federal, or FICA withholdings that are greater than the gross pay.
Input Validation: If the sum state tax + federal tax + FICA withholdings for any employee is greater than gross pay, print an error message and ask the user to reenter the data for that employee.
*/

#include <iostream>

int main(){
    int employee_number{0}, gross_pay{0}, t_gross_pay{0}, state_tax{0}, federal_tax{0}, fica{0}, t_state_tax{0}, t_federal_tax{0}, t_fica{0}, t_net_pay{0};

    std::cout << "Press any number to start: ";
    std::cin >> employee_number;

    while(employee_number != 0){
        std::cout << "\n";

        std::cout << "Input employee number: ";
        std::cin >> employee_number;

        if(employee_number != 0){
            std::cout << "Input gross pay: ";
            std::cin >> gross_pay;
            while(gross_pay<0){
                std::cout << "Input Validation: Do not accept negative numbers for any of the items entered." << std::endl;
                std::cout << "Input gross pay: ";
                std::cin >> gross_pay;
            }
            t_gross_pay = t_gross_pay + gross_pay;
        }
        
        if(employee_number !=0){
            std::cout << "Input state tax: ";
            std::cin >> state_tax;
            while(state_tax<0 || state_tax > gross_pay){
                std::cout << "Input Validation: Do not accept negative numbers for any of the items entered." << std::endl;
                std::cout << "Input Validation: Do not accept values for state, federal, or FICA withholdings that are greater than the gross pay." << std::endl;
                std::cout << "Input state tax: ";
                std::cin >> state_tax;
            }
            t_state_tax = t_state_tax + state_tax;
        }

        if(employee_number !=0){
            std::cout << "Input federal tax: "; 
            std::cin >> federal_tax;
            while(federal_tax<0 || federal_tax > gross_pay){
                std::cout << "Input Validation: Do not accept negative numbers for any of the items entered." << std::endl;
                std::cout << "Input Validation: Do not accept values for state, federal, or FICA withholdings that are greater than the gross pay." << std::endl;
                std::cout << "Input federal tax: "; 
                std::cin >> federal_tax;
            }
            t_federal_tax = t_federal_tax + federal_tax;
        }

        if(employee_number !=0){
            std::cout << "Input fica: ";
            std::cin >> fica;
            while(fica<0 || fica > gross_pay){
                std::cout << "Input Validation: Do not accept negative numbers for any of the items entered." << std::endl;
                std::cout << "Input Validation: Do not accept values for state, federal, or FICA withholdings that are greater than the gross pay." << std::endl;
                std::cout << "Input fica: ";
                std::cin >> fica;
            }
            t_fica = t_fica + fica;
        }

        if(state_tax+federal_tax+fica > gross_pay && employee_number != 0){
            std::cout << "Input Validation: Sum of state tax + federal tax + FICA withholdings greater than gross pay." << std::endl;
            std::cout << "Reenter the data for that employee." << std::endl;
            t_gross_pay = t_gross_pay - gross_pay;
            t_state_tax = t_state_tax - state_tax;
            t_federal_tax = t_federal_tax - federal_tax;
            t_fica = t_fica - fica;
        }
    }
    
    std::cout << "\n";
    std::cout << "The totals for gross pay, state tax, federal tax, FICA withholdings, and net pay are:" << "\n";
    std::cout << "Total gross_pay: " << t_gross_pay << "\n";
    std::cout << "Total state_tax: " << t_state_tax << "\n";
    std::cout << "Total federal_tax: " << t_federal_tax << "\n";
    std::cout << "Total fica: " << t_fica << "\n";

    t_net_pay = t_gross_pay - t_state_tax - t_federal_tax - t_fica;
    std::cout << "Total net_pay: " << t_net_pay << "\n";
    
    return 0;
}
