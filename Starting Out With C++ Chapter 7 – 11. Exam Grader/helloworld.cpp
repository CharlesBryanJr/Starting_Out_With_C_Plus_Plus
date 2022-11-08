/*
Starting Out With C++ Chapter 7 – 11. Exam Grader
One of your professors has asked you to write a program to grade her final exams, which consist of only 20 multiple-choice questions. 
Each question has one of four possible answers: A, B, C, or D. 
The file CorrectAnswers.txtcontains the correct answers for all of the questions, with each answer written on a separate line. 
The first line contains the answer to the first question, the second line contains the answer to the second question, and so forth. 

Write a program that reads the contents of the CorrectAnswers.txtfile into a char array, and then reads the contents of another file, containing a student’s answers, into a second char array. 

The program should determine the number of questions that the student missed and then display the following:
- A list of the questions missed by the student, showing the correct answer and the incorrect answer provided by the student for each missed question.
• The total number of questions missed
• The percentage of questions answered correctly. This can be calculated as
Correctly Answered Questions ÷ Total Number of Questions
• If the percentage of correctly answered questions is 70% or greater, the program should indicate that the student passed the exam. 
Otherwise, it should indicate that the student failed the exam.
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

void GET_userAnswers(char userAnswers[], const int SIZEof_exam, int &ele)
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

void GRADE_userAnswers(char userAnswers[], char correctAnswers[], bool userAnswers_incorrect[], const int SIZEof_exam, int &ele)
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

    std::cout << "User, you correctly answered : " << score << " questions." << "\n";
    std::cout << "User, you incorrectly answered : " << SIZEof_exam - score << " questions." << "\n";
    
    float grade = float(score)/float(SIZEof_exam);
        std::cout << "User, the percentage of questions answered correctly : " << grade << "%\n";

    if(score>=14) // 14/20 == 70%
    {
        std::cout << " PASSED! " << "\n";
    }
    else
    {
        std::cout << " Failed " << "\n";
    }

    std::cout << " " << "\n";

    for(ele=0;ele<SIZEof_exam;++ele)
    {
        if(userAnswers_incorrect[ele] == true)
        {
            std::cout << "For question " << ele+1 << ", your answer of " << userAnswers[ele] << ", was incorrect." << "\n";
            std::cout << "The correct answer was : " << correctAnswers[ele] << "\n"; 
            std::cout << " " << "\n";
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
                                      'A','C','D','B','D',
                                      'C','C','A','D','B'};

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