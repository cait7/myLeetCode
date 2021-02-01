/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {

        vector<ListNode*> res(k);
        ListNode *ptr1, *ptr2;

        int len = 0;
        ptr1 = root;
        while(root) {
            len++;
            root = root->next;
        }

        int averageLen, segLen, restLen;
        restLen = len;
        for (int i=0; i<k; i++) {
            res[i] = ptr1;

            averageLen = restLen / (k-i);

            if (restLen - averageLen * (k-i)) {
                segLen = averageLen + 1;
            }
            else {
                segLen = averageLen;
            }

            restLen -= segLen;
            
            for (int j=0; j<segLen-1; j++) {
                if (ptr1 != NULL)
                    ptr1 = ptr1->next;
            }

            if (ptr1 != NULL) {
                ptr2 = ptr1->next;
                ptr1->next = NULL;
                ptr1 = ptr2;
            }
        }

        return res;
    }
};
