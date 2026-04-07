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

    ListNode* getkth(ListNode* kth, int k){
        while(kth && k>0){
            kth=kth->next;
            k--;
        }

        return kth;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        ListNode* gprev=dummy;
        gprev->next=head;

        while(true){
            ListNode* kth=getkth(gprev, k);

            if(kth==NULL)
                break;

            ListNode* gnext=kth->next;

            ListNode* prev=gnext;
            ListNode* cur=gprev->next;
            ListNode* fwd=gprev->next;

            for(int i=0; i<k; i++){
                fwd=cur->next;
                cur->next=prev;
                prev=cur;
                cur=fwd;
            }

            ListNode* temp=gprev->next;
            gprev->next=kth;
            gprev=temp;
        }

        return dummy->next;
    }
};