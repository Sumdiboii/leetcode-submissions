class Solution:
    # 5. Lowest Common Ancestor of a Binary Search Tree (LeetCode 235)
    def lowestCommonAncestor(self, root: [TreeNode], p: [TreeNode], q: [TreeNode]) -> [TreeNode]:
        # Current node value
        val = root.val
        
        # If both nodes are greater than root, LCA must be in the right subtree
        if p.val > val and q.val > val:
            return self.lowestCommonAncestor(root.right, p, q)
            
        # If both nodes are smaller than root, LCA must be in the left subtree
        if p.val < val and q.val < val:
            return self.lowestCommonAncestor(root.left, p, q)
            
        # Otherwise, this node is the split point, which is the Lowest Common Ancestor
        return root