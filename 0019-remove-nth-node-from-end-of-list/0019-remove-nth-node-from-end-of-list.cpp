class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int len = 0;
        ListNode* temp = head;

        // find length
        while(temp){
            len++;
            temp = temp->next;
        }

        // if deleting head
        if(n == len)
            return head->next;

        int steps = len - n - 1;

        temp = head;
        while(steps--){
            temp = temp->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};