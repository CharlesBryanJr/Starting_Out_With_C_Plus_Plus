// This program demonstrates a simple class.
#include <iostream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <cctype>
#include <cstring>
#include <string>
#include <cstdlib>

// Rectangle class declaration.
class Rectangle
{
    private:
        double width;
        double length;
    
    public:
        void setWidth(double);
        void setLength(double);
        double getWidth() const;
        double getLength() const;
        double getArea() const;
};

//**************************************************
// setWidth assigns a value to the width member. *
//**************************************************
void Rectangle::setWidth(double w)
{
    width = w;
}

//***************************************************
// setLength assigns a value to the length member. *
//***************************************************

void Rectangle::setLength(double len)
{
    length = len;
}

//***************************************************
// getWidth returns the value in the width member. *
//***************************************************

double Rectangle::getWidth() const
{
    return width;
}

//****************************************************
// getLength returns the value in the length member. *
//****************************************************
double Rectangle::getLength() const
{
    return length;
}

//******************************************************
// getArea returns the product of width times length. *
//******************************************************

double Rectangle::getArea() const
{
    return width * length;
}

//*****************************************************
// Function main *
//*****************************************************
int main()
{
    Rectangle box; // Define an instance of the Rectangle class
    double rectWidth; // Local variable for width
    double rectLength; // Local variable for length

    // Get the rectangle's width and length from the user.
    std::cout << "This program will calculate the area of a rectangle. What is the width? : ";
        std::cin >> rectWidth;
    
    std::cout << "What is the length? ";
        std::cin >> rectLength;

    // Store the width and length of the rectangle in the box object.
    box.setWidth(rectWidth);
    box.setLength(rectLength);

    // Display the rectangle's data.
    std::cout << "Here is the rectangle's data:\n";
    std::cout << "Width: " << box.getWidth() << std::endl;
    std::cout << "Length: " << box.getLength() << std::endl;
    std::cout << "Area: " << box.getArea() << std::endl;
    return 0;
}