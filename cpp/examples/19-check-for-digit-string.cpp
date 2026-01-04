// How do you check if a string contains only digits?

#include <iostream>
#include <string>
#include <algorithm>

std::string your_string = "012345678774829506432X";
std::string my_set      = "0123456789";
std::string::iterator it = my_set.begin();

auto main () -> int
{
    for ( auto el : your_string )
    {
        it = std::find( my_set.begin(), my_set.end(), el );
        if ( it ==  my_set.end())
            std::cout << "el out of set found" << std::endl;
    }
}