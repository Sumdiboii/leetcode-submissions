class Solution:
    # 9. Add Strings (LeetCode 415)
    def addStrings(self, num1: str, num2: str) -> str:
        # Initialize pointers at the end of both strings and carry to 0
        i, j = len(num1) - 1, len(num2) - 1
        carry = 0
        res = []
        
        while i >= 0 or j >= 0 or carry:
            # Extract digits from strings if pointers are valid
            digit1 = int(num1[i]) if i >= 0 else 0
            digit2 = int(num2[j]) if j >= 0 else 0
            
            # Calculate sum and new carry
            total = digit1 + digit2 + carry
            carry = total // 10
            res.append(str(total % 10))
            
            i -= 1
            j -= 1
            
        # Reverse the result list and join into a string
        return ''.join(res[::-1])