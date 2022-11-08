/*
Starting Out With C++ Chapter 9 Pointers – 5. Pointer Rewrite
The following function uses reference variables as parameters. 
Rewrite the function so it uses pointers instead of reference variables, and then demonstrate the function in a complete program.

int doSomething(int &x, int &y)
{
int temp = x;
x = y * 10;
y = temp * 10;
return x + y;
}
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
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

int doSomething_ref(int &x, int &y)
{
    int temp = x;
    x = y * 10;
    y = temp * 10;
    return x + y;
}

int doSomething_ptr(int *ptr_x, int *ptr_y)
{
    int temp = *ptr_x;
    *ptr_x = *ptr_y * 10;
    *ptr_y = temp * 10;
    return *ptr_x + *ptr_y;
}

int main()
{
	char letter;
    int ele,
        x{13},
        y{33};
    int *ptr_x{&x},
        *ptr_y{&y};

	while(letter != 'n')
	{
        //std::cout << "reference variables : " << doSomething_ref(x,y) << "\n";
        std::cout << "pointers : " << doSomething_ptr(ptr_x,ptr_y) << "\n";
	
		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
			inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}