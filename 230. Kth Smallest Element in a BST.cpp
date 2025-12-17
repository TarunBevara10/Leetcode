#include <stack>

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        std::stack<TreeNode*> st;
        TreeNode* curr = root;
        
        // Loop while there are nodes to process
        while (curr != nullptr || !st.empty()) {
            
            // 1. Go as deep left as possible
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            
            // 2. Process the node (this is the "Root" step of Inorder)
            curr = st.top();
            st.pop();
            
            // Decrement k. If k becomes 0, this is our node.
            k--;
            if (k == 0) {
                return curr->val;
            }
            
            // 3. Move to the right child
            curr = curr->right;
        }
        
        return -1; // Should not be reached given the problem constraints
    }
};