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
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        stack<TreeNode*> s;
        s.push(root);
        TreeNode *head, *ptr, *curr;
        head = ptr = curr = nullptr;
        while (!s.empty()) {
            // 中序遍历
            curr = s.top();
            s.pop();
            if (curr->right != nullptr) {
                s.push(curr->right);
            }
            if (curr->left != nullptr) {
                s.push(curr->left);
            }
            // 构建单链表
            if (head == nullptr) {
                head = ptr = new TreeNode (curr->val);
            }
            else {
                ptr->right = new TreeNode (curr->val);
                ptr = ptr->right;
            }
        }
        root->right = head->right;
        root->left = nullptr;
    }
};
