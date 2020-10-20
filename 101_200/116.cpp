/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }
        
        int numsOfLayer = 1;
        queue<Node*> q;

        q.push(root);
        while(q.size() != 0) {
            for (int i=0; i<numsOfLayer; i++) {
                Node *item = q.front();
                q.pop();
    
                if (item->left != NULL && item->right != NULL) {
                    q.push(item->left);
                    q.push(item->right);
                }
            }

            if (q.size() == 0) {
                break;
            }

            queue<Node*> temp;
            Node *aNode = q.front(), *bNode;
            temp.push(aNode);
            q.pop();

            while (q.size() != 0 && aNode != NULL) {
                bNode = q.front();
                temp.push(bNode);
                aNode->next = bNode;
                aNode = bNode;
                q.pop();
            }

            q = temp;
            numsOfLayer *= 2;
        }

        return root;

    }
};
