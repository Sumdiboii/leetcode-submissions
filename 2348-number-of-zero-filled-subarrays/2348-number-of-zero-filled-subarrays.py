class Solution:
    def zeroFilledSubarray(self, nums: list[int]) -> int:
        total_subarrays = 0
        streak = 0
        
        for n in nums:
            if n == 0:
                streak += 1
                total_subarrays += streak
            else:
                streak = 0
                
        return total_subarrays