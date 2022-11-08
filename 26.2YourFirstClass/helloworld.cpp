#include <iostream>

const double PI{3.1415926535897932384626433832795};

class Cylinder{
    // Member variables
    private:
    public:
        double base_radius{1};
        double height{1};

    // Member Methods/Funcitons
    private:
    public:
        double volume(){
            return PI * base_radius * base_radius * height;
            }
};


int main(){
    
    Cylinder cylinder1;
    std::cout << cylinder1.volume() << "\n";

    cylinder1.base_radius =10;
    cylinder1.height =3;
    std::cout << cylinder1.volume() << "\n";


    return 0;
}
