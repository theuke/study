class Solution {
private: 
public:
    int climbStairs(int n) {
        // n = 1: 1 = 1
        // n = 2: 1 1 + 2 = 2
        // n = 3: 1 1 1 + 2 1 + 1 2 = 3
        // n = 4: 1 1 1 1 + 2 1 1 + 1 2 1 + 1 1 2 + 2 2 = 5
        // n = 5: 1 1 1 1 1 + 2 1 1 1 + 1 2 1 1 + 1 1 2 1 + 1 1 1 2 + 2 2 1 + 2 1 2 + 1 2 2 = 8
        // n = 6: 1 1 1 1 1 1 + 2 1 1 1 1 + 1 2 1 1 1 + 1 1 2 1 1 + 1 1 1 2 1 + 1 1 1 1 2 + 2 2 1 1 + 2 1 2 1 + 1 2 1 2 + 1 2 2 1 + 1 1 2 2 + 2 1 1 2 + 2 2 2 = 13
        // n = 7: 21
        // n = 8: 34

        int first = 1
        int second = 2;
        int curr;

        if (n == 1)
            curr = first;
        else if (n == 2)
            curr = second;
        
        for (int i = 2; i < n; ++i)
        {
            curr = first + second;
            first = second;
            second = curr;
        }

        return curr;
    }
};