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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        //we find the middle of the LL
        while(fast && fast->next){
            slow = slow->next;
            fast=fast->next->next;
        }

        //we reverse the last part from middle of the LL
        ListNode* curr= slow;
        ListNode* nextNext = nullptr;
        ListNode* prev = nullptr;

        while(curr){
            nextNext = curr->next;
            curr->next =prev;
            prev = curr;
            curr=nextNext;
        }

        ListNode* temp = head;
        ListNode* temp2 = prev;

        while(temp->next && temp2->next){
            ListNode* nextT2 = temp2->next;
            ListNode* nextT1 = temp->next;
            temp->next = temp2;
            temp = nextT1;
            temp2->next = nextT1;
            temp2 = nextT2;
        }

    }
};