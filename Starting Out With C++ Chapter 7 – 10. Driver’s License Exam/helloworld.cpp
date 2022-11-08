/*
Starting Out With C++ Chapter 7 – 10. Driver’s License Exam
The local Driver’s License Office has asked you to write a program that grades the written portion of the driver’s license exam. 
The exam has 20 multiple choice questions.

Here are the correct answers:
1. A
2. D
3. B
4. B
5. C

6. B
7. A
8. B
9. C
10. D

11. A
12. C
13. D
14. B
15. D

16. C
17. C
18. A
19. D
20. B

Your program should store the correct answers shown above in an array. 
It should ask the user to enter the student’s answers for each of the 20 questions, and the answers should be stored in another array. 
After the student’s answers have been entered, the program should display a message indicating whether the student passed or failed the exam. 
(A student must correctly answer 15 of the 20 questions to pass the exam.) 
It should then display the total number of correctly answered questions, 
the total number of incorrectly answered questions, 
and a list showing the question numbers of the incorrectly answered questions.
Input Validation: Only accept the letters A, B, C, or D as answers.
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

char inputValidation_character(char userAnswers[], char character, const int &ele)
{
    std::cin >> userAnswers[ele];

    while( !(userAnswers[ele] == 'A' 
          || userAnswers[ele] == 'B'
          || userAnswers[ele] == 'C'
          || userAnswers[ele] == 'D') )
    {
        std::cin.clear();
        std::cout << "Input Validation: Only accept the letters A, B, C, or D as answers." << "\n";
        std::cout << "User, input your answer for question " << ele+1 << ", : ";
            std::cin >> userAnswers[ele];
    }
    std::cout << " " << "\n";
    return userAnswers[ele];
}

void GET_userAnswers(char userAnswers[], int SIZEof_exam, int &ele)
{
    std::cout << "---GET_userAnswers---" << "\n"; std::cout << " " << "\n";
    char character;

    for(ele=0;ele<SIZEof_exam;++ele)
    {
        std::cout << "User, input your answer for question " << ele+1 << ", : ";
            inputValidation_character(userAnswers, character, ele);
    }

    std::cout << " " << "\n";
}

void GRADE_userAnswers(char userAnswers[], char correctAnswers[], bool userAnswers_incorrect[], int SIZEof_exam, int &ele)
{
    std::cout << "---GRADE_userAnswers---" << "\n"; std::cout << " " << "\n";
    int score{0}; // starting point for addition or subtract

    for(ele=0;ele<SIZEof_exam;++ele)
    {
        if( userAnswers[ele] == correctAnswers[ele] )
        {
            score += 1;
        }
        else 
        {
            userAnswers_incorrect[ele] = true;
        }
    }

    if(score>=15)
    {
        std::cout << " PASSED! " << "\n";
    }
    else
    {
        std::cout << " Failed " << "\n";
    }

    std::cout << "User, you correctly answered : " << score << " questions." << "\n";
    std::cout << "User, you incorrectly answered : " << SIZEof_exam - score << " questions." << "\n";
    std::cout << " " << "\n";

    for(ele=0;ele<SIZEof_exam;++ele)
    {
        if(userAnswers_incorrect[ele] == true)
        {
            std::cout << "For question " << ele+1 << ", your answer of " << userAnswers[ele] << ", was incorrect." << "\n"; 
        }
    }

    std::cout << " " << "\n";
}

int main()
{
	char letter;
    int ele,
        SIZEof_exam{20};
    bool userAnswers_incorrect[SIZEof_exam];
    char userAnswers[SIZEof_exam],
         correctAnswers[SIZEof_exam] {'A','D','B','B','C',
                                      'B','A','B','C','D',
                                      'A','C','D','B','D'};

	while(letter != 'n')
	{
        GET_userAnswers(userAnswers, SIZEof_exam, ele);
        GRADE_userAnswers(userAnswers, correctAnswers, userAnswers_incorrect, SIZEof_exam, ele);
        
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}