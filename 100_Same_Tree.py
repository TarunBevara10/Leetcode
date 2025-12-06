class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        # Case 1: Both nodes are None (end of a branch), so they are structurally the same.
        if not p and not q:
            return True
        
        # Case 2: One is None and the other isn't (structural mismatch)
        # OR Case 3: The values differ.
        if not p or not q or p.val != q.val:
            return False
        
        # Recursive Step: Check if left subtrees match AND right subtrees match.
        return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)