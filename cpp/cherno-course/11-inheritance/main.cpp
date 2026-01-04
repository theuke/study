#include <iostream>

class Entity
{
public:
    float X, Y;

    void Move(float xa, float ya)
    {
        X += xa;
        Y += ya;
    }
};

class Player : public Entity
{
public:
    const char *Name;

    void PrintName()
    {
        std::cout << Name << std::endl;
    }
};

int main()
{
    // Expected to be 8 bytes.
    std::cout << sizeof(Entity) << std::endl;

    // Expected to be 8 + 8 (pointer is 8 bytes) = 16 bytes.
    std::cout << sizeof(Player) << std::endl;

    // Player can access all public member variables and methods directly, just as if it was an instance of Entity.
    Player player;
    player.Move(5, 5);
    player.X = 2;


    std::cin.get();
}