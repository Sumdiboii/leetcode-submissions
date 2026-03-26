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

        int steps = len - n;

        temp = head;
        while(steps != 1){
            temp = temp->next;
            steps--;
        }

        temp->next = temp->next->next;

        return head;
    }
};