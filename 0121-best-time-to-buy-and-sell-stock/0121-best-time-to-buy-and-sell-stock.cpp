class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        int minbuy = prices[0];

        for( int i = 0; i< prices.size(); i++){


            profit = max(profit, prices[i] - minbuy);
             minbuy = min(minbuy, prices[i]);
        }

        return profit;
    }
};