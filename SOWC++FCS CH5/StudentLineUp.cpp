/*
Student Line Up
A teacher has asked all her students to line up single file according to their first name.
For example, in one class Amy will be at the front of the line and Yolanda will be at the end. 

Write a program that prompts the user to enter the number of students in the class, then loops to read that many names. 

Once all the names have been read it reports which student would be at the front of the line and which one would be at the end of the line. 

You may assume that no two students have the same name.

Input Validation: Do not accept a number less than 1 or greater than 25 for the number of students.
*/
#include <iostream>


int main(){
    int number_of_students{0}; std::string student_name;

    std::cout << "Input the number of students: ";
    std::cin >> number_of_students;
    std::cout << "\n";

    //Input Validation: Do not accept a number less than 1 or greater than 25 for the number of students.
    if(number_of_students<1 || number_of_students>25){
        std::cout << "Input Validation: Do not accept a number less than 1 or greater than 25 for the number of students." << "\n";
        std::cout << "Input the number of students: ";
        std::cin >> number_of_students;
        std::cout << "\n";
    }
    
     
    for (int i{0}; i < number_of_students; ++i){
        std::cout << "Input the name of student " << i << ": ";
        std::cin >> student_name;
        if(student_name<i){
            
        }
        std::cout << "\n";
    }

    return 0;
}
 





