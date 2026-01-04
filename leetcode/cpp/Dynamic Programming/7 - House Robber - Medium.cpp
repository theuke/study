// Fast DP Solution with O(1) space
class Solution {
public:
    int rob(vector<int>& nums) {
        int nums_size = nums.size();

        if (nums_size == 1)
            return nums[0];
        else if (nums_size == 2)
            return max(nums[0], nums[1]);

        int dp[3];

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        dp[2] = max(dp[0] + nums[2], dp[1]);

        for (int i = 3; i < nums_size; ++i)
        {
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = max(dp[0] + nums[i], dp[1]);
        }

        return max(dp[2]);
    }
};



// Fast DP Solution with O(1) space
class Solution {
public:
    int rob(vector<int>& nums) {
        int nums_size = nums.size();

        if (nums_size == 1)
            return nums[0];
        else if (nums_size == 2)
            return max(nums[0], nums[1]);
        else if (nums_size == 3)
            return max(nums[0] + nums[2], nums[1]);
        
        int dp[4];

        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = max(nums[0] + nums[2], nums[1]);
        dp[3] = nums[3] + max(dp[0], dp[1]);

        for (int i = 4; i < nums_size; ++i)
        {
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = dp[3];
            dp[3] = nums[i] + max(dp[0], dp[1]);
        }

        return max(dp[2], dp[3]);
    }
};




// Fast DP Solution with O(n) space
class Solution {
public:
    int rob(vector<int>& nums) {
        int nums_size = nums.size();

        if (nums_size == 1)
            return nums[0];
        else if (nums_size == 2)
            return max(nums[0], nums[1]);
        else if (nums_size == 3)
            return max(nums[0] + nums[2], nums[1]);
        
        int dp[100];

        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = max(nums[0] + nums[2], nums[1]);

        for (int i = 3; i < nums_size; ++i)
            dp[i] = nums[i] + max(dp[i - 3], dp[i - 2]);

        return max(dp[nums_size - 2], dp[nums_size - 1]);

        // i   v   s                                               last robbed
        // 0   2   2                                               -1
        // 1   7   7                                               -1
        // 2   9   11                                              0
        // 3   3   v[3] + max(s[0], s[1]) = 3 + max(2, 7) = 10     1
        // 4   1   v[4] + max(s[1], s[2]) = 1 + max(7, 11) = 12    2
        // 5   2   v[5] + max(s[2], s[3]) = 2 + max(11, 10) = 13   2
        // 6   7   v[6] + max(s[3], s[4]) = 7 + max(10, 12) = 19   4
        // 7   3   v[7] + max(s[4], s[5]) = 3 + max(12, 13) = 16   5

        // total_max = max(v[nums_size - 1], v[nums_size - 2]);
    }
};