# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        # Initialize global max with a very small number
        self.global_max = float('-inf')
        
        def get_max_gain(node):
            if not node:
                return 0
            
            # Recursive Step: Get max gain from left and right subtrees.
            # We use max(..., 0) to ignore negative paths. 
            # If a subtree sum is negative, we are better off not including it at all.
            left_gain = max(get_max_gain(node.left), 0)
            right_gain = max(get_max_gain(node.right), 0)
            
            # Case 1: The "Split" Path (Potential Global Max)
            # This path goes Left -> Node -> Right. 
            # It cannot continue up to the parent.
            current_path_sum = node.val + left_gain + right_gain
            
            # Update the global maximum if this split path is better
            self.global_max = max(self.global_max, current_path_sum)
            
            # Case 2: The "Return" Path (Value for Parent)
            # The parent can only choose ONE side of the current node (Left OR Right)
            # to continue the path. We choose the larger side.
            return node.val + max(left_gain, right_gain)
        
        get_max_gain(root)
        return self.global_max