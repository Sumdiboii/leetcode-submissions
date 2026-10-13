/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> umap;
        Node* curr = head;
        umap[NULL] = NULL;

        while(curr){
            Node* copy = new Node(curr->val);

            umap[curr] = copy;
            curr = curr->next;
        }

        curr = head;


        while(curr){

            Node* copyptr = umap[curr];
            // Connect the clone's pointers using the map lookups
            copyptr->next = umap[curr->next];     // Fix: Added next pointer assignment
            copyptr->random = umap[curr->random]; // Fix: Keeps Node* lookup instead of val
            curr = curr ->next;
        }


        return umap[head];
    }
};