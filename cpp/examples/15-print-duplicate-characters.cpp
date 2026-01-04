// How do you print duplicate characters from a string?

#include <iostream>
#include <string>
#include <set>

std::string my_string = "hello world";
std::string your_string = "bye world";
std::set<char> my_set;

auto main () -> int
{
    int i, j;
    for ( i = 0; i < my_string.size()-1; ++i )
        for ( j = i+1; j < my_string.size(); ++j )
            if ( my_string[i] == my_string[j] )
                my_set.insert(my_string[j]); // the loops find the duplicate elements and the set filters out ones we already have
    for ( char el : my_set )
        std::cout << el << std::endl;
}