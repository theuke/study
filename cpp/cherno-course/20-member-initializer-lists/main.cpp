#include <iostream>
#include <string>

class Example
{
public:
    Example()
    {
        std::cout << "Created Entity!" << std::endl;
    }

    Example(int x)
    {
        std::cout << "Created Entity with " << x << "!" << std::endl;
    }
};

class Entity
{
private:
    std::string m_Name;
    int x, y, z;
    Example m_Example;
public:
    // // Bad member initialization. Initializing member variables in the consturcure in this way
    // // results in two copies of each non primitive member being created. In this case, that is m_Name.
    // // In this case the default constructor is invoked for m_Name() and then that gets overriden
    // // with std::string("Unknown"). This is wasteful and just bad practice.
    // Entity()
    // {
    //     // Note that the below two lines are equivalent. C++ execute the code as if it was the commented out line shown below.
    //     // m_Name = std::string("Unknown");
    //     m_Name = "Unknown";
    //     x = 0;
    //     y = 0;
    //     z = 0;

    //     m_Example = Example(8);
    // }

    // Good member initailization. Gauranteed to result in only one copy of each member variable being created.
    // Note that the member variables will be initailized in their order of apperance within the class defintion,
    // not the in the order used in the constructor. Hence, always initialize member variables in their natural order.
    Entity()
        : m_Name("Unknown"), x(0), y(0), z(0), m_Example(8)
    {
    }

    Entity(const std::string &name)
    {
        m_Name = name;
    }

    const std::string &GetName() const { return m_Name; }
};

int main()
{
    Entity e0;
    std::cout << e0.GetName() << std::endl;

    Entity e1("Cherno");
    std::cout << e1.GetName() << std::endl;

    Entity e2;

    std::cin.get();
}