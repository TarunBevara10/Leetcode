class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        if not root:
            return True
        
        # We need a helper to compare two separate branches
        def isMirror(t1, t2):
            # Base Case 1: Both empty -> Symmetric
            if not t1 and not t2:
                return True
            # Base Case 2: One empty, one not -> Not Symmetric
            # Base Case 3: Values differ -> Not Symmetric
            if not t1 or not t2 or t1.val != t2.val:
                return False
            
            # Recursive Step:
            # 1. Compare Outer nodes (t1.left vs t2.right)
            # 2. Compare Inner nodes (t1.right vs t2.left)
            return isMirror(t1.left, t2.right) and isMirror(t1.right, t2.left)

        return isMirror(root.left, root.right)