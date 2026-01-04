#include <iostream>

class Entity
{
public:
    float X, Y;

    // Under the hood a default constructor is always present, however it literaly does nothing.
    // Unlike Java which iniitializes primitive types to 0, C++ does nothing.
    Entity()
    {
        X = 0.0f;
        Y = 0.0f;
    }

    Entity(float x, float y)
    {
        X = 0.0f;
        Y = 0.0f;
    }

    void Print()
    {
        std::cout << X << ", " << Y << std::endl;
    }
};

int main()
{
    Entity e;
    e.Print();

    // If vars not initialized, will not compile due to use of uninitialzied local variables.
    // std::cout << e.X << ", " << e.Y << std::endl;

    Entity e1(10.0f, 5.0f);
    e1.Print();

    std::cin.get();
}

// If my entire class is logically "static" and I only want users to invoke the methods like Log::Write()
// and not be able t create instance variables, then there are two ways to accomplish this.
class Log
{
// Method 1: make default constructor private.
private:
    Log() {}

public:
    // Method 2: Delete the default consturctor.
    Log() = delete;

    static void Write()
    {
        
    }
};