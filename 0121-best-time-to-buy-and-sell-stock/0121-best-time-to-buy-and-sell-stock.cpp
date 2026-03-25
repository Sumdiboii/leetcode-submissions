class Solution {
public:
    int maxProfit(vector<int>& prices) {

        auto& p  = prices;
        int n = p.size();

        int minbuy = p[0];
        int profit = 0;

        for(int i = 0; i< n; i++){
            profit = max(profit, p[i] - minbuy);
            minbuy = min(minbuy, p[i]);
        }

        return profit;
    }
};