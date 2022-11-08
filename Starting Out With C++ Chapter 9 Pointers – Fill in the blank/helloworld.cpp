/*
Starting Out With C++ Chapter 9 Pointers – Fill in the blank
13. Each byte in memory is assigned a unique _____address_____.
14. The _____&_____ operator can be used to determine a variable’s address. 
15. _____pointer_____ variables are designed to hold addresses.
16. The _____* or indirection_____ operator can be used to work with the variable a pointer points to.
17. Array names can be used as _____pointers_____, and vice versa.
18. Creating variables while a program is running is called ____dynamic_memory_allocation______.
19. The _____new_____ operator is used to dynamically allocate memory.
20. Under older compilers, if the new operator cannot allocate the amount of memory requested, it returns ___0_______.
21. A pointer that contains the address 0 is called a(n) ____nullptr______ pointer.
22. When a program is finished with a chunk of dynamically allocated memory, it should free it with the ____delete______ operator.
23. You should only use pointers with delete that were previously used with ____new_operator____.
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>

int main()
{

	const int p_array_SIZE{10};	
    int array[p_array_SIZE]{1,2,3,4,5,6,7,8,9,10};
	int *p_array { new(std::nothrow) int[p_array_SIZE]{} };

    int ele;
	for(ele=0;ele<p_array_SIZE;++ele)
	{
		if(p_array) // *p_array[ele] != nullptr
		{
			std::cout << "Valid dynamically memory allocated array." << '\n';
			std::cout << "Element " << ele << ", equals " << p_array[ele] << '\n';
		}
	}
	delete[] p_array;
	p_array = nullptr;

	std::unique_ptr<int> ptr( new int );
	
	const int SIZE = 100;
	std::unique_ptr<int[]> ptr1( new int[SIZE] );

	
	return 0;
}