# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        
        def dfs(node, current_num):
            # Base case: empty node contributes nothing
            if not node:
                return 0
            
            # Update the number formed by the path so far
            current_num = (current_num * 10) + node.val
            
            # If we are at a leaf node, return the completed number
            if not node.left and not node.right:
                return current_num
            
            # If not a leaf, recurse deeper and sum the results
            return dfs(node.left, current_num) + dfs(node.right, current_num)
            
        # Initial call with running sum of 0
        return dfs(root, 0)