// How do you find the duplicate number on a given integer array?

#include <iostream>
#include <algorithm>

// core search algorithm
int find_max (int* _counter)
{
    int i;
    for ( i = 0; i < 100; ++i )
        if (_counter[i] >= 2) break;
    return i;
};

int main()
{
    // generate valid test case relevant to problem statement
    int list[100];
    for ( int i = 0; i < 100; ++i )
        list[i] = i + 1;
    list[50] = 50;

    // initialize a counter array that will help us find duplicate entries
    int counter[100];
    for ( int el : counter )
        el = 0;

    // create an array to implement a hash table where the positions are the key and the number of occurrences is the value
    for ( int i = 0; i < 100; ++i)
        counter[ list[i] - 1 ]++; // assumes entries in list are in the closed set [1, 100]
    
    // find the repeated number. the algorithm returns the *last* occurrence of this
    std::cout << find_max(counter) << std::endl;
}