from typing import Optional

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.min_diff = float('inf')
        self.prev_val = None
        
        def inorder(node):
            if not node:
                return
            
            # 1. Traverse Left
            inorder(node.left)
            
            # 2. Process Current Node
            if self.prev_val is not None:
                # Calculate difference with the previous node in sorted order
                self.min_diff = min(self.min_diff, node.val - self.prev_val)
            
            # Update prev_val to current node for the next step
            self.prev_val = node.val
            
            # 3. Traverse Right
            inorder(node.right)
            
        inorder(root)
        return int(self.min_diff)