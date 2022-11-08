/*
Rectangle Area

The program will ask the user to enter the width and length of a rectangle and then display the rectangle’s area. 

The program calls the following functions, which have not been written:

• getLength – This function should ask the user to enter the rectangle’s length and then return that value as a double.

• getWidth – This function should ask the user to enter the rectangle’s width and then return that value as a double .

• getArea – This function should accept the rectangle’s length and width as arguments and return the rectangle’s area. 
The area is calculated by multiplying the length by the width.

• displayData – This function should accept the rectangle’s length, width, and area as arguments and display them in an appropriate message on the screen.
*/

#include <iostream>

double getLength(){
    double length{0};
    std::cout << " " << "\n";
    std::cout << " --- getLength --- " << "\n";
    std::cout << "enter the rectangle's length: "; std::cin >> length;
    std::cout << "The rectangle's length is : " << length << "\n";
    return length;
}

double getWidth(){
    double width{0};
    std::cout << " " << "\n";
    std::cout << " --- getWidth --- " << "\n";
    std::cout << "enter the rectangle's width: "; std::cin >> width;
    std::cout << "The rectangle's width is : " << width << "\n";
    return width;
}

double getArea(double length1, double width1){
    double area{0};
    std::cout << " " << "\n";
    std::cout << " --- getArea --- " << "\n";
    area = length1*width1; // area = r0*r1
    std::cout << "The rectangle's area is : " << area << "\n";
    return area;
}

double displayData(double length11, double width11, double area11)
{
    std::cout << " " << "\n";
    std::cout << " --- displayData --- ";
    std::cout << "The rectangle's length is : " << length11 << " and the rectangle's width is : " << width11 << "\n";
    std::cout << "The rectangle's area is : " << area11 << "\n";
    return 0;
}


int main(){

    double r0{getLength()};

    double r1{getWidth()};

    double r2{getArea(r0,r1)};

    double r3{displayData(r0,r1,r2)};

    std::cout << " " << "\n";
    return 0;
}
