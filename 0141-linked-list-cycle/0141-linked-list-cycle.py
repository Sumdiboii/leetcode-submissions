class Solution:
    # 3. Linked List Cycle (LeetCode 141)
    def hasCycle(self, head: [ListNode]) -> bool:
        # Initialize slow and fast pointers at the head of the list
        slow = head
        fast = head
        
        # Traverse the list with fast moving 2 steps and slow moving 1 step
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            
            # If pointers meet, a cycle exists
            if slow == fast:
                return True
                
        # If the fast pointer reaches the end, there is no cycle
        return False