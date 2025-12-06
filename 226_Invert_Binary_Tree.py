class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        
        # Pythonic swap: Invert right and assign to left, Invert left and assign to right
        # The RHS is evaluated before assignment, so no temp variable is needed.
        root.left, root.right = self.invertTree(root.right), self.invertTree(root.left)
        
        return root