/*
22. isPrime Function
A prime number is a number that is only evenly divisible by itself and 1. 

For example, the number 5 is prime because it can only be evenly divided by 1 and 5. 

The number 6, however, is not prime because it can be divided evenly by 1, 2, 3, and 6.

Write a function name isPrime, which takes an integer as an argument and returns true if the argument is a prime number, or false otherwise. 

Demonstrate the function in a complete program.
*/
#include <iostream>

char inputValidation_y_or_n(char &letter)
{
    std::cin >> letter;

    while ( !(letter == 'y' || letter == 'n') )
    {
        std::cout << "ERROR: a 'y' or an 'n' must be entered: ";
        std::cin.clear();
        std::cin >> letter;
    }
    return letter;
}

double inputValidation_postiveInteger(int &postiveInteger)
{
    while( !(std::cin >> postiveInteger) || (postiveInteger<0) )
    {
        std::cout << "Input Validation: Must be a postive integer : ";
        std::cin.clear();
    }
    return postiveInteger;
}

bool isPrime(int &postiveInteger)
{
    for(int number{2}; number<10; ++number)
    {
        if ( postiveInteger % number == 0 )
        {
            if(postiveInteger != number)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
	char letter;
    //std::string TorF;
    int postiveInteger;

	 while(letter != 'n')
	{
        std::cout << " " << "\n";
        std::cout << "A prime number is a number that is only evenly divisible by itself and 1." << "\n";
        std::cout << "Input an postive integer : ";
            inputValidation_postiveInteger(postiveInteger);

        //std::cout << " " << "\n";
        //TorF = (isPrime(postiveInteger)) ? "IS a prime number" : "is NOT a prime number";
            //std::cout << TorF << "\n";
        
        std::cout << " " << "\n"; 
        std::cout << postiveInteger << ( (isPrime(postiveInteger)) ? " IS a prime number" : " is NOT a prime number" ) << "\n";
    
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		    inputValidation_y_or_n(letter);		

		std::cout << " " << "\n";
    }
	
	return 0;
}