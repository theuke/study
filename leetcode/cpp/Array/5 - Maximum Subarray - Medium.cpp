class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int current_subarray = nums[0];
        int max_subarray = current_subarray;
        
        // If the new number is greater than the current subarray AND the
        // current subarray is negative, then discard the current subarray
        // and make it now be just the new number. Else, the new num is
        // worth considering.
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > current_subarray && current_subarray < 0)
                current_subarray = nums[i];
            else
                current_subarray += nums[i];

            if (current_subarray > max_subarray)
                max_subarray = current_subarray;
        }

        return max_subarray;
    }
};