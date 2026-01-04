// How do you check if two strings are anagrams of each other?

#include <iostream>
#include <string>
#include <algorithm>

std::string ana = "cinema";
std::string gram = "iceman";

int main ()
{
    std::sort(ana.begin(), ana.end());   //if this
    std::sort(gram.begin(), gram.end()); //equals this

    std::cout << (ana == gram) << std::endl;//we're good
}