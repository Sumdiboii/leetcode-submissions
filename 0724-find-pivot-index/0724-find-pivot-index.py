class Solution:
    def pivotIndex(self, nums: list[int]) -> int:
        # Calculate the total sum of all the numbers in the array
        total_sum = sum(nums)
        
        # Initialize left sum to 0 as there are no elements to the left of the first index initially
        left_sum = 0
        
        # Iterate through each index and its corresponding number in the array
        for i, num in enumerate(nums):
            # The right sum is the total sum minus the left sum and the current number
            if left_sum == total_sum - left_sum - num:
                return i
            
            # Add the current number to the left sum for the next iteration
            left_sum += num
            
        # Return -1 if no such pivot index exists
        return -1