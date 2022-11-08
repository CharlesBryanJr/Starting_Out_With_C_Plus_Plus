/*
Characters for the ASCII Codes
Write a program that uses a loop to display the characters for the ASCII codes 0 through 127. 
Display 16 characters on each line.
*/

#include <iostream>

int main()
{
	//loop counter
	int i;
	
	for(i=0; i<128; i++)
		std::cout << "CHAR: " << (char)i << " ASCII: "<< i << '\n';
	
	return 0;
}



