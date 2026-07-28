class Solution:
    # 4. Reverse String (LeetCode 344)
    def reverseString(self, s: list[str]) -> None:
        # Initialize two pointers at opposite ends of the list
        left, right = 0, len(s) - 1
        
        # Swap characters moving towards the center
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1