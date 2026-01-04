class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int nums_size = nums.size();
        vector<int> products(nums_size);

        int prefix = 1;
        products[0] = 1;

        // Traverse the array from right to left, accumulating the left prefix sum as we go.
        for (int i = 1; i < nums_size; ++i)
        {
            prefix *= nums[i - 1];
            products[i] = prefix;
        }

        prefix = 1;

        // Traverse back from right to left accumulating the right prefix sum as we go and
        // setting the product to be product[i] * prefix.
        for (int i = nums_size - 2; i >= 0; --i)
        {
            prefix *= nums[i + 1];
            products[i] *= prefix;
        }

        return products;
    }
};