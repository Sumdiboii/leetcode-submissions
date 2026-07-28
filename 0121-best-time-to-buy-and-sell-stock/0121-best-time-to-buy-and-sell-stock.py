class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        # Initialize min_price to infinity to track the lowest price seen so far
        min_price = float('inf')
        
        # Initialize max_profit to 0 as the baseline profit before making any trades
        max_profit = 0
        
        # Loop through each stock price in the given daily prices array
        for price in prices:
            # Check if the current price is lower than the lowest price recorded so far
            if price < min_price:
                # Update the minimum price to the current lower price
                min_price = price
            # Calculate potential profit if sold today and check if it exceeds the maximum profit
            elif price - min_price > max_profit:
                # Update max_profit with the new higher profit value
                max_profit = price - min_price
                
        # Return the maximum possible profit found after evaluating all prices
        return max_profit