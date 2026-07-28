class Solution:
    # 5. Group Anagrams (LeetCode 49)
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        from collections import defaultdict
        
        # Dictionary to hold lists of anagrams, keyed by character count tuple
        anagram_map = defaultdict(list)
        
        for s in strs:
            # Create a character count array of size 26 for lowercase English letters
            count = [0] * 26
            for char in s:
                count[ord(char) - ord('a')] += 1
                
            # Use the tuple of counts as the hashable key and append the string to its group
            anagram_map[tuple(count)].append(s)
            
        # Return all the grouped anagram lists
        return list(anagram_map.values())