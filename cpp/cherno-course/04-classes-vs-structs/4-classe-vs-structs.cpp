#include <iostream>

// For a struct the default element visibility is public. Struct is often used for just data.
// For a class the default element visibility is private.
class Player
{
public:
    int x, y;
    int speed;

    void Move(int xa, int ya)
    {
        x += xa * speed;
        y += ya * speed;
    }
};

// struct Player
// {
// private:
//     int x, y;
//     int speed;

// public:
//     void Move(int xa, int ya)
//     {
//         x += xa * speed;
//         y += ya * speed;
//     }
// };

int main()
{
    Player player;
    player.Move(1, -1);
    std::cin.get();
}