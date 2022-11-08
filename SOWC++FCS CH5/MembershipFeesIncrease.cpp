/*
Membership Fees Increase
A country club, which currently charges $2,500 per year for membership, has
announced it will increase its membership fee by 4% each year for the next six years.
Write a program that uses a loop to display the projected rates for the next six years.
*/

#include <iostream>


int main(){
    double base_membership_rate{2500};
    double membership_increase{0.04};
    double projected_membership_rates{2500};
    
    for (int years{0}; years < 6; ++years){
        if(years==0){
            std::cout << base_membership_rate << "\n";
        }
        else{
            projected_membership_rates = projected_membership_rates + projected_membership_rates*membership_increase;
            std::cout << projected_membership_rates << '\n';
        }
    }

    return 0;
}




 

