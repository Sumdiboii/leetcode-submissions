class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        # Pointer for the last valid element in nums1
        p1 = m - 1
        
        # Pointer for the last element in nums2
        p2 = n - 1
        
        # Pointer for the last position in the overall merged nums1 array
        p = m + n - 1
        
        # While there are elements to compare in both nums1 and nums2
        while p1 >= 0 and p2 >= 0:
            # Compare elements from the back and place the larger one at the end of nums1
            if nums1[p1] > nums2[p2]:
                nums1[p] = nums1[p1]
                p1 -= 1
            else:
                nums1[p] = nums2[p2]
                p2 -= 1
            # Move the insertion pointer backward
            p -= 1
            
        # If there are any remaining elements in nums2, copy them over
        # (If elements remain in nums1, they are already in their correct sorted positions)
        nums1[:p2 + 1] = nums2[:p2 + 1]