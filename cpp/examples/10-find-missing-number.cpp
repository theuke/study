
// How do you find the missing number in a given integer array of 1 to 100?

#include <iostream>
#include <algorithm>

int arr[100];

int main()
{
    for( int i = 0; i < 100; ++i )
        arr[i] = i + 1;
    arr[49] = 0;

    //std::for_each(&arr[0], &arr[99], [](int el){std::cout << el << std::endl;});

    for (int _el : arr)
        std::cout << _el << std::endl;

    int* missing_num_location = std::find(&arr[0], &arr[99], 0);

    std::cout << std::endl << missing_num_location - &arr[0] <<std::endl;
}