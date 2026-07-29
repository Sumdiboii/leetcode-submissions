class Solution:
    def increasingTriplet(self, nums: list[int]) -> bool:
        first = second = third = float('inf')
        
        for num in nums:
            if num <= first:
                first = num
            elif num <= second:
                second = num
            else:

                third = num
                # If we reach here, num is greater than both first and second
                return True
                
        return False