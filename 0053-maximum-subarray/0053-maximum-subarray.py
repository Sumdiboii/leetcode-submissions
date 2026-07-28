class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        # Initialize current_sum and max_sum with the first element of the array
        current_sum = max_sum = nums[0]
        
        # Iterate through the remaining numbers starting from the second element
        for num in nums[1:]:
            # Decide whether to add the current number to the existing subarray 
            # or start a fresh subarray starting at the current number
            current_sum = max(num, current_sum + num)
            
            # Update max_sum if the current subarray sum is greater than the highest recorded so far
            max_sum = max(max_sum, current_sum)
            
        # Return the maximum subarray sum found after checking all elements
        return max_sum