#include <iostream>
#include <array>

class Entity
{
    static const int exampleSize = 5;
    int example[exampleSize];

    std::array<int, 5> another;

    Entity()
    {
        for (int i = 0; i < exampleSize; ++i)
            example[i] = 2;

        for (int i = 0; i < another.size(); ++i)
            another[i] = 2;
    }
};

int main()
{
    int example[5];
    example[0] = 2;
    example[4] = 4;

    // Prints address of array example.
    std::cout << example << std::endl;

    std::cout << example[0] << std::endl;

    // Out of bounds access.
    std::cout << example[5] << std::endl;

    for (int i = 0; i < 5; ++i)
        example[i] = 2;
    
    // Can access array elements via pointer arithmetic.
    int *ptr = example;
    *(ptr + 2) = 6;

    // Equivalent, but roundabout
    *((char *)ptr + 8) = 6;


    // Heap allocated array.
    int *another = new int[5];
    delete[] another;

    std::cin.get();
}