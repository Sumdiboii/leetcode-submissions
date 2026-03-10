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
    long long totalSum = 0;
    long long maxProd = 0;
    vector<long long> allSubtreeSums;

public:
    int maxProduct(TreeNode* root) {
        // Step 1: Calculate total sum and store all possible subtree sums
        totalSum = calculateSubtreeSums(root);
        
        // Step 2: Iterate through all stored subtree sums to find max product
        for (long long s_i : allSubtreeSums) {
            long long currentProduct = s_i * (totalSum - s_i);
            if (currentProduct > maxProd) {
                maxProd = currentProduct;
            }
        }
        
        return maxProd % 1000000007;
    }

private:
    long long calculateSubtreeSums(TreeNode* node) {
        if (!node) return 0;
        
        // Recursive DFS to get the sum of the current subtree
        long long currentSubtreeSum = node->val + 
                                      calculateSubtreeSums(node->left) + 
                                      calculateSubtreeSums(node->right);
        
        // Store this sum to check it later
        allSubtreeSums.push_back(currentSubtreeSum);
        
        return currentSubtreeSum;
    }
};