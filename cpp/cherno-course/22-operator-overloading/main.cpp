#include <iostream>
#include <string>

// Operators (like +, *, derefernce, etc...) are really just functions, and in C++ they can be overloaded.
// A good rule of them is if people need to look up what your operator does then that is a bad use of operator overloading.

struct Vector2
{
    float x, y;
    Vector2(float x, float y)
        : x(x), y(y) {}
    
    Vector2 Add(const Vector2 &other) const
    {
        return Vector2(x + other.x, y + other.y);

        // // The below two are both valid when the "logic" of the Add is defined
        // // in the operator funcion itself. The second is seldom used, but the point is
        // // that the + operator really is just a function.
        // return *this + other;
        // return operator+(other);
    }

    Vector2 operator+(const Vector2 &other) const
    {
        // Always use this design pattern as it is cleanest. Always have an actual Add function and
        // if overloading an operator, just call the underlying function and that's it. Wrapper approach here is best.
        return Add(other);
    }

    Vector2 Multiply(const Vector2 &other) const
    {
        return Vector2(x * other.x, y * other.y);
    }

    Vector2 operator*(const Vector2 &other) const
    {
        // Always use this design pattern as it is cleanest. Always have an actual Add function and
        // if overloading an operator, just call the underlying function and that's it. Wrapper approach here is best.
        return Multiply(other);
    }

    bool operator==(const Vector2 &other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2 &other) const
    {
        return !(*this == other);
    }
};


// Overloads the << operator in the std::ostream class. We define an overload for the
// operator which takes in an ostream (since that is what std::cout is) and then a Vector2.
// Note this overloading has nothing to do with the Vector2 class, but has to do with the ostream class.
std::ostream &operator<<(std::ostream &stream, const Vector2 &other)
{
    stream << other.x << ", " << other.y;
}

int main()
{
    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 powerup(1.1f, 1.1f);

    // This is valid, but hard to read.
    Vector2 result1 = position.Add(speed.Multiply(powerup));

    // This is valid and easier to read. Note that due to operator precedence the multiplication is evaluated before the addition.
    Vector2 result2 = position + speed * powerup;

    if (result1 == result2)
    {
        // Do something
    }

    // Works becaues the ostream << operator was overloaded.
    std::cout << result2 << std::endl;

    std::cin.get();
}