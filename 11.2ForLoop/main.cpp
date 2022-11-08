#include <iostream>

int main()
{
    //Print I love C++ 10 times : The bad way
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "I love C++" << std::endl;
    std::cout << "End" << "\n";


    const unsigned int count{0};
    unsigned int x{10};
    for(; x>count; x--)
    {
        std::cout << "I love C++" << "\n";
    }
    std::cout << "End" << "\n";

    return 0;
}
