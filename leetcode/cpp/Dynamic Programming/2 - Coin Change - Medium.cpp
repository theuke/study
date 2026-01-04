class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Sort the coins in ascending order.
        sort(coins.begin(), coins.end());

        int num_coins = coins.size();
        int min_count[10000 + 1];
        min_count[0] = 0;

        for (int i = 1; i <= amount; ++i)
        {
            min_count[i] = amount + 1;

            for (int j = 0; j < num_coins; ++j)
            {
                if (coins[j] <= i)
                    min_count[i] = min(min_count[i], min_count[i - coins[j]] + 1);
            }
        }

        return min_count[amount] > amount ? -1 : min_count[amount];
    }
};