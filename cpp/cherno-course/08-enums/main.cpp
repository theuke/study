#include <iostream>

// // By default an enum is an int, but it can be assigned to any non-float / non-double data type smaller than an int.
// // Additionally, enums by default always start at 0.
// enum Example : unsigned char
// {
//     // A, B, C
//     // A = 5, B, C
//     A = 0, B, C
// };

// int main()
// {
//     Example value = B;

//     if (value == 1)
//     {
//         // Do something here
//     }

//     std::cin.get();
// }


class Log
{
public:
    enum Level
    {
        LevelError = 0, LevelWarning, LevelInfo
    };

private:
    Level m_LogLevel;

public:
    void SetLevel(Level level)
    {
        m_LogLevel = level;
    }

    void Error(const char *message)
    {
        if(m_LogLevel >= LevelError)
            std::cout << "[ERROR]: " << message << std::endl;
    }

    void Warn(const char *message)
    {
        if(m_LogLevel >= LevelWarning)
            std::cout << "[WARNING]: " << message << std::endl;
    }

    void Info(const char *message)
    {
        if(m_LogLevel >= LevelInfo)
            std::cout << "[INFO]: " << message << std::endl;
    }
};

int main()
{
    Log log;
    log.SetLevel(Log::LevelError);
    log.Warn("Hello");
    log.Error("Hello");
    log.Info("Hello");
    std::cin.get();
}