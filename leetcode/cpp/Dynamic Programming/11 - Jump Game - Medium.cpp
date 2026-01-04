// Greedy Method
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // It turns out the greedy method can be used here.
        // This means there is no need for the inner loop and
        // memo table. Instead, we can simply keep track of the
        // last (leftmost) good position. Then, as we explore
        // positions from right to left, we simply check if
        // that position's jump is enough to get to atleast
        // get to that leftmost position.
        int last_good_index = nums.size() - 1;

        for (int i = nums.size() - 2; i >= 0; --i)
        {
            if (i + nums[i] >= last_good_index)
                last_good_index = i;
        }

        return last_good_index == 0;
    }
};



// Bottom-up DP solution
class Solution {
public:
    bool canJump(vector<int>& nums) {
        // [2, 3, 1, 1, 4]
        // [t, t, t, t, t]

        // [3, 2, 1, 0, 4]
        // [f, f, f, f, t]

        // We simply need to iterate from right to left and
        // at each step check and see (via inner loop) whether
        // or not we can get to a "true" node from where we currently
        // are.

        int nums_size = nums.size();
        bool dp[10000];

        dp[nums_size - 1] = true;

        for (int i = nums_size - 2; i >= 0; --i)
        {
            for (int j = 1; j <= nums[i] && j + i < nums_size; ++j)
            {
                if (nums[i + j])
                {
                    nums[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};