/*
11. Lowest Score Drop
Write a program that calculates the average of a group of test scores, where the lowest score in the group is dropped. 

It should use the following functions:

• void getScore() should ask the user for a test score, store it in a reference parameter variable, and validate it. 
This function should be called by main once for each of the five scores to be entered.

• void calcAverage() should calculate and display the average of the four highest scores. 
This function should be called just once by main and should be passed the five scores.

• int findLowest() should find and return the lowest of the five scores passed to it.
It should be called by calcAverage, which uses the function to determine which of the five scores to drop.

Input Validation: Do not accept test scores lower than 0 or higher than 100.
*/
#include <iostream>
#include "headers.h"

int main()
{
    char letter;
    int test_score_1, 
        test_score_2, 
        test_score_3, 
        test_score_4, 
        test_score_5;
    
    while(letter != 'n'){
        std::cout << "Write a program that calculates the average of a group of test scores, where the lowest score in the group is dropped." << "\n";

        getScore(test_score_1);
        getScore(test_score_2);
        getScore(test_score_3);
        getScore(test_score_4);
        getScore(test_score_5);

        calcAverage(test_score_1, test_score_2, test_score_3, test_score_4, test_score_5);

        std::cout << "Would you like to run the program again? (y/n) : "; 
        inputValidation_y_or_n(letter);

        std::cout << " " << "\n";
    }

    return 0;
}