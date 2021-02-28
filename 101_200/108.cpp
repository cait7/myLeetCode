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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return auxSortedArrayToBST(nums, 0, nums.size()-1);
    }

    TreeNode* auxSortedArrayToBST(vector<int>& nums, int b, int e) {
        if (b > e) {
            return NULL;
        }
        TreeNode *mid = new TreeNode(nums[ (b+e)/2 ]);
        mid->left = auxSortedArrayToBST(nums, b, (b+e)/2 - 1);
        mid->right = auxSortedArrayToBST(nums, (b+e)/2 +1, e);
        return mid;
    }
};
