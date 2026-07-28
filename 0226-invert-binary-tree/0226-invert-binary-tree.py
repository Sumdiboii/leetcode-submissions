class Solution:
    # 3. Invert Binary Tree (LeetCode 226)
    def invertTree(self, root: [TreeNode]) -> [TreeNode]:
        # Base case: if the root is None, return None
        if not root:
            return None
            
        # Swap the left and right children
        root.left, root.right = root.right, root.left
        
        # Recursively invert the left and right subtrees
        self.invertTree(root.left)
        self.invertTree(root.right)
        
        return root