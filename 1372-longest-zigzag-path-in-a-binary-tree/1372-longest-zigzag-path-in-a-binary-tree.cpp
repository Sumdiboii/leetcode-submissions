#include <bits/stdc++.h>
using namespace std;

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
    int longestZigZag(TreeNode* root) {
        int ans = 0;
        dfs(root, true, 0, ans); // assuming start left
        dfs(root, false, 0, ans); // assuming start right
        return ans;
    }
private:
    void dfs(TreeNode* node, bool goLeft, int length, int &ans) {
        if (!node) return;
        // update global max
        ans = max(ans, length);
        if (goLeft) {
            // if next is left, length + 1
            dfs(node->left, false, length + 1, ans);
            // reset if we go in same direction
            dfs(node->right, true, 1, ans);
        } else {
            dfs(node->right, true, length + 1, ans);
            dfs(node->left, false, 1, ans);
        }
    }
};