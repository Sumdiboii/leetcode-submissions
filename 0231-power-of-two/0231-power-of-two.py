class Solution:
    # 3. Power of Two (LeetCode 231)
    def isPowerOfTwo(self, n: int) -> bool:
        # A power of two must be strictly greater than 0 and have only one bit set (n & (n - 1) == 0)
        return n > 0 and (n & (n - 1)) == 0