class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Because we are dealing with multiplication, the general rule is that
        // we want to multiply all non-zero numbers together because they increase
        // magnitude. Hence, the special factor here has to do with 0 and the sign
        // of the current_subarray.
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;

        for (int i = 1; i < nums.size(); ++i)
        {
            int curr = nums[i];
            int max_so_far_by_curr = max_so_far * curr;
            max_so_far = max(curr, max(max_so_far_by_curr, min_so_far * curr));
            min_so_far = min(curr, min(max_so_far_by_curr, min_so_far * curr));

            result = max(max_so_far, result);
        }

        return result;
    }
};