/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* previousptr = nullptr;
        ListNode* currentptr = head;

        while(currentptr != nullptr){
             ListNode* temporaryptr = currentptr -> next;
             currentptr -> next = previousptr;
             previousptr = currentptr;
             currentptr = temporaryptr;
        } 

        return previousptr;
    }   
};