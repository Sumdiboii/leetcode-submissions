class Solution:
    def missingNumber(self, nums: list[int]) -> int:
        # Get the length of the array, which represents the maximum number in the range [0, n]
        n = len(nums)
        
        # Calculate the expected sum of numbers from 0 to n using the formula n * (n + 1) // 2
        expected_sum = n * (n + 1) // 2
        
        # Calculate the actual sum of the elements present in the array
        actual_sum = sum(nums)
        
        # The missing number is the difference between the expected sum and the actual sum
        return expected_sum - actual_sum