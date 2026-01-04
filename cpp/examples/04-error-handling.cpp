#include <iostream>
#include <string>
using String = std::string;

int main () {
    try {
        String my_str = "Yikes";
        throw my_str;
    }
    catch (String e) {
        std::cout
        << "Int exception thrown "
        << e
        << std::endl;
    }
}