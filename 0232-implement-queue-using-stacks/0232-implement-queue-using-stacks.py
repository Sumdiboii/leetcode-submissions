class MyQueue:
    # 2. Implement Queue using Stacks (LeetCode 232)
    def __init__(self):
        # Stack to push incoming elements
        self.in_stack = []
        # Stack to pop/peek elements in FIFO order
        self.out_stack = []

    def push(self, x: int) -> None:
        # Push elements onto the input stack
        self.in_stack.append(x)

    def pop(self) -> int:
        # Transfer elements if out_stack is empty to reverse order
        self.peek()
        # Pop from the output stack
        return self.out_stack.pop()

    def peek(self) -> int:
        # If out_stack is empty, move all elements from in_stack to out_stack
        if not self.out_stack:
            while self.in_stack:
                self.out_stack.append(self.in_stack.pop())
        # Return the top element of out_stack without removing it
        return self.out_stack[-1]

    def empty(self) -> bool:
        # Return True if both stacks are empty
        return not self.in_stack and not self.out_stack