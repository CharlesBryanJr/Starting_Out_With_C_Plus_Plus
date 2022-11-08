/*
Write a program that asks the user for a positive integer no greater than 15. 

The program should then display a square on the screen using the character ‘X’. 

The number entered by the user will be the length of each side of the square. 

For example, if the user enters 5, the program should display the following:
XXXXX
XXXXX
XXXXX
XXXXX
XXXXX

If the user enters 8, the program should display the following:
XXXXXXXX
XXXXXXXX
XXXXXXXX
XXXXXXXX
XXXXXXXX
XXXXXXXX
XXXXXXXX
XXXXXXXX
*/

#include <iostream>

int main(){
    int postive_integer{0};

    std::cout << "Input a postive integer no greater than 15: "; std::cin >> postive_integer;

    while(postive_integer>15 || postive_integer<1){
        std::cout << "Error: postive integer no greater than 15." << std::endl;
        std::cout << "Input a postive integer no greater than 15: "; std::cin >> postive_integer;
    }

    for(int i{0}; i<postive_integer; ++i){

        for(int it{0}; it<postive_integer; ++it){
            std::cout << "X";
        }
        std::cout << "\n";
    }
    
    return 0;
}
