/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // Edge case: if the list is empty or has only one node, no duplicates possible
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* current = head;
        
        // Traverse the list until the second-to-last node
        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                // Found a duplicate! Save a pointer to delete it and free memory
                ListNode* duplicate = current->next;
                current->next = current->next->next; // Skip the duplicate
                delete duplicate;                    // Free the memory
            } else {
                // No duplicate, just move to the next node
                current = current->next;
            }
        }
        
        return head;
    }
};