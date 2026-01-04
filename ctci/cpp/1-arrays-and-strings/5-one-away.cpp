/* One Away:
 * There are three types of edits tht can be performed on strings: insert a character,
 * remove a character, or replace a character. Given two strings, write a function to
 * check if they are one edit (or zero edits) away.
*/

#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <cstring>

class Solution {
public:
    bool isOneAway(const char *str1, const char *str2) {
        // Iterate through both strings at the same time and check that the respective characters match.
        // If they do not, check that the next character is the same. If it is not, then return false.
        // If they are, then keep iterating through both strings. If any difference is found here-after,
        // return false.
        const int len1 = strlen(str1);
        const int len2 = strlen(str2);
        const int lenDiff = len1 - len2;
        int diff = 0;

        if (len1 == len2) {
            for (const char *c1 = str1, *c2 = str2; c1 < str1 + len1; ++c1, ++c2) {
                if (*c1 != *c2) {
                    if (diff != 0)
                        return false;
                    else
                        diff = 1;
                }
            }
        } else if (lenDiff < -1 || lenDiff > 1) {
            return false;
        } else {
            const char *strLong;
            const char *strShort;
            int lenShort;
            
            if (lenDiff > 0 ? str1 : str2) {
                strLong = str1;
                strShort = str2;
                lenShort = len2;
            } else {
                strLong = str2;
                strShort = str1;
                lenShort = len1;
            }

            for (const char *cShort = strShort, *cLong = strLong; cShort < strShort + lenShort; ++cShort, ++cLong) {
                if (*cShort != *cLong) {
                    if (diff != 0) {
                        return false;
                    } else {
                        ++cLong;
                        diff = 1;
                    }
                }
            }
        }

        return true;
    }
};

struct TestCase {
    const char *str1;
    const char *str2;
    bool output;
};

int main() {
    Solution solution;
    std::vector<TestCase> cases = {
        {"pale", "ple", true},
        {"pales", "pale", true},
        {"pale", "bale", true},
        {"pale", "bake", false}
    };

    for (int i = 0; i < cases.size(); ++i) {
        TestCase *testCase = &cases.at(i);
        const bool output = solution.isOneAway(testCase->str1, testCase->str2);
        assert(output == testCase->output);
        std::cout << "test case " << i <<  " passed" << std::endl;
    }
}