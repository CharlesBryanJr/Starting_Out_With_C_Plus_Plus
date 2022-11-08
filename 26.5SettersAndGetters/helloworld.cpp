#include <iostream>

const double PI {3.1415926535897932384626433832795};

class Cylinder{
    //Member variables
    private:
        double base_radius{1.0};
        double height{1.0};

    public:
        //Constctors
        Cylinder() = default;

        Cylinder(double base_radius_param, double height_param){
            base_radius = base_radius_param;
            height = height_param;
        }

        //Getter methods
        double get_base_radius(){
            return base_radius;
        }
        double get_height(){
            return height;
        }

        //Setter methods
        void set_base_radius(double base_radius_param){
            base_radius = base_radius_param;
        }

        void set_base_height(double height_param){
            height = height_param;
        }

        //Functions (methods)
        double volume(){
            return PI * base_radius * base_radius * height;
            }
};

int main(){

    Cylinder cylinder1(11.1,22.2);
    std::cout << cylinder1.get_base_radius() << "\n";
    std::cout << cylinder1.get_height() << "\n";
    std::cout << "volume: " << cylinder1.volume() << "\n";

    //Modify our object
    cylinder1.set_base_radius(55.5);
    cylinder1.set_base_height(33.3);
    std::cout << cylinder1.get_base_radius() << "\n";
    std::cout << cylinder1.get_height() << "\n";
    std::cout << "volume: " << cylinder1.volume() << "\n";

    return 0;
}
