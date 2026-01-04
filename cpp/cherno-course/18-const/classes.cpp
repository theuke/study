#include <iostream>
#include <string>

class Entity
{
private:
    int *m_X;
    int m_Y;
    int m_Z;
    int m_V;
    int m_W;

    // Mutable keyword makes it such that the variable is mutable within const methods.
    mutable int var;

public:

    // A method can be marked as constant by including cosnt after the method signature.
    // A const method enforces that the class's member variables will not be modified.
    // Additionally, if a method can be marked const, then always do so. If you don't then that
    // method will not be able to be called if someone has a reference or pointer to a const object.
    int GetY() const
    {
        // Cannot do this
        // m_Y = 2;
        return m_Y; 
    }

    int SetY(int y)
    {
        m_Y = y;
    }

    // This method ensures that the member variables of the class cannot be modified
    // and that the returned value is a constant pointer to a constant int.
    const int *const GetX() const
    {
        // Can do this
        // *m_X = 2;

        // Cannot do this
        // m_X = &m_Y;

        return m_X;
    }

    int GetZ()
    {
        // m_Z = 2;
        return m_Z; 
    }

    // We can overload the GetV() method so there is a const and non-const variant.
    // In general, try to avoid this design pattern.
    int GetV()
    {
        return m_V;
    }

    int GetV() const
    {
        return m_V;
    }

    // This works sinec var is mutable.
    int GetW() const
    {
        var = 10;
        return m_W;
    }
};

// // This works fine.
// void PrintEntity(Entity e)
// {
//     std::cout << e.GetX() << std::endl;
// }

// // This works fine.
// void PrintEntity(Entity &e)
// {
//     // This works becaues the entity itself is being re-assigned.
//     e = Entity();
//     std::cout << e.GetX() << std::endl;
// }

// This does not work.
void PrintEntity(const Entity &e)
{
    // This does not work becaues the reference has been marked constant. Similiar behavioru as const pointers.
    // e = Entity();
    std::cout << e.GetX() << std::endl;

    // This is ensured to work becaues although e is a constant reference to an Entity, the GetY() method has been marked as const. 
    std::cout << e.GetY() << std::endl;

    // Cannot do this because the entity itself is marked as const, but the GetZ() method
    // modifies the member variables of the class. Note it doesn't matter whether GetZ() actually modifies the object.
    // All that matters is that it CAN modify the object, thus it is not allowed to be called for a const entitty.
    // Naturally, this means this is a compile time check.
    std::cout << e.GetZ() << std::endl;

    // This works because there is both a const and non-const version of GetV().
    std::cout << e.GetV() << std::endl;

    // This works becaues GetW() only modifies a mutable member variable.
    std::cout << e.GetW() << std::endl;
}

int main()
{
    Entity e;
    PrintEntity(e);
    std::cin.get();
}