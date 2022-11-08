#include <iostream>
#include <array>


int main(){

    std::array<int,10> scores;

    std::cout << "Scores: " << scores[0] << "\n";
    std::cout << "Scores: " << scores[1] << "\n";

    // Read an array with a loop
    for(unsigned int i{0}; i<10; ++i)
    {
        std::cout << "scores [" << i << "] : " << scores[i] << std::endl;
    }

    std::cout << "\n";
    scores[0]=20;
    scores[1]=21;
    scores[2]=22;
        // Read an array with a lool
    for(unsigned int i{0}; i<10; ++i)
    {
        std::cout << "scores [" << i << "] : " << scores[i] << std::endl;
    }

    std::cout << "\n";
    //Write data in a loop
    for(unsigned int i{0}; i<10; ++i)
    {
        scores[i] = i*10;
    }

    for(unsigned int i{0}; i<10; ++i)
    {
        std::cout << "scores [" << i << "] : " << scores[i] << std::endl;
    }

    std::cout << "\n";
    //Declare and initialize at the same time
    double salaries[5]{1000,2000,3000,4000,5000};

    for(unsigned int i{0}; i<5; ++i)
    {
        std::cout << "salaries [" << i << "] : " << salaries[i] << std::endl;
    }

    std::cout << "\n";
    int families[5] {12, 7, 5};
	
	for(size_t i{0}; i < 5; ++i){
		std::cout << "families[" << i << "] : " << families[i] << std::endl;
	}

    std::cout << "\n";
    //Omit the size of the array at declaration
    int class_sizes[]{10,12,15,11,18,17,23,56};

    // Will print this with a range based for loop
	for(auto value : class_sizes){
		std::cout << "value : " << value << std::endl;
	}

    return 0;
}