class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        minbuy = prices[0]
        profit = 0

        for n in prices:
            minbuy = min(minbuy, n)
            profit = max(profit, n- minbuy)

        return profit