#include <iostream>
#include <string>

class Entity
{
private:
    std::string m_Name;

    // Mutable keyword makes it such that the variable is mutable within const methods.
    mutable int m_DebugCount = 0;
public:
    const std::string &GetName() const
    {
        // Cannot do this because this is a const method.
        // m_Name = "";

        // Can do this because m_DebugCount has been marked mutable.
        m_DebugCount++;

        return m_Name;
    }
};

int main()
{
    const Entity e;
    e.GetName();

    // Basic lambda with no args.
    auto f = []()
    {
        std::cout << "Hello" << std::endl;
    };

    int x = 8;
    auto f = [x]()
    {
        // Can't do this because lambdas are like const methods.
        // x++;
        std::cout << x << std::endl;
    };
    
    int y = 8;
    auto f = [y]() mutable
    {
        // this works because the lambda has been marked mutable. Note that y is passed
        // in by value, not reference, hence the real value of y does not change.
        y++;
        std::cout << y << std::endl;
    };

    std::cin.get();
}