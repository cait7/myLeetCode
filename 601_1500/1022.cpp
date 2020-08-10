/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;

        if (root == NULL) {
            return res;
        }

        return calRootToLeaf(root, 0);
    }

    int calRootToLeaf(TreeNode* root, int val) {
        if (root == NULL) {
            return 0;
        }

        if (root->left == NULL && root->right == NULL) {
            return val * 2 + root->val;
        }

        return calRootToLeaf(root->left, val * 2 + root->val) + calRootToLeaf(root->right, val * 2 + root->val);
    }
};
