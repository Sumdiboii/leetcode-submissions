class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minbuy = prices[0];
        int maxprofit = 0;

        for( int &p : prices){
        minbuy = min(minbuy, p);
        profit = max(profit, p - minbuy);
        }


        return profit;


    }
};