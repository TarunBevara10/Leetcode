# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        
        def dfs(node, depth):
            if not node:
                return
            
            # If the current level (depth) matches the number of items in result,
            # it means this is the first node we are visiting at this depth.
            # Because we go Right -> Left, this MUST be the rightmost node.
            if depth == len(result):
                result.append(node.val)
            
            # Traverse Right FIRST, then Left
            dfs(node.right, depth + 1)
            dfs(node.left, depth + 1)
        
        dfs(root, 0)
        return result