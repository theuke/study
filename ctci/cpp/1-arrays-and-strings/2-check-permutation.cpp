/* Check Permutation:
 * Given two strigs, write a method to decide if one is a permutatino of the other.
*/

#include <iostream>
#include <vector>
#include <map>
#include <cassert>

class Solution {
public:
    bool isPermutation(const char *str1, const char *str2) {
        // A str1 is a permutation of str2 only if the frequency count of each character in str1 matches
        // the frequency count of each character in str2.
        std::map<char, int> freqCount;

        for (const char *c = str1; *c != '\0'; ++c) {
            if (freqCount.count(*c) == 0) {
                freqCount.insert({*c, 1});
            } else {
                ++freqCount[*c];
            }
        }

        for (const char *c = str2; *c != '\0'; ++c) {
            if (freqCount.count(*c) == 0) {
                return false;
            } else {
                --freqCount[*c];
                if (freqCount[*c] == 0)
                    freqCount.erase(*c);
            }
        }

        return freqCount.size() == 0;
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
        {"abcd", "bdca", true},
        {"hola", "hello", false}
    };

    for (int i = 0; i < cases.size(); ++i) {
        TestCase *testCase = &cases.at(i);
        bool output = solution.isPermutation(testCase->str1, testCase->str2);
        assert(output == testCase->output);
        std::cout << "test case " << i <<  " passed" << std::endl;
    }
}