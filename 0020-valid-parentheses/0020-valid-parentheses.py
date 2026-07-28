class Solution:
    # 1. Valid Parentheses (LeetCode 20)
    def isValid(self, s: str) -> bool:
        # Stack to keep track of opening brackets
        stack = []
        # Mapping of closing brackets to their corresponding opening brackets
        mapping = {")": "(", "}": "{", "]": "["}
        
        for char in s:
            # If the character is a closing bracket
            if char in mapping:
                # Pop the top element from stack if it's not empty, else assign a dummy value
                top_element = stack.pop() if stack else '#'
                
                # If the mapped opening bracket doesn't match the stack's top element, return False
                if mapping[char] != top_element:
                    return False
            else:
                # If it's an opening bracket, push it onto the stack
                stack.append(char)
                
        # Return True if the stack is empty (all brackets matched), otherwise False
        return not stack