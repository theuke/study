class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

    Input: nums = [1,2,3], target = 4
    Output: 7
    Explanation:
    The possible combination ways are:
    (1, 1, 1, 1)
    (1, 1, 2)
    (1, 2, 1)
    (1, 3)
    (2, 1, 1)
    (2, 2)
    (3, 1)

        1   2   3       F(i)
    0   -   -   -       0
    1   1   -   -       1
    2   1   1   -       2
    3   1   2   1       4
    4   1   4   2       7
    5   

    }
};