#include <iostream>

char inputValidation_y_or_n(char &letter)
{
    std::cin >> letter;

    while (!(letter == 'y' || letter == 'n'))
    {
        std::cout << "ERROR: a 'y' or an 'n' must be entered: ";
        std::cin.clear();
        std::cin >> letter;
    }
    return letter;
}

int inputValidation_postiveInteger(int &ref_number)
{
    while( !(std::cin >> ref_number) || (ref_number<0) )
    {
        std::cout << "Input Validation: Must be a postive integer : ";
        std::cin.clear();
    }
    return ref_number;
}

void getScore(int &ref_test_score)
{
    std::cout << "Input the test score: ";
    inputValidation_postiveInteger(ref_test_score);
}

int findLowest(int &test_score_1, int &test_score_2, int &test_score_3, int &test_score_4, int &test_score_5)
{
    int lowest;
    
    if(test_score_1<test_score_2)
    {
        if(test_score_1<test_score_3)
        {
            if(test_score_1<test_score_4)
            {
                if(test_score_1<test_score_5)
                {
                    lowest = test_score_1;
                }
            }
        }
    }

    
    if(test_score_2<test_score_1)
    {
        if(test_score_2<test_score_3)
        {
            if(test_score_2<test_score_4)
            {
                if(test_score_2<test_score_5)
                {
                    lowest = test_score_2;
                }
            }
        }
    }

    
    if(test_score_3<test_score_1)
    {
        if(test_score_3<test_score_2)
        {
            if(test_score_3<test_score_4)
            {
                if(test_score_3<test_score_5)
                {
                    lowest = test_score_3;
                }
            }
        }
    }

    if(test_score_4<test_score_1)
    {
        if(test_score_4<test_score_2)
        {
            if(test_score_4<test_score_3)
            {
                if(test_score_4<test_score_5)
                {
                    lowest = test_score_4;
                }
            }
        }
    }

    if(test_score_5<test_score_1)
    {
        if(test_score_5<test_score_2)
        {
            if(test_score_5<test_score_3)
            {
                if(test_score_5<test_score_4)
                {
                    lowest = test_score_5;
                }
            }
        }
    }

    return lowest;
}

void calcAverage(int &test_score_1, int &test_score_2, int &test_score_3, int &test_score_4, int &test_score_5)
{
    int lowest,
        avg_test_score;
    
    lowest = findLowest(test_score_1, test_score_2, test_score_3, test_score_4, test_score_5);

    if(test_score_1 == lowest)
    {
        avg_test_score = 0.25 * (test_score_2 + test_score_3 + test_score_4 + test_score_5);
        std::cout << "The average test score of the four highest grades is : " << avg_test_score << "\n";
    }
    
    else if(test_score_2 == lowest)
    {
        avg_test_score = 0.25 * (test_score_1 + test_score_3 + test_score_4 + test_score_5);
        std::cout << "The average test score of the four highest grades is : " << avg_test_score << "\n";
    }
 
    else if(test_score_3 == lowest)
    {
        avg_test_score = 0.25 * (test_score_1 + test_score_2 + test_score_4 + test_score_5);
        std::cout << "The average test score of the four highest grades is : " << avg_test_score << "\n";
    }

    else if(test_score_4 == lowest)
    {
        avg_test_score = 0.25 * (test_score_1 + test_score_2 + test_score_3 + test_score_5);
        std::cout << "The average test score of the four highest grades is : " << avg_test_score << "\n";
    }

    else if(test_score_5 == lowest)
    {
        avg_test_score = 0.25 * (test_score_1 + test_score_2 + test_score_3 + test_score_4);
        std::cout << "The average test score of the four highest grades is : " << avg_test_score << "\n";
    }

}
