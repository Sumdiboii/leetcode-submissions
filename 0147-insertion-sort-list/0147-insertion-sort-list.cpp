class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = head;
        
        while (curr != nullptr) {
            // Keep track of the next node to process
            ListNode* nextNode = curr->next;
            
            // Start searching from the dummy node
            ListNode* prev = dummy;
            
            // Find the correct insertion point in the sorted portion
            while (prev->next != nullptr && prev->next->val < curr->val) {
                prev = prev->next;
            }
            
            // Perform the insertion
            curr->next = prev->next;
            prev->next = curr;
            
            // Move to the next node in the original list
            curr = nextNode;
        }
        
        ListNode* sortedHead = dummy->next;
        delete dummy; // Clean up memory
        return sortedHead;
    }
};