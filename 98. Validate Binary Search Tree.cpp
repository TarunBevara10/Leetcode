class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // Use long long to handle edge cases where node val is INT_MIN or INT_MAX
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode* node, long long minVal, long long maxVal) {
        // An empty tree is a valid BST
        if (node == nullptr) {
            return true;
        }

        // The current node's value must be strictly within the range (minVal, maxVal)
        if (node->val <= minVal || node->val >= maxVal) {
            return false;
        }

        // 1. Check left subtree: Update max limit to current node's val
        // 2. Check right subtree: Update min limit to current node's val
        return validate(node->left, minVal, node->val) && 
               validate(node->right, node->val, maxVal);
    }
};