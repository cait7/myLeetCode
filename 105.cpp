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
        
        if (!preorder.size() && !inorder.size()) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[0]);

        if (preorder.size() == 1 && inorder.size() == 1) {
            root->left = NULL;
            root->right = NULL;

            return root;
        }

        vector<int> in_left, in_right;

        bool isLeft = true;
        for (int i=0; i<inorder.size(); i++) {
            if (inorder[i] == preorder[0]) {
                isLeft = false;
                continue;
            }
            
            if (isLeft) {
                in_left.push_back(inorder[i]);
            }
            else {
                in_right.push_back(inorder[i]);
            }
        }

        vector<int> pre_left(preorder.begin()+1, preorder.begin()+in_left.size()+1);
        vector<int> pre_right(preorder.begin()+in_left.size()+1, preorder.end());

        root->left = buildTree(pre_left, in_left);
        root->right = buildTree(pre_right, in_right);

        return root;
    }
};
