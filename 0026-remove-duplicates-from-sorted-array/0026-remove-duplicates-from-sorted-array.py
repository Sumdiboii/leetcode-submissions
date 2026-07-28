class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        # Handle edge case where the array is empty
        if not nums:
            return 0
        
        # Initialize the slow pointer to track the position of the last unique element
        slow = 0
        
        # Iterate with the fast pointer starting from the second element to scan the array
        for fast in range(1, len(nums)):
            # Check if the current element is different from the last unique element
            if nums[fast] != nums[slow]:
                # Increment the slow pointer to the next position
                slow += 1
                # Update the position with the new unique value
                nums[slow] = nums[fast]
                
        # Return the count of unique elements, which is the slow pointer index plus one
        return slow + 1