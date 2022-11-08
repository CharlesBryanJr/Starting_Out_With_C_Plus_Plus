/*
Population Bar Chart
Write a program that produces a bar chart showing the population growth of Prairieville, a small town in the Midwest, at 20-year intervals during the past 100 years.

The program should read in the population figures (rounded to the nearest 1,000 people) for 1900, 1920, 1940, 1960, 1980, and 2000 from a file.

For each year it should display the date and a bar consisting of one asterisk for each 1,000 people. 

The data can be found in the People.txt file.

Here is an example of how the chart might begin:
PRAIRIEVILLE POPULATION GROWTH
(each * represents 1,000 people)
1900 **
1920 ****
1940 *****
*/

#include <iostream>
int pop_1900{0}, pop_1920{0}, pop_1940{0}, pop_1960{0}, pop_1980{0}, pop_2000{0};
std::string display_pop_1900, display_pop_1920, display_pop_1940, display_pop_1960, display_pop_1980, display_pop_2000;

int main(){

    std::cout << "Input the Population for year 1900: "; std::cin >> pop_1900;
    for(int i{1}; i<pop_1900/1000; ++i){
        display_pop_1900 = display_pop_1900 + "*";
    }
    if(pop_1900/1000 == 1){
         display_pop_1900 = display_pop_1900 + "*";
    }

    std::cout << "Input the Population for year 1920: "; std::cin >> pop_1920;
    for(int i{1}; i<pop_1920/1000; ++i){
        display_pop_1920 = display_pop_1920 + "*";
    }
    if(pop_1920/1000 == 1){
         display_pop_1920 = display_pop_1920 + "*";
    }

    std::cout << "Input the Population for year 1940: "; std::cin >> pop_1940;
    for(int i{1}; i<pop_1940/1000; ++i){
        display_pop_1940 = display_pop_1940 + "*";
    }
    if(pop_1940/1000 == 1){
         display_pop_1940 = display_pop_1940 + "*";
    }

    std::cout << "Input the Population for year 1960: "; std::cin >> pop_1960;
    for(int i{1}; i<pop_1960/1000; ++i){
        display_pop_1960 = display_pop_1960 + "*";
    }
    if(pop_1960/1000 == 1){
         display_pop_1960 = display_pop_1960 + "*";
    }

    std::cout << "Input the Population for year 1980: "; std::cin >> pop_1980;
    for(int i{1}; i<pop_1980/1000; ++i){
        display_pop_1980 = display_pop_1980 + "*";
    }
    if(pop_1980/1000 == 1){
         display_pop_1980 = display_pop_1980 + "*";
    }

    std::cout << "Input the Population for year 2000: "; std::cin >> pop_2000;
    for(int i{1}; i<pop_2000/1000; ++i){
        display_pop_2000 = display_pop_2000 + "*";
    }
    if(pop_1900/1000 == 1){
         display_pop_2000 = display_pop_2000 + "*";
    }

    std::cout << "PRAIRIEVILLE POPULATION GROWTH" << "\n" << "(each * represents 1,000 people)";
    std::cout << "\n";

    std::cout << "the Population for year 1900: " << display_pop_1900 << "\n";
    std::cout << "the Population for year 1920: " << display_pop_1920 << "\n";
    std::cout << "the Population for year 1940: " << display_pop_1940 << "\n";
    std::cout << "the Population for year 1960: " << display_pop_1960 << "\n";
    std::cout << "the Population for year 1980: " << display_pop_1980 << "\n";
    std::cout << "the Population for year 2000: " << display_pop_2000 << "\n";

    std::cout << "\n";

    return 0;
}
