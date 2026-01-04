/* Palindrome Permutation:
 * Given a strnig, write a function to check if it is a permutation of a palindrome.
 * A palindrome is a word or phrase that i the same forwards and backwards. A permutation
 * is a rearrangement of letters. The palindrome does not need to be limited to just
 * dictionary words. You can ignore casing and non-letter characters.
*/

#include <iostream>
#include <vector>
#include <map>
#include <cassert>
#include <cstring>

class Solution {
private:
    #define LOWER_CASE_ALPHABET_OFFSET 'a';
public:
    bool isPalindromePermutation(const char *str) {
        // A string can only be a palindrome if:
        // - There is an even number of each character
        //   > A single odd number of characters is allowed for one of the characters if the total
        //     number of characters is odd.
        //
        // The solution philosphy is use character frequency counting. To make this fast, we use
        // some variation of a hash map. Note because only lower case english characters are being
        // considered, one optimization we can make is to just use an array of length 26 and use the
        // ascii value as the key.

        int freqCount[26] = { 0 };

        for (const char *c; *c != '\0'; ++c) {
            if ('a' <= *c <= 'z' || 'A' <= *c <= 'Z') {
                const int index = *c - 'a';
                ++freqCount[index];
            }
        }

        bool hasOddFreqCount = false;

        for (int *count = freqCount; count < freqCount + sizeof(freqCount) / sizeof(freqCount[0]); ++count) {
            if (*count & 1) {
                if (hasOddFreqCount)
                    return false;
                else
                    hasOddFreqCount = true;
            }
        }

        return true;


        // // Alternate solution needing only one loop (its not more optimal)
        // int freqCount[26] = { 0 };
        // int oddCount = 0;

        // for (const char *c; *c != '\0'; ++c) {
        //     if ('a' <= *c <= 'z' || 'A' <= *c <= 'Z') {
        //         const int index = *c - 'a';
        //         ++freqCount[index];

        //         if (freqCount[index] & 1)
        //             ++oddCount;
        //         else
        //             --oddCount;
        //     }
        // }

        // return oddCount < 2;
    }
};

struct TestCase {
    const char *input;
    bool output;
};

int main() {
    Solution solution;
    std::vector<TestCase> cases = {
        {"Tact Coa", true} // permutations: "taco cat", "atco cta", etc..
    };

    for (int i = 0; i < cases.size(); ++i) {
        TestCase *testCase = &cases.at(i);
        const bool output = solution.isPalindromePermutation(testCase->input);
        assert(output == testCase->output);
        std::cout << "test case " << i <<  " passed" << std::endl;
    }
}