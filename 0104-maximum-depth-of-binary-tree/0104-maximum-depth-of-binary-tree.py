# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    # 2. Maximum Depth of Binary Tree (LeetCode 104)
    def maxDepth(self, root: [TreeNode]) -> int:
        # Base case: if the tree is empty, depth is 0
        if not root:
            return 0
            
        # Recursively find the depth of the left and right subtrees
        left_depth = self.maxDepth(root.left)
        right_depth = self.maxDepth(root.right)
        
        # The maximum depth is the greater of the two depths plus one for the current node
        return max(left_depth, right_depth) + 1