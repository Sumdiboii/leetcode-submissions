class Solution:
    # 8. Length of Last Word (LeetCode 58)
    def lengthOfLastWord(self, s: str) -> int:
        # Strip trailing spaces and split the string by spaces to get words
        words = s.strip().split()
        # Return the length of the last word in the list
        return len(words[-1]) if words else 0