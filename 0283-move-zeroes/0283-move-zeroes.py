class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        # 1. Filter out all non-zero elements using a list comprehension
        non_zeroes = [x for x in nums if x != 0]
        
        # 2. Count the zeroes and generate a padding array
        zero_count = nums.count(0)
        
        # 3. Use slice assignment to overwrite the original memory reference in-place
        nums[:] = non_zeroes + [0] * zero_count