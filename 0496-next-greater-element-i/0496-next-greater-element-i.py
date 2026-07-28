class Solution:
    # 4. Next Greater Element I (LeetCode 496)
    def nextGreaterElement(self, nums1: list[int], nums2: list[int]) -> list[int]:
        # Dictionary to store the next greater element for each number in nums2
        nge_map = {}
        # Monotonic decreasing stack to track elements waiting for a greater number
        stack = []
        
        for num in nums2:
            # While stack is not empty and current number is greater than the stack's top element
            while stack and num > stack[-1]:
                nge_map[stack.pop()] = num
            stack.append(num)
            
        # For any remaining elements in the stack, there is no next greater element (-1)
        while stack:
            nge_map[stack.pop()] = -1
            
        # Build the result for nums1 using the precomputed map
        return [nge_map[num] for num in nums1]