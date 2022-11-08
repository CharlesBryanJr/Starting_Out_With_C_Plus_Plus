
// 5.6 Name the three expressions that appear inside the parentheses in the for loop’s header.
// 5.7 You want to write a for loop that displays “I love to program” 50 times. Assume that you will use a counter variable named count .
// A) What initialization expression will you use? unsigned int i{0}
// B) What test expression will you use? i<50
// C) What update expression will you use? ++i
// D) Write the loop. for(unsigned int i{0},i<50,++i)

/*

5.9 Write a for loop that displays your name 10 times.
for (int i{0}; i < 10; ++i){
    std::cout << "Charles" << '\n';
}

5.10 Write a for loop that displays all of the odd numbers, 1 through 49.
for (int i{0}; i < 49; ++i){
    if(i%2 ==0){
        std::cout << i << '\n';
    }
}

#include <iostream>

int main(){
    // 5.11 Write a for loop that displays every fifth number, zero through 100.
    
    for (int i{0}; i < 100; ){
        std::cout << i << '\n';
        i = i+5;
    }

    return 0;
}

*/

#include <iostream>
#include <fstream>

int main(){
    // 5.12 Write a for loop that repeats seven times, asking the user to enter a number. The loop should also calculate the sum of the numbers entered.
    int n{0};
    int m{0};
    for (int i{0}; i < 7; ++i){
        std::cout << "enter a number" << '\n';
        std::cin >> n;
        m = m+n;
        std::cout << '\n';
    }
    std::cout << m << '\n';

    return 0;
}




