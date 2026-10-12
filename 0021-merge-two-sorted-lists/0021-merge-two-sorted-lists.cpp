class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        // 1. Process nodes while both lists have elements
        while (curr1 && curr2) {
            if (curr1->val <= curr2->val) {
                tail->next = curr1;
                curr1 = curr1->next;
            } else {
                tail->next = curr2;
                curr2 = curr2->next;
            }
            tail = tail->next;
        }

        // 2. Direct connection: Link the entire remaining chain at once
        tail->next = curr1 ? curr1 : curr2;

        return dummy.next;
    }
};
