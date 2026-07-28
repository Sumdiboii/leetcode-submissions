class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        # Set to keep track of numbers we have already encountered in the array
        seen = set()
        
        # Iterate through each number in the given list
        for num in nums:
            # Check if the current number is already present in our set
            if num in seen:
                # Return True immediately if a duplicate is found
                return True
            # Add the current number to the set for future checks
            seen.add(num)
            
        # Return False if the loop completes without finding any duplicates
        return False