class Solution:
    # 1. Single Number (LeetCode 136)
    def singleNumber(self, nums: list[int]) -> int:
        # Initialize the result to 0
        single = 0
        
        # XOR all elements together; duplicates cancel out to 0, leaving the single number
        for num in nums:
            single ^= num
            
        return single