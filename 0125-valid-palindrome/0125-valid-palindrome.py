class Solution:
    def isPalindrome(self, s: str) -> bool:
        left, right = 0, len(s) - 1
        
        while left < right:
            # Move left pointer until it hits an alphanumeric char
            if not s[left].isalnum():
                left += 1
            # Move right pointer until it hits an alphanumeric char
            elif not s[right].isalnum():
                right -= 1
            # Compare and move both
            else:
                if s[left].lower() != s[right].lower():
                    return False
                left += 1
                right -= 1
                
        return True