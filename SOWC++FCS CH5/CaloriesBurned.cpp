#include <iostream>
/*
// =============================================================
// This is a program to of Programming Challenge 5.04
// =============================================================

Running on a particular treadmill you burn 3.6 calories per minute. 
Write a program that uses a loop to display the number of calories burned after 5, 10, 15, 20, 25, and 30 minutes.
*/

int main(){
    double calories_per_minute{3.6};
    double calories_burned{1};
    
    for (int mins{1}; mins < 31; ++mins){
        if(mins%5 ==0)
        {
            calories_burned = calories_per_minute*mins;
            std::cout << "After " << mins << " minutes" << " you have burned " << calories_burned << " calories."<< '\n';
        }
    }

    return 0;
}






