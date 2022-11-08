/*
Pattern Displays
Write a program that uses a loop to display Pattern A below, followed by another loop that displays Pattern B.
Pattern A Pattern B
+ ++++++++++
++ +++++++++
+++ ++++++++
++++ +++++++
+++++ ++++++
++++++ +++++
+++++++ ++++
++++++++ +++
+++++++++ ++
++++++++++ +

*/

#include <iostream>

int main(){
    std::string pattern;

    for(int a{0}; a<10; ++a){
    
        for(int b{0}; b<1; ++b){
            pattern = pattern + "X";
            std::cout << pattern << "\n";
        }

    }

    return 0;
}
