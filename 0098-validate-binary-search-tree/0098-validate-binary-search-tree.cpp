class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // Use long long boundaries to handle INT_MIN and INT_MAX edge cases safely
        return validate(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validate(TreeNode* node, long long min_val, long long max_val) {
        // An empty tree is a valid BST
        if (node == nullptr) {
            return true;
        }

        // The current node's value must strictly fall within the range
        if (node->val <= min_val || node->val >= max_val) {
            return false;
        }

        // Recursively validate left and right subtrees with updated bounds
        return validate(node->left, min_val, node->val) && 
               validate(node->right, node->val, max_val);
    }
};