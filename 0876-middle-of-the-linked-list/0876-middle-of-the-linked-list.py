class Solution:
    # 4. Middle of the Linked List (LeetCode 876)
    def middleNode(self, head: [ListNode]) -> [ListNode]:
        # Initialize slow and fast pointers at the head
        slow = head
        fast = head
        
        # Move fast by 2 steps and slow by 1 step until fast reaches the end
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
        # When fast reaches the end, slow will be at the middle node
        return slow