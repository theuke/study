/* String Compression:
 * Implement a method to perform basic strign compression usnig the coutns of repeated
 * characters. For example, the strnig aabcccccaaa would become a2b1c5a3. If the "compressed"
 * string would not become smaller than the original string, your method should return the original
 * string. You can assume the strnig has only uppercase and lowercase letters (a-z).
*/

#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>

class Solution {
public:
    const char *stringCompression(const char *str, char *compressed) {
        // Most basic solution is to just traverse str and fill out compressed as we go.
        const int strLen = strlen(str);
        const char *strIter = str;
        const char *strEnd = str + strLen;
        char *compressedIter = compressed;
        char streakChar = '\0';
        int streakCount = 0;

        while (strIter <= strEnd) {
            if (*strIter != streakChar) {
                if (streakCount > 0) {
                    *compressedIter++ = streakChar;
                    strcpy(compressedIter, std::to_string(streakCount).c_str());
                    compressedIter += strlen(compressedIter);
                }

                streakChar = *strIter;
                streakCount = 1;
            } else {
                ++streakCount;
            }

            ++strIter;
        }

        return strlen(compressed) < strLen ? compressed : str;
    }
};

struct TestCase {
    const char *input;
    const char *output;
};

int main() {
    Solution solution;
    std::vector<TestCase> cases = {
        {"aabcccccaaa", "a2b1c5a3"}
    };

    for (int i = 0; i < cases.size(); ++i) {
        TestCase *testCase = &cases.at(i);
        char compressedString[50];
        const char *output = solution.stringCompression(testCase->input, compressedString);
        assert(strcmp(output, testCase->output) == 0);
        std::cout << "test case " << i <<  " passed" << std::endl;
    }
}