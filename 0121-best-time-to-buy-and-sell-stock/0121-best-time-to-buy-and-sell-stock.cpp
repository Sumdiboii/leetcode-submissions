class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minbuy = prices[0];
        int maxprofit = 0;
          


          for( int i = 0 ; i< prices.size() ;i++){
            maxprofit = max(maxprofit, prices[i] - minbuy);
            minbuy = min(prices[i], minbuy);
          }

          return maxprofit;
    }
};