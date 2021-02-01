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
        return isNodeSymmetric(root, root);
    }

    bool isNodeSymmetric(TreeNode* ptr1, TreeNode* ptr2) {
        if (ptr1 != nullptr && ptr2 != nullptr) {
            return ptr1->val == ptr2->val && isNodeSymmetric(ptr1->left, ptr2->right) && isNodeSymmetric(ptr1->right, ptr2->left);
        }
        return ptr1 == ptr2;
    }
};
