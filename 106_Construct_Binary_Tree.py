# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        # Hash map to store index of each value in inorder traversal for O(1) lookup
        inorder_map = {val: idx for idx, val in enumerate(inorder)}
        
        def helper(left_boundary, right_boundary):
            # Base case: if there are no elements to construct the subtree
            if left_boundary > right_boundary:
                return None
            
            # The last element in postorder is the root of the current subtree
            root_val = postorder.pop()
            root = TreeNode(root_val)
            
            # Get the index of the root in the inorder traversal
            idx = inorder_map[root_val]
            
            # Recursively build the right and left subtrees.
            # CRITICAL: We must build the RIGHT subtree first because we are popping 
            # from the end of the postorder array (Root -> Right -> Left logic).
            root.right = helper(idx + 1, right_boundary)
            root.left = helper(left_boundary, idx - 1)
            
            return root

        # Initiate recursion with the full range of the inorder array
        return helper(0, len(inorder) - 1)