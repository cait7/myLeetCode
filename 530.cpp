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
    int getMinimumDifference(TreeNode* root) {
        
        vector<int> list;
        inorderSearch(root, list);

        int res = 10000;
        for (int i=1; i<list.size(); i++) {
            res = res > abs(list[i]-list[i-1]) ? abs(list[i]-list[i-1]) : res;
        }

        return res;
    }

    void inorderSearch(TreeNode* ptr, vector<int>& list) {
        
        if (!ptr) {
            return;
        }

        inorderSearch(ptr->left, list);
        list.push_back(ptr->val);
        inorderSearch(ptr->right, list);
    }

};
