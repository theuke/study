#include <iostream>
#include <vector>

int main()
{
    auto square = [](int num){return num*num;};
    auto print = [](int s){std::cout << s << std::endl;};

    std::vector<int> values = { 0, 1, 2, 3, 4, 5 };

    for (int value : values)
        print(square(value));

}