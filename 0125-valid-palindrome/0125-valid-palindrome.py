class Solution:
    # 1. Valid Palindrome (LeetCode 125)
    def isPalindrome(self, s: str) -> bool:
        # Filter the string to keep only alphanumeric characters and convert to lowercase
        filtered = ''.join(char.lower() for char in s if char.isalnum())
        # Check if the filtered string is equal to its reverse
        return filtered == filtered[::-1]