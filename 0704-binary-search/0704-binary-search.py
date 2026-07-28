class Solution:
    # 1. Binary Search (LeetCode 704)
    def search(self, nums: list[int], target: int) -> int:
        # Initialize left and right pointers at the bounds of the array
        left = 0
        right = len(nums) - 1
        
        # Continue searching while the search space is valid
        while left <= right:
            # Find the middle index
            mid = (left + right) // 2
            
            # Check if target is at mid
            if nums[mid] == target:
                return mid
            # If target is greater, discard the left half
            elif nums[mid] < target:
                left = mid + 1
            # If target is smaller, discard the right half
            else:
                right = mid - 1
                
        # Return -1 if target is not found
        return -1