#include <iostream>

const double PI {3.1415926535897932384626433832795};

// constructors are used to initialize objects

class Cylinder{
    private:
        double base_radius{1};
        double height{1};

    public:
        Cylinder(){
            base_radius = 2.0;
            height = 2.0;
        }

        Cylinder(double base_radius_param, double height_param){
            base_radius = base_radius_param;
            height = height_param;
        }

        double volume(){
            return PI * base_radius * base_radius * height;
            }
};

int main(){

    Cylinder cylinder1;
    Cylinder cylinder2(3,3);

    std::cout << "volume: " << cylinder1.volume() << "\n";
    std::cout << "volume: " << cylinder2.volume() << "\n";

    return 0;
}
