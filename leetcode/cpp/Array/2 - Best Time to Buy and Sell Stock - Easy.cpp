class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // The solution iterates through the array, making sure to keep track of the
        // lowest price seen so far. It then compares each subsequent price with the lowest
        // price to figure out the profit between those days and records the max_profit.
        int low_price = prices[0];
        int max_profit = 0;

        for (int i = 1; i < prices.size();; ++i)
        {
            int price = prices[i];
            int profit = price - low_price;

            if (profit > max_profit)
                max_profit = profit;
            else if (price < low_price)
                low_price = price;
        }

        return max_profit;
    }
};