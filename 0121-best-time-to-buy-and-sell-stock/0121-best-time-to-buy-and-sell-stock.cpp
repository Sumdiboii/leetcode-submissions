class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int minbuy = prices[0];
        int maxprofit = 0;

        for (int i = 0; i < n; i++) {
            maxprofit = max(maxprofit, prices[i] - minbuy);
            minbuy = min(minbuy, prices[i]);
        }
        return maxprofit;
    }
};