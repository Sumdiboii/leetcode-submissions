/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *first=NULL,*second=NULL,*prev=NULL;
    void inorder(TreeNode* node)
    {
        if(node==NULL)  return ;
        inorder(node->left);
        if(prev && prev->val >node->val)
        {
            if(!first)  first=prev;
            second=node;
        }
        prev=node;
        inorder(node->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val,second->val);
    }
};