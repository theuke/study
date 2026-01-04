/* URLify:
 * Write a method to prelace all spaces in a strign with '%20'.
 * You may assume that the string has sufficient space at the end to hold the additional characters,
 * and that you are given the 'true' length of the string.
*/

#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <cstring>

class Solution {
private:
    // #define NUM_CHARS_TO_SHIFT (sizeof("%20") - sizeof(" "))
    #define NUM_CHARS_TO_SHIFT 2
public:
    void urlify(char *input, const int length) {
        // In an array of size length, store the new index of each character.
        int *newIndices = new int[length];
        int shiftCount = 0;

        for (int i = 0; i < length; ++i) {
            newIndices[i] = i + shiftCount;
            if (input[i] == ' ')
                shiftCount += NUM_CHARS_TO_SHIFT;
        }

        // Shift all non whitespace indices to their final indices and replace the value at their old
        // indices with whitespace. Must be done front to be to ensure no over-writing.
        for (int i = length - 1; i >= 0; --i) {
            if (newIndices[i] != i) {
                input[newIndices[i]] = input[i];
                input[i] = ' ';
            }
        }

        const int newLength = length + shiftCount;

        for (int i = 0; i < newLength; ++i) {
            if (input[i] == ' ') {
                input[i] = '%';
                input[i + 1] = '2';
                input[i + 2] = '0';
                i += 2;
            }
        }

        input[newLength] = '\0';

        delete[] newIndices;
    }
};

struct TestCase {
    char input[50];
    int length;
    const char *output;
};

int main() {
    Solution solution;
    std::vector<TestCase> cases = {
        {"Mr John Smith    ", 13, "Mr%20John%20Smith"}
    };

    for (int i = 0; i < cases.size(); ++i) {
        TestCase *testCase = &cases.at(i);
        solution.urlify(testCase->input, testCase->length);
        assert(strcmp(testCase->input, testCase->output) == 0);
        std::cout << "test case " << i <<  " passed" << std::endl;
    }
}