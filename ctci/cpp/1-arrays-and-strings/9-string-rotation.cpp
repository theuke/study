/* String Rotation:
 * Assume that you have a method isSubstring which checks if one word is a substring of another.
 * Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using only one call to isSubstring
 * (e.g., "waterbottle" is a rotation of "erbottlewat").
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>

class Solution {
public:
    bool isRotation(const char *s1, const char *s2) {
        const int s1_len = strlen(s1);

        if (s1_len != strlen(s2)) return false;

        char *s1s1 = new char[s1_len + s1_len + 1];
        strcpy(s1s1, s1);
        strcpy(s1s1 + s1_len, s1);

        return strstr(s1s1, s2) != NULL;
    }
};

struct TestCase {
    const char *s1;
    const char *s2;
    const bool output;
};

int main() {
    Solution solution;
    std::vector<TestCase> cases = {
        {
            "watererbottle",
            "erbottlewater",
            true
        }
    };

    for (int i = 0; i < cases.size(); ++i) {
        TestCase *testCase = &cases.at(i);
        const bool output = solution.isRotation(testCase->s1, testCase->s2);
        assert(output == testCase->output);
        std::cout << "test case " << i <<  " passed" << std::endl;
    }
}