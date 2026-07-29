class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minbuy = prices[0]
        profit = 0

        for p in prices:
            minbuy = min(minbuy, p)
            profit = max(profit, p-minbuy)

        return profit