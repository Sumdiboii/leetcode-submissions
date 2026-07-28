class Solution:
    # 2. Merge Two Sorted Lists (LeetCode 21)
    def mergeTwoLists(self, list1: [ListNode], list2: [ListNode]) -> [ListNode]:
        # Create a dummy node to serve as the start of the merged list
        dummy = ListNode(-1)
        current = dummy
        
        # Loop while both lists have nodes remaining
        while list1 and list2:
            if list1.val <= list2.val:
                current.next = list1
                list1 = list1.next
            else:
                current.next = list2
                list2 = list2.next
            current = current.next
            
        # Attach the remaining nodes from whichever list is not empty
        current.next = list1 if list1 else list2
        
        # Return the head of the merged list, skipping the dummy node
        return dummy.next