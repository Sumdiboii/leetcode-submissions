class Solution:
    # 5. Backspace String Compare (LeetCode 844)
    def backspaceCompare(self, s: str, t: str) -> bool:
        # Helper function to build the final string using a stack-like list
        def build(string: str) -> str:
            stack = []
            for char in string:
                if char != '#':
                    stack.append(char)
                elif stack:
                    stack.pop()
            return "".join(stack)
            
        # Compare the processed versions of both strings
        return build(s) == build(t)