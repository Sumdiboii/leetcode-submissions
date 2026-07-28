class Solution:
    # 5. Remove Linked List Elements (LeetCode 203)
    def removeElements(self, head: [ListNode], val: int) -> [ListNode]:
        # Create a dummy node to handle edge cases where the head itself needs to be removed
        dummy = ListNode(-1)
        dummy.next = head
        current = dummy
        
        # Traverse the list and check the next node's value
        while current.next:
            if current.next.val == val:
                # Bypass the node with the target value
                current.next = current.next.next
            else:
                # Move forward if the value doesn't match
                current = current.next
                
        # Return the updated list starting after the dummy node
        return dummy.next