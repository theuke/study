#include <iostream>
#include <string>

int main()
{
    // int is marked as const, but because it is on the stack that can be cast awawy.
    const int MAX_AGE = 90;

    // a is an int pointer  which can have both its value (address pointed to) and the value
    // of the address modified.
    int *a = new int;
    *a = 2;
    std::cout << *a << std::endl;
    a = (int *)&MAX_AGE;
    std::cout << *a << std::endl;

    // For variable declarations, if const appears before the * symbol then it applies to the value being pointd to.
    // Else, if it appears after the * symbol it applies to the pointer itself (i.e. can't reassign the pointer to point to a different address).

    // The value pointd to by the pointer cannot be changed.
    const int *b = new int;
    // Cannot do this.
    // *b = 2;
    std::cout << *b << std::endl;
    b = (int *)&MAX_AGE;
    std::cout << *b << std::endl;

    // The pointer itself cannot be changed.
    int *const c = new int;
    *c = 2;
    std::cout << *c << std::endl;
    // Cannot do this.
    // c = (int *)&MAX_AGE;
    std::cout << *c << std::endl;

    // The pointer itself cannot be changed.
    const int *const d = new int;
    // Cannot do this.
    // *d = 2;
    std::cout << *c << std::endl;
    // Cannot do this.
    // d = (int *)&MAX_AGE;
    std::cout << *d << std::endl;

    std::cin.get();
}