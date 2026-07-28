class Solution:
    # 4. Same Tree (LeetCode 100)
    def isSameTree(self, p: [TreeNode], q: [TreeNode]) -> bool:
        # If both nodes are None, they are identical
        if not p and not q:
            return True
            
        # If one is None and the other is not, or values differ, they are not identical
        if not p or not q or p.val != q.val:
            return False
            
        # Recursively check both left and right subtrees
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)