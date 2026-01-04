#include <iostream>
#include <string>

// this keyword is a pointer to the object with which the method call was made.

void PrintEntity(Entity *e);

void PrintEntity(const Entity &e);

class Entity
{
public:
    int x, y;

    Entity(int x, int y)
    {
        // // This does nothing.
        // x = x;

        // Correct way.
        this->x = x;
        this->y = y;

        PrintEntity(this);

        PrintEntity(*this);

        // // Don't do this. You can, but don't.
        // delete this;
    }

    int GetX() const
    {
        // // Cannot do this since for const method "this" is a ponter to a constant value.
        // Entity *e = this;

        // Can do this
        const Entity *e = this;

        return x;
    }
};

void PrintEntity(Entity *e)
{
    // Print entity stuff.
}

int main()
{
    std::cin.get();
}