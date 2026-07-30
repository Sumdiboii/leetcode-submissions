class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k = k % len(nums)

        def reverse(l: int, r: int) -> None:
            while l <= r:
                nums[l], nums[r] = nums[r], nums[l]
                l += 1
                r -= 1

        # Step 1: Reverse the entire array
        reverse(0, len(nums) - 1)

        # Step 2: Reverse the first k elements (0 to k-1)
        reverse(0, k - 1)

        # Step 3: Reverse the remaining elements (k to len(nums)-1)
        reverse(k, len(nums) - 1)