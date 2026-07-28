class Solution:
    def sortedSquares(self, nums: list[int]) -> list[int]:
        # Get the length of the input array
        n = len(nums)
        
        # Initialize a result array of the same size to store squared values in sorted order
        result = [0] * n
        
        # Initialize two pointers: 'left' at the beginning and 'right' at the end of the array
        left = 0
        right = n - 1
        
        # Fill the result array from right to left (largest squares to smallest squares)
        for i in range(n - 1, -1, -1):
            # Compare the absolute values at the two pointers to find the larger square
            if abs(nums[left]) > abs(nums[right]):
                result[i] = nums[left] ** 2
                # Move the left pointer forward
                left += 1
            else:
                result[i] = nums[right] ** 2
                # Move the right pointer backward
                right -= 1
                
        # Return the newly sorted array of squares
        return result