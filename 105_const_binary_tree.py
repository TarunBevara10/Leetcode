class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        # Map inorder values to their indices for O(1) access
        inorder_map = {val: idx for idx, val in enumerate(inorder)}
        
        # Track our current position in the preorder array
        self.pre_idx = 0
        
        def array_to_tree(left, right):
            # Base Case: If the boundaries cross, there are no nodes here
            if left > right:
                return None
            
            # 1. Get the root value from the current preorder element
            root_val = preorder[self.pre_idx]
            self.pre_idx += 1
            root = TreeNode(root_val)
            
            # 2. Get the index of this root in the inorder map to split boundaries
            mid = inorder_map[root_val]
            
            # 3. Recursively build subtrees
            # Note: We MUST call left before right because preorder is (Root, Left, Right)
            root.left = array_to_tree(left, mid - 1)
            root.right = array_to_tree(mid + 1, right)
            
            return root
        
        return array_to_tree(0, len(preorder) - 1)