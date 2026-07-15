class Solution:
    def merge(self, nums1: list[int], m: int, nums2: list[int], n: int) -> None:
        # Pointers for nums1, nums2, and the end of the merged array
        i, j, k = m - 1, n - 1, m + n - 1
        
        # Merge while there are elements to compare in both arrays
        while i >= 0 and j >= 0:
            if nums1[i] > nums2[j]:
                nums1[k] = nums1[i]
                i -= 1
            else:
                nums1[k] = nums2[j]
                j -= 1
            k -= 1
        
        # If there are remaining elements in nums2, copy them
        # (Remaining elements in nums1 are already in place)
        while j >= 0:
            nums1[k] = nums2[j]
            j -= 1
            k -= 1