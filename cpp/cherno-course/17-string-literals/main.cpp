#include <iostream>
#include <string>

#include <stdlib.h>

int main()
{
    const char *name = "Cherno";

    using namespace std::string_literals;

    std::u32string name0 = U"Cherno"s + U" hello";

    const char *name1 = u8"Cherno";

    const wchar_t *name2 = L"Cherno";

    const char16_t *name2 = u"Cherno";

    const char32_t *name2 = U"Cherno";

    // R stands for roll.
    const char *lines = R"(Line)"
"Line2)"
"Line3)";

    const char *lines = "(Line)\n"
    "Line2)\n"
    "Line3)";

    std::cin.get();
}