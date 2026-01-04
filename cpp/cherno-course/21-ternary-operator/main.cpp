#include <iostream>
#include <string>

static int s_Level = 1;
static int s_Speed = 2;

int main()
{
    // Equivalent statements but ternary operator is cleaner.
    if (s_Level > 5)
        s_Speed = 10;
    else
        s_Speed = 5;

    s_Speed = s_Level > 5 ? 10 : 5;


    // Functionally equivalent, but ternary option is slightly better because it does not create an extra empty string object.
    std::string rank = s_Level > 10 ? "Master" : "Beginner";

    std::string otherRank;
    if (s_Level > 5)
        otherRank = "Master";
    else
        otherRank = "Beginner";


    // Ternary operators can be nested.
    s_Speed = s_Level > 5 ? s_Level > 10 ? 15 : 10 : 5;

    std::cin.get();
}