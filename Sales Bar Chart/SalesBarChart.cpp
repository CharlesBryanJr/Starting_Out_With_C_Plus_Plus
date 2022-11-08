/*
Sales Bar Chart
Write a program that asks the user to enter today’s sales for five stores. 

The program should then display a bar graph comparing each store’s sales. 

Create each bar in the bar graph by displaying a row of asterisks. 

Each asterisk should represent $100 of sales.

Here is an example of the program’s output.
Enter today's sales for store 1: 1000 [Enter]
Enter today's sales for store 2: 1200 [Enter]
Enter today's sales for store 3: 1800 [Enter]
Enter today's sales for store 4: 800 [Enter]
Enter today's sales for store 5: 1900 [Enter]
SALES BAR CHART
(Each * = $100)
Store 1: **********
Store 2: ************
Store 3: ******************
Store 4: ********
Store 5: *******************
*/

#include <iostream>
#include <string.h>

int main(){
    // Write a program that asks the user to enter today’s sales for five stores. 
    double store1{0}, store2{0}, store3{0}, store4{0}, store5{0};
    std::string display_store1, display_store2, display_store3, display_store4, display_store5;

    std::cout << "Input today's sales for store 1: ";
    std::cin >> store1;
    for(int i{1}; i<store1/100; ++i){
        display_store1 = display_store1 + "*";
    }
    if(store1/100 == 1){
        display_store1 = display_store1 + "*";
    }

    std::cout << "Input today's sales for store 2: ";
    std::cin >> store2;
    for(int i{1}; i<store2/100; ++i){
        display_store2 = display_store2 + "*";
    }
    if(store2/100 == 1){
        display_store2 = display_store2 + "*";
    }


    std::cout << "Input today's sales for store 3: ";
    std::cin >> store3;
    for(int i{1}; i<store3/100; ++i){
        display_store3 = display_store3 + "*";
    }
    if(store3/100 == 1){
        display_store3 = display_store3 + "*";
    }


    std::cout << "Input today's sales for store 4: ";
    std::cin >> store4;
    for(int i{1}; i<store4/100; ++i){
        display_store4 = display_store4 + "*";
    }
    if(store4/100 == 1){
        display_store4 = display_store4 + "*";
    }


    std::cout << "Input today's sales for store 5: ";
    std::cin >> store5;
    for(int i{1}; i<store5/100; ++i){
        display_store5 = display_store5 + "*";
    }
    if(store5/100 == 1){
        display_store5 = display_store5 + "*";
    }

    // The program should then display a bar graph comparing each store’s sales. 
    // Create each bar in the bar graph by displaying a row of asterisks. 
    // Each asterisk should represent $100 of sales.
    std::cout << "\n";
    std::cout << "SALES BAR CHART" << "\n";
    std::cout << "(Each * = $100)" << "\n";

    std::cout << "Store 1: " << display_store1 << "\n";

    std::cout << "Store 2: " << display_store2 << "\n";

    std::cout << "Store 3: " << display_store3 << "\n";

    std::cout << "Store 4: " << display_store4 << "\n";

    std::cout << "Store 5: " << display_store5 << "\n";


    std::cout << "\n";
    return 0;
}
