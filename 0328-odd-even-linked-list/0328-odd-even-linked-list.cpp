/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        // Edge case: if the list has 0, 1, or 2 nodes, no reordering is needed
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
            return head;
        }
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; // Remember the start of the even list
        
        // Loop runs as long as there are nodes to process in the even list
        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;   // Connect current odd to next odd
            odd = odd->next;          // Move odd pointer forward
            
            even->next = odd->next;   // Connect current even to next even
            even = even->next;        // Move even pointer forward
        }
        
        // Connect the end of the odd list to the head of the even list
        odd->next = evenHead;
        
        return head;
    }
};