
class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if (prices.size() < 2) return 0;

        int buy1 = -prices[0];
        int sel1 = 0;
        int buy2 = -prices[0];
        int sel2 = 0;

        for (int i = 1; i < prices.size(); ++i)
        {
            int new_sel2 = std::max(sel2, buy2 + prices[i]);
            int new_buy2 = std::max(buy2, sel1 - prices[i]);
            int new_sel1 = std::max(sel1, buy1 + prices[i]);
            int new_buy1 = std::max(buy1, -prices[i]);

            sel2 = new_sel2;
            buy2 = new_buy2;
            sel1 = new_sel1;
            buy1 = new_buy1;
        }

        return sel2;
    }
};