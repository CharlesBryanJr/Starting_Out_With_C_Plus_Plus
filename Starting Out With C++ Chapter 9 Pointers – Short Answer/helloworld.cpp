/*
Short Answer
1. What does the indirection operator do? 
dereferences a pointer's address to the value stored inside of the address that the pointer is pointing to.

2. Look at the following code.
int x = 7;
int *iptr = &x;
What will be displayed if you send the expression *iptr to cout? 
display 7
What happens if you send the expression ptr to cout ?
display the address of x.

3. So far you have learned three different uses for the * operator. What are they?
multiplication operator,
definition of a pointer variable
dereferencing a pointer variable

4. What math operations are allowed on pointers?
++ and −− operators may be used to increment or decrement a pointer variable. (address)
+ and − operators, or the += and −= operators, may be used to add or subtract an integer from a pointer variable. (value)
cannot multiply or divide a pointer.

5. Assuming that ptr is a pointer to an int, what happens when you add 4 to ptr ?
The value 16 is added to the memory address of ptr. 
4 * sizeof(int) = 4 * 4 = 16

6. Look at the following array definition.
int numbers[] = { 2, 4, 6, 8, 10 };
What will the following statement display?
cout << *(numbers + 3) << endl;
8

7. What is the purpose of the new operator?
To create dynamically allocated memory on the heap.

8. What happens when a program uses the new operator to allocate a block of memory, but the amount of requested memory isn’t available?
if new fails, it throws bad_alloc exception. 

How do programs written with older compilers handle this?
In older computers, new returns value 0

9. What is the purpose of the delete operator?
The delete operator is used to release / free up dynamically allocated memory on the heap.

10. Under what circumstances can you successfully return a pointer from a function?
If the address that the pointer is pointing to exist outside of the function.
When a pointer variable is passed into a function as a parameter
A pointer is indicated to dynamically allocated memory

11. What is the difference between a pointer to a constant and a constant pointer?
a pointer to a constant is a pointer that points to a address that stores a constant value. 

a constant pointer is a pointer that can only point to one address.

12. What are two advantages of declaring a pointer parameter as a constant pointer?
use a constant pointer parameter when the parameter will be initialized with the address that is passed as an argument into it.
use a constant pointer parameter when the functions is only supposed to point to one address.

*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>

int main()
{
    int numbers[] = { 2, 4, 6, 8, 10 };
    std::cout << *(numbers + 3) << std::endl;

    std::cout << "----------" << '\n';

    int n{0};
    int *n_ptr{&n};
    std::cout << n_ptr << '\n';
    std::cout << *n_ptr << '\n';

    n_ptr = n_ptr + 4;

    std::cout << n_ptr << '\n';
    std::cout << *n_ptr << '\n';

    *n_ptr = *n_ptr + 4;

    std::cout << n_ptr << '\n';
    std::cout << *n_ptr << '\n';

    return 0;
}