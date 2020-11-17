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
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        return auxSymmetric(root->left, root->right);
    }

    bool auxSymmetric(TreeNode* l, TreeNode* r) {
        if (l==NULL && r==NULL) return true;
        else if (l!=NULL && r!=NULL && l->val==r->val) return auxSymmetric(l->left, r->right) && auxSymmetric(l->right, r->left);
        else return false;
    }
};
