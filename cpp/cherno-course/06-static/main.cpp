#include <iostream>
#include "static.h"

// Static keyword
//     - When used outside of a class this makes the entity local to the file (translation unit)
//     - When used inside of a class it means the entity is a class level entity (as opposed to object level)
//       and is therefore shared between all instances object instances of the class.

int s_Variable = 10;

int main()
{
    std::cout << s_Variable << std::endl;
    std::cin.get();
}