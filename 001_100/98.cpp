/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidTreeNode(root, -LONG_MAX, LONG_MAX);
    }

    bool isValidTreeNode(TreeNode *ptr, long l, long r) {
        if (ptr == nullptr) {
            return true;
        }
        if (ptr->val <= l || ptr->val >= r) {
            return false;
        }
        return isValidTreeNode(ptr->left, l, ptr->val) && isValidTreeNode(ptr->right, ptr->val, r);
    }
};
