class Solution:
    def searchInsert(self, nums: list[int], target: int) -> int:
        # Initialize the left pointer at the beginning of the array
        left = 0
        
        # Initialize the right pointer at the end of the array
        right = len(nums) - 1
        
        # Perform binary search while the search space is valid
        while left <= right:
            # Find the middle index of the current search space
            mid = (left + right) // 2
            
            # If the target is found at mid, return its index
            if nums[mid] == target:
                return mid
            # If the target is greater than the middle element, search the right half
            elif nums[mid] < target:
                left = mid + 1
            # If the target is smaller than the middle element, search the left half
            else:
                right = mid - 1
                
        # If the loop finishes without finding the target, 'left' points to the correct insert position
        return left