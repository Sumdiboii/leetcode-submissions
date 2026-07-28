class Solution:
    def intersection(self, nums1: list[int], nums2: list[int]) -> list[int]:
        # Convert the first list into a set to remove duplicates and enable efficient lookups
        set1 = set(nums1)
        
        # Convert the second list into a set to remove duplicates as well
        set2 = set(nums2)
        
        # Find the intersection of both sets using the bitwise AND operator and convert back to a list
        return list(set1 & set2)