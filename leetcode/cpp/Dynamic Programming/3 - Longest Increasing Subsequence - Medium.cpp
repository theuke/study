class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // the dp array represents the length of the longest increasing subsequence at index i.
        // Initialized to all 1's since we can always say that the lngest increasing subsequnece
        // at any index will atleast be a subsequence including only itself (length 1)
        int dp[2500];
        int nums_size = nums.size();
        int lis_max = 1;

        for (int i = 0; i < nums_size; ++i)
        {
            dp[i] = 1;

            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    lis_max = max(lis_max, dp[i]);
                }
            }
        }

        return lis_max;
    }
};