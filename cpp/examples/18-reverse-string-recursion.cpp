
// How can a given string be reversed using recursion?

#include <iostream>
#include <string>

std::string reverse( const std::string& str )
{
    std::string _str = str;
    if ( _str.size() > 1 )
        return reverse( _str.substr( 1, _str.size() - 1 ) ).append( _str.substr( 0, 1 ) );
    else return _str;
}

int main ()
{
    std::string my_str = "abcd";
    my_str = reverse( my_str );
    std::cout << my_str << std::endl;
}