/*
Starting Out With C++ Chapter 7 – 12. Grade Book
A teacher has five students who have taken four tests. 
The teacher uses the following grading scale to assign a letter grade to a student, based on the average of his or her four test scores.
Test Score Letter Grade
90–100 A
80–89 B
70–79 C
60–69 D
0–59 F
Write a program that uses 
an array of string objects to hold the five student names,
an array of five characters to hold the five students’ letter grades, 
and five arrays of four doubles to hold each student’s set of test scores.

The program should allow the user to enter each student’s name and his or her four test scores. 

It should then calculate and display each student’s average test score and a letter grade based on the average.

Input Validation: Do not accept test scores less than 0 or greater than 100.
*/

#include <iostream>
#include <iomanip>
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

void Get_student_names(std::string student_names[], const int &numberOFstudedents, int &ele)
{
    std::cout << "*** ---student_names--- ***" << "\n"; std::cout << " " << "\n";

    for(ele=0;ele<numberOFstudedents;++ele)
    {
        std::cout << "Input the name for student " << ele+1 << ", : ";
            std::cin >> student_names[ele];
    }

    std::cout << " " << "\n";
}

void Get_testScores(const int numberOFtests,
                    const std::string student_names[],
                    int testScores_student1[],
                    int testScores_student2[],
                    int testScores_student3[],
                    int testScores_student4[],
                    int testScores_student5[],
                    int &ele)
{
    std::cout << "*** ---Get_testScores--- ***" << "\n"; std::cout << " " << "\n";
    int score;

    for(ele=0;ele<numberOFtests;++ele)
    {
        std::cout << "For student 1, " << student_names[0] <<  ", input the score for test " << ele+1 << " : ";
            std::cin >> testScores_student1[ele];
    }
    std::cout << " " << "\n";

    for(ele=0;ele<numberOFtests;++ele)
    {
        std::cout << "For student 2, " << student_names[1] <<  ", input the score for test " << ele+1 << " : ";
            std::cin >> testScores_student2[ele];
    }
    std::cout << " " << "\n";

    for(ele=0;ele<numberOFtests;++ele)
    {
        std::cout << "For student 3, " << student_names[2] <<  ", input the score for test " << ele+1 << " : ";
            std::cin >> testScores_student3[ele];
    }
    std::cout << " " << "\n";

    for(ele=0;ele<numberOFtests;++ele)
    {
        std::cout << "For student 4, " << student_names[3] <<  ", input the score for test " << ele+1 << " : ";
            std::cin >> testScores_student4[ele];
    }
    std::cout << " " << "\n";

    for(ele=0;ele<numberOFtests;++ele)
    {
        std::cout << "For student 5, " << student_names[4] <<  ", input the score for test " << ele+1 << " : ";
            std::cin >> testScores_student5[ele];
    }
    std::cout << " " << "\n";

    for(ele=0;ele<numberOFtests;++ele)
    {
        while( (testScores_student1[ele] < 0) || (testScores_student1[ele] > 100) )
        {
            std::cout << "Input Validation: Do not accept test scores less than 0 or greater than 100." << "\n";
            std::cout << "For student 1, input the score for test " << ele+1 << " : ";
                std::cin >> testScores_student1[ele];
            std::cout << " " << "\n";
        }

        while( (testScores_student2[ele] < 0) || (testScores_student2[ele] > 100) )
        {
            std::cout << "Input Validation: Do not accept test scores less than 0 or greater than 100." << "\n";
            std::cout << "For student 2, input the score for test " << ele+1 << " : ";
                std::cin >> testScores_student2[ele];
            std::cout << " " << "\n";
        }

        while( (testScores_student3[ele] < 0) || (testScores_student3[ele] > 100) )
        {
            std::cout << "Input Validation: Do not accept test scores less than 0 or greater than 100." << "\n";
            std::cout << "For student 3, input the score for test " << ele+1 << " : ";
                std::cin >> testScores_student3[ele];
            std::cout << " " << "\n";
        }

        while( (testScores_student4[ele] < 0) || (testScores_student4[ele] > 100) )
        {
            std::cout << "Input Validation: Do not accept test scores less than 0 or greater than 100." << "\n";
            std::cout << "For student 4, input the score for test " << ele+1 << " : ";
                std::cin >> testScores_student4[ele];
            std::cout << " " << "\n";
        }

        while( (testScores_student5[ele] < 0) || (testScores_student5[ele] > 100) )
        {
            std::cout << "Input Validation: Do not accept test scores less than 0 or greater than 100." << "\n";
            std::cout << "For student 1, input the score for test " << ele+1 << " : ";
                std::cin >> testScores_student5[ele];
            std::cout << " " << "\n";
        }
    }

    std::cout << " " << "\n";
}

void calculate_students_letter_grades(const int numberOFtests,
                                      const int testScores_student1[],
                                      const int testScores_student2[],
                                      const int testScores_student3[],
                                      const int testScores_student4[],
                                      const int testScores_student5[],
                                      char students_letter_grades[],
                                      int &ele,
                                      char letter_grades)
{
    std::cout << "*** ---calculate_students_letter_grades--- ***" << "\n"; std::cout << " " << "\n";
    int avg{0};

    for(ele=0;ele<numberOFtests;++ele)
    {
        avg += testScores_student1[ele];
    }

    if(avg/numberOFtests > 90)
    {
        students_letter_grades[0] = 'A';
    }
    else if(avg/numberOFtests <= 89 && avg/numberOFtests >= 80 )
    {
        students_letter_grades[0] = 'B';
    }
    else if(avg/numberOFtests <= 79 && avg/numberOFtests >= 70 )
    {
        students_letter_grades[0] = 'C';
    }
    else if(avg/numberOFtests <= 69 && avg/numberOFtests >= 60 )
    {
        students_letter_grades[0] = 'D';
    }
    else
    {
        students_letter_grades[0] = 'F';
    }

    avg = 0;
    for(ele=0;ele<numberOFtests;++ele)
    {
        avg += testScores_student2[ele];
    }

    if(avg/numberOFtests > 90)
    {
        students_letter_grades[1] = 'A';
    }
    else if(avg/numberOFtests <= 89 && avg/numberOFtests >= 80 )
    {
        students_letter_grades[1] = 'B';
    }
    else if(avg/numberOFtests <= 79 && avg/numberOFtests >= 70 )
    {
        students_letter_grades[1] = 'C';
    }
    else if(avg/numberOFtests <= 69 && avg/numberOFtests >= 60 )
    {
        students_letter_grades[1] = 'D';
    }
    else
    {
        students_letter_grades[1] = 'F';
    }

    avg = 0;
    for(ele=0;ele<numberOFtests;++ele)
    {
        avg += testScores_student3[ele];
    }
    
    if(avg/numberOFtests > 90)
    {
        students_letter_grades[2] = 'A';
    }
    else if(avg/numberOFtests <= 89 && avg/numberOFtests >= 80 )
    {
        students_letter_grades[2] = 'B';
    }
    else if(avg/numberOFtests <= 79 && avg/numberOFtests >= 70 )
    {
        students_letter_grades[2] = 'C';
    }
    else if(avg/numberOFtests <= 69 && avg/numberOFtests >= 60 )
    {
        students_letter_grades[2] = 'D';
    }
    else
    {
        students_letter_grades[2] = 'F';
    }

    avg = 0;
    for(ele=0;ele<numberOFtests;++ele)
    {
        avg += testScores_student4[ele];
    }
    
    if(avg/numberOFtests > 90)
    {
        students_letter_grades[3] = 'A';
    }
    else if(avg/numberOFtests <= 89 && avg/numberOFtests >= 80 )
    {
        students_letter_grades[3] = 'B';
    }
    else if(avg/numberOFtests <= 79 && avg/numberOFtests >= 70 )
    {
        students_letter_grades[3] = 'C';
    }
    else if(avg/numberOFtests <= 69 && avg/numberOFtests >= 60 )
    {
        students_letter_grades[3] = 'D';
    }
    else
    {
        students_letter_grades[3] = 'F';
    }

    avg = 0;
    for(ele=0;ele<numberOFtests;++ele)
    {
        avg += testScores_student5[ele];
    }
    
    if(avg/numberOFtests > 90)
    {
        students_letter_grades[4] = 'A';
    }
    else if(avg/numberOFtests <= 89 && avg/numberOFtests >= 80 )
    {
        students_letter_grades[4] = 'B';
    }
    else if(avg/numberOFtests <= 79 && avg/numberOFtests >= 70 )
    {
        students_letter_grades[4] = 'C';
    }
    else if(avg/numberOFtests <= 69 && avg/numberOFtests >= 60 )
    {
        students_letter_grades[4] = 'D';
    }
    else
    {
        students_letter_grades[4] = 'F';
    }

    std::cout << " " << "\n";
}

int main()
{
	char letter,
         letter_grades;
    int ele,
        element,
        numberOFstudedents{5},
        numberOFtests{4};

    std::string student_names[numberOFstudedents];
    char students_letter_grades[numberOFstudedents];
    int testScores_student1[numberOFtests],
        testScores_student2[numberOFtests],
        testScores_student3[numberOFtests],
        testScores_student4[numberOFtests],
        testScores_student5[numberOFtests];

	while(letter != 'n')
	{
        Get_student_names(student_names, numberOFstudedents, ele);
        Get_testScores( numberOFtests,
                        student_names,
                        testScores_student1,
                        testScores_student2,
                        testScores_student3,
                        testScores_student4,
                        testScores_student5,
                        ele);
        calculate_students_letter_grades( numberOFtests,
                                          testScores_student1,
                                          testScores_student2,
                                          testScores_student3,
                                          testScores_student4,
                                          testScores_student5,
                                          students_letter_grades,
                                          ele,
                                          letter_grades);

        for(int i{0};i<numberOFstudedents;++i)
        {
            std::cout << "For student " << i+1 << ", " << student_names[i] << ", their letter grade was : " << students_letter_grades[i] << "\n";
            std::cout << " " << "\n";
        }
                        
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}