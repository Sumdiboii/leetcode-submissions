class Solution:
    def increasingTriplet(self, nums: list[int]) -> bool:
        first = second = float('inf')
        
        for num in nums:
            if num <= first:
                first = num
            elif num <= second:
                second = num
            else:
                # If we reach here, num is greater than both first and second
                return True
                
        return False