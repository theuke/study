class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> unique_nums;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (unique_nums.count(nums[i]) == 0)
                unique_nums.insert(nums[i]);
            else
                return true;
        }

        return false;
    }
};