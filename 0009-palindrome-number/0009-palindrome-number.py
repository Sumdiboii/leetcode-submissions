class Solution:
    # 4. Palindrome Number (LeetCode 9)
    def isPalindrome(self, x: int) -> bool:
        # Negative numbers and numbers ending in 0 (except 0 itself) cannot be palindromes
        if x < 0 or (x % 10 == 0 and x != 0):
            return False
            
        reversed_half = 0
        # Reverse only the last half of the digits to avoid overflow
        while x > reversed_half:
            reversed_half = reversed_half * 10 + x % 10
            x //= 10
            
        # Check if the first half equals the reversed second half (handles even and odd length numbers)
        return x == reversed_half or x == reversed_half // 10