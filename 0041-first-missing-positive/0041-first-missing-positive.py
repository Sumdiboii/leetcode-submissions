class Solution:
    def firstMissingPositive(self, nums: list[int]) -> int:
        n = len(nums)
        
        # Step 1: Place each number in its correct position if possible
        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                # Swap current number to its target index
                target_idx = nums[i] - 1
                nums[i], nums[target_idx] = nums[target_idx], nums[i]
                
        # Step 2: Scan to find the first index that doesn't match its expected value
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
                
        # Step 3: If 1 to n are all present, the answer is n + 1
        return n + 1