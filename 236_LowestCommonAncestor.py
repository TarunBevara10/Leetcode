# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # Base Case: 
        # 1. We reached the bottom (root is None)
        # 2. We found p OR we found q (return the node found)
        if not root or root == p or root == q:
            return root
        
        # Recursive Step: Search in left and right subtrees
        left_result = self.lowestCommonAncestor(root.left, p, q)
        right_result = self.lowestCommonAncestor(root.right, p, q)
        
        # Logic:
        # If both left and right returned a node, it means p is on one side 
        # and q is on the other. The current 'root' is the LCA.
        if left_result and right_result:
            return root
        
        # Otherwise, return the non-None value. 
        # This propagates the found node (p or q) or the already found LCA up the stack.
        return left_result if left_result else right_result