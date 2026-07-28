class Solution:
    # 10. Roman to Integer (LeetCode 13)
    def romanToInt(self, s: str) -> int:
        # Map of Roman numerals to their respective integer values
        roman_map = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        total = 0
        
        for i in range(len(s)):
            # If current value is less than the next value, subtract it (e.g., IV = 5 - 1)
            if i < len(s) - 1 and roman_map[s[i]] < roman_map[s[i + 1]]:
                total -= roman_map[s[i]]
            else:
                total += roman_map[s[i]]
                
        return total