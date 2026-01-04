#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <assert.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> nums_set;

        int nums_size = nums.size();
        for (int i = 0; i < nums_size; ++i)
            nums_set.insert(nums[i]);
        
        int longest_streak = 0;

        for (set<int>::iterator iter = nums_set.begin(); iter != nums_set.end(); ++iter)
        {
            int curr_num = *iter;
            if (!nums_set.count(curr_num - 1))
            {
                int curr_streak = 1;

                while (nums_set.count(curr_num + 1))
                {
                    ++curr_num;
                    ++curr_streak;
                }

                if (curr_streak > longest_streak)
                    longest_streak = curr_streak;
            }
        }

        return longest_streak;
    }
};

int main()
{
    vector<int> nums {100, 4, 200, 1, 3, 2};
    int answer = 4;

    Solution solution;
    int my_answer = solution.longestConsecutive(nums);

    cout << "answer    = " << answer << endl;
    cout << "my_answer = " << my_answer << endl;
}