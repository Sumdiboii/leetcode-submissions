"""

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
            
        seen1 = {}
        seen2 = {}

        for ch in s:
            seen1[ch] = seen1.get(ch, 0) + 1

        for ch in t:
            seen2[ch] = seen2.get(ch, 0) + 1
        
        return seen1 == seen2
        """

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        counts = {}
        
        # Increment for string s
        for ch in s:
            counts[ch] = counts.get(ch, 0) + 1
            
        # Decrement for string t
        for ch in t:
            # If the character isn't in counts or the count is 0,
            # it means t has a char that s doesn't have (or too many of them)
            if ch not in counts or counts[ch] == 0:
                return False
            counts[ch] -= 1
            
        return True