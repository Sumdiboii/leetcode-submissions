class Solution:
    # 3. Longest Common Prefix (LeetCode 14)
    def longestCommonPrefix(self, strs: list[str]) -> str:
        # Handle edge case where array is empty
        if not strs:
            return ""
        
        # Assume the first string is the prefix and shrink it progressively
        prefix = strs[0]
        for s in strs[1:]:
            # While the current string does not start with the prefix, shorten the prefix
            while s.find(prefix) != 0:
                prefix = prefix[:-1]
                if not prefix:
                    return ""
        return prefix