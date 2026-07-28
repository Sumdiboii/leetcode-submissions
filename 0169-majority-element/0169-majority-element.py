class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        # Initialize the candidate for the majority element and a counter for its frequency
        candidate = None
        count = 0
        
        # Iterate through each number in the array using Boyer-Moore Voting Algorithm
        for num in nums:
            # If the count drops to zero, choose the current number as the new candidate
            if count == 0:
                candidate = num
            
            # Increment the count if the current number matches the candidate, otherwise decrement it
            count += (1 if num == candidate else -1)
            
        # Return the majority element that appears more than n // 2 times
        return candidate