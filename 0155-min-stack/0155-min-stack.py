class MinStack:
    # 3. Min Stack (LeetCode 155)
    def __init__(self):
        # Main stack to store all elements
        self.stack = []
        # Auxiliary stack to store the minimum values at each level
        self.min_stack = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        # Push the new minimum onto min_stack (compare with current minimum)
        if not self.min_stack or val <= self.min_stack[-1]:
            self.min_stack.append(val)
        else:
            self.min_stack.append(self.min_stack[-1])

    def pop(self) -> None:
        # Pop from both stacks to keep minimum tracking synchronized
        self.stack.pop()
        self.min_stack.pop()

    def top(self) -> int:
        # Return the top element of the main stack
        return self.stack[-1]

    def getMin(self) -> int:
        # Return the top element of the min stack, which is the current minimum
        return self.min_stack[-1]