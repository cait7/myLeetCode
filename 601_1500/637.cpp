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
    vector<double> averageOfLevels(TreeNode* root) {

        int numOfLevel, numOfNextLevel, count;
        long value;
        
        queue<TreeNode*> q;
        vector<double> res;

        q.push(root);
        numOfLevel = 1;
        numOfNextLevel = count = value = 0;

        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();

            if (node->left != NULL) {
                q.push(node->left);
                numOfNextLevel += 1;
            }
            if (node->right != NULL) {
                q.push(node->right);
                numOfNextLevel += 1;
            }

            count += 1;
            value += node->val;

            if (count == numOfLevel) {
                res.push_back(double(value)/count);

                numOfLevel = numOfNextLevel;
                numOfNextLevel = count = value = 0;
            }
        }

        return res;
    }
};
