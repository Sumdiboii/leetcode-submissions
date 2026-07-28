class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # Pointer to track the position where the next non-zero element should be placed
        last_non_zero_found_at = 0
        
        # Traverse through the entire array
        for i in range(len(nums)):
            # If the current element is not zero, we need to shift it forward
            if nums[i] != 0:
                # Swap the current non-zero element with the element at the last_non_zero_found_at pointer
                nums[last_non_zero_found_at], nums[i] = nums[i], nums[last_non_zero_found_at]
                # Increment the pointer to the next available position for a non-zero element
                last_non_zero_found_at += 1