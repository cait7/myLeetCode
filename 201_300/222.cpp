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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        int lLevel = countLevel(root->left), rLevel = countLevel(root->right);
        if (lLevel == rLevel) {
            return (1 << lLevel) + countNodes(root->right);
        }
        else {
            return countNodes(root->left) + countNodes(root->right) + 1;
        }
    }

    int countLevel(TreeNode* root) {
        int level = 0;
        while(root) {
            root = root->left;
            level++;
        }
        return level;
    }
};
