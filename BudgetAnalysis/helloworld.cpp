/*
Write a program that asks the user to enter the amount that he or she has budgeted for a month. 
A loop should then prompt the user to enter each of his or her expenses for the month and keep a running total. 
When the loop finishes, the program should display the amount that the user is over or under budget.
*/

#include <iostream>

int main(){
    int monthly_budgeted{0}, total_months{0}, expenses{0}, t_expenses{0};

    std::cout << "enter the amount that he or she has budgeted for a month: "; std::cin >> monthly_budgeted;

    std::cout << "enter the total months: "; std::cin >> total_months;

    for(int month{0}; month<total_months; ++month){
        std::cout << "For month: " << month << ", enter each of his or her expenses for the month: "; std::cin >> expenses;
        t_expenses += expenses;
    }

    if( total_months*monthly_budgeted < t_expenses ){
        std::cout << " \n";
        std::cout << "User, you are OVER budget by: " << -(total_months*monthly_budgeted - t_expenses);
    }

    if( total_months*monthly_budgeted > t_expenses ){
        std::cout << " \n";
        std::cout << "User, you are UNDER budget by: " << total_months*monthly_budgeted - t_expenses;
    }

    std::cout << " \n";
    return 0;
}
