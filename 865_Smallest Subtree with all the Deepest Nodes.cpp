/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Helper function that returns a pair: {subtree_height, lca_node}
    pair<int, TreeNode*> dfs(TreeNode* node) {
        if (!node) {
            return {0, nullptr};
        }

        // Recursively visit left and right children
        pair<int, TreeNode*> left = dfs(node->left);
        pair<int, TreeNode*> right = dfs(node->right);

        int leftDepth = left.first;
        int rightDepth = right.first;

        // If left is deeper, the answer is in the left subtree
        if (leftDepth > rightDepth) {
            return {leftDepth + 1, left.second};
        }
        // If right is deeper, the answer is in the right subtree
        else if (rightDepth > leftDepth) {
            return {rightDepth + 1, right.second};
        }
        // If depths are equal, THIS node is the new common ancestor
        else {
            return {leftDepth + 1, node};
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
};