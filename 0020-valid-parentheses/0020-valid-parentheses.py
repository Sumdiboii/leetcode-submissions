class Solution:
    def isValid(self, s: str) -> bool:
        # A dictionary makes mapping closing to opening brackets very clean
        bracket_map = {')': '(', ']': '[', '}': '{'}
        stack = []
        
        for char in s:
            # If the character is a closing bracket
            if char in bracket_map:
                # Pop the top element if the stack isn't empty, otherwise use a dummy
                top_element = stack.pop() if stack else '#'
                
                # If the popped element doesn't match the required opening bracket
                if bracket_map[char] != top_element:
                    return False
            else:
                # If it's an opening bracket, push it onto the stack
                stack.append(char)
        
        # If the stack is empty, it's valid
        return not stack