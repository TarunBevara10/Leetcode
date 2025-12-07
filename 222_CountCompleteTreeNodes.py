# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        # Get the depth of the leftmost path
        left_depth = 0
        node = root
        while node:
            left_depth += 1
            node = node.left
            
        # Get the depth of the rightmost path
        right_depth = 0
        node = root
        while node:
            right_depth += 1
            node = node.right
            
        # If depths are equal, it's a perfect binary tree
        # Formula for nodes in perfect tree: 2^depth - 1
        if left_depth == right_depth:
            return (2 ** left_depth) - 1
        
        # If not perfect, calculate recursively (1 for root + left + right)
        else:
            return 1 + self.countNodes(root.left) + self.countNodes(root.right)