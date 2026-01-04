#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cassert>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices(2);

        // Brute force solution.
        // for (int i = 0; i < nums.size(); ++i)
        // {
        //     for (int j = 0; j < nums.size(); ++j)
        //     {
        //         if (i != j)
        //         {
        //             if (nums[i] + nums[j] == target)
        //             {
        //                 indices.at(0) = i;
        //                 indices.at(1) = j;
        //                 return indices;
        //             }
        //         }
        //     }
        // }

        // Hashmap solution.
        map<int, int> m;

        for (int i = 0; i < nums.size(); ++i)
        {
            int val_1 = nums[i];
            int val_2 = target - val_1;

            if (m.count(val_2))
            {
                indices[0] = i;
                indices[1] = m[val_2];
                break;
            }
            else
            {
                m[nums[i]] = i;
            }
        }

        return indices;
    }
};

struct TestCase {
    vector<int> input;
    int target;
    vector<int> output;
};

int main() {
    Solution solution;
    vector<TestCase> cases = {
        {{2, 7, 11, 15}, 9, {0, 1}},
        {{3, 2, 4}, 6, {1, 2}},
        {{3, 3}, 6, {0, 2}}
    };

    for (int i = 0; i < cases.size(); ++i) {
        TestCase *testCase = &cases.at(i);
        vector<int> output = solution.twoSum(testCase->input, testCase->target);
        assert(output == testCase->output);
    }
}