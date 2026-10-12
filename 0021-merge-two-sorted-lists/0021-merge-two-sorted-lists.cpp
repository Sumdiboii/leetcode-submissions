class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 1. Create a dummy node to act as the starting anchor
        ListNode dummy(0);
        ListNode* tail = &dummy; // This pointer tracks the last node of our new list

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        // 2. Compare nodes from both lists and attach the smaller one
        while (curr1 && curr2) {
            if (curr1->val <= curr2->val) {
                tail->next = curr1;  // Link the smaller node
                curr1 = curr1->next; // Move forward in list1
            } else {
                tail->next = curr2;  // Link the smaller node
                curr2 = curr2->next; // Move forward in list2
            }
            tail = tail->next; // Move the tail forward
        }

        // 3. Attach the remaining nodes (replaces your second while loop)
        if (curr1) {
            tail->next = curr1;
        } else {
            tail->next = curr2;
        }

        // 4. Return the head of the merged list (skipping the dummy node)
        return dummy.next;
    }
};
