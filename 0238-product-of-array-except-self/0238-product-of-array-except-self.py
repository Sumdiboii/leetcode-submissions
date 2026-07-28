class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        # Initialize the result array with 1s of the same length as nums
        res = [1] * (len(nums))
        
        # Pass 1: Calculate left products for each element
        # 'prefix' keeps track of the product of all elements to the left
        prefix = 1
        for i in range(len(nums)):
            res[i] = prefix
            prefix *= nums[i]
            
        # Pass 2: Calculate right products and multiply with left products in place
        # 'suffix' keeps track of the product of all elements to the right
        suffix = 1
        for i in range(len(nums) - 1, -1, -1):
            res[i] *= suffix
            suffix *= nums[i]
            
        # Return the final product array where each element is the product of all other elements
        return res