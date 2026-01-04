#include <iostream>

class Entity
{
// The defautl visibility for classes is private and for structs its public.
private:
    int x, y;

// Protected means that the class and all of its subclasses (e.g. Player) can access the symbols.
protected:
    int speed;

// The members of public can be accessed anywhere
public:
    void Print()
    {
        std::cout << x << ", " << y << std::endl;
    }
};

class Player : public Entity
{
public:
    Player()
    {
        // Can't access X because its private.
        // X = 2;

        speed = 5;
        Print();
    }
};

int main()
{
    std::cin.get();
}