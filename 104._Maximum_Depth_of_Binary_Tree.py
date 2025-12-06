class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        # Base Case: If the node is empty, depth is 0
        if not root:
            return 0
        
        # Recursive Step: 1 (for self) + max depth of left or right sub-trees
        return 1 + max(self.maxDepth(root.left), self.maxDepth(root.right))