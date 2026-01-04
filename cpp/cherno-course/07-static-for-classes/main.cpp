#include <iostream>

// Static keyword in context of classes
//     - A static variable within a class means that there is only one instacne of that variable for the entire class.
//       No matter how many object isntancates are created from the class, there is only one instance of the variable.
//     - A static method does not have access to the class instance (object). Hence cannot refer to the
//       class instance (variables and methods) from within a static method.

// // Non-static variables
// struct Entity
// {
//     int x, y;

//     void Print()
//     {
//         std::cout << x << ", " << y << std::endl;
//     }
// };

// int main()
// {
//     Entity e;
//     e.x = 2;
//     e.y = 3;

//     Entity e1;
//     e1.x = 5;
//     e1.y = 8;

//     e.Print();
//     e1.Print();
//     std::cin.get();
// }


// // static variables
// struct Entity
// {
//     static int x, y;

//     void Print()
//     {
//         std::cout << x << ", " << y << std::endl;
//     }
// };

// int Entity::x;
// int Entity::y;

// int main()
// {
//     Entity e;
//     e.x = 2;
//     e.y = 3;

//     Entity e1;
//     Entity::x = 5;
//     Entity::y = 8;

//     e.Print();
//     e1.Print();
//     std::cin.get();
// }


// static variables and method
struct Entity
{
    static int x, y;

    static void Print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

int Entity::x;
int Entity::y;

int main()
{
    Entity e;
    Entity::x = 2;
    Entity::y = 3;

    Entity e1;
    Entity::x = 5;
    Entity::y = 8;

    Entity::Print();
    Entity::Print();
    std::cin.get();
}