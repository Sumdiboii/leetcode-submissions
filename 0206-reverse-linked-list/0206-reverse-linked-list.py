# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    # 1. Reverse Linked List (LeetCode 206)
    def reverseList(self, head: [ListNode]) -> [ListNode]:
        # Initialize previous pointer to None and current pointer to head
        prev = None
        curr = head
        
        # Traverse the list and reverse the pointers
        while curr:
            # Store the next node temporarily
            next_node = curr.next
            # Reverse the current node's pointer to point backwards
            curr.next = prev
            # Move prev and curr one step forward
            prev = curr
            curr = next_node
            
        # Return the new head of the reversed list
        return prev