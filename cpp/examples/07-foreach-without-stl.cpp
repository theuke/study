#include <iostream>
#include <vector>

void Print(int s)
{
    std::cout << s << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int))
{
    for(int value : values) // this is called a range-based for loop, and I love it!  // https://www.cprogramming.com/c++11/c++11-ranged-for-loop.html
        func(value);
}

int main()
{
    std::vector<int> values = { 1, 2, 3, 4, 5, 6, 7, 8 };

    auto myfun = Print;

    ForEach(values, myfun);
}