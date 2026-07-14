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