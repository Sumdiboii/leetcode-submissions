class Solution:
    # 5. First Unique Character in a String (LeetCode 387)
    def firstUniqChar(self, s: str) -> int:
        # Count the frequency of each character
        count = {}
        for char in s:
            count[char] = count.get(char, 0) + 1
            
        # Find the index of the first character with a frequency of 1
        for i, char in enumerate(s):
            if count[char] == 1:
                return i
        return -1