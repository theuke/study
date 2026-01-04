#include <iostream>

#define LOG(x) std::cout << x << std::endl

// // Aliasing a variable
// int main()
// {
//     int a = 5;
//     int& ref = a;
//     ref = 2;
//     LOG(a);
//     std::cin.get();
// }

// // Pointer pass by reference
// void Increment(int *value)
// {
//     (*value)++;
// }

// int main()
// {
//     int a = 5;
//     Increment(&a);
//     LOG(a);
//     std::cin.get();
// }


// Reference pass by reference
//     - Using a reference is always preferable to using a pointer.
//     - References cannot be changed to "point" to another variable.
//     - Reference must be immediatley initialized.
//     - References are put syntax sugar. They get compiled away into regular pointers.
void Increment(int &value)
{
    value++;
}

int main()
{
    int a = 5;
    Increment(a);
    LOG(a);
    std::cin.get();
}