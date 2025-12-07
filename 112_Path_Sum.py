# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        # Base case: if the tree is empty or we reached a None child
        if not root:
            return False
        
        # Check if the current node is a leaf
        if not root.left and not root.right:
            # If it is a leaf, check if it equals the remaining sum
            return root.val == targetSum
        
        # Recursive step: Subtract current value from target and check children
        remaining_sum = targetSum - root.val
        
        return (self.hasPathSum(root.left, remaining_sum) or 
                self.hasPathSum(root.right, remaining_sum))