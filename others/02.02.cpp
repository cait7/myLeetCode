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
    int kthToLast(ListNode* head, int k) {
        ListNode *former, *latter;
        former = latter = head;
        while(k--) {
            if (latter != NULL) {
                latter = latter->next;
            }
        }
        while(latter) {
            latter = latter->next;
            former = former->next;
        }
        return former->val;
    }
};
