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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0,  preorder.size(), 0, inorder.size());
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if (ps == pe) {
            return NULL;
        }
        TreeNode *node = new TreeNode(preorder[ps]);
        int mid = is;
        for (; mid<ie; mid++) {
            if (inorder[mid] == preorder[ps]) {
                break;
            }
        }
        int preEnd = mid - is + ps + 1;
        node->left = buildTree(preorder, inorder, ps+1, preEnd, is, mid);
        node->right = buildTree(preorder, inorder, preEnd, pe, mid+1, ie);
        return node;
    }
};
