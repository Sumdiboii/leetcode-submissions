class Solution:
    # 6. Find the Index of the First Occurrence in a String (LeetCode 28)
    def strStr(self, haystack: str, needle: str) -> int:
        # Use Python's built-in find method to locate the substring index
        return haystack.find(needle)