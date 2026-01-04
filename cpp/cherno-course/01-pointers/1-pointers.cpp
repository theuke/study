#include <iostream>
#include <cstring>

#define LOG(x) std::cout << x << std::endl

int main()
{
    // Stack allocation
    // int var = 8;
    // int *ptr = &var;
    // *ptr = 10;
    // LOG(var);

    // Heap allocation
    // char *buffer = new char[8];
    // memset(buffer, 0, 8);
    // delete[] buffer;

    // Heap allocation
    char *buffer = new char[8];
    memset(buffer, 0, 8);
    char **ptr = &buffer;
    delete[] buffer;


    std::cin.get();
}