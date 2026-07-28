class Solution:
    # 1. Ransom Note (LeetCode 383)
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        # Dictionary to store the frequency of each character in the magazine
        char_count = {}
        
        # Count each character's frequency in the magazine
        for char in magazine:
            char_count[char] = char_count.get(char, 0) + 1
            
        # Check if the ransom note can be constructed using the magazine's characters
        for char in ransomNote:
            # If the character is not available or its count is depleted, return False
            if char not in char_count or char_count[char] == 0:
                return False
            # Decrement the count for the used character
            char_count[char] -= 1
            
        # Return True if all characters for the ransom note were successfully found
        return True