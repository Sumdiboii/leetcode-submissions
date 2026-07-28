class Solution:
    # 2. Number of 1 Bits (LeetCode 191)
    def hammingWeight(self, n: int) -> int:
        # Initialize count of set bits to 0
        count = 0
        
        # Loop until all bits are zero
        while n:
            # Drop the least significant set bit using n & (n - 1)
            n &= n - 1
            count += 1
            
        return count