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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return vector<vector<int>>();
        }
        int direction = 1, count = 1;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()) {
            vector<TreeNode*> nodeForLevel;
            for (int i=0; i<count; i++) {
                TreeNode *ptr = q.front();
                q.pop();
                nodeForLevel.push_back(ptr);
            }
            int nextCount = 0;
            vector<int> valueForLevel;
            for (int i=0; i<count; i++) {
                TreeNode *ptr = nodeForLevel[i];
                valueForLevel.push_back( (direction?ptr:nodeForLevel[count-1-i])->val );
                if (ptr->left != nullptr) {
                    q.push(ptr->left);
                    nextCount++;
                }
                if (ptr->right != nullptr) {
                    q.push(ptr->right);
                    nextCount++;
                }
            }
            direction = direction == 0 ? 1 : 0;
            count = nextCount;
            ans.push_back(valueForLevel);
        }
        return ans;
    }
};
