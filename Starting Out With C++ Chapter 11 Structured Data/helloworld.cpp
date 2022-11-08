// --- Starting Out With C++ Chapter 11 Structured Data ---

#include <iostream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <cctype>
#include <cstring>
#include <string>
#include <cstdlib>
#include <limits>

    struct Rectangle
    {
        int length;
        int width;
    };

    Rectangle pool{ 10, 10 };

    // 11.11 Write a function that accepts a Rectangle structure as its argument and displays the structure's contents on the screen.
    void displayRectangle(const Rectangle &r)
    {
        std::cout << r.length << '\n';
        std::cout << r.width << '\n';
    }

    void displayRectangle(const Rectangle *r_ptr)
    {
        std::cout << (*r_ptr).length << '\n';
        std::cout << (*r_ptr).width << '\n';
    }

    // 11.12 Write a function that uses a Rectangle structure reference variable as its parameter and stores the user’s input in the structure’s members.
    void getRectangle(Rectangle &r)
    {
        std::cout << "User, input a length : ";
            std::cin >> r.length;

        std::cout << "User, input a width : ";
            std::cin >> r.width;
    }

    // 11.13 Write a function that returns a Rectangle structure. 
    // The function should store the user’s input in the members of the structure before returning it.
    Rectangle returnRectangle(Rectangle &r)
    {
        getRectangle(r);
        return r;
    }

    // 11.16 Declare a union named ThreeTypes with the following members:
    // letter: A character
    // whole: An integer
    // real: A double

    union ThreeTypes
    {
        char letter;
        int whole;
        double real;
    };

    // 11.17 Write the definition for an array of 50 of the ThreeTypes structures you declared in Question 11.16.
    ThreeTypes a[50];


int main()
{
    /*
    11.1 Write a structure declaration to hold the following data about a savings account:
    Account Number ( string object)
    Account Balance ( double )
    Interest Rate ( double )
    Average Monthly Balance ( double )
    */
    
    struct SavingAccount
    {
        std::string accountNumber;
        double accountBalance;
        double interestRate;
        double averageMonthlyBalance;
    };

    /*
    11.2 Write a definition statement for a variable of the structure you declared in Question 11.1. 
    Initialize the members with the following data:
    Account Number: ACZ42137-B12-7
    Account Balance: $4512.59
    Interest Rate: 4%
    Average Monthly Balance: $4217.07
    */

    SavingAccount collegeFund{"ACZ42137-B12-7", 4512.59, 0.04, 4217.07};

    /*
    11.3 The following program skeleton, when complete, asks the user to enter these data about his or her favorite movie:
    Name of movie
    Name of the movie’s director
    Name of the movie’s producer
    The year the movie was released
    Complete the program by declaring the structure that holds this data, defining a structure variable, and writing the individual statements necessary.
    */

    // define the structure variable here.
    struct Movie
    {
        std::string movieName;
        std::string movieDirector;
        std::string movieProducer;
        int movieRelasedYear;
    };

    Movie favoriteMovie;

    std::cout << "Enter the following data about your favorite movie.\n";

    // Write a statement here that lets the user enter the name of a favorite movie. 
    // Store the name in the structure variable.
    std::cout << "name: ";
        std::cin.ignore();
        std::getline(std::cin,favoriteMovie.movieName);

    // Write a statement here that lets the user enter the name of the movie's director.
    // Store the name in the structure variable.
    std::cout << "Director: ";
        //std::cin.ignore();
        std::getline(std::cin,favoriteMovie.movieDirector);

    // Write a statement here that lets the user enter the name of the movie's producer. 
    // Store the name in the structure variable.
    std::cout << "Producer: ";
        //
        std::cin.ignore();
        std::getline(std::cin,favoriteMovie.movieProducer);

    // Write a statement here that lets the user enter the year the movie was released. 
    // Store the year in the structure variable.
    std::cout << "Year of release: ";
        std::cin >> favoriteMovie.movieRelasedYear;

    // Write statements here that display the data.
    std::cout << "Here is data on your favorite movie:\n";

    std::cout << favoriteMovie.movieName << '\n';
    std::cout << favoriteMovie.movieDirector << '\n';
    std::cout << favoriteMovie.movieProducer << '\n';
    std::cout << favoriteMovie.movieRelasedYear << '\n';

    std::cout << "-------Test Driven Development-------"; std::cout << " " << "\n";
    std::cout << "-------Test Driven Development-------"; std::cout << " " << "\n";
    std::cout << "-------Test Driven Development-------"; std::cout << " " << "\n";

    struct Product
    {
        std::string description; // Product description
        int partNum; // Part number
        double cost; // Product cost
    };

    // 11.4 Write a definition for an array of 100 Product structures. Do not initialize the array.
    unsigned int sizeOfArray{100};
    Product toys[sizeOfArray];

    // 11.5 Write a loop that will step through the entire array you defined in Question 11.4, setting all the product descriptions to an empty string, all part numbers to zero, and all costs to zero.
    for(unsigned int ele{0}; ele<sizeOfArray; ++ele)
    {
        toys[ele].description = "";
        toys[ele].partNum = 0;
        toys[ele].cost = 0;
    }

    // 11.6 Write the statements that will store the following data in the first element of the array you defined in Question 11.4:
    toys[0].description = "Claw hammer";
    toys[0].partNum = 547;
    toys[0].cost = 8.29;
    
    // 11.7 Write a loop that will display the contents of the entire array you created in Question 11.4.
    for(unsigned int ele{0}; ele<sizeOfArray; ++ele)
    {
        std::cout << toys[ele].description << '\n';
        std::cout << toys[ele].partNum << '\n';
        std::cout << toys[ele].cost << '\n';
    }

    // 11.8 Write a structure declaration named Measurement , with the following members: miles, an integer meters, a long integer
    struct Measurement
    {
        int miles;
        long int meters;
    };

    // 11.9 Write a structure declaration named Destination , with the following members: city, a string object distance, a Measurement structure (declared in Question 11.8)
    struct Destination
    {
        std::string city;
        Measurement distance;
    };

    Destination nashville;

    // 11.10 Write statements that store the following data in the variable you defined in Question 11.9:
    // City: Tupelo
    // Miles: 375
    // Meters: 603,375

    nashville.city = "Tupelo";
    nashville.distance.miles = 375;
    nashville.distance.meters = 603375;

    std::cout << "-------Test Driven Development-------"; std::cout << " " << "\n";
    std::cout << "-------Test Driven Development-------"; std::cout << " " << "\n";
    std::cout << "-------Test Driven Development-------"; std::cout << " " << "\n";

    displayRectangle(pool);

    // 11.14 Write the definition of a pointer to a Rectangle structure.
    Rectangle *ptrRectangle{nullptr};
        ptrRectangle = new Rectangle;

    *ptrRectangle = returnRectangle(pool);

    displayRectangle(ptrRectangle);

    std::cout << "-------Test Driven Development-------"; std::cout << " " << "\n";
    std::cout << "-------Test Driven Development-------"; std::cout << " " << "\n";
    std::cout << "-------Test Driven Development-------"; std::cout << " " << "\n";

    // 11.18 Write a loop that stores the floating point value 2.37 in all the elements of the array you defined in Question 11.17.
    for(unsigned int ele{0}; ele<50; ++ele)
    {
        a[ele].real = 2.37;
    }

    // 11.19 Write a loop that stores the character ‘A’ in all the elements of the array you defined in Question 11.17.
    for(unsigned int ele{0}; ele<50; ++ele)
    {
        a[ele].letter = 'A';
    }

    // 11.20 Write a loop that stores the integer 10 in all the elements of the array you defined in Question 11.17.
    for(unsigned int ele{0}; ele<50; ++ele)
    {
        a[ele].whole = 10;
    }

    enum Color {red,green,blue};
    Color c;
    c = red;
    c = static_cast<Color>(c+1);

    return 0;
}