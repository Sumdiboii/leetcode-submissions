class Solution:
    # 1. Valid Palindrome (LeetCode 125) using Two Pointers
    def isPalindrome(self, s: str) -> bool:
        # Initialize two pointers: 'left' at the beginning and 'right' at the end of the string
        left = 0
        right = len(s) - 1
        
        # Loop until the two pointers meet in the middle
        while left < right:
            # Move the left pointer forward if the character is not alphanumeric
            if not s[left].isalnum():
                left += 1
            # Move the right pointer backward if the character is not alphanumeric
            elif not s[right].isalnum():
                right -= 1
            # Both characters are alphanumeric; compare them case-insensitively
            else:
                if s[left].lower() != s[right].lower():
                    # Return False if characters do not match
                    return False
                # Move both pointers inward if they match
                left += 1
                right -= 1
                
        # Return True if the entire string has been checked successfully
        return True