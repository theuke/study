/* Is Unique:
 * Implement an algorithim to determine if a string has all unique characters.
 * What if you cannot use additional data structures?
*/

#include <iostream>
#include <vector>
#include <map>
#include <cassert>

class Solution {
public:
    bool isUnique_usingHashMap(const char *str) {
        // Store the freqency count of each character in a has map.
        std::map<char, int> freqCount;

        for (const char *c = str; *c != '\0'; ++c) {
            if (freqCount.count(*c) == 0) {
                freqCount.insert({*c, 1});
            } else {
                return false;
            }
        }

        return true;
    }

    bool isUnique_noAdditionalDataStructures(const char *str) {
        for (const char *c1 = str; *c1 != '\0'; ++c1) {
            for (const char *c2 = c1; *c2 != '\0'; ++c2) {
                if (*c1 == *c2)
                    return false;
            }
        }

        return true;
    }
};

struct TestCase {
    const char *input;
    bool output;
};

int main() {
    Solution solution;
    std::vector<TestCase> cases = {
        {"somestring", false},
        {"uniqueword", true}
    };

    for (int i = 0; i < cases.size(); ++i) {
        TestCase *testCase = &cases.at(i);
        bool output = solution.isUnique_usingHashMap(testCase->input);
        assert(output == testCase->output);
        std::cout << "test case " << i <<  " passed" << std::endl;
    }
}