# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        current = root
        
        while current:
            if current.left:
                # Step 1: Find the rightmost node of the left subtree
                last_node_in_left = current.left
                while last_node_in_left.right:
                    last_node_in_left = last_node_in_left.right
                
                # Step 2: Wire the original right subtree to the end of the left subtree
                last_node_in_left.right = current.right
                
                # Step 3: Move the whole left subtree to the right
                current.right = current.left
                current.left = None
            
            # Move to the next node (which is now always to the right)
            current = current.right