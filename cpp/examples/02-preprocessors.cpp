#include <iostream>

#define LOG(x) std::cout << x << std::endl;

int main()
{
    char* buffer = new char[8];
    int a = 5;
    void* ptr = &a;
    LOG(*(int*)ptr);
    delete[] buffer;
}