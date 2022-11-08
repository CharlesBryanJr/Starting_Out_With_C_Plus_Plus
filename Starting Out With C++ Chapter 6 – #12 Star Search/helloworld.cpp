/*
12. Star Search
A particular talent competition has five judges, each of whom awards a score between 0 and 10 to each performer. 

Fractional scores, such as 8.3, are allowed. 

A performer’s final score is determined by dropping the highest and lowest score received, then averaging the three remaining scores. 

Write a program that uses this method to calculate a contestant’s score. 

It should include the following functions:

• void getJudgeData() should ask the user for a judge’s score, store it in a reference parameter variable, and validate it. 
This function should be called by main once for each of the five judges.

• void calcScore() should calculate and display the average of the three scores that remain after dropping the highest and lowest scores the performer received. 
This function should be called just once by main and should be passed the five scores.

The last two functions, described below, should be called by calcScore, which uses the returned information to determine which of the scores to drop.

• int findLowest() should find and return the lowest of the five scores passed to it.
• int findHighest() should find and return the highest of the five scores passed to it.

Input Validation: Do not accept judge scores lower than 0 or higher than 10.
*/
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

double inputValidation_postiveInteger(double &ref_number)
{
    while( !(std::cin >> ref_number) || (ref_number<0) || (ref_number>10) )
    {
        std::cout << "Input Validation: Must be a postive integer less than 10 : ";
        std::cin.clear();
    }
    return ref_number;
}

void getJudgeData(double &ref_score_judge) 
{
    std::cout << "Input the judge's score : ";
    inputValidation_postiveInteger(ref_score_judge);
}

double findLowest(double &score_judge1, double &score_judge2, double &score_judge3, double &score_judge4, double &score_judge5)
{
    
    double lowest; 

    if( (score_judge1 == score_judge2) && (score_judge1 == score_judge3) && (score_judge1 == score_judge4) && (score_judge1 == score_judge5) )
    {
        lowest = score_judge1;
    }
    
    if(score_judge1<score_judge2)
    {
        if(score_judge1<score_judge3)
        {
            if(score_judge1<score_judge4)
            {
                if(score_judge1<score_judge5)
                {
                    lowest = score_judge1;
                }
            }
        }
    }

    if(score_judge2<score_judge1)
    {
        if(score_judge2<score_judge3)
        {
            if(score_judge2<score_judge4)
            {
                if(score_judge2<score_judge5)
                {
                    lowest = score_judge2;
                }
            }
        }
    }

    if(score_judge3<score_judge1)
    {
        if(score_judge3<score_judge2)
        {
            if(score_judge3<score_judge4)
            {
                if(score_judge3<score_judge5)
                {
                    lowest = score_judge3;
                }
            }
        }
    }

    if(score_judge4<score_judge1)
    {
        if(score_judge4<score_judge2)
        {
            if(score_judge4<score_judge3)
            {
                if(score_judge4<score_judge5)
                {
                    lowest = score_judge4;
                }
            }
        }
    }

    if(score_judge5<score_judge1)
    {
        if(score_judge5<score_judge2)
        {
            if(score_judge5<score_judge3)
            {
                if(score_judge5<score_judge4)
                {
                    lowest = score_judge5;
                }
            }
        }
    }

    return lowest;
}

double findHighest(double &score_judge1, double &score_judge2, double &score_judge3, double &score_judge4, double &score_judge5)
{
    double highest;

    if( (score_judge1 == score_judge2) && (score_judge1 == score_judge3) && (score_judge1 == score_judge4) && (score_judge1 == score_judge5) )
    {
        highest = score_judge1;
    }
    
    if(score_judge1>score_judge2)
    {
        if(score_judge1>score_judge3)
        {
            if(score_judge1>score_judge4)
            {
                if(score_judge1>score_judge5)
                {
                    highest = score_judge1;
                }
            }
        }
    }

    if(score_judge2>score_judge1)
    {
        if(score_judge2>score_judge3)
        {
            if(score_judge2>score_judge4)
            {
                if(score_judge2>score_judge5)
                {
                    highest = score_judge2;
                }
            }
        }
    }

    if(score_judge3>score_judge1)
    {
        if(score_judge3>score_judge2)
        {
            if(score_judge3>score_judge4)
            {
                if(score_judge3>score_judge5)
                {
                    highest = score_judge3;
                }
            }
        }
    }

    if(score_judge4>score_judge1)
    {
        if(score_judge4>score_judge2)
        {
            if(score_judge4>score_judge3)
            {
                if(score_judge4>score_judge5)
                {
                    highest = score_judge4;
                }
            }
        }
    }

    if(score_judge5>score_judge1)
    {
        if(score_judge5>score_judge2)
        {
            if(score_judge5>score_judge3)
            {
                if(score_judge5>score_judge4)
                {
                    highest = score_judge5;
                }
            }
        }
    }

    return highest;
}

void calcScore(double &score_judge1, double &score_judge2, double &score_judge3, double &score_judge4, double &score_judge5) 
{
    double  lowest,
            highest,
            avg_judge_score;
    
    lowest = findLowest(score_judge1, score_judge2, score_judge3, score_judge4, score_judge5); 
    highest = findHighest(score_judge1, score_judge2, score_judge3, score_judge4, score_judge5);

    avg_judge_score = 0.3333333333 * (score_judge1 + score_judge2 + score_judge3 + score_judge4 + score_judge5 - highest - lowest);

    std::cout << "Not including the highest " << highest << ", or the lowest " << lowest << ", the average judge score is : " << avg_judge_score << "\n";

}

int main()
{
	char letter;
    double  score_judge1{8},
            score_judge2{4},
            score_judge3{1},
            score_judge4{33},
            score_judge5{999};

    std::cout << " " << "\n";
    std::cout << score_judge1 << " " << &score_judge1 << "\n";
    std::cout << score_judge2 << " " << &score_judge2 << "\n";
    std::cout << score_judge3 << " " << &score_judge3 << "\n";
    std::cout << score_judge4 << " " << &score_judge4 << "\n";
    std::cout << score_judge5 << " " << &score_judge5 << "\n";
    std::cout << " " << "\n";
    
	while(letter != 'n')
	{
        getJudgeData(score_judge1);
        getJudgeData(score_judge2);
        getJudgeData(score_judge3);
        getJudgeData(score_judge4);
        getJudgeData(score_judge5);

        std::cout << " " << "\n";
        calcScore(score_judge1, score_judge2, score_judge3, score_judge4, score_judge5);

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }

    std::cout << " " << "\n";
    std::cout << score_judge1 << " " << &score_judge1 << "\n";
    std::cout << score_judge2 << " " << &score_judge2 << "\n";
    std::cout << score_judge3 << " " << &score_judge3 << "\n";
    std::cout << score_judge4 << " " << &score_judge4 << "\n";
    std::cout << score_judge5 << " " << &score_judge5 << "\n";
    std::cout << " " << "\n";
	
	return 0;
}

