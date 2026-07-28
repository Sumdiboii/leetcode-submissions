class Solution:
    # 3. Happy Number (LeetCode 202)
    def isHappy(self, n: int) -> bool:
        # Set to keep track of numbers we have already seen to detect cycles
        seen = set()
        
        while n != 1 and n not in seen:
            # Add the current number to the seen set
            seen.add(n)
            
            # Compute the sum of the squares of its digits
            total_sum = 0
            while n > 0:
                digit = n % 10
                total_sum += digit ** 2
                n //= 10
            
            # Update n to the new total sum
            n = total_sum
            
        # Return True if n becomes 1, meaning it is a happy number
        return n == 1