#include <iostream>

int main()
{
    int max;

    int a{35};
    int b{200};

    std::cout << std::endl;
    std::cout << "if statement" << std::endl;

    if (a>b){
        max = a;
        std::cout << "max: " << max << "\n";
    }else {
        max = b;
        std::cout << "max: " << max << "\n";
    }


    std::cout << "ternary operator" << "\n";

    int maximum = (a>b) ? maximum = a : maximum = b;

    std::cout << "maximum: " << maximum << "\n";



    std::cout << "ternary operator initialization" << "\n";

    int maximum1 { (a>b) ? maximum1 = a : maximum1 = b };

    std::cout << "maximum: " << maximum1 << "\n";

    return 0;
}
