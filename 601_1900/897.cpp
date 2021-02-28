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
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode *l, *r, *curr;
        l = curr = increasingBST(root->left);
        r = increasingBST(root->right);
        if (curr) {
            while (curr->right) {
                curr = curr->right;
            }
            curr->right = root;
        }
        root->left = NULL;
        root->right = r;
        return l == NULL ? root : l;
    }
};
